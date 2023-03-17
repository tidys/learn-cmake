#!/bin/sh
ndk_dir=$(pwd)/android-ndk-r14b
rm -rf ./build
mkdir ./build
cd ./build
compiler=$ndk_dir/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin
sysroot=$ndk_dir/sysroot
platform=$ndk_dir/platforms/android-21/arch-arm64/
export PATH=$PATH:$compiler:$sysroot:$platform

host=aarch64-linux-android
gcc_compiler=$host-gcc
gxx_compiler=$host-g++

cmake ..    -DANDROID_ABI="arm64-v8a" \
            -DANDROID_NDK=$ndk_dir \
            -DANDROID_PLATFORM=android-21 \
            -DANDROID_STL=c++_shared \
            -DCMAKE_BUILD_TYPE=Release \
            -DCMAKE_SYSROOT=$platform \
            -DCMAKE_C_COMPILER=$gcc_compiler \
            -DCMAKE_CXX_COMPILER=$gxx_compiler \
            -DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER \
            -DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=ONLY \
            -DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=ONLY \

            # -DANDROID_TOOLCHAIN=clang \
            # -DCMAKE_TOOLCHAIN_FILE=$ndk_dir/build/cmake/android.toolchain.cmake \
            # -DBUILD_SHARED_LIBS=OFF \
            # -DCMAKE_INSTALL_PREFIX=$(pwd)/android/arm64-v8a \

# make