/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef NIEDOIDA_GTO_KIT_OS1_CONSTANTS_HPP
#define NIEDOIDA_GTO_KIT_OS1_CONSTANTS_HPP

#include <cmath>

namespace niedoida {
    namespace gto {
        constexpr double two_times_pi_to_five_over_two = 34.9868366552497256924;
        constexpr double two_pi_to_five_over_four = 5.91496717279561287781;
        constexpr double sqrt3 = 1.732050807568877293;
        constexpr double sqrt12 = 3.464101615137754587;
        constexpr double sqrt15 = 3.872983346207416885;
        constexpr double sqrt24 = 4.898979485566356196;
        constexpr double sqrt40 = 6.324555320336758663;
        constexpr double sqrt60 = 7.745966692414833770;
        constexpr double sqrt84 = 9.165151389911680013;
        constexpr double sqrt105 = 10.246950765959598383;
        constexpr double sqrt168 = 12.961481396815720461;
        constexpr double sqrt192 = 13.856406460551018348;
		constexpr double sqrt336 = 18.33030277982336002635;
        constexpr double sqrt6720 = 81.975606127676787065;

        // not higher than g functions
        constexpr unsigned OS1_L_MAX = 4;
        // default size for vr, svr, transfer
        constexpr unsigned OS1_S1 ((2 * OS1_L_MAX + 1) * (2 * OS1_L_MAX + 2) * (2 * OS1_L_MAX + 3) / 6);
    }
}

#endif