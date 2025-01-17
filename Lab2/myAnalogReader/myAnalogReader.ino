/**************************************************************************
 This is an analog reader implemented by using adafruit 12C example code.
 Wrtten by Everett Key for Lab 2 of TECH 5314 Interactive Device Design
 Cornell Tech Electrical and Computer Engineering
 Professor: Wendy Ju
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

int sensorPin = A1;
int sensorValue = 0; 

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
  Serial.println(sensorValue);
  testdrawstyles(sensorValue);
  delay(5);
}


void testdrawstyles(int val) {
  display.clearDisplay();

  display.setTextSize(2);             // Draw 2X-scale text
  display.setCursor(0,0);             // Start at top-left corner
  display.setTextColor(SSD1306_WHITE);
  display.print(val);

  display.display();
}
