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
 * \file      dummy_tests.h
 * \brief     Dummy tests used in the main qtest_sute_test_main.cpp to test if some tests are executed.

 * \author    Jakub Klener <lumiksro@centrum.cz>
 * \date      2018-07-19
 * \copyright Copyright (C) 2018 Jakub Klener. All rights reserved.
 *
 * \copyright This project is released under the 3-Clause BSD License. You should have received a copy of the 3-Clause
 *            BSD License along with this program. If not, see https://opensource.org/licenses/.
 */

#ifndef LUMIK_QTEST_SUITE_DUMMY_TESTS_H_
#define LUMIK_QTEST_SUITE_DUMMY_TESTS_H_

#include <QObject>
#include <QtTest>

#include "lumik/qtest_suite/qtest_suite.h"

namespace lumik {
namespace qtest_suite {

class DummyTest1: public QObject
{
    Q_OBJECT

private slots:  // NOLINT(whitespace/indent)
    void initTestCase() { QFAIL("Dummy fail!"); }
};

ADD_TEST(DummyTest1)


class DummyTest2: public QObject
{
    Q_OBJECT

private slots:  // NOLINT(whitespace/indent)
    void cleanupTestCase() { QFAIL("Dummy fail!"); }
};

ADD_TEST(DummyTest2)

}  // namespace qtest_suite
}  // namespace lumik

#endif  // LUMIK_QTEST_SUITE_DUMMY_TESTS_H_
