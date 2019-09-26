/*
 * DIO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */
#include "DIO.h"
#include "Regs.h"
Std_Func_t DIO_init (void)
{
	Std_Func_t retval = OK;
	uint8 loop_index = 0;
	if (NUM_OF_PINS<=MAX_NUM_OF_PINS)
	{
		for(loop_index = 0;loop_index<NUM_OF_PINS;loop_index++)
		{
			DIO_cnfg_arr[loop_index].IS_init_arr = INITIALIZED;
			switch(DIO_cnfg_arr[loop_index].PORT)
			{
			case PORT_A:
				if(DIO_cnfg_arr[loop_index].DIR == OUTPUT)
				{
					DDRA_REG |=(1u<<DIO_cnfg_arr[loop_index].PIN);
					if (DIO_cnfg_arr[loop_index].OUT == HIGH)
					{
						PORTA_REG |=(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else if (DIO_cnfg_arr[loop_index].OUT == LOW)
					{
						PORTA_REG &=~(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else
					{
						DIO_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
						retval = NOK;
					}
				}
				else if(DIO_cnfg_arr[loop_index].DIR == INPUT)
				{
					DDRA_REG &=~(1u<<DIO_cnfg_arr[loop_index].PIN);
					if (DIO_cnfg_arr[loop_index].RES == PULLUP)
					{
						PORTA_REG |=(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else if (DIO_cnfg_arr[loop_index].RES == EXTRES)
					{
						PORTA_REG &=~(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else
					{
						DIO_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
						retval = NOK;
					}
				}
				else
				{
					DIO_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
				break;
			case PORT_B:
				if(DIO_cnfg_arr[loop_index].DIR == OUTPUT)
				{
					DDRB_REG |=(1u<<DIO_cnfg_arr[loop_index].PIN);
					if (DIO_cnfg_arr[loop_index].OUT == HIGH)
					{
						PORTB_REG |=(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else if (DIO_cnfg_arr[loop_index].OUT == LOW)
					{
						PORTB_REG &=~(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else
					{
						DIO_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
						retval = NOK;
					}
				}
				else if(DIO_cnfg_arr[loop_index].DIR == INPUT)
				{
					DDRB_REG &=~(1u<<DIO_cnfg_arr[loop_index].PIN);
					if (DIO_cnfg_arr[loop_index].RES == PULLUP)
					{
						PORTB_REG |=(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else if (DIO_cnfg_arr[loop_index].RES == EXTRES)
					{
						PORTB_REG &=~(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else
					{
						DIO_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
						retval = NOK;
					}
				}
				else
				{
					DIO_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
				break;
			case PORT_C:
				if(DIO_cnfg_arr[loop_index].DIR == OUTPUT)
				{
					DDRC_REG |=(1u<<DIO_cnfg_arr[loop_index].PIN);
					if (DIO_cnfg_arr[loop_index].OUT == HIGH)
					{
						PORTC_REG |=(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else if (DIO_cnfg_arr[loop_index].OUT == LOW)
					{
						PORTC_REG &=~(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else
					{
						DIO_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
						retval = NOK;
					}
				}
				else if(DIO_cnfg_arr[loop_index].DIR == INPUT)
				{
					DDRC_REG &=~(1u<<DIO_cnfg_arr[loop_index].PIN);
					if (DIO_cnfg_arr[loop_index].RES == PULLUP)
					{
						PORTC_REG |=(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else if (DIO_cnfg_arr[loop_index].RES == EXTRES)
					{
						PORTC_REG &=~(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else
					{
						DIO_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
						retval = NOK;
					}
				}
				else
				{
					DIO_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
				break;
			case PORT_D:
				if(DIO_cnfg_arr[loop_index].DIR == OUTPUT)
				{
					DDRD_REG |=(1u<<DIO_cnfg_arr[loop_index].PIN);
					if (DIO_cnfg_arr[loop_index].OUT == HIGH)
					{
						PORTD_REG |=(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else if (DIO_cnfg_arr[loop_index].OUT == LOW)
					{
						PORTD_REG &=~(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else
					{
						DIO_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
						retval = NOK;
					}
				}
				else if(DIO_cnfg_arr[loop_index].DIR == INPUT)
				{
					DDRD_REG &=~(1u<<DIO_cnfg_arr[loop_index].PIN);
					if (DIO_cnfg_arr[loop_index].RES == PULLUP)
					{
						PORTD_REG |=(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else if (DIO_cnfg_arr[loop_index].RES == EXTRES)
					{
						PORTD_REG &=~(1u<<DIO_cnfg_arr[loop_index].PIN);
					}
					else
					{
						DIO_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
						retval = NOK;
					}
				}
				else
				{
					DIO_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
				break;
			default:
				DIO_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
				retval = NOK;
			}
		}
	}
	else
	{
		for (loop_index = 0; loop_index <NUM_OF_PINS ;loop_index++)
		{
			DIO_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
		}
		retval = NOK;
	}
	return retval;
}

Std_Func_t DIO_read (uint8 port,uint8 pin,uint8 * Pval)
{
	Std_Func_t retval = OK;
	uint8 loop_index ;
	for (loop_index = 0; loop_index <NUM_OF_PINS ;loop_index++)
	{
		if ((DIO_cnfg_arr[loop_index].PORT == port)&&(DIO_cnfg_arr[loop_index].PIN == pin))
		{
			if((DIO_cnfg_arr[loop_index].IS_init_arr == INITIALIZED)&&(DIO_cnfg_arr[loop_index].DIR == INPUT))
			{
				switch (port)
				{
				case PORT_A:
					*Pval = (1u&(PINA_REG>>pin));
					break;
				case PORT_B:
					*Pval = (1u&(PINB_REG>>pin));
					break;
				case PORT_C:
					*Pval = (1u&(PINC_REG>>pin));
					break;
				case PORT_D:
					*Pval = (1u&(PIND_REG>>pin));
					break;
				}
				loop_index = (uint8)(MAX_NUM_OF_PINS+1);
			}
			else
			{
				retval = NOK;
			}
		}
		else
		{
			retval = NOK;//NOK
		}
	}
	return retval;
}

Std_Func_t DIO_write (uint8 port,uint8 pin,uint8 val)
{
	Std_Func_t retval = OK;
	uint8 loop_index ;
	for (loop_index = 0; loop_index <NUM_OF_PINS ;loop_index++)
	{
		if ((DIO_cnfg_arr[loop_index].PORT == port)&&(DIO_cnfg_arr[loop_index].PIN == pin))
		{
			if(((DIO_cnfg_arr[loop_index].IS_init_arr == INITIALIZED))
					&&(DIO_cnfg_arr[loop_index].DIR == OUTPUT)
					&&((val == HIGH)||(val == LOW)))
			{
				switch (port)
				{
				case PORT_A:
					if (val == HIGH)
					{
						PORTA_REG |=(1u<<pin);
					}
					else
					{
						PORTA_REG &=~(1u<<pin);
					}
					break;
				case PORT_B:
					if (val == HIGH)
					{
						PORTB_REG |=(1u<<pin);
					}
					else
					{
						PORTB_REG &=~(1u<<pin);
					}
					break;
				case PORT_C:
					if (val == HIGH)
					{
						PORTC_REG |=(1u<<pin);
					}
					else
					{
						PORTC_REG &=~(1u<<pin);
					}
					break;
				case PORT_D:
					if (val == HIGH)
					{
						PORTD_REG |=(1u<<pin);
					}
					else
					{
						PORTD_REG &=~(1u<<pin);
					}
					break;
				}
				loop_index = (uint8)(MAX_NUM_OF_PINS+1);
				break;
			}
			else
			{
				retval = NOK;
			}
		}
		else
		{
			retval = NOK;
		}
	}
	return retval;
}


