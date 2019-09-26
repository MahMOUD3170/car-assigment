#ifndef TIMER_H_
#define TIMER_H_

#include "data_types.h"
#include "timer_confg.h"
#include "regester file.h"
#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif
typedef enum{NOK,OK}Std_Func_t;
Std_Func_t TIMER_init (void);
//void timer0_init_normal_mode(void);
#endif
