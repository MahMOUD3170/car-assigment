#ifndef TIMER_H_
#define TIMER_H_


#include "manual_std_types.h"
#include "regs.h"
#include "timer_confg.h"

#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif
//typedef enum{NOK,OK}Std_Func_t;
uint8 TIMER_init (void);
uint8 TIMER_FAST_PWM (uint8 timer, uint16 duty);
/*void timer0_init_normal_mode(void);*/
#endif
