/*	Author: Festo Bwogi
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


int main(void) {
   
    DDRB = 0x00; PORTB = 0x00;
    DDRC = 0x06; PORTC = 0x00;
    /* Insert your solution below */
    unsigned short weightSensor = 0x00;
    while (1) {
   	weightSensor = ((PIND<<1) | (0x01&PINB));

	if (weightSensor <= 5) {
		PORTB = 0x00;
	}
	else if (weightSensor >= 70) {
		PORTB = 0x02;
	}
	else if ((weightSensor > 5) && (weightSensor < 70)) {
		PORTB = 0x04;
	}
    }
    return 1;
}
