################################################################################

1. How to Build
	- get Toolchain
		From android git server, codesourcery and etc ..
		 - arm-linux-gnueabihf-

	- edit Makefile
		edit "CROSS_COMPILE" to right toolchain path(You downloaded).
		Ex)   export PATH=$PATH:$(android platform directory you download)/prebuilts/gcc/linux-x86/arm/gcc-linaro-arm-linux-gnueabihf-4.7/bin
		Ex)   export CROSS_COMPILE=$(android platform directory you download)/prebuilts/gcc/linux-x86/arm/gcc-linaro-arm-linux-gnueabihf-4.7/bin/arm-linux-gnueabihf-

		$ mkdir ../out
		$ make ARCH=arm O=out merge_hi3630_defconfig
		$ make ARCH=arm O=out 
or 

use the build_release.sh attached.

2. Output files
		- Kernel : out/arch/arm/boot/Image
		- module : out/drivers/*/*.ko

3. How to Clean
		$ make ARCH=arm distclean
		$ rm -rf out
################################################################################
