 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Regs.h
 *
 * Description: Header file for Dio Module Registers.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef _REGS_H
#define _REGS_H

#include "Std_Types.h"


/* Definition for PORTA Registers */
#define PORTA_REG	(*(volatile uint8 * const)0x003B)
#define DDRA_REG	(*(volatile uint8 * const)0x003A)
#define PINA_REG 	(*(volatile const uint8 * const)0x0039)

/* Definition for PORTB Registers */
#define PORTB_REG	(*(volatile uint8 * const)0x0038)
#define DDRB_REG	(*(volatile uint8 * const)0x0037)
#define PINB_REG 	(*(volatile const uint8 * const)0x0036)

/* Definition for PORTC Registers */
#define PORTC_REG	(*(volatile uint8 * const)0x0035)
#define DDRC_REG	(*(volatile uint8 * const)0x0034)
#define PINC_REG 	(*(volatile const uint8 * const)0x0033)

/* Definition for PORTD Registers */
#define PORTD_REG	(*(volatile uint8 * const)0x0032)
#define DDRD_REG	(*(volatile uint8 * const)0x0031)
#define PIND_REG 	(*(volatile const uint8 * const)0x0030)


/* Definition for TIMER0 Registers */
#define TCCR0_REG	(*(volatile uint8 * const)0x0053)
#define TCNT0_REG	(*(volatile uint8 * const)0x0052)
#define OCR0_REG	(*(volatile uint8 * const)0x005C)
#define TIMSK_REG	(*(volatile uint8 * const)0x0059)
#define TIFR_REG	(*(volatile uint8 * const)0x0058)
#define SFIOR_REG	(*(volatile uint8 * const)0x0050)
/* Definition for TIMER1 Registers */
#define TCCR1A_REG	(*(volatile uint8 * const)0x004F)
#define TCCR1B_REG	(*(volatile uint8 * const)0x004E)
#define TCNT1L_REG	(*(volatile uint8 * const)0x004C)
#define TCNT1H_REG	(*(volatile uint8 * const)0x004D)
#define OCR1AL_REG	(*(volatile uint8 * const)0x004A)
#define OCR1AH_REG	(*(volatile uint8 * const)0x004B)
#define OCR1BL_REG	(*(volatile uint8 * const)0x0048)
#define OCR1BH_REG	(*(volatile uint8 * const)0x0049)
#define ICR1L_REG	(*(volatile uint8 * const)0x0046)
#define ICR1H_REG	(*(volatile uint8 * const)0x0047)
/* Definition for TIMER2 Registers */
#define TCCR2_REG	(*(volatile uint8 * const)0x0045)
#define TCNT2_REG	(*(volatile uint8 * const)0x0044)
#define OCR2_REG	(*(volatile uint8 * const)0x0043)
#define ASSR_REG	(*(volatile uint8 * const)0x0042)

#define SREG_REG	(*(volatile uint8 * const)0x005F)



#endif /* _REGS_H */
