//Connect LED to A0

#define PINC 0x26
#define DDRC 0x27
#define PORTC 0x28
#define PIND 0x29
#define DDRD 0x2A
#define PORTD 0x2B
#define EICRA 0x69
#define EIMSK 0x3D

void setup() {
  *(uint8_t*) DDRC = (uint8_t) 0b0;
  *(uint8_t*) PORTC = (uint8_t) 0b0;
  *(uint8_t*) DDRD = (uint8_t) 0b100;
  *(uint8_t*) PORTD = (uint8_t) 0b0;
  *(uint8_t*) EICRA = (uint8_t) 0b10;
  *(uint8_t*) EIMSK = (uint8_t) 0b1;
}

void loop() {
  *(uint8_t*) PINC |= (uint8_t) 0b10;
  delay(500);
}

ISR(INT0_vect) {
  *(uint8_t*) PINC = (uint8_t) 0b1;
}