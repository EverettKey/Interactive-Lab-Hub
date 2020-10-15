// This borrows code from Examples->EEPROM->eeprom_read
// READ STATE
byte value;

void state1Setup() {
  Serial.println("Reading from EEPROM");

  for (int i = 0; i < EEPROMSIZE; i++) {
    value = EEPROM.read(i);
    display.println(value);
    display.display();
    if (i % 4 == 0){
      display.clearDisplay();
      display.setCursor(0,0);
    }
    Serial.println(value);
  }
  Serial.println();

  Serial.println("Done reading from EEPROM");
  display.println("Done reading from EEPROM");
  display.display();
}

void state1Loop() {
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}

void doState1() {
  if (lastState != 1) { state1Setup(); }
  state1Loop();
}
