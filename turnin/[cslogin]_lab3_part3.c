/*	Author: Festo Bwogi
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #3  Exercise #3
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
    unsigned char tempAupper = 0x00;
    unsigned char tempAlower = 0x00;
    unsigned char tempC = 0x00;
    while (1) {
	tempAlower = PINA & 0x0F;
	tempAupper = PINA & 0x70;
	if(tempAlower == 1 || tempAlower == 2) {
		tempC = 0x20;
	}
	else if(tempAlower == 3 || tempAlower == 4) {
		tempC = 0x30;
	}
	else if(tempAlower == 5 || tempAlower == 6) {
		tempC = 0x38;
	}
	else if(tempAlower == 7 || tempAlower == 8 || tempAlower == 9) {
		tempC = 0x3C;
	}
	else if(tempAlower == 10 || tempAlower == 11 || tempAlower == 12) {
		tempC = 0x3E;
	}
	else if(tempAlower == 13 || tempAlower == 14 || tempAlower == 15) {
		tempC = 0x3F;
	}
	else {
		tempC = 0;
	}
		
	if(tempAlower <= 4) {
		tempC = tempC | 0x40;
	}
		
	tempAupper = tempAupper >> 4;
		
	if(tempAupper == 3) {
		tempC = tempC | 0x80;
	}
		
	PORTC = tempC;	
    }
    return 1;
}
