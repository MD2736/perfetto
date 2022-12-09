

module.exports = {
  packagerConfig: {
  description: "Perfetto for Gecho",
  icon: 'logo-128.ico',
  appVersion: "10.0.0",
  appCopyright: "Copyright (C) Matrox Electronic Systems Ltd., 1992-2023 All rights reserved",
  Win32MetadataOptions:{
      FileDescription: "Perfetto for Gecho",
      ProductName: "Perfetto"
  }
  },
  rebuildConfig: {},
  makers: [
    {
      name: '@electron-forge/maker-zip',
      platforms: ['win32', 'linux'],
    },
    {
      name: '@electron-forge/maker-deb',
      config: {
        maintainer: 'Zebra',
        icon: 'logo-128.png'
        },
    },
    {
      name: '@electron-forge/maker-rpm',
      config: {},
    },
  ],
};