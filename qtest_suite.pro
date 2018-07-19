TEMPLATE = subdirs

qtest_suite_test.file = tests/lumik/qtest_suite/qtest_suite_test.pro

# build only tests
SUBDIRS += \
    qtest_suite_test

QMAKE_EXTRA_TARGETS += \
    dox

HEADERS += \
    include/lumik/qtest_suite/qtest_suite.h

OTHER_FILES += \
    Doxyfile

DISTFILES += \
    .qmake.conf

# Add custom "doc" target
_CMD_SEP = ;
win32:_CMD_SEP = &

dox.target = doc
dox.commands = \
    cd $$shell_path($$PWD) $$_CMD_SEP \
    doxygen Doxyfile
dox.depends =

# instal the library
!equals(qtest_suite_install_prefix, $$qtest_suite_source_dir) {
    qtest_suite_include.path = $$qtest_suite_install_prefix/include/lumik/qtest_suite1.0.0
    qtest_suite_include.files = $$qtest_suite_source_dir/include/lumik/qtest_suite/*
    INSTALLS += qtest_suite_include

    documentation.files = doc/*
    documentation.path = $$qtest_suite_install_prefix/doc
    INSTALLS += documentation
}
