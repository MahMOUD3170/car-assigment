/*
 * sevenSegment.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#include"sevenSegment.h"


void segment_init(void)
{
	//DDRB &= ~((1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4));
	CLEAR_BIT(DDRB,1);
	CLEAR_BIT(DDRB,2);
	CLEAR_BIT(DDRB,3);
	CLEAR_BIT(DDRB,4);
	DIO_write(PORT_B,PIN0,0);
	DIO_write(PORT_B,PIN1,0);
	DIO_write(PORT_B,PIN2,0);
	DIO_write(PORT_B,PIN3,0);
}

void segment_write (uint8 sement_value)
{
	// every second increase counter by 1 and pass it to this function
	switch(sement_value)
	{
	case 0:
		DIO_write(PORT_B,PIN0,0);
		DIO_write(PORT_B,PIN1,0);
		DIO_write(PORT_B,PIN2,0);
		DIO_write(PORT_B,PIN3,0);
		break;
	case 1:
		DIO_write(PORT_B,PIN0,1);
		DIO_write(PORT_B,PIN1,0);
		DIO_write(PORT_B,PIN2,0);
		DIO_write(PORT_B,PIN3,0);
		break;
	case 2:
		DIO_write(PORT_B,PIN0,0);
		DIO_write(PORT_B,PIN1,1);
		DIO_write(PORT_B,PIN2,0);
		DIO_write(PORT_B,PIN3,0);
		break;
	case 3:
		DIO_write(PORT_B,PIN0,1);
		DIO_write(PORT_B,PIN1,1);
		DIO_write(PORT_B,PIN2,0);
		DIO_write(PORT_B,PIN3,0);
		break;
	case 4:
		DIO_write(PORT_B,PIN0,0);
		DIO_write(PORT_B,PIN1,0);
		DIO_write(PORT_B,PIN2,1);
		DIO_write(PORT_B,PIN3,0);
		break;
	case 5:
		DIO_write(PORT_B,PIN0,1);
		DIO_write(PORT_B,PIN1,0);
		DIO_write(PORT_B,PIN2,1);
		DIO_write(PORT_B,PIN3,0);
		break;
	case 6:
		DIO_write(PORT_B,PIN0,0);
		DIO_write(PORT_B,PIN1,1);
		DIO_write(PORT_B,PIN2,1);
		DIO_write(PORT_B,PIN3,0);
		break;
	case 7:
		DIO_write(PORT_B,PIN0,1);
		DIO_write(PORT_B,PIN1,1);
		DIO_write(PORT_B,PIN2,1);
		DIO_write(PORT_B,PIN3,0);
		break;
	case 8:
		DIO_write(PORT_B,PIN0,0);
		DIO_write(PORT_B,PIN1,0);
		DIO_write(PORT_B,PIN2,0);
		DIO_write(PORT_B,PIN3,1);
		break;
	case 9:
		DIO_write(PORT_B,PIN0,1);
		DIO_write(PORT_B,PIN1,0);
		DIO_write(PORT_B,PIN2,0);
		DIO_write(PORT_B,PIN3,1);
		break;
	}
}
