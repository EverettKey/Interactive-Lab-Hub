var socket = io();

// send out LedRED message over socket
function ledRED() {
    socket.emit('red');
	console.log('R');
}

// send out ledGREeN message over socket
function ledGREEN() {
    socket.emit('green');
	console.log('G');

}

// send out ledBLUE message over socket
function ledBLUE(){
    socket.emit('blue');
	console.log('B');
}
// read the data from the message that the server sent and change the
// background of the webpage based on the data in the message
socket.on('server-msg', function(msg) {
    console.log('msg:', msg);
    switch(msg) {
        case 'light':
            document.body.style.backgroundColor = 'purple';
            console.log('purple')
            break;
        case 'dark':
            document.body.style.backgroundColor = 'black';
            console.log('black');
            break;
    }
});
