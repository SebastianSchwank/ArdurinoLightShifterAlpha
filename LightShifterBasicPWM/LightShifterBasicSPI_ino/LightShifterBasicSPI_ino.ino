/*
 Example 34.1 - SPI bus demo using a Microchip MCP4162 digital potentiometer [http://bit.ly/iwDmnd]
 http://tronixstuff.com/tutorials > chapter 34 | CC by-sa-nc | John Boxall
*/
 
#include "SPI.h" // necessary library
int ss=10; // using digital pin 10 for SPI slave select
int del=200; // used for various delays
 
void setup()
{
  pinMode(ss, OUTPUT); // we use this for SS pin
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
  // our MCP4162 requires data to be sent MSB (most significant byte) first
}
 
void setValue(int value)
{
  digitalWrite(ss, LOW);
  SPI.transfer(0); // send value (0~255)
  SPI.transfer(0); // send value (0~255)
  SPI.transfer(255); // send value (0~255)
  SPI.transfer(255); // send value (0~255)
  SPI.transfer(15); // send value (0~255)
  SPI.transfer(15); // send value (0~255)
  digitalWrite(ss, HIGH);
}
 
void loop()
{
  digitalWrite(ss, LOW);
  for(byte i = 0; i < 256; i++){
    SPI.transfer(170); // send value (0~255)
  }
  digitalWrite(ss, HIGH);
}
