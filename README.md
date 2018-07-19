# QTest Suite

A library for automated QtTest addition and execution.


## Requirements

* `c++` compiler.
* `git` – to clone the `SpRelay` repository. You can get git from [here][git].
* `Qt` > 5 – to compile the program. You can get it from [here][qt].
* `Doxygen` – for documentation compilation, you can get it from [here][doxygen].
* `dot` – for graphs in documentation, it is part of the GraphViz library, you can get it from [here][graphviz].

Make sure that the Doxygen and GraphViz binaries are in the `PATH` variable.


## Getting Started

Download `include/lumik/qtest_suite/qtest_suite.h` header from the repository and include it into your project.


### Obtaining `QTest Suite` library

If you just want to use `enum_flags` download the latest release from:
[https://github.com/lumik/qtest_suite/releases][releases]


You can also clone the `enum_flags` repository using git:

```
git clone https://github.com/lumik/qtest_suite.git
```

If you just want to use `QTest Suite` without the commit history then you can do:

```
git clone --depth=1 https://github.com/lumik/qtest_suite.git
```

The `depth=1` tells git to only pull down one commit worth of historical data.


### Installation


#### Linux or Linux-like terminal (MSYS2, cygwin, ...)

Make sure that you have Qt in system PATH. Go to the source directory and run in terminal
```
mkdir build
cd build
qmake "CONFIG+=release" qtest_suite_install_prefix="path/where/you/want/the/library/installed" ../qtest_suite.pro -r
```
If you are under windows, you should also add something like `-spec win32-g++`
```
make -j2
make -j1 check TESTARGS="-silent"  # optional if you want to run tests
make doc      # optional if you want to make documentation
make install  # optional if you want to install the application, see above
```

#### Compilation using Qt Creator
Open the qtest_suite.pro project file in the top directory and cofigure it for appropriate compiler. Then you can build and run tests.

Then compile the documentation by executing
```
doxygen Doxyfile
```
from command line from the project folder.


### Usage

You can add tests using `ADD_TEST()` macro and consecutively execute them by `run_tests()` function.

```cpp
// test.h
#include <QObject>
#include <QtTest>

#include "lumik/qtest_suite1.0.0/qtest_suite.h"

namespace test_class_namespace {

class TestClass : public QObject
{
    Q_OBJECT

private slots:
    void testCase() { QVERIFY(true); }
};

ADD_TEST(TestClass);

}  // namespace test_class_namespace
```

```cpp
// main.cpp
#include "lumik/qtest_suite1.0.0/qtest_suite.h"

int main(int argc, char **argv)
{
    return lumik::qtest_suite::run_tests(argc, argv);
}
```

More info can be found in the [documentation](#documentation).


## Documentation

Documentation can be found in the `doc` folder, html documentation can be opened by the `index.html` file.


[git]: https://git-scm.com/
[qt]: https://www.qt.io/
[doxygen]: http://www.stack.nl/~dimitri/doxygen/
[graphviz]: http://graphviz.org/
[releases]: https://github.com/lumik/qtest_suite/releases