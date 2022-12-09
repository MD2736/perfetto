#!/bin/bash


#../ui/build

rm -r -d -f perfetto
rm -r -d -f  node_modules
rm -f package-lock.json

npm init electron-app@latest --fetch-retries=0 perfetto

cp index.js ./perfetto/src
cp preload.js ./perfetto/src
cp forge.config.js ./perfetto

sed -i -e 's/forge make/forge make --arch=arm64,x64,armv7l/g' ./perfetto/package.json
sed -i -e '/"make"/  i\    "makewin32": "electron-forge make --platform=win32",' ./perfetto/package.json


./build.sh





