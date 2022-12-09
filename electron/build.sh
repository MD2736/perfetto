#!/bin/bash


#../ui/build


cp *.ico ./perfetto
cp *.png ./perfetto
cp -r ../out/ui/ui/dist/* ./perfetto/src

cd perfetto/
npm run make
npm run makewin32



