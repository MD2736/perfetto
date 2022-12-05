#!/bin/bash


#../ui/build

rm -r -d -f perfetto
rm -r -d -f  node_modules
rm -f package-lock.json

npm init electron-app@latest --fetch-retries=0 perfetto

cp index.js ./perfetto/src
cp preload.js ./perfetto/src
cp forge.config.js ./perfetto

sed -i -e 's/forge make/forge make --platform=win32/g' ./perfetto/package.json

./build.sh





