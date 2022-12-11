/*
  Blink

  Turns a LEDs on, then off, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

int RED    = 13;
int YELLOW = 12;
int GREEN  = 8;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as output.
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(RED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait
  digitalWrite(RED, LOW);   // turn the LED off by making the voltage LOW
  delay(500);                      // wait
  digitalWrite(YELLOW, HIGH);
  delay(500);                    
  digitalWrite(YELLOW, LOW); 
  delay(500);                    
  digitalWrite(GREEN, HIGH);
  delay(500);                    
  digitalWrite(GREEN, LOW); 
  delay(500);                    
}
