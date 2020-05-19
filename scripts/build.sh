#!/bin/bash

if [[ -d "build/.cache/" ]]; then
  cmake --build build --config Debug --target all -- -j 20
  cd build/
  make
else
  cmake . -B build
  cd build/
  make
fi
