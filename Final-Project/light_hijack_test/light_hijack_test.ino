/*
This scrip is an attempt to testing hijacking the microphone of a christmast light
 */
int mic = 7;           // the PWM pin the LED is attached to
int high = 255;    // High voltage


int low = 0;    // low voltage

// the setup routine runs once when you press reset:
void setup() {
  pinMode(mic, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
//  digitalWrite(mic, HIGH);
  analogWrite(mic, high);
  delay(2000);
//  digitalWrite(mic, LOW);
  analogWrite(mic, low);
  delay(2000);
}
