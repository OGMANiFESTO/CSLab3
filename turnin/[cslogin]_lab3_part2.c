/*	Author: Festo Bwogi
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #3  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}


int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0x00;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    unsigned char tempA = 0x00;
    unsigned char tempC = 0x00;
    while (1) {
	tempA = PINA & 0x0F;
	if(tempA == 1 || tempA == 2) {
		tempC = 0x20;
	}
	else if(tempA == 3 || tempA == 4) {
		tempC = 0x30;
	}
	else if(tempA == 5 || tempA == 6) {
		tempC = 0x38;
	}
	else if(tempA == 7 || tempA == 8 || tempA == 9) {
		tempC = 0x3C;
	}
	else if(tempA == 10 || tempA == 11 || tempA == 12) {
		tempC = 0x3E;
	}
	else if(tempA == 13 || tempA == 14 || tempA == 15) {
		tempC = 0x3F;
	}
	else {
		tempC = 0;		
	}
		
	if(tempA <= 4) {
		tempC = tempC | 0x40;
	}

	PORTC = tempC;
    }
    return 1;
}
