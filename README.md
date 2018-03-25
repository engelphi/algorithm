# Algorithm
[![Build Status](https://travis-ci.org/engelphi/algorithm.svg?branch=master)](https://travis-ci.org/engelphi/algorithm)
[![codecov](https://codecov.io/gh/engelphi/algorithm/branch/master/graph/badge.svg)](https://codecov.io/gh/engelphi/algorithm)

This header-only library provides algorithms for standard containers inspired by
the C++-Standard library. The library utilizes C++17 features and therefore needs a conforming
compiler to be used in a project.

## Build Instructions

This library is a header-only library. Therefore, it is not necessary to build the library.
Nevertheless, the library contains a set of unit-tests which can be build on a local machine for 
testing that the library works as expected.

### Requirements

- C++17 compiler (clang6 and g++ 7.3.0 are currently used for building and testing)
- cmake 3.9 for building
- clang-format && clang-tidy for formatting and static analysis
- doxygen for building the documentation

### Build

For building the tests on a linux based system execute the following commands:

```bash
mkdir build
cd build
cmake -DCMAKE_CXX_COMPILER=<compiler> ..
make
```

This will create a binary with the name test-algorithm which can then be executed to run the
test suite.

