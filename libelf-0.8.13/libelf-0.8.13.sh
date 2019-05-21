#!/bin/sh

PREFIX=/opt/spice/ltrace
export PKG_CONFIG_PATH=$PREFIX/lib/pkgconfig:$PREFIX/share/pkgconfig:$PKG_CONFIG_PATH
export PATH=$PREFIX/bin/x86_64:$PREFIX/bin:$PATH

./configure --build=x86_64-linux-gnu --host=arm-linux-gnueabihf LDFLAGS="-L$PREFIX/lib -Wl,-rpath-link,$PREFIX/lib" --prefix=$PREFIX

