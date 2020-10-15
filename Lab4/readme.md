# Data Logger (and using cool sensors!)

## Part A.  Writing to the Serial Monitor 
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**
 
    0 ~ 1023

**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have** (hint: where might you look to find this sort of thing)? How many are you using with the range of values you're seeing?

    1024 is 2 to the 10th power, so 10 bits

## Part B. RGB LED
**a. What voltage values do you see from your force sensor?**

    Using a 100 Ohm resistor, the highest A0 reading I could reach by pinching the sensor was ~300. Using a 5K1 Ohm resister I could get the value pass 1000 but never was ablt to reach 1023. We can get close but never reach 5V using the sensor.

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

    Exponential, the log-log plot of the sensor's received force and resistance is linear

**c. In `Examples->Basic->Fading` the RGB LED values range from 0-255. What do you have to do so that you get the full range of output voltages from the RGB LED when using your FSR to change the LED color?**
    I can first divide the A0 reading by 1024 and then multiply it by 256 (256/1024 = 0.25) to get the FSR reading mapped to the LED


## Flex Sensor, Photo cell, Softpot

**a. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

    2 10k resistors in series works best for the flex sensor

**b. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

    The flex sensor is roughly linear.

## Part D. I2C Sensors 

Some more sophisticated sensors have ICs that measure physical phenomena and then output an digital signal indicating what the analog voltage reading is. 

### Accelerometer

**a. Include your accelerometer read-out code in your write-up.**

    okay

## Part E. Logging values to the EEPROM and reading them back
**a. Does it matter what actions are assigned to which state? Why?**

    Yes, the assigned actions matters because they do different things

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

    Because the actions are done only once. The loop is only for keeping the LED.


**c. How many byte-sized data samples can you store on the Atmega328?**

    1024 bytes

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

    I can make a mask to shif the bits. For I2C devices it's the same, just change the mask so data will be adjusted to be byte sized.
    
**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

    I can use the put() mthod to write data bigger than a byte, or I can divide the data into byte-sizes and write them in separate bytes.


### 2. Design your logger

**a. Turn in a copy of your final state diagram.**

![My State Diagram](https://imgur.com/afMb6Qt.)

## Part G. Create your own data logger!
Now it's up to you to integrate the software and hardware necessary to interface with your data logger! Your logger should be able to record a stream of analog data (at a sample rate of your desire) and then play it back at some later point in time on your display of choice.
 
**a. Record and upload a short demo video of your logger in action.**

https://youtu.be/paNI2D0-QiM