// -*-c++-*-

/***************************************************************************
**                                                                        **
**  Test suite for automated test adition for Qt Test framwork.           **
**  Copyright (C) 2018 Jakub Klener                                       **
**                                                                        **
**  This file is part of QTest Suite library.                             **
**                                                                        **
**  You can redistribute it and/or modify it under the terms of the       **
**  3-Clause BSD License as published by the Open Source Initiative.      **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          **
**  3-Clause BSD License for more details.                                **
**                                                                        **
**  You should have received a copy of the 3-Clause BSD License along     **
**  with this program.                                                    **
**  If not, see https://opensource.org/licenses/                          **
**                                                                        **
****************************************************************************/

/*!
 * \file      qtest_suite_test_main.cpp
 * \brief     Main file for qtest_suite tests.

 * \author    Jakub Klener <lumiksro@centrum.cz>
 * \date      2018-07-19
 * \copyright Copyright (C) 2018 Jakub Klener. All rights reserved.
 *
 * \copyright This project is released under the 3-Clause BSD License. You should have received a copy of the 3-Clause
 *            BSD License along with this program. If not, see https://opensource.org/licenses/.
 */

#include <iostream>

#include "lumik/qtest_suite/qtest_suite.h"

int main(int argc, char **argv)
{
    // ANSI colors
#if defined(_WIN32)
    const char *red = "";
    const char *reset_color = "";
#else
    const char *red = "\033[0;31m";
    const char *reset_color = "\033[0m";
#endif
    const int expected_state = 2;

    // run tests
    const int state = lumik::qtest_suite::run_tests(argc, argv);

    // check result
    int err_code;
    if (state != expected_state) {
        std::cerr << red << "Return state test failed: " << reset_color << "got " << state << " but expected "
            << expected_state << "!\n";
        err_code = state > expected_state ? state - expected_state : state;
    } else {
        err_code = 0;
    }
    return err_code;
}
