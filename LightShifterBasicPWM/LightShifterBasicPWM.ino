/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 */

int pin = 6;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(pin, OUTPUT);
  
  //Set the FastPWM on Pin 6
  TCCR0B = (TCCR0B & 0b11110000) | 0b00001001;
  TCCR0A = TCCR0A | 0b110011;
  
  OCR0A = 255;
  0CR0B = 127;
  
} 

// the loop routine runs over and over again forever:
void loop()  { 
  
  /*
  // set the brightness of pin 6:
  analogWrite(pin, 127);
  
  // wait for 1 second 
  delay(10000);   

  // set the brigtness of pin 6:
  analogWrite(pin, 0);
  
  // wait for 1 second 
  delay(10000);   
  */
}

