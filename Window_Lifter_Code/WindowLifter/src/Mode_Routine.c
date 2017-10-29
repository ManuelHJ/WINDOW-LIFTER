#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "Mode_Routine.h"
#include "initproyect.h"
#include "MAL/Definitions.h"


void Down_Mode_Routine (int *window_level)

{
switch ( (*window_level) )

{

case 0: //PTD-> PSOR |= 1<<PTD0; /* Clear Output on port D0 (LED on) */
break;
case 1: PTE-> PSOR |= 1<<PTE1; /* Clear Output on port C7 (LED on) */
break;
case 2: PTC-> PSOR |= 1<<PTC14; /* Clear Output on port B17 (LED on) */
break;
case 3: PTE-> PSOR |= 1<<PTE14; /* Clear Output on port B14 (LED on) */
break;
case 4: PTE-> PSOR |= 1<<PTE15; /* Clear Output on port B15 (LED on) */
break;
case 5: PTE-> PSOR |= 1<<PTE16; /* Clear Output on port B16 (LED on) */
break;
case 6: PTB-> PSOR |= 1<<PTB16; /* Clear Output on port E16 (LED on) */
break;
case 7: PTB-> PSOR |= 1<<PTB15; /* Clear Output on port E15 (LED on) */
break;
case 8: PTB-> PSOR |= 1<<PTB14; /* Clear Output on port E14 (LED on) */
break;
case 9: PTB-> PSOR |= 1<<PTB17; /* Clear output on port C14 (POT)  (LED on) */
break;
case 10: PTC-> PSOR |= 1<<PTC7; /*Clear Output on port E1 (LED on) */
break;
default: //*window_level=0;
break;

}
 
}

void Up_Mode_Routine (int *window_level)
{
	switch ( (*window_level) ) {
					 case 0:
						 			 			 //PTD-> PCOR |= 1<<PTD0; /* Clear Output on port D0 (LED on) */

						 break;
					 case 1:
			 	 	 	 	 	 	 	 	 	 PTE-> PCOR |= 1<<PTE1; /*Clear Output on port E1 (LED on) */

						 break;
					 case 2:
						 	 	 	 	 	 	 PTC-> PCOR |= 1<<PTC14; /* Clear output on port C14 (POT)  (LED on) */

						 break;
					 case 3:
						 	 	 	 	 	 	 PTE-> PCOR |= 1<<PTE14; /* Clear Output on port E14 (LED on) */

						 break;
					 case 4:
						 	 	 	 	 	 	 PTE-> PCOR |= 1<<PTE15; /* Clear Output on port E15 (LED on) */

						 break;
					 case 5:
						 	 	 	 	 	 	 PTE-> PCOR |= 1<<PTE16; /* Clear Output on port E16 (LED on) */

						 break;
					 case 6:
						 	 	 	 	 	 	 PTB-> PCOR |= 1<<PTB16; /* Clear Output on port B16 (LED on) */

						 break;
					 case 7:
						 	 	 	 	 	 	 PTB-> PCOR |= 1<<PTB15; /* Clear Output on port B15 (LED on) */

						 break;
					 case 8:
						 	 	 	 	 	 	 PTB-> PCOR |= 1<<PTB14; /* Clear Output on port B14 (LED on) */


						 break;
					 case 9:
						 	 	 	 	 	 	 PTB-> PCOR |= 1<<PTB17; /* Clear Output on port B17 (LED on) */


						 break;
					 case 10:
						 	 	 	 	 	 	 PTC-> PCOR |= 1<<PTC7; /* Clear Output on port C7 (LED on) */


			  	  	  	  	  	  	  	  	  	  	  	  	 // *window_level=0;
						 break;

					 default:
						 	 	 	 	 	 	 *window_level=10;
						 break;

					 }
}
