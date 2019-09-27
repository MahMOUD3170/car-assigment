#include "timer_confg.h"

TIMER_cnfg TIMER_cnfg_arr [NUM_OF_TIMERS] =

{
	{timer_0,CTC,NA,NORMAL_C,125,internal,NA,F_CPU_1024,int_active,INITIALIZED},
	{timer_2,NORMAL,NA,NORMAL_C,NA,internal,NA,T2_F_CPU_1024,int_active,INITIALIZED}
};
//{timer_1,T1_NORMAL,NA,CLEAR_C,250,internal,NA,F_CPU_1024,int_active,INITIALIZED},
