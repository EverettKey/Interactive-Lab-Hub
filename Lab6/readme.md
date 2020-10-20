**How do you know what the shell script is doing?**
    
    We used nano to inspect the scripts 

**How do we use ``vosk`` to recognize words and phrases?**

    We do it by executing a shell script, which records an audio file and then execute a python script that finds words from a given list.

**Include the output of vosk recognizing phrases you taught it to look for.**

    text: ['Banana', 'Apple', 'Orange']

**Include the listing for a shell script and model files that you use to get vosk to recognize these phrases.**

    test_words.py <- chage the word list


### Experimenting with Linux processes


## Connect the Arduino and the RPi

**What would you change to make sayHelloPi say something else?**

    We can do so simply by changing the data string to any text and it will try to pronounce it

**How could you make it so that the Pi would only say something if the lights came on in the room?**

    We can connect arduino to a light sensor and modify helloPi.ino so it only send strings through the serial port when there's enough light detected in the light sensor.

**How could you make it so that the Pi would say different things based on different sensor values read by the Arduino?**

    We will first mondify hellpi.ino to send different serial signals when different values are read by the sensor. We will then change sayHellopi.py to play different sound files, or text2speech different strings.

**Next, try out ``HelloArduino``. First have ``HelloArduino.ino`` listen for messages from ``HelloArduino.py``. Next, use ``morse_code_translator.ino``. What happens differently?**


## Your own voice agent 

Program a simple application that understands different basic greetings (for example, Yo!, Good morning! And Good afternoon!) and responds either visibly, physically or auditorially in kind!

You are free to adapt this assignment to have the agent respond to any other set of vocabulary for any other purpose.

**Record someone trying out your design**

https://youtu.be/wJwiNVCM4z0

**Submit your code to Github**
