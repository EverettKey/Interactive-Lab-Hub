int redPin = 11;
int greenPin = 10;
int bluePin = 9;

String inChar;  // character we will use for messages from the RPi

int button = 2;
int buttonState;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(button, INPUT);
  setColor(255,255,255);
}

void loop() {
  // read the character we recieve on the serial port from the RPi
  if(Serial.available()) {
    inChar = Serial.readString();
      // if we get a 'R', turn the LED RED
    if(inChar == "red"){
      setColor(255,0,0);
    }
    else if(inChar == "green"){
      setColor(0,255,0);
    }
    else if(inChar == "blue"){
      setColor(0,0,255);
    }
  }

  // Button event checker - if pressed, send message to RPi
  int newState = digitalRead(button);
  if (buttonState != newState) {
    buttonState = newState;
    if(buttonState == HIGH){
      Serial.println("green");
    }
  }
}

void setColor(int red, int green, int blue)
{
  red = 255-red;
  green=255-green;
  blue=255-blue;
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
