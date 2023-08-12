byte i = 0;
bool inc = true;

long calc_freq(long sample_rate, long freq, long prescalar) {
  return (16000000) / (sample_rate * freq * prescalar) - 1;
}


void setup () {
  // Set DAC input pins to write (connect DAC input pins to arduino pins 2-9)
  DDRD = DDRD | 0b11111100;
  DDRB = 255;
  
  cli(); //Disable global interrupts

  // Init interupt
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  // Set interupt freq
  OCR1A = calc_freq(256*2, 261, 1);

  // Set Interupt settings
  TCCR1B |= (1 << WGM12);  //Turn on CTC mode
  TCCR1B |= (1 << CS10);  // Prescalar of 1
  TIMSK1 |= (1 << OCIE1A); //Enable timer interrupt
  
  sei(); //Enable interrupts
}

void loop() {
  // Output to DAC pins
  byte b = i;
  PORTD = b<<2;
  PORTB = (b & 0b11000000) >> 6;
}

// Generate Saw Wave
ISR(TIMER1_COMPA_vect) {
  if (inc) {
    i++;
  } else {
    i--;
  }
  
  if(i >= 255){
    inc = false;    
  } else if (i <=0) {
    inc = true;
  }
}
