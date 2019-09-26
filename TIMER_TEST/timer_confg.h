#ifndef TIMER_CNFG_H
#define TIMER_CNFG_H
#include "data_types.h"
#define NUM_OF_TIMERS   3

//timer
#define timer_0	    	0
#define timer_1	    	1
#define timer_2		    2

//modes
typedef enum
{
	NORMAL,PWM_PHASE,CTC,FAST_PWM,MAX_T0_MODES
}T_MODES;
typedef enum
{
	T1_NORMAL,PWM_PHASE_8,PWM_PHASE_9,PWM_PHASE_10,CTC_OCR1A,FAST_PWM_8,FAST_PWM_9,FAST_PWM_10,
	PWM_PHASE_FREQ_ICR1,PWM_PHASE_FREQ_OCR1A,PWM_PHASE_ICR1,PWM_PHASE_OCR1A,CTC_ICR1,RESERVED,FAST_PWM_ICR1,FAST_PWM_OCR1A,MAX_T1_MODES
}T1_MODES;



//interrupt
#define int_active		    1
#define int_not_active		0

//prescaler
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024,MAX_CLK
}Icu_Clock;

typedef enum
{
	T2_NO_CLOCK,T2_F_CPU_CLOCK,T2_F_CPU_8,T2_F_CPU_32,T2_F_CPU_64,T2_F_CPU_128,T2_F_CPU_256,T2_F_CPU_1024,MAX_T2_CLK
}Icu_T2_Clock;

//output compare reg./*
/*#define ctc		       0
#define pwm			   1
 */
//internal or ext. clock
#define internal	   0
#define external	   1

//COMPARE PINS
typedef enum
{
	NORMAL_C,TOGGLE_C,CLEAR_C,COMPARE_C,MAX_COMPARE
}COMPARE_BITS;

//typedef enum
/*{
	OVERFLOW_T1=2,COMPARE_B_T1=3,COMPARE_A_T2=4,MAX_T1_INTER
}T1_INTER;
*///icu
#define ICU_active			1
#define ICU_not_active		0

//icu EDGE
#define rising  1
#define falling 0

//external clk edge
#define EX_falling   6
#define EX_rising    7
//RTC
#define RTC_off        0
#define RTC_on         0

//output pins
#define one_pin        0
#define two_pins       1

#define NA			0xff
#define T1_MAX      0XFFFF
#define T_MAX       256

#define INITIALIZED			1
#define NOT_INITIALIZED		0
typedef struct
{
	UINT8 TIMER;
	UINT8 MODE;
	UINT8 OUTPUT_PINS;
	COMPARE_BITS COMPARE_COND1 ;
	/*COMPARE_BITS COMPARE_COND2 ;
	*/UINT8 O_C_R1;
	/*UINT16 O_C_R2;*/
	/*UINT16 ICR;*/
	UINT8 CLK_SOURCE;
	UINT8 EXTERNAL_CLK_EDGE;
	Icu_Clock PRESCALER;
	UINT8 INTERUPT;/*
	UINT8 ICU;
	UINT8 EDGE;*/
	UINT8 IS_init_arr;
}TIMER_cnfg;

extern TIMER_cnfg TIMER_cnfg_arr [NUM_OF_TIMERS];



#endif /* TIMER_CNFG_H_ */
