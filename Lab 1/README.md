# IDD-Fa19-Lab1: Blink!

**A lab report by John Q. Student**

**Fork** this repository to get a template for Lab 1 for *Developing and Designing Interactive Devices* at Cornell Tech, Fall 2019. You should modify this `README.md` file to delete this paragraph and update below. As the lab asks:

> Include your responses to the bold questions on your own fork of the lab activities. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as `README.md` pages on your GitHub, and post a link to that on your main class hub page.

We've copied the questions from the lab here. Answer them below!

## Part A. Set Up a Breadboard

<a href="https://imgur.com/jnYbQjl"><img src="https://i.imgur.com/jnYbQjl.jpg" title="source: imgur.com" /></a>


## Part B. Manually Blink a LED

**a. What color stripes are on a 100 Ohm resistor?**

Red, Red, Brown

First Digit: 2 (Red)

Second Digit: 2 (red)

Multiplier: 10 (Brown)

22 X 10 = 220
 
**b. What do you have to do to light your LED?**

I need to press the switch, the LED only lights up when the 
switch is pressed and hold down.

## Part C. Blink a LED using Arduino

### 1. Blink the on-board LED

**a. What line(s) of code do you need to change to make the LED blink (like, at all)?**

I didn't need to change any code.

**b. What line(s) of code do you need to change to change the rate of blinking?**

I need to change the variables in the `delay()` function, the larger the number, the longer the LED stays in the state written by the `digitalWrite()` statement.

**c. What circuit element would you want to add to protect the board and external LED?**
 
A see-through cover board can protect the board from dust and scratch.

**d. At what delay can you no longer *perceive* the LED blinking? How can you prove to yourself that it is, in fact, still blinking?**

I can no longer *perceive* the blinking when `delay` is set at 13.

I can film the board with high frame rate camera and replay the footage in slow-mo to observe the blinking of LED.

**e. Modify the code to make your LED blink your way. Save your new blink code to your lab 1 repository, with a link on the README.md.**

Yes ma'am.

### 2. Blink your LED

**Make a video of your LED blinking, and add it to your lab submission.**

<a href="https://www.youtube.com/watch?v=TlChYUmCGXQ
" target="_blank"><img src="https://www.youtube.com/watch?v=TlChYUmCGXQ/0.jpg" 
alt="Blink it my way" width="240" height="180" border="10" /></a>


## Part D. Manually fade an LED

**a. Are you able to get the LED to glow the whole turning range of the potentiometer? Why or why not?**

Yes, the potentiameter provides variable resistance that can be adjusted by turning the knob. The changing resistance can be used to adjust the voltage across LED.

## Part E. Fade an LED using Arduino

**a. What do you have to modify to make the code control the circuit you've built on your breadboard?**

I had to change the variable `int led` from `9` to `11`.

**b. What is analogWrite()? How is that different than digitalWrite()?**

`analogWrite()` makes the pin oscillate with the designated value with pulse length the same as the duty cycle.

`digitalWrite`, on the other hand, changes the value to either high or low and stays at the designated value.


## Part F. FRANKENLIGHT!!!

### 1. Take apart your electronic device, and draw a schematic of what is inside. 

**a. Is there computation in your device? Where is it? What do you think is happening inside the "computer?"**

I took apart a bicycle taillight that I don't need.

**b. Are there sensors on your device? How do they work? How is the sensed information conveyed to other portions of the device?**

There is a push button on the light. By pressing the button I can switch the light to different modes: off, bright, dim, slow blink, and fast blink.

**c. How is the device powered? Is there any transformation or regulation of the power? How is that done? What voltages are used throughout the system?**

The bike light is powered by a 803030  3.7V 650mAh  Li-polymer battery. I couldn't identify antying resembling a transformer on the board. However, because the light can be dimmed, we can infer that there is a mechanism that regulate the voltage across the LEDs. 

**d. Is information stored in your device? Where? How?**

If we consider the state of the LED to be information, then we can say that the light stores information in it. However, such information is only stored when the power is plugged in. I did an experiment of turing the light on and unplugging the power. If I plug the power back in the light will not turn on. Instead it will return to its orignal state: off. Information is lost when the device loses power.

### 2. Using your schematic, figure out where a good point would be to hijack your device and implant an LED.

Although I very much want to play with the switch or the embeded LED, I did not pocess the skill to modify them. The only section that I can modify is where the battery is attached to the board.
I attached a little green LED to a break-out circut, drawing power from the li-po battery. The poor guy can never join the party with the rest of the red LEDs. But I know it's the one that emits the most warming of light.
Born from the corpse of used device by a master student in the name of engineering. I hereby name you after the mad scientist: Frankenlight.


### 3. Build your light!

**Make a video showing off your Frankenlight.**

<a href="https://www.youtube.com/watch?v=7jxjTcmRmbU
" target="_blank"><img src="https://www.youtube.com/watch?v=7jxjTcmRmbU/0.jpg" 
alt="Working Frankenlight" width="240" height="180" border="10" /></a>