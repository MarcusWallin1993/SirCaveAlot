/*
 * TestAtmega1284.c
 *
 * Created: 3/26/2017 3:44:22 PM
 *  Author: marwa079
 */ 

//#define F_CPU 1000000UL

#include <avr/io.h>
//#include <util/delay.h>
//#include <stdbool.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>


int main(void)
{
	 DDRD = (1 << DDD3);
	 EIMSK = 1<<INT0;
	 EICRA = (1<<ISC01) | (1<<ISC00);
	 ADMUX = (1<<ADLAR) |  (MUX0 << 1);
	 DDRB = 0xFF;
	 sei();
	 //PORTB = 0x0F;
	 
	 //while(1);
	 
	
	
	
    while(1);
	
	
}


ISR(INT0_vect){
	
	ADCSRA = 0xEC;
	
	
	
	
	
}

ISR(ADC_vect){
	
	PORTB = ADCH;
	ADCSRA = 0x00;
	
	PORTD = 0x08;
	for(int i = 0 ; i < 10000 ; ++i)
	{
		
	}
	PORTD = 0x00;
	for(int i = 0 ; i < 10000 ; ++i)
	{
		
	}
	
}



int blinklamp(unsigned int onoff )
{
	if(onoff == 1)
	{
		PORTD = 0x08;
		onoff = 0;
	}
	else
	{
		PORTD = 0x00;
		onoff = 1;
	}
	for(int i = 0 ; i < 10000 ; ++i)
	{
		
	}

    return onoff;	
}

void pwmtest(void)
{
	DDRD = 0x88;
	
	//Right wheel
	TCCR2B = (CS00 << 1);  //Intern clock
	TCCR2A = (WGM01 << 1) | (WGM00 << 1) | (COM0A1 << 1 );
	//set fast pwm-mode           //clear register when match with OCR2A
	OCR2A = 0x3F;
	OCR2B = 0x3F;
	
	
	
}