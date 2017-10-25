#!/bin/sh


set -e


rm -rf build
mkdir build
pushd build

# configure
cmake -DPYTHON_DESIRED=3 ..

# compile
make

# run tests
export CTEST_OUTPUT_ON_FAILURE=1
make test

popd
