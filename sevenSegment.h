/*
 * sevenSegment.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

//#include"avr/io.h"
#include"manual_std_types.h"
#include"regs.h"
#include"dio.h"

#define CLEAR_BIT(REG,BIT) (REG &= ~(1<<BIT))
void segment_init(void);

void segment_write (uint8 sement_value);

#endif /* SEVENSEGMENT_H_ */
