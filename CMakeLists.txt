cmake_minimum_required (VERSION 3.8.0)

project (AdventOfCode2017 CXX)

set(CMAKE_CXX_COMPILER clang++ CACHE FILEPATH "C++ Compiler")
set(CMAKE_BUILD_TYPE Release CACHE STRING "Release Type")
set(ADVENT_CXX_FLAGS -Wall -Wextra -Wpedantic -pedantic -pedantic-errors -Wno-gnu-zero-variadic-macro-arguments)

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -stdlib=libc++")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -stdlib=libc++")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include_directories(include)
add_subdirectory(src)
