/*
  BlinkMyWay
  Turns the onboard LED MY WAY. Sending the most deepest message from the bottom of my heart.
  Modified by Everett Key
  Sep 7, 2020
*/
int s = 150;
int l = 500;
int pause = 100;
int space = 750;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  blink3(s); // S
  blink3(l); // O
  blink3(s); // S
  delay(space);
}
  
void blink3(int len){
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(len);                     
  digitalWrite(LED_BUILTIN, LOW);   
  delay(s);
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(len);                     
  digitalWrite(LED_BUILTIN, LOW);   
  delay(s);   
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(len);                     
  digitalWrite(LED_BUILTIN, LOW);   
  delay(space);             
}


