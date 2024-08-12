#include <avr/io.h>  // AVR IO registers for interacting with hardware
#include <util/delay.h> // For delay functions

// Define the CPU frequency if it's not already defined
#ifndef F_CPU
#define F_CPU 16000000UL // Set the frequency to 16 MHz
#endif

// Define ON and OFF states
uint8_t ON  = 0xFF;
uint8_t OFF = 0x00; 

// Function prototype for swapping values
void change(uint8_t* x, uint8_t* y);

// Function to swap two uint8_t values
void change(uint8_t* x, uint8_t* y){
  uint8_t temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int main(void) {
  DDRD = 0xFF; // Set all pins of Port D as output
  
  while(1){
    PORTD = ON; // Turn on all LEDs connected to Port D
    _delay_ms(500); // Wait for 500 milliseconds
    change(&ON,&OFF); // Swap ON and OFF values
  }
}