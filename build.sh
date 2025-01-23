#!/bin/bash
export CROSS_COMPILE=$(pwd)/gcc/bin/arm-linux-gnueabihf-
export ARCH=arm

if [ ! -d "out" ]; then
    mkdir out
else
    echo "Out directory exists!"
fi

make O=out merge_hi3630_defconfig
make O=out -j$(nproc --all)
