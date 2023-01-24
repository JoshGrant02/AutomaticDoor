#define PIND 0x29
#define DDRD 0x2A
#define PORTD 0x2B
#define TCCR0A 0x44
#define TCCR0B 0x45
#define OCR0A 0x47
#define CLKPR 0x61
#define SREG 0x5f

void setup() {
  *(uint8_t*) SREG &= (uint8_t) ~(1<<7);
  //Write to clock prescaler to slow down clock by factor of 256
  *(uint8_t*) CLKPR = (uint8_t) 0b10000000;
  *(uint8_t*) CLKPR = (uint8_t) 0b00001000;
  *(uint8_t*) SREG |= (uint8_t) (1<<7);

  *(uint8_t*) DDRD = (uint8_t) (1<<5);
  *(uint8_t*) TCCR0A = (uint8_t) 0b01000010;
  *(uint8_t*) TCCR0B = (uint8_t) 0b10000100;
  *(uint8_t*) OCR0A = (uint8_t) 122;
}

void loop() {
}
