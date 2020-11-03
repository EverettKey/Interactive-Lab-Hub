# Prelab

For this week's [Lab 7](https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/Lab-07) we'll be making our own Video Doorbells, like a DIY [Ring](https://ring.com).

Bring your whole kit, Pi and Arduino, to lab this Thursday.
 
In preparation for this week's lab, you'll build a small circuit with your Arduino and test it with some code. You don't need the Pi for this preLab.

### Button Circuit

On your breadboard, make this basic button circuit connected to `pin 2` of the Arduino. (The LED is built in on the board and connected to `pin 13`.)

<img src="https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/images/button_circuit.png" width="200px">

<img src="https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/images/metroCircuit.png" width="400px"> 

<img src="https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/wiki/images/realCircuit.jpg" width="400px">

Remember that the orientation of the button matters. Of the four pins, the pairs of pins closest to each other are the two that get connected when you push the button. And in fact, each pin of the close pair is **always connected** to the corresponding pin of the other close pair. This diagram my help:

<img src="https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/blob/2020Fall/images/button-deal.png" width="400px" />

### Upload the `HelloYou` code

`HelloYou` is Arduino code that communicates over Serial to a Raspberry Pi (or any computer with a serial interface), sending any button events **out** to the computer, and turning on or off the built-in LED in response to message events coming **in**.

Copy this [HelloYou.ino](https://github.com/FAR-Lab/interaction-engine/blob/master/helloYouSketch.ino) sketch into a new Arduino window and upload it to your board. (The built-in LED marked `L` should be off.)

Open the Serial Monitor in Arduino and observe what happens when you press the button in your circuit -- you should see a change!

## Internet browsing on the Raspberry Pi

To fetch information that is on the internet, we have used curl or  wget:
```
pi@ixe00:~/helloYou $ curl http://google.com
<HTML><HEAD><meta http-equiv="content-type" content="text/html;charset=utf-8">
<TITLE>301 Moved</TITLE></HEAD><BODY>
<H1>301 Moved</H1>
The document has moved
<A HREF="http://www.google.com/">here</A>.
</BODY></HTML>

pi@ixe00:~ $ wget http://www.google.com
--2020-09-03 19:02:22--  http://www.google.com/
Resolving www.google.com (www.google.com)... 172.217.164.100, 2607:f8b0:4005:805::2004
Connecting to www.google.com (www.google.com)|172.217.164.100|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: unspecified [text/html]
Saving to: ‘index.html’

index.html              [ <=>                ]  11.84K  --.-KB/s    in 0.001s  

2020-09-03 19:02:22 (18.2 MB/s) - ‘index.html’ saved [12127]
```
These programs are similar, but the above example shows how they differ. Curl does a ‘one-shot’ download of the file, whereas wget gets the forward and then goes to the forwarded address to download the index.html file.

We can use this to get data from the internet! Try:
```
$ curl extreme-ip-lookup.com/csv/
```
This looks up the information about Pi’s location through the IP address of the local router.

Weather:
```
$ curl wttr.in
$ curl wttr.in/moon
```
This can be used to download files that are hosted on the internet. Download a musical clip that you like that is in a format that can be played on the Raspberry Pi.

How can we *view* the web from a command line interface? Two ways! First, we can just use a text based browser, like lynx.
```
$ sudo apt install lynx
$ lynx http://cornell.edu
```
We can also use X windows to view the internet in a more familiar way:

Epiphany browser: ` $ sudo apt install epiphany`
Midori browser: `$ sudo apt install midori`
Which one did you like more? Uninstall the other one!
```
$ sudo apt uninstall [package that you did not prefer]

```

## Serving webpages with the Raspberry Pi

** customize the code enough that the webpage served up is clearly your own, and include a screenshot and any modified code in the lab folder. **

<img src="https://imgur.com/zMghMew.jpg" width="800px">

## Set up and Run Interaction Engine


### Flash the HelloYou Sketch onto the Arduino

Make sure your arduino is connected to your Raspberry Pi with a USB cable. Using the Arduino IDE on the Raspberry Pi, open `helloYou/helloYou.ino`.

Look at the code. How does the Arduino communicate with the Pi when the code is running?

    When a button is pressed, information is sent through the serial port and read by Pi. Serial port is the communication portabl between Pi and Arduino.
** What messages are sent from the Arduino to the Pi? **

    "Light" or "Dartk" Strings

** What messages are expected from the Pi to the Arduino? **

    Character "H", which will turn the LED
** What happens if the Pi sends an unexpected message to the Arduino? **
    The LED will turn off.
** How fast does the Arduino communicate with the Pi? What would you change to make it send messages less often? **
    The baud rate is 9600 so 9600 bits persecond. I can set it to lower baud rate to send messages less often.

Compile and flash the `helloYou.ino` code onto the Arduino.

### Run the HelloYou server on the RPi
Look at the code. What interface does the Pi use to communicate with the Arduino when the code is running?

    They communicate through the serial port

What messages are sent from the Pi to the Arduino?

    When the buttons are pressed on the website, a message of "H" or "L" will be sent from Pi to Arduino


What messages are expected from the Arduino to the Pi?

    We are expecting "Light" or "Dark" messages from arduino to Pi, which changes the website's background

What happens if the Arduino sends an unexpected message to the Pi?
    Nothing will happen

What part of the code controls what is served when a browser requests a page from the server?

    The helloYou.py code controls what is served, namely the app.route function which sends the index.html

What messages are sent to the console? When?

    'ledON' and 'ledOFF' are sent to the console, when the respective button is pressed on the website

## Internet of Cornell Tech Things 

See MyInternet OfCornlellThings for code
Video

## Video doorbell

Now, using design a video doorbell, or any application where you can remotely control and observe action at another location. It is okay to partner up on this assignment so that you and someone else in the class have devices that communicate with one another. 

** Please include video of the project **
** All supporting designs materials and code should be in your lab assignment folder, and documented enough that you could recreate it from scratch if you had memory loss. **
