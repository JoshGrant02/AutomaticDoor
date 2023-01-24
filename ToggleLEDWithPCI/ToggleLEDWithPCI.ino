//Connect LED to A0

#define PINC 0x26
#define DDRC 0x27
#define PORTC 0x28
#define PCICR 0x68
#define PCMASK1 0x6C

void setup() {
  *(uint8_t*) DDRC = (uint8_t) 0b11;
  *(uint8_t*) PORTC = (uint8_t) 0b00;
  *(uint8_t*) PCICR = (uint8_t) 0b10;
  *(uint8_t*) PCMASK1 = (uint8_t) 0b10;
}

void loop() {
  *(uint8_t*) PINC |= (uint8_t) 0b10;
  delay(500);
}

ISR(PCINT1_vect) {
  bool pressed = (*(uint8_t*) PORTC) && 0b10;
  if (pressed) {
    *(uint8_t*) PINC = (uint8_t) 0b1;
  }
}