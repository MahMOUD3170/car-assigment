/*
 * DIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#ifndef DIO_H_
#define DIO_H_

#include "Std_Types.h"

#define MAX_NUM_OF_PINS		(uint8)32

#include "DIO_cnfg.h"

Std_Func_t DIO_init (void);

Std_Func_t DIO_write (uint8 port,uint8 pin,uint8 val);

Std_Func_t DIO_read (uint8 port,uint8 pin,uint8 * Pval);

#endif /* DIO_H_ */
