/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "td_kit/tdks_tda.hpp"
#include "core_kit/pseudo_fock_matrix_generator.hpp"

#include <boost/ref.hpp>

#include <boost/lambda/algorithm.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>

#include "io_kit/logger.hpp"
#include "misc_kit/blackbox.hpp"

#include <cmath>

#include "gto_kit/os1_integral_engine.hpp"
#include "io_kit/log.hpp"
#include "misc_kit/dispatcher.hpp"

namespace niedoida {
    namespace td {

        TDKS_TDA::MultiSigma::MultiSigma(
            std::shared_ptr<const core::System> system,
            const arma::mat& mo_coeffs,
            const arma::vec& eps,
            std::size_t no_frozen,
            std::size_t no_deleted,
            Multiplicity mult,
            core::PseudoFockMultiMatrixGenerator& fm_gen,
            std::shared_ptr<XCMultiKernelGenerator> generator,
            double hf_exchange_contribution) :
            Base::MultiSigma(system,
                             mo_coeffs,
                             eps,
                             no_frozen,
                             no_deleted,
                             mult,
                             hf_exchange_contribution),
            m_fock_matrix_generator(&fm_gen),
            m_xc_kernel_generator(generator)
        {
        }

        std::vector<arma::mat> TDKS_TDA::MultiSigma::calc(
            const std::vector<arma::mat>& ci_coeffs) const
        {
            // density matrix
            const arma::mat P = scf::density_matrix(m_full_mo_coeffs, m_no_occ);

            const std::size_t no_vectors = ci_coeffs.size();

            std::vector<arma::cube> fake_P(2);
            std::vector<arma::cube> symmetrized_fake_P(2);

            fake_P[core::SPIN_ALPHA].set_size(
                m_mo_coeffs.n_rows, m_mo_coeffs.n_rows, no_vectors);
            fake_P[core::SPIN_BETA].set_size(
                m_mo_coeffs.n_rows, m_mo_coeffs.n_rows, no_vectors);

            symmetrized_fake_P[core::SPIN_ALPHA].set_size(
                m_mo_coeffs.n_rows, m_mo_coeffs.n_rows, no_vectors);
            symmetrized_fake_P[core::SPIN_BETA].set_size(
                m_mo_coeffs.n_rows, m_mo_coeffs.n_rows, no_vectors);

            for (std::size_t n = 0; n < no_vectors; ++n) {
                const arma::mat fP =
                    core::pseudo_density_matrix(m_mo_coeffs, ci_coeffs[n]);

                fake_P[core::SPIN_ALPHA].slice(n) = fP;
                fake_P[core::SPIN_BETA].slice(n) = fP;

                const arma::mat sfP = (fP + trans(fP)) / 2;

                symmetrized_fake_P[core::SPIN_ALPHA].slice(n) = sfP;
                symmetrized_fake_P[core::SPIN_BETA].slice(n) = sfP;
            }

            m_fock_matrix_generator->set_density_matrix(fake_P);
            m_xc_kernel_generator->set_density_matrix(P, P, symmetrized_fake_P);

            std::vector<arma::mat> multi_sigma;

            for (std::size_t n = 0; n < no_vectors; ++n) {
                const arma::mat J = m_fock_matrix_generator->coulomb_matrix(n);

                const arma::mat K = m_fock_matrix_generator->exchange_matrix(
                    n, core::SPIN_ALPHA);

                const arma::mat fxcaa = m_xc_kernel_generator->integrals(
                    n, core::SPIN_ALPHA, core::SPIN_ALPHA);

                const arma::mat fxcab = m_xc_kernel_generator->integrals(
                    n, core::SPIN_ALPHA, core::SPIN_BETA);

                const arma::mat fxcbb = m_xc_kernel_generator->integrals(
                    n, core::SPIN_BETA, core::SPIN_BETA);

                const arma::mat fxc_s = 0.5 * fxcaa + fxcab + 0.5 * fxcbb;

                const arma::mat fxc_t = 0.5 * fxcaa - fxcab + 0.5 * fxcbb;

                arma::mat F_ao;
                if (m_mult == SINGLET) {
                    F_ao = m_hf_x_contrib * K;
                    F_ao += J + fxc_s;
                } else {
                    F_ao = m_hf_x_contrib * K;
                    F_ao += fxc_t;
                }

                // transform the pseudo-fock matrix to the MO basis
                const arma::mat A = F_ao * m_mo_coeffs_virt;
                const arma::mat F_mo_ov = trans(m_mo_coeffs_occ) * A;

                // form the final result, including both diagonal and
                // nondiagonal terms
                const arma::mat sigma = ci_coeffs[n] % m_delta_eps + F_mo_ov;

                multi_sigma.push_back(sigma);
            }

            return multi_sigma;
        }

