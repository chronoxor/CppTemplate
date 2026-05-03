# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project

CppTemplate is a starter template for new C++ library projects. The shipped library (`cpptemplate`) is a placeholder containing a sample `Template` class and a sample `function`; consumers fork this repo and replace those symbols with their own.

## Bootstrap (required before first build)

The `build/`, `cmake/`, and `modules/Catch2`, `modules/CppBenchmark` directories are **not** stored in this repo — they are fetched by [gil](https://github.com/chronoxor/gil) using `.gitlinks`. A fresh clone has no build scripts and won't compile until gil runs.

```shell
pip3 install gil
gil update
```

If `build/` or `cmake/` is missing, run `gil update` rather than trying to recreate them by hand.

## Common commands

All numbered scripts live under `build/<platform>/` (`Unix`, `MinGW`, `VisualStudio`). The wrapper scripts at `build/unix.sh` / `build/mingw.bat` / `build/vs.bat` chain steps 01→04 (and 05 if `$doxygen` is set). Run individual steps from the platform subdirectory:

```shell
cd build/Unix
./01-generate.sh   # cmake configure into ../../temp
./02-build.sh      # make -j4 all
./03-tests.sh      # ctest -V
./04-install.sh    # make install -> ../../bin
./05-doxygen.sh    # publishes to gh-pages (requires GITHUB_ACTOR/GITHUB_TOKEN)
./06-clean.sh      # rm -rf ../../temp and documents/html
./07-coverage.sh   # gcovr HTML report under temp/coverage/ (Unix only)
```

Out-of-tree build dir is `temp/` at the repo root; install output goes to `bin/`. Both are gitignored.

### Running a single test

`cpptemplate-tests` is a single Catch2 binary that aggregates every `tests/*.cpp` file. Filter with Catch2 tags or names:

```shell
./temp/cpptemplate-tests "[CppTemplate]"        # by tag
./temp/cpptemplate-tests "Template class"       # by TEST_CASE name
./temp/cpptemplate-tests --list-tests
```

### Running examples / benchmarks

Each `.cpp` under `examples/` and `performance/` becomes its own executable: `cpptemplate-example-<name>` and `cpptemplate-performance-<name>` (e.g. `cpptemplate-example-template_class`). They're built by `02-build.sh` and installed to `bin/`.

## Architecture

- **Library layout:** Public API headers in `include/template/` (with `.inl` for template/inline definitions), implementation `.cpp` in `source/template/`. CMake globs both trees recursively into the `cpptemplate` static library — adding a header/source file requires no CMake edits, just a re-run of `01-generate.sh`.
- **Auto-discovery convention:** `examples/*.cpp`, `performance/*.cpp`, and `tests/*.cpp` are each globbed by `CMakeLists.txt`. Examples and benchmarks each produce one executable per file; tests are merged into one Catch2 binary. Don't add per-file CMake targets.
- **`CPPTEMPLATE_MODULE` guard:** When this repo is consumed as a sub-project (added via `add_subdirectory`) with `CPPTEMPLATE_MODULE` set, only the library target is built — examples, benchmarks, tests, and install rules are skipped. Preserve this guard when adding top-level CMake logic.
- **Compiler flags:** `PEDANTIC_COMPILE_FLAGS` (defined by `cmake/SetCompilerWarnings.cmake` from the `cmake/` gil submodule) is applied to the library, examples, benchmarks, and tests. Don't bypass it for new targets in this tree.
- **Namespace & versioning:** All public symbols live in `namespace CppTemplate`. The version string is a single constant in [include/template/version.h](include/template/version.h) — bump it there.
- **Renaming the project:** The library, all targets, and the `CPPTEMPLATE_*` macros are derived from `project(cpptemplate)` in [CMakeLists.txt](CMakeLists.txt). A rename touches that line, the `CPPTEMPLATE_MODULE` flag name, the `cpptemplate-*` target prefix in the foreach loops, the `CppTemplate` namespace, and the `CPPTEMPLATE_*` header guards.

## CI

GitHub Actions builds run `gil update` then invoke the same `build/<platform>` wrapper scripts a developer would (`build/unix.sh`, `build/mingw.bat`, `build/vs.bat`). There is no separate CI-only build path — if the local script works, CI should too.
