int lightPin = 7;

String inChar;  // character we will use for messages from the RPi

int buttonState;

void setup() {
  Serial.begin(115200);
  pinMode(lightPin, OUTPUT);
}

void loop() {
  // read the character we recieve on the serial port from the RPi
  if(Serial.available()) {
    inChar = Serial.readString();
    Serial.println(inChar);
    if(inChar == "r"){
      digitalWrite(lightPin, LOW);
    }
    else if(inChar == "g"){
      digitalWrite(lightPin, HIGH);
    }

  }
}

