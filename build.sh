#!/bin/bash

mkdir -p build
pushd build
  cmake -DCMAKE_TOOLCHAIN_FILE=$(pwd)/../toolchain.cmake -DCMAKE_BUILD_TYPE=Release ..
  VERBOSE=1 cmake --build . 
popd