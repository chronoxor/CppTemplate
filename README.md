# CppTemplate

[![Linux build status](https://img.shields.io/travis/chronoxor/CppTemplate/master.svg?label=Linux)](https://travis-ci.org/chronoxor/CppTemplate)
[![OSX build status](https://img.shields.io/travis/chronoxor/CppTemplate/master.svg?label=OSX)](https://travis-ci.org/chronoxor/CppTemplate)
[![Cygwin build status](https://img.shields.io/appveyor/ci/chronoxor/CppTemplate/master.svg?label=Cygwin)](https://ci.appveyor.com/project/chronoxor/CppTemplate)
[![MinGW build status](https://img.shields.io/appveyor/ci/chronoxor/CppTemplate/master.svg?label=MinGW)](https://ci.appveyor.com/project/chronoxor/CppTemplate)
[![Windows build status](https://img.shields.io/appveyor/ci/chronoxor/CppTemplate/master.svg?label=Windows)](https://ci.appveyor.com/project/chronoxor/CppTemplate)

C++ Template Library contains initial templates for a new C++ library project.

[CppTemplate API reference](https://chronoxor.github.io/CppTemplate/index.html)

# Contents
  * [Features](#features)
  * [Requirements](#requirements)
  * [How to build?](#how-to-build)

# Features
* Cross platform (Linux, OSX, Windows)
* Benchmarks
* Examples
* Tests
* [Doxygen](http://www.doxygen.org) API documentation
* Continuous integration ([Travis CI](https://travis-ci.com), [AppVeyor](https://www.appveyor.com))

# Requirements
* Linux (binutils-dev uuid-dev)
* OSX
* Windows 10
* [cmake](https://www.cmake.org)
* [gcc](https://gcc.gnu.org)
* [git](https://git-scm.com)
* [gil](https://github.com/chronoxor/gil.git)

Optional:
* [clang](https://clang.llvm.org)
* [clion](https://www.jetbrains.com/clion)
* [Cygwin](https://cygwin.com)
* [MinGW](https://mingw-w64.org/doku.php)
* [Visual Studio](https://www.visualstudio.com)

# How to build?

### Setup repository with [gil (git links) tool](https://github.com/chronoxor/gil#setup)
```shell
git clone https://github.com/chronoxor/CppTemplate.git
cd CppTemplate
gil update
```

### Linux
```shell
cd build
./unix.sh
```

### OSX
```shell
cd build
./unix.sh
```

### Windows (Cygwin)
```shell
cd build
cygwin.bat
```

### Windows (MinGW)
```shell
cd build
mingw.bat
```

### Windows (Visual Studio)
```shell
cd build
vs.bat
```
