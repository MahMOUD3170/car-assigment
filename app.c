/*
 * app.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#include"manual_std_types.h"
#include"regs.h"
#include"interrupt_manual.h"
#include"sevenSegment.h"
#include<avr/delay.h>
#include"dio.h"
#include "motor.h"
#include "timer.h"

#define NUMBER_OF_OVERFLOWS_PER_SECOND 4
uint8 interruptFlag = 0;
uint8  tick = 0,num=0,flag=0;
uint8  g2_tick = 0;

void __vector_11 (void)
{
	interruptFlag = 1;
}

int main(void)
{

	DDRB  = 0x0F;    // Configure all pins in PORTC as output pins.
	PORTB = 0;
	SREG  |= (1<<7); //enable global interrupts in MC by setting the I-Bit.
	motor_init();
	TIMER_init();
	TIMER_FAST_PWM ( 2,50);//50 % duty cycle
	while(1)
	{
		if(interruptFlag == 1)
		{
			interruptFlag = 0;
			tick++;
			if(tick == NUMBER_OF_OVERFLOWS_PER_SECOND)
			{
				tick=0;
				if (flag==0 && num != 9)
				{	num++;

				segment_write(num);
				moveForward();
				if (num == 9 && flag==0)
				{
					flag=1;
				}
				}

				else if(flag==1 && (num != 0))
				{

					num--;
					segment_write(num);
					moveBackward();
					if (num == 0 && flag==1)
					{
						flag=0;
					}
				}
			}
		}
	}
}
