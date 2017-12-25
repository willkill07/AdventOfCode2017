cmake_minimum_required (VERSION 3.9.0)

set(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang++")
set(CXX_TARGET_FLAGS -O3 -march=native -Wall -Wextra -Wpedantic -pedantic -pedantic-errors)

project (AdventOfCode2017 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

set(CMAKE_EXPORT_COMPILE_COMMANDS On)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(include)
add_subdirectory(src)
