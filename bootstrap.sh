#!/bin/sh

git submodule add https://github.com/microsoft/vcpkg.git .vcpkg
git submodule init --recursive

.vcpkg/bootstrap-vcpkg.sh
ln -s .vcpkg/vcpkg vcpkg

echo "Be sure to run env-setup.sh once to set the right cmake toolchain!"