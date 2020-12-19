# Scarecrow Party Robot

## Inception
The idea for the project was from this Youtube video, and this scene from Dark Knight Rises. Cool guys ought not to look at explosions. But sometimes things don’t go as planned, and one may end up facing the explosion when they’re not ready or were just trying to resolve some technical difficulties. It would be nice to have a mechanism that makes sure you’ve turned away from the bomb before setting it off. 
## Face detection: Are you looking at me?
I am using the already trained model from <source> with some minor changes. The most significant part being sending a ‘Face detected’ signal through serial port. I also stopped the program from searching for all the faces. Only one detected face is needed.

![face_detection](\pictures\face_detection_test.jpg)

## Serial communication: switching LED
After getting the face detection working. It is time to work on the actuation. Using the setup from Lab7, I send a ‘g’ (green) signal from the Pi to Arduino when the camera sees no face and send a ‘r’ (red) when a face is detected.

![LED board](\pictures\LED_setup.jpg)

## No more explosions
The working LED prototype inspired me to change my work into a scarecrow game. My machine could be partying when no one’s looking at it, and turns itself off when we turn our face to look at it. This will be a more fun interaction as we can play peekaboo with the machine, instead of watching it play an explosion animation.
## Music
* After demoing, Wendy suggested that instead of visual signal, I could also put int audio signal to represent the state of the face detection. This makes a lot of sense because it is hard for me to confirm whether the machine is working when I’m turned away from it. A music that plays when I’m turned away can very much help me make sure the machine is working. This also makes the scarecrow more fun because there could be a party behind my back.
* I was going to give the music playing job to Arduino, I even bought a audio module for this job. However, David and Ilan suggested me to control the music playing using the Pi. This turned out to make a lot of sense because I found I can use shell script to control the play/pause of audio files very easily. So thanks to David and Ilan for saving me a lot of time. My Arduino can now sing.
* I chose "In The Hall of Mountain King" from Edvard Grieg for its repetitive motif. I think it gives a sneaky party vibe. One can easily recognize the music and nod along with it. The only problem is that although I'm done with the project, the song is still stuck in my head.
## Laser projector
In order to find a party light. I embarked on a journey to find the most rad party light. Well, actually, the only place I went to was the gift shop on Roosevelt Island. There, I found two broken Christmas laser projectors. Although it was a bit disappointing because I was looking for something more like a disco ball, but this will also work because Christmas is around the corner. Why the store sells broken Christmas lights baffles me, but I got two laser projectors for $10. I managed to fix one of the projectors by resoldering a power joint that came loose.
![Projector](https://imgur.com/bzwAMeB.jpg)
## Controlling the laser projector: Power source vs Mic
* After fixing the projector, I needed to figure out a way to turn it on and off with Arduino. The projector takes 5V power source but requires more current than the Arduino can supply. I had two options:
1. Directory controlling the power source. This is the most straight forward way and can be easily done with a transistor or a relay. However, I don’t have a transistor nor a relay on my hand, so I have to look into a different approach.
2. Or, I could try to control the laser projector by sending ‘fake’ sound signal to its microphones. The projector has a “Sound control” mode, where it will turn itself on when it hears sound. I thought this is a better method because this gauge only controls the laser. Other mechanisms such as cooling fan and mirror motor would remain running when the laser is turned off in this mode. I thought this would be a more reliable solution
* After wiring out two wires from the 2 pin electret mic. I was able to control the laser on-off on my computer but could not replicate it on the Pi. This puzzled me for the longest time. I think the reason was because: 1. The sound detection mechanism wasn’t as simple as measuring the amplitude (voltage) from the microphone. It could be the change in voltage. So a flat 2V voltage raise from my Arduino pin would not trigger the light to turn on. And 2. The Pi and my computer may have grounded differently.
* After several failed attempts, I decided to give up on hacking the microphone pin and turn to controlling the laser via its power.
## Transistor vs Relay
* To control the power, I have two options: a transistor or a relay
* First I tried out the transistor TIP20 transistor because it is what I’ve got. However, although I know in principle how a transistor, because of my lack of knowledge in circuitry and datasheet reading, I spent a lot of time debugging the circuit. Darren is very nice and gave me a crash course on circuitry.
![Darren_circuit_lesson](https://imgur.com/l1uQI6t.jpg)

* I found a relay in the electronics cart and got it to work the first time I hooked it up. Thinking back, a relay should have been the very first solution I tried. The reason I did not use a relay was because I didn’t have one on my hand. So, I had to work with what I’ve got: the mic input, or the transistor. 
## Making an Enclosure
* I have two goals in mind when designing the enclosure. First, it needs to resemble some sort of creature. This way people will make the connection between music and light and recognize that it is having fun. Secondly, it must have something resembling eyes and looks like it is ‘looking’ at the direction where the camera points.
* I used an empty Fage 2% yogurt bucket as a general structure

![yogurt_bucket](\pictures\yogurt_bucket.JPG)

* I painted the bucket black. The reason being I’m using a red Bluetooth speaker, and I think red and black looks good together. Also, my only other option was white.
# Putting it all together
* These are all the cables I need. I have a power chord for Pi and a power chord for projector, an aux cable, a camera cable, a USB to the Auduino, and a power line from the relay to the projector. Now all I needto do is to organize the wires and neatly fit  them inside the bucket.
![wire_layout](\pictures\wire_layout.JPG)
![drawing](\pictures\drawing.jpg)
* Bam! Beautiful
![nice_cords_arangement](https://imgur.com/zUWJOtq.jpg)
* The breadboard is positioned closed to the opening for the relay to attach to.
![back_hole](https://imgur.com/1HflDu2.jpg)
![Layout](https://imgur.com/tp68FTS.jpg)
##  The working video
A hat is added for better presentation.
![setup](\pictures\setup_room.JPG)
[Video](https://youtu.be/XP9JwoVYuVE)