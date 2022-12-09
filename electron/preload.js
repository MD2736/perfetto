const { ipcRenderer } = require('electron')

addEventListener("message", (evt) => {
  if(evt.data == 'PONG')
    ipcRenderer.invoke('PONG','PONG');
});

ipcRenderer.on("SendPing", (event, data) => {
   postMessage(data, '*');
});

ipcRenderer.on("SendData", (event, data) => {
   postMessage(data, '*');
});

