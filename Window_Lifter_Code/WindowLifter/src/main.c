#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "initproyect.h"
#include "clocks_and_modes.h"



int  lpit0_ch0_flag_counter=0;



void WDOG_disable (void){
 WDOG->CNT=0xD928C520; /*Unlock watchdog*/
 WDOG->TOVAL=0x0000FFFF; /*Maximum timeout value*/
 WDOG->CS = 0x00002100; /*Disable watchdog*/
}

int main(void) {
 WDOG_disable();
 SOSC_init_8MHz(); /* Initialize system oscillator for 8 MHz xtal */
 SPLL_init_160MHz(); /* Initialize SPLL to 160 MHz with 8 MHz SOSC */
 NormalRUNmode_80MHz(); /* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
 NVIC_init_IRQs(); /* Enable desired interrupts and priorities */
 LPIT0_init(); /* Initialize PIT0*/
 EnablePCC ();
 WindowInit ();
 IndicatorsInit();
 ButtonsInit ();

 PTD-> PSOR |= 1<<PTD0; /* Set Output off */ //Need to SET the LEDS (The default value is Clear (ON))
 PTD-> PSOR |= 1<<PTD16; /* Set Output off */ //Need to SET the LEDS (The default value is Clear (ON))
 PTD-> PSOR |= 1<<PTD15; /* Set Output off */ //Need to SET the LEDS (The default value is Clear (ON))

 for (;;) {

	 	 if (PUSHUP)
	 	 {
	 		PTD-> PCOR |= 1<<PTD0; /* Clear Output on */
	 	 }
	 	 else
	 	 {
	 		PTD-> PSOR |= 1<<PTD0; /* Set Output off */
	 	 }

 }
}

void LPIT0_Ch0_IRQHandler (void) {
 lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
 //PTD->PTOR |= 1<<0; /* Toggle output on port D0 (blue LED) */
 //PTC->PTOR |= 1<<7; //C7
 LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
}
