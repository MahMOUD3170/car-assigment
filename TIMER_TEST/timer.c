
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
				TCCR0=(TCCR0&0XCF)| (TIMER_cnfg_arr[loop_index].COMPARE_COND1 <<4);
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
					TCCR0 = (TCCR0 & 0xF8) | EX_falling;
				}

				else if (TIMER_cnfg_arr[loop_index].EXTERNAL_CLK_EDGE==EX_rising)
				{
					TCCR0 = (TCCR0 & 0xF8) | EX_rising;
				}
				else
				{
					TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
				if(TIMER_cnfg_arr[loop_index].PRESCALER<MAX_CLK)
				{
					TCCR0 = (TCCR0 & 0xF8) | TIMER_cnfg_arr[loop_index].PRESCALER;
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
					TIMSK &=~ (1<<TOIE0);
				}
				else
				{
					TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
			}
			else if(TIMER_cnfg_arr[loop_index].MODE == CTC &&TIMER_cnfg_arr[loop_index].MODE<MAX_T0_MODES )
			{TCNT0 = 0;
			TCCR0 = (1<<FOC0) | (1<<WGM01);
			if (TIMER_cnfg_arr[loop_index].COMPARE_COND1 <MAX_COMPARE)
			{
				TCCR0=(TCCR0&0XCF)| (TIMER_cnfg_arr[loop_index].COMPARE_COND1 <<4);
				if (TIMER_cnfg_arr[loop_index].O_C_R1 < T_MAX )
				{
					OCR0=TIMER_cnfg_arr[loop_index].O_C_R1;
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
				TCCR0 = (TCCR0 & 0xF8) | EX_falling;
			}

			else if (TIMER_cnfg_arr[loop_index].EXTERNAL_CLK_EDGE==EX_rising)
			{
				TCCR0 = (TCCR0 & 0xF8) | EX_rising;
			}
			else
			{
				TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
				retval = NOK;
			}
			if(TIMER_cnfg_arr[loop_index].PRESCALER<MAX_CLK)
			{
				TCCR0 = (TCCR0 & 0xF8) | TIMER_cnfg_arr[loop_index].PRESCALER;
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
			else if(TIMER_cnfg_arr[loop_index].MODE == FAST_PWM &&TIMER_cnfg_arr[loop_index].MODE<MAX_T0_MODES )
			{
				TCCR0 =(1<<WGM00) | (1<<WGM01);
				TCCR0 &=~(1<<FOC0);/*FOCO BINS WILL BE ZERO */
				TCNT0 = 0;
				/*SET THE MODE*/


				/*Set OUTPUT PIN for timer1 */
				if (TIMER_cnfg_arr[loop_index].OUTPUT_PINS==one_pin)
				{ DDRB  = DDRB | (1<<PB3);//set OC0 as output pin --> pin where the PWM signal is generated from MC
				if (TIMER_cnfg_arr[loop_index].COMPARE_COND1 <MAX_COMPARE)
				{
					TCCR0=(TCCR0&0XCF)| (TIMER_cnfg_arr[loop_index].COMPARE_COND1 <<4);
					if (TIMER_cnfg_arr[loop_index].O_C_R1 <=T_MAX )
					{ /*  Set the compare value IN  OCR0*/
						OCR0=TIMER_cnfg_arr[loop_index].O_C_R1; /*COMPARE VALUE IN OCR0*/
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
				}
				else
				{
					TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}

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
					TCCR0 = (TCCR0 & 0xF8) | EX_falling;
				}

				else if (TIMER_cnfg_arr[loop_index].EXTERNAL_CLK_EDGE==EX_rising)
				{
					TCCR0 = (TCCR0 & 0xF8) | EX_rising;
				}
				else
				{
					TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
				if(TIMER_cnfg_arr[loop_index].PRESCALER<MAX_CLK)
				{
					TCCR0 = (TCCR0 & 0xF8) | TIMER_cnfg_arr[loop_index].PRESCALER;
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
			}
			else if(TIMER_cnfg_arr[loop_index].MODE == PWM_PHASE &&TIMER_cnfg_arr[loop_index].MODE<MAX_T0_MODES )
			{
				TCCR0 =(1<<WGM00) ;
				TCCR0 &=~(1<<FOC0);/*FOCO BINS WILL BE ZERO */
				TCNT0 = 0;
				/*SET THE MODE*/


				/*Set OUTPUT PIN for timer1 */
				if (TIMER_cnfg_arr[loop_index].OUTPUT_PINS==one_pin)
				{ DDRB  = DDRB | (1<<PB3);//set OC0 as output pin --> pin where the PWM signal is generated from MC
				if (TIMER_cnfg_arr[loop_index].COMPARE_COND1 <MAX_COMPARE)
				{
					TCCR0=(TCCR0&0XCF)| (TIMER_cnfg_arr[loop_index].COMPARE_COND1 <<4);
					if (TIMER_cnfg_arr[loop_index].O_C_R1 <=T_MAX )
					{ /*  Set the compare value IN  OCR0*/
						OCR0=TIMER_cnfg_arr[loop_index].O_C_R1; /*COMPARE VALUE IN OCR0*/
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
				}
				else
				{
					TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}

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
					TCCR0 = (TCCR0 & 0xF8) | EX_falling;
				}

				else if (TIMER_cnfg_arr[loop_index].EXTERNAL_CLK_EDGE==EX_rising)
				{
					TCCR0 = (TCCR0 & 0xF8) | EX_rising;
				}
				else
				{
					TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
				if(TIMER_cnfg_arr[loop_index].PRESCALER<MAX_CLK)
				{
					TCCR0 = (TCCR0 & 0xF8) | TIMER_cnfg_arr[loop_index].PRESCALER;
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
			}
			else
			{
				TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
				retval = NOK;
			}



			break;
		case timer_2:
			if(TIMER_cnfg_arr[loop_index].MODE == NORMAL &&TIMER_cnfg_arr[loop_index].MODE<MAX_T0_MODES )
			{
				TCCR2 = (1<<FOC2) ;
				TCNT2 = 0;
				TCCR2=(TCCR2&0XCF)| (TIMER_cnfg_arr[loop_index].COMPARE_COND1 <<4);
				if (TIMER_cnfg_arr[loop_index].CLK_SOURCE == internal)
				{
					if(TIMER_cnfg_arr[loop_index].PRESCALER<MAX_T2_CLK)
					{

						TCCR2 =	(TCCR2 & 0xF8) | TIMER_cnfg_arr[loop_index].PRESCALER;
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
					TIMSK |= (1<<TOIE2);
				}
				else if(TIMER_cnfg_arr[loop_index].INTERUPT == int_not_active)
				{
					TIMSK &=~ (1<<TOIE2);
				}
				else
				{
					TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
			}
			else if(TIMER_cnfg_arr[loop_index].MODE == CTC &&TIMER_cnfg_arr[loop_index].MODE<MAX_T0_MODES )
			{TCNT2 = 0;
			TCCR2 = (1<<FOC2) | (1<<WGM21);
			if (TIMER_cnfg_arr[loop_index].COMPARE_COND1 <MAX_COMPARE)
			{
				TCCR2=(TCCR2&0XCF)| (TIMER_cnfg_arr[loop_index].COMPARE_COND1 <<4);
				if (TIMER_cnfg_arr[loop_index].O_C_R1 < T_MAX )
				{
					OCR2=TIMER_cnfg_arr[loop_index].O_C_R1;
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
			if (TIMER_cnfg_arr[loop_index].CLK_SOURCE == internal)
			{
				if(TIMER_cnfg_arr[loop_index].PRESCALER<MAX_T2_CLK)
				{

					TCCR2 =	(TCCR2 & 0xF8) | TIMER_cnfg_arr[loop_index].PRESCALER;
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
				TIMSK |= (1<<OCIE2);
			}
			else if(TIMER_cnfg_arr[loop_index].INTERUPT == int_not_active)
			{
				TIMSK &=~ (1<<OCIE2);
			}
			else
			{
				TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
				retval = NOK;
			}

			}
			else if(TIMER_cnfg_arr[loop_index].MODE == FAST_PWM &&TIMER_cnfg_arr[loop_index].MODE<MAX_T0_MODES )
			{
				TCCR2 =(1<<WGM20) | (1<<WGM21);
				TCCR2 &=~(1<<FOC2);/*FOCO BINS WILL BE ZERO */
				TCNT2 = 0;
				/*SET THE MODE*/


				/*Set OUTPUT PIN for timer1 */
				if (TIMER_cnfg_arr[loop_index].OUTPUT_PINS==one_pin)
				{ DDRB  = DDRD | (1<<PB7);//set OC0 as output pin --> pin where the PWM signal is generated from MC
				if (TIMER_cnfg_arr[loop_index].COMPARE_COND1 <MAX_COMPARE)
				{
					TCCR2=(TCCR2&0XCF)| (TIMER_cnfg_arr[loop_index].COMPARE_COND1 <<4);
					if (TIMER_cnfg_arr[loop_index].O_C_R1 <=T_MAX )
					{ /*  Set the compare value IN  OCR0*/
						OCR2=TIMER_cnfg_arr[loop_index].O_C_R1; /*COMPARE VALUE IN OCR0*/
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
				}
				else
				{
					TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}

				if (TIMER_cnfg_arr[loop_index].CLK_SOURCE == internal)
				{
					if(TIMER_cnfg_arr[loop_index].PRESCALER<MAX_T2_CLK)
					{

						TCCR2 =	(TCCR2 & 0xF8) | TIMER_cnfg_arr[loop_index].PRESCALER;
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
			}
			else if(TIMER_cnfg_arr[loop_index].MODE == PWM_PHASE &&TIMER_cnfg_arr[loop_index].MODE<MAX_T0_MODES )
			{
				TCCR2 =(1<<WGM20) ;
				TCCR2 &=~(1<<FOC2);/*FOCO BINS WILL BE ZERO */
				TCNT2 = 0;
				/*SET THE MODE*/


				/*Set OUTPUT PIN for timer1 */
				if (TIMER_cnfg_arr[loop_index].OUTPUT_PINS==one_pin)
				{ DDRD  = DDRD | (1<<PD7);//set OC0 as output pin --> pin where the PWM signal is generated from MC
				if (TIMER_cnfg_arr[loop_index].COMPARE_COND1 <MAX_COMPARE)
				{
					TCCR2=(TCCR2&0XCF)| (TIMER_cnfg_arr[loop_index].COMPARE_COND1 <<4);
					if (TIMER_cnfg_arr[loop_index].O_C_R1 <=T_MAX )
					{ /*  Set the compare value IN  OCR0*/
						OCR2=TIMER_cnfg_arr[loop_index].O_C_R1; /*COMPARE VALUE IN OCR0*/
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
				}
				else
				{
					TIMER_cnfg_arr[loop_index].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}

				if (TIMER_cnfg_arr[loop_index].CLK_SOURCE == internal)
				{
					if(TIMER_cnfg_arr[loop_index].PRESCALER<MAX_T2_CLK)
					{

						TCCR2 =	(TCCR2 & 0xF8) | TIMER_cnfg_arr[loop_index].PRESCALER;
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
