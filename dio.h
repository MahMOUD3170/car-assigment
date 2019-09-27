/*
 * dio.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#ifndef DIO_H_
#define DIO_H_

//typedef enum{NOK,OK}Std_Func_t;

#define MAX_NUM_OF_PINS		(uint8)32

//#include <avr/io.h>

#include"manual_std_types.h"
#include"regs.h"
#include "dio_cnfg.h"

uint8 DIO_init (void);

uint8 DIO_write (uint8 port,uint8 pin,uint8 val);

uint8 DIO_read (uint8 port,uint8 pin,uint8 * Pval);


#endif /* DIO_H_ */
