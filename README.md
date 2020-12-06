# CppTemplate

[![Linux build status](https://img.shields.io/travis/com/chronoxor/CppTemplate/master?label=Linux)](https://travis-ci.com/chronoxor/CppTemplate)
[![OSX build status](https://img.shields.io/travis/com/chronoxor/CppTemplate/master?label=OSX)](https://travis-ci.com/chronoxor/CppTemplate)
[![Cygwin build status](https://img.shields.io/appveyor/build/chronoxor/CppTemplate/master?label=Cygwin)](https://ci.appveyor.com/project/chronoxor/CppTemplate)
[![MSYS2 build status](https://img.shields.io/appveyor/build/chronoxor/CppTemplate/master?label=MSYS2)](https://ci.appveyor.com/project/chronoxor/CppTemplate)
[![MinGW build status](https://img.shields.io/appveyor/build/chronoxor/CppTemplate/master?label=MinGW)](https://ci.appveyor.com/project/chronoxor/CppTemplate)
[![Windows build status](https://img.shields.io/appveyor/build/chronoxor/CppTemplate/master?label=Windows)](https://ci.appveyor.com/project/chronoxor/CppTemplate)

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
* [python3](https://www.python.org)

Optional:
* [clang](https://clang.llvm.org)
* [CLion](https://www.jetbrains.com/clion)
* [Cygwin](https://cygwin.com)
* [MSYS2](https://www.msys2.org)
* [MinGW](https://mingw-w64.org/doku.php)
* [Visual Studio](https://www.visualstudio.com)

# How to build?

### Install [gil (git links) tool](https://github.com/chronoxor/gil)
```shell
pip3 install gil
```

### Setup repository
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
unix.bat
```

### Windows (MSYS2)
```shell
cd build
unix.bat
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
