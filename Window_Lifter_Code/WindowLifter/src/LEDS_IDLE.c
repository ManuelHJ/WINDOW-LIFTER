#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "LEDS_IDLE.h"
#include "initproyect.h"

void LEDS_IDLE (void){

 PTD-> PSOR |= 1<<PTD0; /* Set Output on port D0 (LED off) */
 PTD-> PSOR |= 1<<PTD16; /* Set Output on port D16 (LED off) */	
 PTC-> PSOR |= 1<<PTC3; /* Set Output on port C3 (LED off) */
 PTC-> PSOR |= 1<<PTC14; /* Set Output on port C14 (LED off) */
 PTB-> PSOR |= 1<<PTB16; /* Set Output on port B16 (LED off) */
 PTB-> PSOR |= 1<<PTB15; /* Set Output on port B15 (LED off) */
 PTB-> PSOR |= 1<<PTB14; /* Set Output on port B14 (LED off) */
 PTB-> PSOR |= 1<<PTB17; /* Set Output on port B17 (LED off) */
 PTC-> PSOR |= 1<<PTC6; /* Set Output on port C6 (LED off) */
 PTC-> PSOR |= 1<<PTC7; /* Set Output on port C7 (LED off) */
 PTE-> PSOR |= 1<<PTE16; /* Set Output on port A4 (LED off) */
 PTE-> PSOR |= 1<<PTE15; /* Set Output on port A10 (LED off) */
 PTE-> PSOR |= 1<<PTE14; /* Set Output on port E14 (LED off) */
 PTE-> PSOR |= 1<<PTE13; /* Set Output on port E13 (LED off) */
 PTE-> PSOR |= 1<<PTE1; /*Set Output on port E1 (LED off) */

}
