/*
 * regs.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: COMPUTER SHOW
 */

#ifndef REGS_H_
#define REGS_H_

/* Definition for PORTA Registers */
#define PORTA	(*(volatile uint8 * const)0x003B)
#define DDRA	(*(volatile uint8 * const)0x003A)
#define PINA 	(*(volatile const uint8 * const)0x0039)

/* Definition for PORTB Registers */
#define PORTB	(*(volatile uint8 * const)0x0038)
#define DDRB	(*(volatile uint8 * const)0x0037)
#define PINB 	(*(volatile const uint8 * const)0x0036)

/* Definition for PORTC Registers */
#define PORTC	(*(volatile uint8 * const)0x0035)
#define DDRC	(*(volatile uint8 * const)0x0034)
#define PINC 	(*(volatile const uint8 * const)0x0033)

/* Definition for PORTD Registers */
#define PORTD	(*(volatile uint8 * const)0x0032)
#define DDRD	(*(volatile uint8 * const)0x0031)
#define PIND 	(*(volatile const uint8 * const)0x0030)


/* Definition for TIMER0 Registers */
#define TCCR0	(*(volatile uint8 * const)0x0053)
#define TCNT0	(*(volatile uint8 * const)0x0052)
#define OCR0	(*(volatile uint8 * const)0x005C)
#define TIMSK	(*(volatile uint8 * const)0x0059)
#define TIFR	(*(volatile uint8 * const)0x0058)
#define SFIOR	(*(volatile uint8 * const)0x0050)
/* Definition for TIMER1 Registers */
#define TCCR1A	(*(volatile uint8 * const)0x004F)
#define TCCR1B	(*(volatile uint8 * const)0x004E)
#define TCNT1L	(*(volatile uint8 * const)0x004C)
#define TCNT1H	(*(volatile uint8 * const)0x004D)
#define OCR1AL	(*(volatile uint8 * const)0x004A)
#define OCR1AH	(*(volatile uint8 * const)0x004B)
#define OCR1BL	(*(volatile uint8 * const)0x0048)
#define OCR1BH	(*(volatile uint8 * const)0x0049)
#define ICR1L	(*(volatile uint8 * const)0x0046)
#define ICR1H	(*(volatile uint8 * const)0x0047)
/* Definition for TIMER2 Registers */
#define TCCR2	(*(volatile uint8 * const)0x0045)
#define TCNT2	(*(volatile uint8 * const)0x0044)
#define OCR2	(*(volatile uint8 * const)0x0043)
#define ASSR	(*(volatile uint8 * const)0x0042)

#define SREG	(*(volatile uint8 * const)0x005F)

/*timer 0 pins*/
#define CS00     0
#define CS01     1
#define CS02     2
#define WGM01    3
#define COM00    4
#define COM01    5
#define WGM00    6
#define FOC0     7
#define TOIE0    0
#define OCIE0    1
#define TOV0      0
#define OCF0      1
#define PSR10    0
/*timer 1 pins*/
#define WGM10     0
#define WGM11     1
#define FOC1B     2
#define FOC1A     3
#define COM1B0    4
#define COM1B1    5
#define TCCR1A_COM1A0    6
#define COM1A1    7
#define CS10      0
#define CS11      1
#define CS12      2
#define WGM12     3
#define WGM13     4
#define RESERVED  5
#define ICES1     6
#define ICNC1     7
#define TOIE1      2
#define OCIE1B     3
#define OCIE1A     4
#define TICIE1     5
#define TOV1      2
#define OCF1B     3
#define OCF1A     4
#define ICF1      5
/*timer 2 pins*/
#define CS20     0
#define CS21     1
#define CS22     2
#define WGM21    3
#define COM20    4
#define COM21    5
#define WGM20    6
#define FOC2     7
#define TOIE2    6
#define OCIE2    7
#define TOV2      6
#define OCF2      7

#define SREG_I_BIT      7

/*general definitions*/
#define OUTPUT		1
#define INPUT		0

#define HIGH		1
#define LOW			0

#define ON			1
#define OFF			0


#define INITIALIZED			1
#define NOT_INITIALIZED		0

#define NA			0xff

#endif /* REGS_H_ */
