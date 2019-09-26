#include "timer.h"
#include <avr/interrupt.h>

#define NUMBER_OF_OVERFLOWS_PER_HALF_SECOND 2

unsigned char g_tick = 0;

ISR(TIMER2_OVF_vect)
{
	g_tick++;
	if(g_tick == NUMBER_OF_OVERFLOWS_PER_HALF_SECOND)
	{
		PORTC = PORTC ^ (1<<PC0); //toggle led every 0.5 second
		g_tick = 0; //clear the tick counter again to count a new 0.5 second
	}
}

/* Description :
 * For clock=1Mhz and prescale F_CPU/1024 every count will take 1ms
 * so put initial timer counter=0  0 --> 255 (256ms per overflow)
 * so we need timer to overflow 2 times to get a 0.5 second
 */


int main(void)
{
	DDRC  |= (1<<PC0); //configure the led pin to be output pin.
	PORTC &= ~(1<<PC0); //LED is off at the beginning(Positive Logic).
	SREG  |= (1<<7); //enable global interrupts in MC by setting the I-Bit.
	 //start the timer.

	TIMER_init ();
    while(1)
    {

    }
}
