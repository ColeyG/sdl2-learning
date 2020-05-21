#!/bin/bash

rm -rf release/
mkdir release
cmake . -DCMAKE_BUILD_TYPE=Release -B release
cd release
make
