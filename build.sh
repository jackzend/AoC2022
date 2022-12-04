#!/usr/bin/bash

mkdir -p build && cd build && cmake .. -DCMAKE_CXX_COMPILER=/usr/bin/g++-11 && make -j$(nproc)