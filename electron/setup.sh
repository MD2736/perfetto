#!/bin/bash


../ui/build

rm -r perfetto
rm -r node_modules
rm package-lock.json


npm init electron-app@latest perfetto

cp index.js ./perfetto/src
cp forge.config.js ./perfetto

sed -i -e 's/forge make/forge make --platform=win32/g' ./perfetto/package.json

cp -r ../out/ui/ui/dist/* ./perfetto/src

cd perfetto/
npm run make




