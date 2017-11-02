#!/bin/sh
TOPDIR=$(dirname $(readlink -f $0))
clang-format -i $(find $TOPDIR/libdnf -name '*.cpp' -o -name '*.hpp')
