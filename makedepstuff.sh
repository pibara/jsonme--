#!/bin/sh
mkdir jsonme++/usr
mkdir jsonme++/usr/lib
mkdir jsonme++/usr/include
cp  ./json-me.hpp jsonme++/usr/include
mv build/libjsonme.so* jsonme++/usr/lib/
fakeroot dpkg-deb --build jsonme++ jsonme++_`grep Version jsonme++/DEBIAN/control |sed -e 's/.* //'`_amd64.deb

