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
 * \file      qtest_suite.h
 * \brief     Test suite for automated test addition.

 * \author    Jakub Klener <lumiksro@centrum.cz>
 * \date      2018-07-19
 * \copyright Copyright (C) 2018 Jakub Klener. All rights reserved.
 *
 * \copyright This project is released under the 3-Clause BSD License. You should have received a copy of the 3-Clause
 *            BSD License along with this program. If not, see https://opensource.org/licenses/.
 *
 * \copyright Inspired by
 * https://stackoverflow.com/questions/12194256/qt-how-to-organize-unit-test-with-more-than-one-class
 */


#ifndef LUMIK_QTEST_SUITE_QTEST_SUITE_H_
#define LUMIK_QTEST_SUITE_QTEST_SUITE_H_

#include <QtTest>

#include <memory>
#include <map>
#include <string>
#include <utility>

namespace lumik {
namespace qtest_suite {

/*!
 * \brief Container type used for storage of tests declaration
 * \sa get_tests()
 */
using TestContainer = std::map<std::string, std::unique_ptr<QObject>>;


/*!
 * \brief Returns the tests storage container static instance.
 * \return The test storage container.
 *
 * This method can be used to insert tests inside test container for the later execution.
 * \code
 * auto &tests = lumik::qtest_suite::get_tests();
 * if (!tests.count(name)) {
 *     tests.insert(std::make_pair(name, std::unique_ptr<TestClass>(new TestClass)));
 * }
 * \endcode
 *
 * \sa run_tests(), lumik::qtest_suite::TestInserter, ADD_TEST
 */
inline TestContainer & get_tests()
{
    static TestContainer map;
    return map;
}


/*!
 * \brief Runs all tests from the test storage.
 * \param argc The number of command line arguments.
 * \param argv Command line arguments.
 * \return Sum of all the returned statuses which equals to the number of failures.
 *
 * Example:
 * \code
 * #include "lumik/qtest_suite1.0.0/qtest_suite.h"
 *
 * int main(int argc, char **argv)
 * {
 *     return lumik::qtest_suite::run_tests(argc, argv);
 * }
 * \endcode
 * \sa ADD_TEST(class_name), lumik::qtest_suite::TestInserter
 */
inline int run_tests(int argc, char **argv) {
    int status = 0;
    for (const auto &i : get_tests()) {
        status += QTest::qExec(i.second.get(), argc, argv);
    }
    return status;
}


/*!
 * \brief Class template for test insertion.
 *
 * Usage:
 * \code
 * #include <QObject>
 * #include <QtTest>
 *
 * #include "lumik/qtest_suite1.0.0/qtest_suite.h"
 *
 * class TestClass : public QObject
 * {
 *     Q_OBJECT
 *
 * private slots:
 *     void testCase() { QVERIFY(true); }
 * };
 *
 * static lumik::qtest_suite::TestInserter<TestClass> test_class{"test id name"};
 * \endcode
 * \sa ADD_TEST(class_name), run_tests()
 */
template <typename TestClass>
struct TestInserter {
    /*!
     * \brief Inserts test with the specified name into test container.
     * \param name The test name.
     * \sa get_tests()
     */
    explicit TestInserter(const std::string &name)
    {
        auto &tests = get_tests();
        if (!tests.count(name)) {
            tests.insert(std::make_pair(name, std::unique_ptr<TestClass>(new TestClass)));
        }
    }
};

}  // namespace qtest_suite
}  // namespace lumik

/*!
 * \brief Macro for adding tests.
 *
 * The macro defines static variable with internal scope and with the name
 * Usage:
 * \code
 * #include <QObject>
 * #include <QtTest>
 *
 * #include "lumik/qtest_suite1.0.0/qtest_suite.h"
 *
 * namespace test_class_namespace {
 *
 * class TestClass : public QObject
 * {
 *     Q_OBJECT
 *
 * private slots:
 *     void testCase() { QVERIFY(true); }
 * };
 *
 * ADD_TEST(TestClass);
 *
 * }  // namespace test_class_namespace
 * \endcode
 * \sa lumik::qtest_suite::TestInserter, run_tests()
 */
#define ADD_TEST(class_name) static lumik::qtest_suite::TestInserter<class_name> test_##class_name{#class_name};

#endif  // LUMIK_QTEST_SUITE_QTEST_SUITE_H_