        TDKS_TDA::TDKS_TDA(
            Multiplicity multiplicity,
            std::shared_ptr<const core::System> system,
            const arma::mat mo_coeffs,
            const arma::vec eps,
            std::shared_ptr<const core::TwoElectronIntegralEngineFactory>
                ie_factory,
            unsigned no_frozen,
            unsigned no_deleted,
            unsigned no_states,
            unsigned no_roots,
            unsigned no_iterations,
            double diagonalization_threshold,
            double integral_threshold,
            std::shared_ptr<XCMultiKernelGenerator> generator,
            double hf_exchange_contribution) :
            RestrictedTD(system, eps, no_frozen, no_deleted, no_roots)
        {
            assert(no_iterations >= 1);
            assert(system->no_electrons(core::SPIN_ALPHA) ==
                   system->no_electrons(core::SPIN_BETA));
            io::Log::Section tdks_tda_section("restricted tdks tda");
            core::PseudoFockMultiMatrixGenerator fm_gen(
                system, ie_factory, integral_threshold);

            // starting vectors for true CIS problem
            arma::mat v_0(m_n, no_roots, arma::fill::zeros);

            if (no_roots > m_n)
                no_roots = m_n;

            MultiSigma ig_sigma(system,
                                mo_coeffs,
                                eps,
                                m_ig_no_frozen,
                                m_ig_no_deleted,
                                multiplicity,
                                fm_gen,
                                generator,
                                hf_exchange_contribution);

            std::function<arma::mat(const arma::mat&)> igs(std::ref(ig_sigma));

            misc::davidson_liu_diagonalize(igs,
                                           m_ig_delta_eps,
                                           m_ig_v_0,
                                           no_roots,
                                           no_roots,
                                           m_energies,
                                           m_coefficients,
                                           1,
                                           1000);

            // fill in starting vectors
            for (unsigned i = 0; i < m_small_part_occ; ++i)
                for (unsigned a = 0; a < m_small_part_virt; ++a)
                    for (unsigned k = 0; k < no_roots; ++k)
                        v_0((i + m_ig_no_frozen - no_frozen) *
                                    (m_no_virt - no_deleted) +
                                a,
                            k) = m_coefficients(i * m_small_part_virt + a, k);

            io::Log::Section main_section("full hamiltonian diagonalization");

            // solve true TDA problem

            MultiSigma sigma(system,
                             mo_coeffs,
                             eps,
                             no_frozen,
                             no_deleted,
                             multiplicity,
                             fm_gen,
                             generator,
                             hf_exchange_contribution);

            arma::vec delta_eps(m_n);
            for (unsigned i = 0; i < m_no_occ - no_frozen; ++i)
                for (unsigned a = m_no_occ;
                     a < m_no_occ + m_no_virt - no_deleted;
                     ++a)
                    delta_eps(i * (m_no_virt - no_deleted) + a - m_no_occ) =
                        eps(a) - eps(i + no_frozen);

            std::function<arma::mat(const arma::mat&)> s(std::ref(sigma));

            m_no_states_converged =
                misc::davidson_liu_diagonalize(s,
                                               delta_eps,
                                               v_0,
                                               no_states,
                                               no_roots,
                                               m_energies,
                                               m_coefficients,
                                               no_iterations,
                                               diagonalization_threshold);

            m_transition_dipoles = arma::zeros<arma::mat>(no_states, 3);

            if (multiplicity == SINGLET) {
                arma::mat C_occ =
                    mo_coeffs.submat(arma::span(0, m_no_occ + m_no_virt - 1),
                                     arma::span(no_frozen, m_no_occ - 1));

                arma::mat C_virt = mo_coeffs.submat(
                    arma::span(0, m_no_occ + m_no_virt - 1),
                    arma::span(m_no_occ,
                               m_no_occ + m_no_virt - no_deleted - 1));

                gto::OS1MultipoleIntegralEngine mie(*system);

                arma::mat d[3];
                d[0] = mie.dipole_matrices()[0];
                d[1] = mie.dipole_matrices()[1];
                d[2] = mie.dipole_matrices()[2];

                for (unsigned k = 0; k < no_states; ++k) {

                    arma::mat k_coeffs(m_no_occ - no_frozen,
                                       m_no_virt - no_deleted);
                    arma::mat half_T_matrix(mo_coeffs.n_rows, k_coeffs.n_cols);
                    arma::mat T_matrix(mo_coeffs.n_rows, mo_coeffs.n_cols);

                    k_coeffs = arma::reshape(m_coefficients.col(k),
                                             m_no_occ - no_frozen,
                                             m_no_virt - no_deleted);

                    half_T_matrix = C_occ * k_coeffs;
                    T_matrix = std::sqrt(2.0) * half_T_matrix * trans(C_virt);

                    for (unsigned l = 0; l < 3; ++l) {
                        for (unsigned p = 0; p < mo_coeffs.n_rows; ++p)
                            for (unsigned q = 0; q < mo_coeffs.n_rows; ++q)
                                m_transition_dipoles(k, l) +=
                                    T_matrix(p, q) * d[l](p, q);
                    }
                }
            }
        }

        arma::mat TDKS_TDA::gradient(const std::vector<unsigned>&, unsigned)
        {
            arma::mat gradient;

            return gradient;
        }
    }
}