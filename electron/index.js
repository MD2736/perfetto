const { app, BrowserWindow, ipcMain } = require('electron');
const fs = require("fs");
const path = require('path');

const WM_LBUTTONDOWN = 0x0201

const getFileInDir = (dir, ext) => {
    const files = fs.readdirSync(dir);
    for (const file of files){
        if(file.includes(ext) == true){
            return file;
        }
    }
    return null
}

function delay(time) {
    return new Promise (resolve => setTimeout(resolve, time));
}


// Handle creating/removing shortcuts on Windows when installing/uninstalling.
if (require('electron-squirrel-startup')) {
    app.quit();
}

let mainWindow;
let gfileTagToOpen = 0;

const createWindow = () => {

    mainWindow = new BrowserWindow({
        width: 1284,
        height: 960,
        autoHideMenuBar: true,
        icon: 'logo-128.png',
        webPreferences: {
            preload: path.join(__dirname, 'preload.js'),
        }
    });
    mainWindow.loadURL(`file://${__dirname}/index.html`);

    //mainWindow.webContents.openDevTools();

    ipcMain.handle('PONG', async(event, text) => {
        let path = ""
        if (process.platform === 'win32') {
            path =  process.env.ProgramData + "\\Matrox Imaging\\Gecho Logs\\";
        }

        const tag = gfileTagToOpen;
        const foundfile = getFileInDir(path, tag);

        if(foundfile)
        {
        const filenameTrace = "file:///" + path + foundfile;
        mainWindow.webContents.send('SendData',
            {
                perfetto: {
                    filename: filenameTrace,
                    buffer: "",
                    title: foundfile,
                    keepApiOpen: true,
                }
            });
        }
        await delay(1000);
    });

    mainWindow.hookWindowMessage(WM_LBUTTONDOWN, (wParam, lParam) => {
        const w = wParam.readUInt32LE(0);
        const l = lParam.readUInt32LE(0);
        if (w === 99999) {
                gfileTagToOpen = l;
                mainWindow.webContents.send('SendPing', "PING");
        }
        return true;
    });
};

// This method will be called when Electron has finished
// initialization and is ready to create browser windows.
// Some APIs can only be used after this event occurs.
app.whenReady().then(() => {

    createWindow()

    app.on('activate', function () {
        if (BrowserWindow.getAllWindows().length === 0) createWindow()
    })
})


// Quit when all windows are closed, except on macOS. There, it's common
// for applications and their menu bar to stay active until the user quits
// explicitly with Cmd + Q.
app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
        app.quit();
    }
});

app.on('activate', () => {
    // On OS X it's common to re-create a window in the app when the
    // dock icon is clicked and there are no other windows open.
    if (BrowserWindow.getAllWindows().length === 0) {
        createWindow();
    }
});

// In this file you can include the rest of your app's specific main process
// code. You can also put them in separate files and import them here.
