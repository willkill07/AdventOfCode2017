cmake_minimum_required (VERSION 3.8.0)

project (AdventOfCode2017 CXX)

set(CMAKE_CXX_COMPILER clang++ CACHE FILEPATH "C++ Compiler")
set(ADVENT_CXX_FLAGS -O3 -march=native -stdlib=libc++ -Wall -Wextra -Wpedantic -pedantic -pedantic-errors -Wno-gnu-zero-variadic-macro-arguments)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include_directories(include)
add_subdirectory(src)
