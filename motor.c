/*
 * app_motor.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#include "motor.h"


void motor_init(void)
{
	//DDRD |= ((1<<PD2)|(1<<PD3));
	SET_BIT(DDRD,2);
	SET_BIT(DDRD,3);
	DIO_write(PORT_D,PIN2,0);
	DIO_write(PORT_D,PIN3,0);
}

void moveForward(void)
{
	//DDRD |= ((1<<PD2)|(1<<PD3));
	//motorsStop();
	//timer2_pwm(value);
	DIO_write(PORT_D,PIN2,0);
	DIO_write(PORT_D,PIN3,1);
	//(PORT_D,PIN6,0);
	//(PORT_D,PIN7,1);
}



void moveBackward(void)
{
	//DDRD |= ((1<<PD2)|(1<<PD3));
	//motorsStop();
	//timer2_pwm(value);
	DIO_write(PORT_D,PIN3,0);
	DIO_write(PORT_D,PIN2,1);
	//(PORT_D,PIN7,0);
	//(PORT_D,PIN6,1);
}




void motorsStop(void)
{
	DIO_write(PORT_D,PIN2,0);
	DIO_write(PORT_D,PIN3,0);
	//(PORT_D,PIN6,0);
	//(PORT_D,PIN7,0);
}
