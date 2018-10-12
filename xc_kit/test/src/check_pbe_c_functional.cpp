/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/test_tools.hpp>    
#include <boost/test/unit_test.hpp>

#include "xc_kit/xc_functionals.hpp"
    
void check_pbe_c_functional()
{
    const double eps = 1e-7;
    XCFunctionalData xc;
    xc = pbe_c_functional(0.17E+01, 0.17E+01, 0.81E-11, 0.81E-11, 0.81E-11, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.277343302026E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.902545684170E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.902545684170E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.828329874208E-03, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.165665974842E-02, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.828329874208E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, 0.129726391337E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.182703394917E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, 0.129726391337E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, -0.324835244787E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, -0.649670489575E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, -0.324835244787E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, -0.324835244787E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, -0.649670489575E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, -0.324835244787E-03, eps);
    //BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.649078703127E-05, eps);
    //BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.129815740625E-04, eps);
    //BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.649078703127E-05, eps);
    //BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.259631481251E-04, eps);
    //BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.129815740625E-04, eps);
    //BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.649078703127E-05, eps);
    xc = pbe_c_functional(0.17E+01, 0.17E+01, 0.17E+01, 0.17E+01, 0.17E+01, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.271855691853E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.923103473041E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.923103473041E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.786385334368E-03, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.157277066874E-02, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.786385334368E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, 0.141731701968E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.168480493572E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, 0.141731701968E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, -0.281023204875E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, -0.562046409750E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, -0.281023204875E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, -0.281023204875E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, -0.562046409750E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, -0.281023204875E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.586202682069E-05, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.117240536414E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.586202682069E-05, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.234481072827E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.117240536414E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.586202682069E-05, eps);
    xc = pbe_c_functional(0.15E+01, 0.15E+01, 0.36E+02, 0.36E+02, 0.36E+02, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.156330536080E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.102948996370E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.102948996370E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.378004824716E-03, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.756009649433E-03, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.378004824716E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, 0.767829363534E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.200905483619E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, 0.767829363534E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, 0.267671090070E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, 0.535342180140E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, 0.267671090070E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, 0.267671090070E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, 0.535342180140E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, 0.267671090070E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.171987026880E-05, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.343974053761E-05, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.171987026880E-05, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.687948107522E-05, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.343974053761E-05, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.171987026880E-05, eps);
    xc = pbe_c_functional(0.88E-01, 0.88E-01, 0.87E-01, 0.87E-01, 0.87E-01, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.353114293615E-02, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.644123523321E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.644123523321E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.830804942063E-02, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.166160988413E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.830804942063E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, -0.294409365638E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.534985274786E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, -0.294409365638E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, 0.746427566937E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, 0.149285513387E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, 0.746427566937E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, 0.746427566937E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, 0.149285513387E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, 0.746427566937E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.283776069209E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.567552138418E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.283776069209E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.113510427684E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.567552138418E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.283776069209E-01, eps);
    xc = pbe_c_functional(0.18E+04, 0.18E+04, 0.55E+00, 0.55E+00, 0.55E+00, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.531558156901E+03, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.157670707589E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.157670707589E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.767547413336E-07, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.153509482667E-06, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.767547413336E-07, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, 0.222158431130E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.278288704562E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, 0.222158431130E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, -0.284276819003E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, -0.568553638007E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, -0.284276819003E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, -0.284276819003E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, -0.568553638007E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, -0.284276819003E-10, eps);
    //BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.526353544028E-16, eps);
    //BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.105270708806E-15, eps);
    //BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.526353544028E-16, eps);
    //BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.210541417611E-15, eps);
    //BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.105270708806E-15, eps);
    //BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.526353544028E-16, eps);
    xc = pbe_c_functional(0.18E+04, 0.18E+04, 0.86E+04, 0.86E+04, 0.86E+04, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.531555516738E+03, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.157671685407E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.157671685407E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.767529308359E-07, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.153505861672E-06, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.767529308359E-07, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, 0.222164315920E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.278281914345E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, 0.222164315920E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, -0.284258379026E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, -0.568516758052E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, -0.284258379026E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, -0.284258379026E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, -0.568516758052E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, -0.284258379026E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.526328718655E-16, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.105265743731E-15, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.526328718655E-16, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.210531487462E-15, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.105265743731E-15, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.526328718655E-16, eps);
    xc = pbe_c_functional(0.16E+04, 0.16E+04, 0.37E+10, 0.37E+10, 0.37E+10, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.204845328577E+03, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.139570172131E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.139570172131E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.609549582413E-08, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.121909916483E-07, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.609549582413E-08, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, -0.845856478622E-05, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.379435495181E-04, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, -0.845856478622E-05, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, 0.183107776239E-11, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, 0.366215552479E-11, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, 0.183107776239E-11, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, 0.183107776239E-11, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, 0.366215552479E-11, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, 0.183107776239E-11, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.402310862302E-18, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.804621724604E-18, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.402310862302E-18, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.160924344921E-17, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.804621724604E-18, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.402310862302E-18, eps);
    xc = pbe_c_functional(0.26E+00, 0.26E+00, 0.28E+00, 0.28E+00, 0.28E+00, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.257202574589E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.866997760784E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.866997760784E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.582853357983E-02, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.116570671597E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.582853357983E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, 0.728321951048E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.756102345474E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, 0.728321951048E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, -0.305698872548E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, -0.611397745095E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, -0.305698872548E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, -0.305698872548E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, -0.611397745095E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, -0.305698872548E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.233980425019E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.467960850038E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.233980425019E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.935921700077E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.467960850038E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.233980425019E-02, eps);
    xc = pbe_c_functional(0.53E+05, 0.53E+05, 0.96E+05, 0.96E+05, 0.96E+05, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.192839940466E+05, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.192144028270E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.192144028270E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.844177976352E-09, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.168835595270E-08, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.844177976352E-09, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, 0.930079636518E-06, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.112362987226E-05, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, 0.930079636518E-06, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, -0.106185890697E-13, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, -0.212371781394E-13, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, -0.106185890697E-13, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, -0.106185890697E-13, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, -0.212371781394E-13, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, -0.106185890697E-13, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.216237891268E-21, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.432475782536E-21, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.216237891268E-21, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.864951565071E-21, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.432475782536E-21, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.216237891268E-21, eps);
    xc = pbe_c_functional(0.47E+05, 0.47E+05, 0.29E+14, 0.29E+14, 0.29E+14, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.621606173598E+04, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.145186193191E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.145186193191E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.239893933515E-10, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.479787867030E-10, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.239893933515E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, -0.415550006172E-06, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.137798903649E-05, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, -0.415550006172E-06, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, 0.270195164309E-15, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, 0.540390328617E-15, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, 0.270195164309E-15, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, 0.270195164309E-15, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, 0.540390328617E-15, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, 0.270195164309E-15, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.210724100250E-24, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.421448200501E-24, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.210724100250E-24, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.842896401002E-24, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.421448200501E-24, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.210724100250E-24, eps);
    xc = pbe_c_functional(0.15E+00, 0.15E+00, 0.16E+00, 0.16E+00, 0.16E+00, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.103495051751E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.808320886304E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.808320886304E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.782485884453E-02, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.156497176891E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.782485884453E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, 0.974468235880E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.195273591427E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, 0.974468235880E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, 0.120240976646E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, 0.240481953292E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, 0.120240976646E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, 0.120240976646E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, 0.240481953292E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, 0.120240976646E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.914758040599E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.182951608120E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.914758040599E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.365903216240E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.182951608120E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.914758040599E-02, eps);
    xc = pbe_c_functional(0.35E+01, 0.00E+00, 0.46E-10, 0.00E+00, 0.00E+00, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.149930438056E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.472559970726E-01, eps);
    BOOST_CHECK_SMALL(xc.de_drb, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.632520331340E-03, eps);
    BOOST_CHECK_SMALL(xc.de_dgab, eps);
    BOOST_CHECK_SMALL(xc.de_dgbb, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, -0.130590959396E-02, eps);
    BOOST_CHECK_SMALL(xc.d2e_drarb, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbrb, eps);
    //BOOST_CHECK_SMALL(xc.d2e_dragaa, eps);
    BOOST_CHECK_SMALL(xc.d2e_dragbb, eps);
    BOOST_CHECK_SMALL(xc.d2e_dragbb, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbgaa, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbgab, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbgbb, eps);
    //BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.735327076770E-05, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgaagab, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgaagbb, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgabgab, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgbbgab, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgbbgbb, eps);
    xc = pbe_c_functional(0.35E+01, 0.00E+00, 0.34E+01, 0.00E+00, 0.00E+00, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.147821297915E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.480325520180E-01, eps);
    BOOST_CHECK_SMALL(xc.de_drb, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.608456906274E-03, eps);
    BOOST_CHECK_SMALL(xc.de_dgab, eps);
    BOOST_CHECK_SMALL(xc.de_dgbb, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, -0.815520844173E-03, eps);
    BOOST_CHECK_SMALL(xc.d2e_drarb, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbrb, eps);
    //BOOST_CHECK_SMALL(xc.d2e_dragaa, eps);
    BOOST_CHECK_SMALL(xc.d2e_dragbb, eps);
    BOOST_CHECK_SMALL(xc.d2e_dragbb, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbgaa, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbgab, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbgbb, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.681211100497E-05, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgaagab, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgaagbb, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgabgab, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgbbgab, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgbbgbb, eps);
    xc = pbe_c_functional(0.30E+01, 0.00E+00, 0.20E+03, 0.00E+00, 0.00E+00, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.596933203014E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.494521116430E-01, eps);
    BOOST_CHECK_SMALL(xc.de_drb, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.163547485507E-03, eps);
    BOOST_CHECK_SMALL(xc.de_dgab, eps);
    BOOST_CHECK_SMALL(xc.de_dgbb, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, -0.918226192391E-02, eps);
    BOOST_CHECK_SMALL(xc.d2e_drarb, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbrb, eps);
    //BOOST_CHECK_SMALL(xc.d2e_dragaa, eps);
    BOOST_CHECK_SMALL(xc.d2e_dragbb, eps);
    BOOST_CHECK_SMALL(xc.d2e_dragbb, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbgaa, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbgab, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbgbb, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.752364152605E-06, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgaagab, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgaagbb, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgabgab, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgbbgab, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgbbgbb, eps);
    xc = pbe_c_functional(0.58E-01, 0.00E+00, 0.47E-01, 0.00E+00, 0.00E+00, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.134201626930E-03, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.113336793038E-01, eps);
    BOOST_CHECK_SMALL(xc.de_drb, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.418957314771E-02, eps);
    BOOST_CHECK_SMALL(xc.de_dgab, eps);
    BOOST_CHECK_SMALL(xc.de_dgbb, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, -0.639691764043E+00, eps);
    BOOST_CHECK_SMALL(xc.d2e_drarb, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbrb, eps);
    //BOOST_CHECK_SMALL(xc.d2e_dragaa, eps);
    BOOST_CHECK_SMALL(xc.d2e_dragbb, eps);
    BOOST_CHECK_SMALL(xc.d2e_dragbb, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbgaa, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbgab, eps);
    BOOST_CHECK_SMALL(xc.d2e_drbgbb, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.192576380057E+00, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgaagab, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgaagbb, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgabgab, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgbbgab, eps);
    BOOST_CHECK_SMALL(xc.d2e_dgbbgbb, eps);
    xc = pbe_c_functional(0.82E+02, 0.81E+02, 0.49E+07, 0.49E+07, 0.49E+07, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.466827360026E+01, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.911386831086E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.914525751657E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.195526696493E-06, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.391053392985E-06, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.195526696493E-06, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, -0.535201657866E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.850604423798E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, -0.538228029079E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, 0.214289755089E-08, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, 0.428579510177E-08, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, 0.214289755089E-08, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, 0.215378864780E-08, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, 0.430757729559E-08, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, 0.215378864780E-08, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.128838364018E-13, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.257676728036E-13, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.128838364018E-13, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.515353456071E-13, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.257676728036E-13, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.128838364018E-13, eps);
    xc = pbe_c_functional(0.39E+02, 0.38E+02, 0.81E+06, 0.82E+06, 0.82E+06, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.184442072405E+01, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.814334534280E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.820182123795E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.510839298939E-06, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.102167859788E-05, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.510839298939E-06, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, -0.124297349784E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.183505806584E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, -0.125767116982E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, 0.134850158624E-07, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, 0.269700317248E-07, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, 0.134850158624E-07, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, 0.136189478240E-07, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, 0.272378956480E-07, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, 0.136189478240E-07, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.216571369852E-12, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.433142739704E-12, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.216571369852E-12, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.866285479407E-12, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.433142739704E-12, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.216571369852E-12, eps);
    xc = pbe_c_functional(0.13E+00, 0.95E-01, 0.15E+00, 0.18E+00, 0.22E+00, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.416748767197E-02, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.595487649525E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.658275108773E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.500446791291E-02, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.100089358258E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.500446791291E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, -0.254320619062E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.454911463637E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, -0.296322781759E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, 0.376458611019E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, 0.752917222037E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, 0.376458611019E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, 0.432477759464E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, 0.864955518927E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, 0.432477759464E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.873874773980E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.174774954796E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.873874773980E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.349549909592E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.174774954796E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.873874773980E-02, eps);
    xc = pbe_c_functional(0.78E-01, 0.31E-01, 0.41E-02, 0.38E-02, 0.36E-02, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.446674124729E-02, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.576230218023E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.884299955306E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.565507026894E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.113101405379E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.565507026894E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, 0.211475716365E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.313442480821E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, 0.661715882717E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, -0.366634765948E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, -0.733269531896E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, -0.366634765948E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, -0.183738128575E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, -0.367476257149E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, -0.183738128575E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.113703722438E+01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.227407444876E+01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.113703722438E+01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.454814889752E+01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.227407444876E+01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.113703722438E+01, eps);
    xc = pbe_c_functional(0.50E+02, 0.49E+02, 0.11E+06, 0.11E+06, 0.11E+06, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.853822762402E+01, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.136330468738E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.137562342876E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.397018264645E-05, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.794036529289E-05, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.397018264645E-05, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, 0.505383535819E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.719176570320E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, 0.520080723382E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, 0.220509385365E-09, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, 0.441018770730E-09, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, 0.220509385365E-09, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, 0.606911398719E-09, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, 0.121382279744E-08, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, 0.606911398719E-09, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.518845125296E-11, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.103769025059E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.518845125296E-11, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.207538050118E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.103769025059E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.518845125296E-11, eps);
    xc = pbe_c_functional(0.40E+02, 0.40E+02, 0.99E+05, 0.98E+05, 0.98E+05, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.615277551535E+01, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.133907518541E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.133907518541E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.414743637478E-05, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.829487274956E-05, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.414743637478E-05, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, 0.435534219905E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.969294804880E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, 0.435534219905E-03, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, 0.125079346911E-07, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, 0.250158693823E-07, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, 0.125079346911E-07, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, 0.125079346911E-07, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, 0.250158693823E-07, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, 0.125079346911E-07, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.710218297869E-11, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.142043659574E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.710218297869E-11, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.284087319147E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.142043659574E-10, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.710218297869E-11, eps);
    xc = pbe_c_functional(0.12E+00, 0.10E+00, 0.12E+00, 0.13E+00, 0.14E+00, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.513978017858E-02, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.677801008926E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.720903652109E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.723862883206E-02, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.144772576641E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.723862883206E-02, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, -0.172744794034E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.396171978594E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, -0.188314565988E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, 0.403167927387E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, 0.806335854774E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, 0.403167927387E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, 0.445643432070E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, 0.891286864140E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, 0.445643432070E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.149411369506E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.298822739012E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.149411369506E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.597645478025E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.298822739012E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.149411369506E-01, eps);
    xc = pbe_c_functional(0.48E-01, 0.25E-01, 0.46E-02, 0.44E-02, 0.41E-02, 2);
    BOOST_CHECK_CLOSE(xc.e, -0.203181802597E-02, eps);
    BOOST_CHECK_CLOSE(xc.de_dra, -0.608626957301E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_drb, -0.779575998152E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgaa, 0.578479124549E-01, eps);
    BOOST_CHECK_CLOSE(xc.de_dgab, 0.115695824910E+00, eps);
    BOOST_CHECK_CLOSE(xc.de_dgbb, 0.578479124549E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drara, 0.152335258351E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drarb, -0.720403954936E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbrb, 0.952448412124E-01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragaa, 0.224592118966E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragab, 0.449184237932E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dragbb, 0.224592118966E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgaa, 0.517340140054E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgab, 0.103468028011E+01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_drbgbb, 0.517340140054E+00, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagaa, -0.238365551254E+01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagab, -0.476731102509E+01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgaagbb, -0.238365551254E+01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgabgab, -0.953462205018E+01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgab, -0.476731102509E+01, eps);
    BOOST_CHECK_CLOSE(xc.d2e_dgbbgbb, -0.238365551254E+01, eps);
}
