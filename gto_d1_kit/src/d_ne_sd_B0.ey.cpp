/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "gto_d1_kit/gto_d1.hpp"
#include <cmath>

namespace {
    static const double Pi = M_PI;
}

void vne_gradient_02_2(double ae,
                       double be,
                       double xA,
                       double yA,
                       double zA,
                       double xB,
                       double yB,
                       double zB,
                       double xC,
                       double yC,
                       double zC,
                       const double* bs,
                       double* const gx,
                       double* const gy,
                       double* const gz,
                       std::size_t matrix_size,
                       std::size_t Ai,
                       std::size_t Bi)
{
    const double C354 = 2. * Pi;
    const double C353 = ae + be;
    const double C352 = ae * be;
    const double C351 = zA - zB;
    const double C350 = yA - yB;
    const double C349 = xA - xB;
    const double C348 = bs[0];
    const double C357 = std::pow(C351, 2);
    const double C356 = std::pow(C350, 2);
    const double C355 = std::pow(C349, 2);
    const double C358 = C355 + C356;
    const double C359 = C358 + C357;
    const double C360 = C359 * C352;
    const double C361 = C360 / C353;
    const double C362 = -C361;
    const double C363 = std::exp(C362);
    const double C364 = C363 * C354;
    const double C365 = C348 * C364;
    const double C369 = bs[1];
    const double C370 = C369 * C364;
    const double C387 = be * zB;
    const double C386 = ae * zA;
    const double C385 = be * C351;
    const double C384 = be * yB;
    const double C383 = ae * yA;
    const double C382 = be * C350;
    const double C381 = bs[2];
    const double C380 = bs[1];
    const double C379 = be * xB;
    const double C378 = ae * xA;
    const double C377 = be * C349;
    const double C392 = C386 + C387;
    const double C391 = C383 + C384;
    const double C390 = C381 * C364;
    const double C389 = C380 * C364;
    const double C388 = C378 + C379;
    const double C395 = C392 / C353;
    const double C394 = C391 / C353;
    const double C393 = C388 / C353;
    const double C398 = C395 - zC;
    const double C397 = C394 - yC;
    const double C396 = C393 - xC;
    const double C77 = (-(C365 * C377) / C353) / C353 - (C396 * C389) / C353 +
                       (C349 * C365) / C353;
    const double C78 = C365 / C353;
    const double C79 = C389 / C353;
    const double C80 = (-(C370 * C377) / C353) / C353 - (C396 * C390) / C353 +
                       (C349 * C370) / C353;
    const double C81 = C390 / C353;
    const double C198 = (-(C365 * C382) / C353) / C353 - (C397 * C370) / C353 +
                        (C350 * C365) / C353;
    const double C199 = (-(C370 * C382) / C353) / C353 - (C397 * C390) / C353 +
                        (C350 * C370) / C353;
    const double C240 = (-(C365 * C385) / C353) / C353 - (C398 * C370) / C353 +
                        (C351 * C365) / C353;
    const double C241 = (-(C370 * C385) / C353) / C353 - (C398 * C390) / C353 +
                        (C351 * C370) / C353;
    const double C97 = be * zB;
    const double C96 = ae * zA;
    const double C95 = be * yB;
    const double C94 = ae * yA;
    const double C93 = bs[3];
    const double C92 = bs[2];
    const double C91 = 4 * Pi;
    const double C90 = zA - zB;
    const double C89 = yA - yB;
    const double C88 = ae * be;
    const double C87 = xA - xB;
    const double C86 = bs[0];
    const double C85 = bs[1];
    const double C84 = be * xB;
    const double C83 = ae * xA;
    const double C82 = ae + be;
    const double C109 = C90 * C88;
    const double C108 = C96 + C97;
    const double C107 = C89 * C88;
    const double C106 = C94 + C95;
    const double C105 = 2 * C82;
    const double C104 = std::pow(C82, 2);
    const double C103 = std::pow(C90, 2);
    const double C102 = std::pow(C89, 2);
    const double C101 = std::pow(C87, 2);
    const double C100 = C87 * C88;
    const double C99 = C83 + C84;
    const double C98 = be / C82;
    const double C121 = C86 * C109;
    const double C120 = C85 * C109;
    const double C119 = C108 / C82;
    const double C118 = C86 * C107;
    const double C117 = C85 * C107;
    const double C116 = C106 / C82;
    const double C115 = 2 * C104;
    const double C114 = C85 * C100;
    const double C113 = C101 + C102;
    const double C112 = C86 * C100;
    const double C111 = C99 / C82;
    const double C110 = C98 - 1;
    const double C132 = C121 / C82;
    const double C131 = C120 / C82;
    const double C130 = C119 - zC;
    const double C129 = C118 / C82;
    const double C128 = C117 / C82;
    const double C127 = C116 - yC;
    const double C126 = C114 / C82;
    const double C125 = C113 + C103;
    const double C124 = C112 / C82;
    const double C123 = C111 - xC;
    const double C122 = C111 - xB;
    const double C136 = be * C130;
    const double C135 = be * C127;
    const double C134 = C125 * C88;
    const double C133 = be * C123;
    const double C143 = C85 * C136;
    const double C142 = C92 * C136;
    const double C141 = C85 * C135;
    const double C140 = C92 * C135;
    const double C139 = C92 * C133;
    const double C138 = C134 / C82;
    const double C137 = C85 * C133;
    const double C150 = C143 - C132;
    const double C149 = C142 - C131;
    const double C148 = C141 - C129;
    const double C147 = C140 - C128;
    const double C146 = C139 - C126;
    const double C145 = -C138;
    const double C144 = C137 - C124;
    const double C151 = std::exp(C145);
    const double C152 = C151 * C91;
    const double C158 = C150 * C152;
    const double C157 = C149 * C152;
    const double C156 = C148 * C152;
    const double C155 = C147 * C152;
    const double C154 = C146 * C152;
    const double C153 = C144 * C152;
    const double C200 = C116 - yB;
    const double C242 = C119 - zB;
    const double C440 = C242 * C157;
    const double C439 = C241 * be;
    const double C438 = C130 * C157;
    const double C437 = C242 * C158;
    const double C436 = C110 * C240;
    const double C435 = C242 * C155;
    const double C434 = C242 * C156;
    const double C433 = C130 * C155;
    const double C432 = C242 * C154;
    const double C431 = C242 * C153;
    const double C430 = C130 * C154;
    const double C429 = C200 * C157;
    const double C428 = C200 * C158;
    const double C427 = C127 * C157;
    const double C426 = C200 * C155;
    const double C425 = C199 * be;
    const double C424 = C127 * C155;
    const double C423 = C200 * C156;
    const double C422 = C110 * C198;
    const double C421 = C200 * C154;
    const double C420 = C200 * C153;
    const double C419 = C127 * C154;
    const double C418 = C157 / C82;
    const double C417 = C92 * C109;
    const double C416 = C93 * C136;
    const double C415 = C158 / C115;
    const double C414 = C155 / C82;
    const double C413 = C92 * C107;
    const double C412 = C93 * C135;
    const double C411 = C156 / C115;
    const double C410 = C154 / C82;
    const double C409 = C92 * C100;
    const double C408 = C93 * C133;
    const double C407 = C81 * be;
    const double C406 = C110 * C79;
    const double C405 = C153 / C115;
    const double C404 = C79 * be;
    const double C403 = C110 * C78;
    const double C468 = C440 / C82;
    const double C467 = C439 / C82;
    const double C466 = C438 / C82;
    const double C465 = C437 / C82;
    const double C464 = C435 / C82;
    const double C463 = C434 / C82;
    const double C462 = C433 / C82;
    const double C461 = C432 / C82;
    const double C460 = C431 / C82;
    const double C459 = C430 / C82;
    const double C458 = C429 / C82;
    const double C457 = C428 / C82;
    const double C456 = C427 / C82;
    const double C455 = C426 / C82;
    const double C454 = C425 / C82;
    const double C453 = C424 / C82;
    const double C452 = C423 / C82;
    const double C451 = C421 / C82;
    const double C450 = C420 / C82;
    const double C449 = C419 / C82;
    const double C448 = -C418;
    const double C447 = C417 / C82;
    const double C446 = -C414;
    const double C445 = C413 / C82;
    const double C444 = -C410;
    const double C443 = C409 / C82;
    const double C442 = C407 / C82;
    const double C441 = C404 / C82;
    const double C482 = C406 - C468;
    const double C481 = C403 - C465;
    const double C480 = C462 - C463;
    const double C479 = C459 - C460;
    const double C478 = C456 - C457;
    const double C477 = C406 - C455;
    const double C476 = C403 - C452;
    const double C475 = C449 - C450;
    const double C474 = C448 / C105;
    const double C473 = C416 - C447;
    const double C472 = C446 / C105;
    const double C471 = C412 - C445;
    const double C470 = C444 / C105;
    const double C469 = C408 - C443;
    const double C489 = C482 - C442;
    const double C488 = C481 - C441;
    const double C487 = C477 - C442;
    const double C486 = C476 - C441;
    const double C485 = C473 * C152;
    const double C484 = C471 * C152;
    const double C483 = C469 * C152;
    const double C497 = C130 * C485;
    const double C496 = C488 + C466;
    const double C495 = C130 * C484;
    const double C494 = C130 * C483;
    const double C493 = C127 * C485;
    const double C492 = C127 * C484;
    const double C491 = C486 + C453;
    const double C490 = C127 * C483;
    const double C503 = C497 / C82;
    const double C502 = C495 / C82;
    const double C501 = C494 / C82;
    const double C500 = C493 / C82;
    const double C499 = C492 / C82;
    const double C498 = C490 / C82;
    const double C509 = C489 + C503;
    const double C508 = C502 - C464;
    const double C507 = C501 - C461;
    const double C506 = C500 - C458;
    const double C505 = C487 + C499;
    const double C504 = C498 - C451;
    const double gx000200 =
        C110 * C77 +
        C122 * (C403 - (C122 * C153) / C82 - C441 + (C123 * C154) / C82) -
        C405 - (C80 * be) / C82 -
        C123 * (C406 - (C122 * C154) / C82 - C442 + (C123 * C483) / C82) - C470;
    const double gx000020 = C200 * C475 - C405 - C127 * C504 - C470;
    const double gx000002 = C242 * C479 - C405 - C130 * C507 - C470;
    const double gx000110 = C422 + C122 * C475 - C454 - C123 * C504;
    const double gx000101 = C436 + C122 * C479 - C467 - C123 * C507;
    const double gx000011 = C200 * C479 - C127 * C507;
    gx[(Ai + 0) * matrix_size + Bi + 0] += std::sqrt(3.0) * gx000110;
    gx[(Ai + 0) * matrix_size + Bi + 1] += std::sqrt(3.0) * gx000011;
    gx[(Ai + 0) * matrix_size + Bi + 2] +=
        -0.5 * gx000200 - 0.5 * gx000020 + gx000002;
    gx[(Ai + 0) * matrix_size + Bi + 3] += std::sqrt(3.0) * gx000101;
    gx[(Ai + 0) * matrix_size + Bi + 4] +=
        std::sqrt(0.75) * gx000200 - std::sqrt(0.75) * gx000020;
    const double gy000200 =
        C122 * ((C123 * C155) / C82 - (C122 * C156) / C82) - C411 -
        C123 * ((C123 * C484) / C82 - (C122 * C155) / C82) - C472;
    const double gy000020 =
        C422 + C200 * C491 - C411 - C454 - C127 * C505 - C472;
    const double gy000002 = C242 * C480 - C411 - C130 * C508 - C472;
    const double gy000110 = C122 * C491 - C123 * C505;
    const double gy000101 = C122 * C480 - C123 * C508;
    const double gy000011 = C436 + C200 * C480 - C467 - C127 * C508;
    gy[(Ai + 0) * matrix_size + Bi + 0] += std::sqrt(3.0) * gy000110;
    gy[(Ai + 0) * matrix_size + Bi + 1] += std::sqrt(3.0) * gy000011;
    gy[(Ai + 0) * matrix_size + Bi + 2] +=
        -0.5 * gy000200 - 0.5 * gy000020 + gy000002;
    gy[(Ai + 0) * matrix_size + Bi + 3] += std::sqrt(3.0) * gy000101;
    gy[(Ai + 0) * matrix_size + Bi + 4] +=
        std::sqrt(0.75) * gy000200 - std::sqrt(0.75) * gy000020;
    const double gz000200 =
        C122 * ((C123 * C157) / C82 - (C122 * C158) / C82) - C415 -
        C123 * ((C123 * C485) / C82 - (C122 * C157) / C82) - C474;
    const double gz000020 = C200 * C478 - C415 - C127 * C506 - C474;
    const double gz000002 =
        C436 + C242 * C496 - C415 - C467 - C130 * C509 - C474;
    const double gz000110 = C122 * C478 - C123 * C506;
    const double gz000101 = C122 * C496 - C123 * C509;
    const double gz000011 = C200 * C496 - C127 * C509;
    gz[(Ai + 0) * matrix_size + Bi + 0] += std::sqrt(3.0) * gz000110;
    gz[(Ai + 0) * matrix_size + Bi + 1] += std::sqrt(3.0) * gz000011;
    gz[(Ai + 0) * matrix_size + Bi + 2] +=
        -0.5 * gz000200 - 0.5 * gz000020 + gz000002;
    gz[(Ai + 0) * matrix_size + Bi + 3] += std::sqrt(3.0) * gz000101;
    gz[(Ai + 0) * matrix_size + Bi + 4] +=
        std::sqrt(0.75) * gz000200 - std::sqrt(0.75) * gz000020;
}