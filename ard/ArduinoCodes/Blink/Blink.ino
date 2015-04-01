/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

void setup() {                
  // initialize the digital pin as an output.
  // Pin 9 has an LED connected on most Arduino boards:
  pinMode(9, OUTPUT);     
}

void loop() {
  digitalWrite(9, HIGH);   // set the LED on
  delay(100);              // wait for a second
  digitalWrite(9, LOW);    // set the LED off
  delay(100);              // wait for a second
}
