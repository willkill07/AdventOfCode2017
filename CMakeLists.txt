cmake_minimum_required (VERSION 3.8.0)

project (AdventOfCode2017 CXX)

set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++ CACHE FILEPATH "C++ Compiler")
set(ADVENT_CXX_FLAGS -O3 -march=native -Wall -Wextra -Wpedantic -pedantic -pedantic-errors -Wno-gnu-zero-variadic-macro-arguments)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

set(CMAKE_EXPORT_COMPILE_COMMANDS On)

include_directories(include)
add_subdirectory(src)
