/*
 * MotorDriver.c
 *
 * Created: 10/11/2023 13:07:49
 * Author : $RHEK00-BS9TAG427UBC
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include "util/delay.h"
#include "utility.h"

void initPWM();
void initPorts();

int main(void)
{

	
	initPWM();
	initPorts();
	int16_t counter;
	
	while (1)
	{
		counter = 255;
		PORTF |= (1<<0);
		while(counter>15){
			
			
			OCR2 = counter;
			counter -= 30;  //counter = counter -30;
			PORTA = OCR2;
			_delay_ms(10);
			
			
		}
		PORTF = 0X00;
		_delay_ms(100);
		PORTF |= (1<<1);
		counter = 255;
		while(counter<0){
			
			PORTF |=(1<<1);
			OCR2 = counter;
			counter -= 30;
			PORTA = OCR2;
			_delay_ms(10);
			
		}
		PORTF = 0xFF;
		_delay_ms(100);
		
	}
}



void initPWM(){
	PORTB |= (1<<7);
	TCCR2 = 0;
	TCCR2 = (1<<WGM20);
	TCCR2 |= (1<<COM20) | (1<<COM21);
	TCCR2 |= (1<<CS20);
}

void initPorts(){
		DDRF |= (1<<PINF0) | (1<<PINF1);
		DDRA = 0xFF;
		
		PORTA = 0x00;
		PORTF = 0x00;
}
