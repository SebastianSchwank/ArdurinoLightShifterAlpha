void setup()
{
  Serial.begin(57600);
  Serial.println("Frequency Generator");
  
  // configure timer1 for CTC operation
  // frequency will be on digital pin 9
  TCCR1A = _BV(COM1A0);    // toggle pin 9 on compare match
  TCCR1B = _BV(WGM12) | _BV(CS10);  // CTC mode 5, prescale = 1
}

void play(word frequency)
{
  if (frequency == 0) {     // stop frequency output
    DDRB &= ~_BV(PORTB1);   // disable output on digital pin 9
    return;
  }
  
  // calculate timer compare value for desired frequency
  OCR1A = F_CPU / 1 / 2 / frequency - 1;
  DDRB |= _BV(PORTB1);  // enable output on digital pin 9
}


void loop()
{
  // sweep frequencies in 1kHz increments and 1s intervals from 1kHz to 20kHz
  //for (byte i = 1; i <= 20; i++) {
    byte i = 800;
    play(i * 1000);
    Serial.print(i, DEC);
    Serial.print("kHz (");
    Serial.print(F_CPU / 1 / 2 / (OCR1A + 1),DEC);
    Serial.println(")");
    delay(1000);
  //}
}
