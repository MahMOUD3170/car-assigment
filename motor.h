/*
 * app.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#ifndef MOTOR_H_
#define MOTOR_H_

//#include<avr/io.h>

#include"manual_std_types.h"
#include"regs.h"
#include"dio.h"
#include"sevenSegment.h"

#define SET_BIT(REG,BIT) (REG |= (1<<BIT))

void moveForward(void);

void moveBackward(void);

void motorsStop(void);

#endif /* MOTOR_H_ */
