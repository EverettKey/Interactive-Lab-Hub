/**************************************************************************
 This is a lab assignment made by Everett Key for Cornell Tech ECE 5413
 Interactive Device Dsign. Lab 2 Part D: Make my own timer
 
The timer will count down according to the reading of the potentiometer. 
When the potentiameter is turned, the timer reset.
When timer reaches 0, buzzer will sound, and continue to sound until timer 
is reset.
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include "pitches.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

int sensorPin = A0;
int sensorValue = 0;
int timeLength = 0;
int endTime = 0;
void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
}

void loop() {
  sensorValue = analogRead(sensorPin);
  if(abs(sensorValue - timeLength) >5){
    startTimer(sensorValue);
  }
  if(endTime > millis()/1000){
    dispNum(endTime - millis()/1000);
  }
  else{
    dispNum(0);
    playMusic();
  }
  delay(20);
}

void startTimer(int len){
  endTime = millis()/1000 + len;
  timeLength = len;
}

void dispNum(int val) {
  display.clearDisplay();

  display.setTextSize(2);             // Draw 2X-scale text
  display.setCursor(0,0);             // Start at top-left corner
  display.setTextColor(SSD1306_WHITE);
  display.print(val);

  display.display();
}

void playMusic(void){
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}

