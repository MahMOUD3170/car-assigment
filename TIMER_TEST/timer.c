
#include "timer.h"
Std_Func_t TIMER_init (void)
{
	Std_Func_t retval = OK;
	UINT8 loop_index = 0;

	for(loop_index = 0;loop_index<NUM_OF_TIMERS;loop_index++)
	{
		TIMER_cnfg_arr[loop_index].IS_init_arr = INITIALIZED;
		switch(TIMER_cnfg_arr[loop_index].TIMER)
		{

		case timer_0:
			if(TIMER_cnfg_arr[loop_index].MODE == NORMAL &&TIMER_cnfg_arr[loop_index].MODE<MAX_T0_MODES )
			{
				TCCR0 = (1<<FOC0) ;
				TCNT0 = 0;

				if (TIMER_cnfg_arr[loop_index].CLK_SOURCE == internal)
				{
					if(TIMER_cnfg_arr[loop_index].PRESCALER<MAX_CLK)
					{

						TCCR0 =	(TCCR0 & 0xF8) | TIMER_cnfg_arr[loop_index].PRESCALER;
					}
					else
					{
						TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
						retval = NOK;
					}
				}

				else if (TIMER_cnfg_arr[loop_index].CLK_SOURCE == external)
				{ DDRB &= ~(1<<PB1);
				if(TIMER_cnfg_arr[loop_index].EXTERNAL_CLK_EDGE==EX_falling)
				{
					TCCR1B = (TCCR1B & 0xF8) | EX_falling;
				}

				else if (TIMER_cnfg_arr[loop_index].EXTERNAL_CLK_EDGE==EX_rising)
				{
					TCCR1B = (TCCR1B & 0xF8) | EX_rising;
				}
				else
				{
					TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
				if(TIMER_cnfg_arr[loop_index].PRESCALER<MAX_CLK)
				{
					TCCR1B = (TCCR1B & 0xF8) | TIMER_cnfg_arr[loop_index].PRESCALER;
				}
				else
				{
					TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
				}
				else
				{
					TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
				if(TIMER_cnfg_arr[loop_index].INTERUPT == int_active)
				{
					TIMSK |= (1<<TOIE0);
				}
				else if(TIMER_cnfg_arr[loop_index].INTERUPT == int_not_active)
				{
					TIMSK &=~ (1<<TOIE1);
				}
				else
				{
					TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
			}
			else if(TIMER_cnfg_arr[loop_index].MODE == CTC &&TIMER_cnfg_arr[loop_index].MODE<MAX_T0_MODES )
			{TCCR0 = (1<<FOC0) | (1<<WGM01);
			TCNT0 = 0;
			OCR0=TIMER_cnfg_arr[loop_index].O_C_R1;
			if (TIMER_cnfg_arr[loop_index].CLK_SOURCE == internal)
			{
				if(TIMER_cnfg_arr[loop_index].PRESCALER<MAX_CLK)
				{

					TCCR0 =	(TCCR0 & 0xF8) | TIMER_cnfg_arr[loop_index].PRESCALER;
				}
				else
				{
					TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
			}

			else if (TIMER_cnfg_arr[loop_index].CLK_SOURCE == external)
			{ DDRB &= ~(1<<PB1);
			if(TIMER_cnfg_arr[loop_index].EXTERNAL_CLK_EDGE==EX_falling)
			{
				TCCR1B = (TCCR1B & 0xF8) | EX_falling;
			}

			else if (TIMER_cnfg_arr[loop_index].EXTERNAL_CLK_EDGE==EX_rising)
			{
				TCCR1B = (TCCR1B & 0xF8) | EX_rising;
			}
			else
			{
				TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
				retval = NOK;
			}
			if(TIMER_cnfg_arr[loop_index].PRESCALER<MAX_CLK)
			{
				TCCR1B = (TCCR1B & 0xF8) | TIMER_cnfg_arr[loop_index].PRESCALER;
			}
			else
			{
				TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
				retval = NOK;
			}
			}
			else
			{
				TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
				retval = NOK;
			}
			if(TIMER_cnfg_arr[loop_index].INTERUPT == int_active)
			{
				TIMSK |= (1<<OCIE0);
			}
			else if(TIMER_cnfg_arr[loop_index].INTERUPT == int_not_active)
			{
				TIMSK &=~ (1<<OCIE0);
			}
			else
			{
				TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
				retval = NOK;
			}

			}
			else
			{
				TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
				retval = NOK;
			}
			break;
		}


	}



	return retval;
}
