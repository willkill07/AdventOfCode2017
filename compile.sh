#!/usr/bin/env bash
mkdir -p build
cd build
cmake .. -DCMAKE_CXX_COMPILER=/usr/local/opt/llvm/bin/clang++
make -j install
