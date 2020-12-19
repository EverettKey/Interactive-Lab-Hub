# Cool Guys Don't Look At Explosions

Explosions are cool, but looking at explosions is not cool


Walking away from explosion without turning your head is a rite of passage for all badasses.

![cool guys](https://imgur.com/vP98R58.png)

But, what if the explosion goes off before you turn your head and starts walking?

Worry not, the `<insert name>` is here to help you always acheiving badassness while blowing things up!

## Set up

For this to happen I will need the following equipments:

![state diagram Ver.1](https://imgur.com/kq4tREC.png)

* Boom box: The sensor that sense the 'Explode' action
* Arduino: Arduino will collect electronic data from the boom box and send it to Pi
* Raspberry Pi: It is unclear how many Pis I will use for my project
* Internet: If I want to set off firewors around the world, I will need to host my own internet server to broadcast the boom signal.
* Display/Sound/Light: Because it is too dangerous to set off actual explosives, I am planning to use a screen with a speaker to mimic such event, possibly with some flashy lighting to make it more dramatic.
* Camera: Camera will be used for face detection to see wheter the badass wannabe has turned around.

### System Diagram stage 1
![state diagram Ver.2](https://imgur.com/oByVyT8.png)

I am planning to implement this as my first step. Mainly setting up the pipeline of inputs (boom box & camera) and the output (TV/speakers). This prototype only requires one arduino and I have all the hardware in order to make this happen. I am planning to use a simple push button for the protype but I am looking to make an authentic boom box for the final version


### System Diagram stage 2
![state diagram Ver.3](https://imgur.com/0qj1VBX.png)

This is my final goal. By broadcasting the signal onto a server that I host, I can send the siganl to every output that has a Pi listening to the server. I can set them off alltogether at the same time.

# Plan

* Set up face recognition
* Set up trigger sensor (prototyping with push button)
* Send both ace and trigger signal to server
* Read face and trigger signal from server
* Execute actions (Light, sound, confetti)