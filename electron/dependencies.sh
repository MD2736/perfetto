#!/bin/bash



npm install --save-dev electron-builder-squirrel-windows
npm install --save-dev electron-winstaller

sudo mkdir -pm755 /etc/apt/keyrings
sudo wget -O /etc/apt/keyrings/winehq-archive.key https://dl.winehq.org/wine-builds/winehq.key
sudo wget -NP /etc/apt/sources.list.d/ https://dl.winehq.org/wine-builds/ubuntu/dists/focal/winehq-focal.sources
sudo apt update
sudo apt install --install-recommends winehq-stable
