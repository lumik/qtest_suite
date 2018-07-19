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
 * \file      qtest_suite_test.cpp
 * \brief     QTest Suite tests.

 * \author    Jakub Klener <lumiksro@centrum.cz>
 * \date      2018-07-19
 * \copyright Copyright (C) 2018 Jakub Klener. All rights reserved.
 *
 * \copyright This project is released under the 3-Clause BSD License. You should have received a copy of the 3-Clause
 *            BSD License along with this program. If not, see https://opensource.org/licenses/.
 */

#include "qtest_suite_test.h"

#include <QtTest>

#include <memory>
#include <utility>

namespace lumik {
namespace qtest_suite {


// Derives from QObject but don't uses Q_OBJECT macro, so all of them are treated as QObject by QT's meta object
// system.
template<int Tag>
class TestClass: public QObject
{
};

// map size type
constexpr TestContainer::size_type operator "" _msz(unsigned long long int n) { return n; }  // NOLINT(runtime/int)

void QTestSuiteTest::addTest()
{
    const char *name1 = "TestClass1";

    // test get_tests
    auto &tests = get_tests();
    const TestContainer::size_type init_size = tests.size();
    QCOMPARE(tests.count(name1), 0_msz);
    tests.insert(std::make_pair(name1, std::unique_ptr<TestClass<1>>(new TestClass<1>)));
    QCOMPARE(get_tests().count(name1), 1_msz);

    // test TestInserter
    const char *name2 = "TestClass2";
    QCOMPARE(get_tests().count(name2), 0_msz);
    TestInserter<TestClass<2>>{name2};
    QCOMPARE(get_tests().count(name2), 1_msz);

    // test ADD_TEST macro
    const char *name3 = "TestClass3";
    QCOMPARE(get_tests().count(name3), 0_msz);
    using TestClass3 = TestClass<3>;
    ADD_TEST(TestClass3)
    QCOMPARE(get_tests().count(name3), 1_msz);
    QCOMPARE(init_size + 3, get_tests().size());
}

}  // namespace qtest_suite
}  // namespace lumik

