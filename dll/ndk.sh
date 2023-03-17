#!/bin/sh
# install dep
sudo apt-get install gcc automake autoconf libtool make gcc-multilib

# download ndk
version=r14b
ndk_dir=$(pwd)/android-ndk-${version}
if [ ! -d "${ndk_dir}" ]; then
    echo "not exists ndk"
    echo "ndk downloading ..."
    wget https://dl.google.com/android/repository/android-ndk-${version}-linux-x86_64.zip
    echo "unzip ndk"
    unzip -o android-ndk-${version}-linux-x86_64.zip -d ./
fi
echo "ndk_dir:${ndk_dir}"