TEMPLATE = app

CONFIG += c++11

QT += testlib core
QT -= gui

CONFIG += \
    console \
    testcase
CONFIG -= \
    app_bundle

QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3

INCLUDEPATH += \
    $$qtest_suite_source_dir/include

SOURCES += \
    qtest_suite_test_main.cpp \
    qtest_suite_test.cpp

DESTDIR = $$qtest_suite_source_dir/bin
target.path = $$qtest_suite_install_prefix/bin

!equals(qtest_suite_install_prefix, $$qtest_suite_source_dir) {
    INSTALLS += target
}

HEADERS += \
    dummy_tests.h \
    qtest_suite_test.h
