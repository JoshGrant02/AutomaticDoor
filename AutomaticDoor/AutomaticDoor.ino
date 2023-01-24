#include <stdio.h>
#include <stdlib.h>

#define PINC (uint8_t*) 0x26
#define DDRC (uint8_t*) 0x27
#define PORTC (uint8_t*) 0x28
#define PIND (uint8_t*) 0x29
#define DDRD (uint8_t*) 0x2A
#define PORTD (uint8_t*) 0x2B
#define EIMSK (uint8_t*) 0x3D
#define TCCR0A (uint8_t*) 0x44
#define TCCR0B (uint8_t*) 0x45
#define OCR0A (uint8_t*) 0x47
#define PCICR (uint8_t*) 0x68
#define EICRA (uint8_t*) 0x69
#define PCMASK1 (uint8_t*) 0x6C
#define PCMASK2 (uint8_t*) 0x6D

//PC0 & PC1 for limit switches are pull up inputs
#define DDRC_MASK (uint8_t) 0b00
#define PORTC_MASK (uint8_t) 0b11

//PD2, PD3, & PD4 are pull up inputs for open/close buttons & lock button
//PD5 is output for controlling motor dir
//PD6 is output for controlling motor step
#define DDRD_MASK (uint8_t) (0b11000 << 2)
#define PORTD_MASK (uint8_t) (0b00111 << 2)

//External Interrupts 0 and 1 are triggered on falling edges
#define EICR_MASK (uint8_t) 0b1010
#define EIMSK_MASK (uint8_t) 0b11

//Pin Change Interrupt 1 is enabled
#define PCICR_MASK (uint8_t) 0b10
//Pins PC0 & PC1 are hooked up to PCINT1
#define PCMASK1_MASK (uint8_t) 0b11
//Pin PD4 is hooked up to PCINT2
//#define PCMASK2_MASK (0b1 << 4)

//Timer will flip pin D6 on compare match
//Timer will use count-to-compare mode
#define TCCR0A_MASK (uint8_t) 0b00000010
//Timer will use clock/8
#define TCCR0B_MASK (uint8_t) 0b010
//Compare match will happen after 187 ticks
#define OCR0A_MASK (uint8_t) 187
#define ENABLE_OC (uint8_t) (b01 << 6)

#define LOCKPIN 0b1
#define LIMITPINS 0b11

void setup() {
  // Setup GPIO
  *DDRC = DDRC_MASK;
  *PORTC = PORTC_MASK;
  *DDRD = DDRD_MASK;
  *PORTD = PORTD_MASK;
  
  //
  // Setup open/close button interrupts
  //
  
  // External interrupt control register
  *EICRA = EICR_MASK;

  // External interrupt enable register
  *EIMSK = EIMSK_MASK;

  //
  // Setup pin change interrupts
  //

  // Pin change interrupt control register
  *PCICR = PCICR_MASK;

  // Pin change interrupt enable register
  *PCMASK1 = PCMASK1_MASK;
  //*(uint32_t*) PCMASK2 = (uint8_t) PCMASK2_MASK;

  //
  // Setup motor controller timer
  //
  *TCCR0A = TCCR0A_MASK;
  *TCCR0B_MASK = TCCR0B_MASK;
  *OCR0A = OCR0A_MASK  
}

void loop() {
  // put your main code here, to run repeatedly:
}

//Handle Inside Button Press
ISR(INT0_vector) {
  toggleDoorMovement(); 
}

//Handle Outside Button Press
ISR(INT1_vector) {
  uint8_t isLocked = *PIND && LOCKPIN;
  if (!isLocked) {
    toggleDoorMovement();
  }
}

//Handle Limit press
ISR(PCINT1_vector) {
  uint8_t shouldStop = *PINC && LIMITPINS;
  if (shouldStop) {
    
  }
}

void toggleDoorMovement() {

}

void stopDoorMovement() {

}
