// This borrows code from Examples->EEPROM->eeprom_write
// WRITE　STATE

int data = 0; // 10 bits
int addr = 0;

void state2Setup() {
  digitalWrite(ledPin, LOW);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);             // Start at top-left corner


  display.println("Writing to EEPROM");
  display.display();
  Serial.println("Writing to EEPROM");
  data = analogRead(dataPin);

  
  
  EEPROM.write(addr, data);
  addr = (addr + 1) % EEPROMSIZE;
  
  display.clearDisplay();
//  display.setTextSize(1);
//  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);  
  Serial.println("Number committed to EEPROM!");
  display.println("Number committed to EEPROM!");
  display.display();

  delay(interval);
}

void state2Loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void doState2() {
  if (lastState != 2){
    addr = 0;
  }
  state2Setup();
  state2Loop();
}
