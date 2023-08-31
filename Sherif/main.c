/*
 * Sherif.c
 *
 * Created: Пн 05.06.23 15:54:03
 * Author : Max
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "avr/interrupt.h"

#define QUANT 10

#define T_IMPULSE 4 * QUANT
#define T_PAUSE 4 * QUANT			// ms
#define T_DELAY 5 * QUANT
#define REPEATS 7


int main(void)
{
  
    DDRB =  0b00000101;  // PB0 - Output CTRL1, PB2 - Output CTRL2
    PORTB = 0b00000101;  // PB0 = 0, PB1 = 0

  
	/* Replace with your application code */
    while (1) 
    {
		for(uint8_t n = 0; n < REPEATS; n++)
		{
			PORTB = 0b00000001;
			_delay_ms(T_IMPULSE);
			PORTB = 0;
			_delay_ms(T_PAUSE);
		}
		_delay_ms(T_DELAY);
		
		for(uint8_t n = 0; n < REPEATS; n++)
		{
			PORTB = 0b00000100;
			_delay_ms(T_IMPULSE);
			PORTB = 0;
			_delay_ms(T_PAUSE);
		}
		_delay_ms(T_DELAY);
		
    }
}

