#include "S32K144.h"
#include "HAL/initproyect.h"

void EnablePCC (void){

 PCC-> PCCn[PCC_PORTA_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT A */
 PCC-> PCCn[PCC_PORTB_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT B */
 PCC-> PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT C */
 PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
 PCC-> PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT E */
}

void NVIC_init_IRQs (void) {
 S32_NVIC->ICPR[1] = 1 << (48 % 32); /* IRQ48-LPIT0 ch0: clr any pending IRQ*/
 S32_NVIC->ISER[1] = 1 << (48 % 32); /* IRQ48-LPIT0 ch0: enable IRQ */
 S32_NVIC->IP[48] =0x0A; /* IRQ48-LPIT0 ch0: priority 10 of 0-15*/
}

void WindowInit (void){

 PTB->PDDR |= 1<<PTB17; /* Port B17: Data Direction= output */
 PTB->PDDR |= 1<<PTB14; /* Port B14: Data Direction= output */
 PTB->PDDR |= 1<<PTB15; /* Port B15: Data Direction= output */
 PTB->PDDR |= 1<<PTB16; /* Port B16: Data Direction= output */
 PORTB->PCR[PTB17] = 0x00000100; /* Port B17: MUX , GPIO  */
 PORTB->PCR[PTB14] = 0x00000100; /* Port B14: MUX , GPIO  */
 PORTB->PCR[PTB15] = 0x00000100; /* Port B15: MUX , GPIO  */
 PORTB->PCR[PTB16] = 0x00000100; /* Port B16: MUX , GPIO  */



 PTC->PDDR |= 1<<PTC7; /* Port C7: Data Direction= output */
 PTC->PDDR |= 1<<PTC6; /* Port C6: Data Direction= output */
 PTC->PDDR |= 1<<PTC14; /* Port C14: Data Direction= output */
 PTC->PDDR |= 1<<PTC3; /* Port C3: Data Direction= output */
 PORTC->PCR[PTC7] = 0x00000100; /* Port C7: MUX , GPIO  */
 PORTC->PCR[PTC6] = 0x00000100; /* Port C6: MUX , GPIO  */
 PORTC->PCR[PTC14] = 0x00000100; /* Port C14: MUX , GPIO  */
 PORTC->PCR[PTC3] = 0x00000100; /* Port C3: MUX , GPIO  */


 PTE->PDDR |= 1<<PTE16; /* Port E16: Data Direction= output */
 PTE->PDDR |= 1<<PTE15; /* Port E15: Data Direction= output */
 PTE->PDDR |= 1<<PTE14; /* Port E14: Data Direction= output */
 PTE->PDDR |= 1<<PTE13; /* Port E13: Data Direction= output */
 PTE->PDDR |= 1<<PTE1; /* Port E1: Data Direction= output */

 PORTE->PCR[PTE16] = 0x00000100; /* Port E16: MUX , GPIO  */
 PORTE->PCR[PTE15] = 0x00000100; /* Port E15: MUX , GPIO  */
 PORTE->PCR[PTE14] = 0x00000100; /* Port E14: MUX , GPIO  */
 PORTE->PCR[PTE13] = 0x00000100; /* Port E13: MUX , GPIO  */
 PORTE->PCR[PTE1] = 0x00000100; /* Port E1: MUX , GPIO  */


}


void IndicatorsInit (void){
 PTD->PDDR |= 1<<PTD0; /* Port D0: Data Direction= output */
 PTD->PDDR |= 1<<PTD16; /* Port D16: Data Direction= output */
 PTD->PDDR |= 1<<PTD15; /* Port D16: Data Direction= output */
 PORTD->PCR[PTD0] = 0x00000100; /* Port D0: MUX , GPIO  */
 PORTD->PCR[PTD16] = 0x00000100; /* Port D16: MUX , GPIO  */
 PORTD->PCR[PTD15] = 0x00000100; /* Port D16: MUX , GPIO  */

 PTD->PSOR |= 1<<PTD0; /* clear pin */
 PTD->PSOR |= 1<<PTD16; /* clear pin */
}

void ButtonsInit (void){

 PTC->PDDR &= ~(1<<PTC12); /* Port C12: Data Direction= input (default) */
 PORTC->PCR[PTC12] = 0x00000110; /* Port C12: MUX = GPIO, input filter enabled */

 PTC->PDDR &= ~(1<<PTC13); /* Port C13: Data Direction= input (default) */
 PORTC->PCR[PTC13] = 0x00000110; /* Port C12: MUX = GPIO, input filter enabled */

 PTD->PDDR &= ~(1<<PTD7); /* Port C13: Data Direction= input (default) */
 PORTD->PCR[PTD7] = 0x00000110; /* Port C12: MUX = GPIO, input filter enabled */

}


void LPIT0_init (void) {
 PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(6); /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
 PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clk to LPIT0 regs */
 LPIT0->MCR = 0x00000001; /* DBG_EN-0: Timer chans stop in Debug mode */
 /* DOZE_EN=0: Timer chans are stopped in DOZE mode */
/* SW_RST=0: SW reset does not reset timer chans, regs */
 /* M_CEN=1: enable module clk (allow writing other LPIT0 regs) */
 LPIT0->MIER = 0x00000001; /* TIE0=1: Timer Interrupt Enabled fot Chan 0 */
 LPIT0->TMR[0].TVAL = 4000000; /* Chan 0 Timeout period: clocks */ //1 segundo es 40000000 POR LO QUE 100 ms es 4000000
 LPIT0->TMR[0].TCTRL = 0x00000000; /* T_EN=1: Timer channel is enabled 0x00000001 */
 LPIT0->TMR[1].TVAL = 4000000;
 LPIT0->TMR[1].TCTRL = 0x00000000;

 /* CHAIN=0: channel chaining is disabled */
/* MODE=0: 32 periodic counter mode */
/* TSOT=0: Timer decrements immediately based on restart */
/* TSOI=0: Timer does not stop after timeout */
/* TROT=0 Timer will not reload on trigger */
/* TRG_SRC=0: External trigger source */
/* TRG_SEL=0: Timer chan 0 trigger source is selected*/
}
