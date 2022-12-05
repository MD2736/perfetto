module.exports = {
  packagerConfig: {
  icon: 'logo-128'
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
