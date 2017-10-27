#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "initproyect.h"
#include "clocks_and_modes.h"
#include "time100ms.h"
#include "time400ms.h"
#include "Mode_Routine.h"



int lpit0_ch0_flag_counter = 0; /* LPIT0 chan 0 timeout counter */
int one_touch_mode_flag=0;
int manual_mode_flag=0;
int level=0;
int pushup=0;





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

 for (;;) {

	 if ( PUSHUP)
	 {
		 EnableTimer100ms();
		 while (lpit0_ch0_flag_counter<2)
		 {
			 /*Do nothing*/
		 }

	}
		 if(lpit0_ch0_flag_counter>=2)
		 {
		 pushup=2;
		 }
		 else if( (lpit0_ch0_flag_counter<2) && (lpit0_ch0_flag_counter != 0) )
		 {
			 pushup=1;
		 }
/////////////////////////////////////////////////////////////////////////////////////////////////////////

		 if( pushup == 2 )
		 {


			 //One_Touch_Routine ();
			 one_touch_mode_flag =0;
			 DisableTimer100ms ();
			 lpit0_ch0_flag_counter=0;



			 One_Touch_Routine();

			 EnableTimer400ms ();

			 while (lpit0_ch0_flag_counter<1){}
			 DisableTimer400ms ();
			 lpit0_ch0_flag_counter=0;
			 level++;

			 if(level > 10)
			 {
				 pushup=0;
				 level=0;
			 }

			 	 	 	// one_touch_mode_flag =0;
			 			 //DisableTimer100ms ();
			 			 //lpit0_ch0_flag_counter=0;

			 			 //PTD-> PCOR |= 1<<PTD0; /* Clear Output on port D0 (LED on) */

			 			  //EnableTimer400ms ();

			 			  //while (lpit0_ch0_flag_counter<1){}

			 			  //DisableTimer400ms ();
			 			  //lpit0_ch0_flag_counter=0;
			 			  //level++;

			 //if (level==1)
			 // {

			 //PTE-> PCOR |= 1<<PTE1; /*Clear Output on port E1 (LED on) */

			 //	 EnableTimer400ms ();

			 // while (lpit0_ch0_flag_counter<1){}

			 // DisableTimer400ms ();
			 // lpit0_ch0_flag_counter=0;
			 // level++;
			 //  }

			 //  if(level==2)
			 //  {

			 // PTC-> PCOR |= 1<<PTC14; /* Clear output on port C14 (POT)  (LED on) */


			 // 	 	 	      EnableTimer400ms ();

			 //		 			  while (lpit0_ch0_flag_counter<1){}

			 //		 			  DisableTimer400ms ();
			 // 			 			  lpit0_ch0_flag_counter=0;
			 //  }



		 }

		 	 if(pushup == 0)
		 	 {
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

			 		 		EnableTimer400ms ();

			 		 					 			 			 			  while (lpit0_ch0_flag_counter<1){}

			 		 					 			 			 			  DisableTimer400ms ();
			 		 					 			 			 			  lpit0_ch0_flag_counter=0;
		 	 }



}
}

void LPIT0_Ch0_IRQHandler (void) {
 lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
 //PTD->PTOR |= 1<<0; /* Toggle output on port D0 (blue LED) */
 //PTC->PTOR |= 1<<7; //C7
 LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
}

void One_Touch_Routine () {
	switch (level)
				 {
				 case 0:
					 	 	 	 	 	     one_touch_mode_flag =0;
					 			 			 DisableTimer100ms ();
					 			 			 lpit0_ch0_flag_counter=0;

					 			 			 PTD-> PCOR |= 1<<PTD0; /* Clear Output on port D0 (LED on) */

					 			 			  EnableTimer400ms ();

					 			 			  while (lpit0_ch0_flag_counter<1){}

					 			 			  DisableTimer400ms ();
					 			 			  lpit0_ch0_flag_counter=0;
					 			 			  level++;
					 break;
				 case 1:
					 	 	 	 	 	 	 	 	 	 PTE-> PCOR |= 1<<PTE1; /*Clear Output on port E1 (LED on) */

					 			 			 	 	 	 EnableTimer400ms ();

					 			 			 			  while (lpit0_ch0_flag_counter<1){}

					 			 			 			  DisableTimer400ms ();
					 			 			 			  lpit0_ch0_flag_counter=0;
					 			 			 			  level++;
					 break;
				 case 2:
					 	 	 	 	 	 	 	 	 	  PTC-> PCOR |= 1<<PTC14; /* Clear output on port C14 (POT)  (LED on) */


					 			 			 	 	      EnableTimer400ms ();

					 			 			 			  while (lpit0_ch0_flag_counter<1){}

					 			 			 			  DisableTimer400ms ();
					 			 			 			  lpit0_ch0_flag_counter=0;
					 			 			 			  level++;
					 break;
				 case 3:	   							  PTE-> PCOR |= 1<<PTE14; /* Clear Output on port E14 (LED on) */


		 	 	      	  	  	  	  	  	  	  	  	  EnableTimer400ms ();

		 	 	      	  	  	  	  	  	  	  	  	  while (lpit0_ch0_flag_counter<1){}

		 	 	      	  	  	  	  	  	  	  	  	  DisableTimer400ms ();
		 	 	      	  	  	  	  	  	  	  	  	  lpit0_ch0_flag_counter=0;
		 	 	      	  	  	  	  	  	  	  	  	  level++;
					 break;
				 case 4:								  PTE-> PCOR |= 1<<PTE15; /* Clear Output on port E15 (LED on) */

		  	  	  	  	  	  	  	  	  	  	  	  	  EnableTimer400ms ();

		  	  	  	  	  	  	  	  	  	  	  	  	  while (lpit0_ch0_flag_counter<1){}

		  	  	  	  	  	  	  	  	  	  	  	  	  DisableTimer400ms ();
		  	  	  	  	  	  	  	  	  	  	  	  	  lpit0_ch0_flag_counter=0;
		  	  	  	  	  	  	  	  	  	  	  	  	  level++;
					 break;
				 case 5:								  PTE-> PCOR |= 1<<PTE16; /* Clear Output on port E16 (LED on) */

	 	  	  	  	  	  	  	  	  	  	  	  	  	  EnableTimer400ms ();

	 	  	  	  	  	  	  	  	  	  	  	  	  	  while (lpit0_ch0_flag_counter<1){}

	 	  	  	  	  	  	  	  	  	  	  	  	  	  DisableTimer400ms ();
	 	  	  	  	  	  	  	  	  	  	  	  	  	  lpit0_ch0_flag_counter=0;
	 	  	  	  	  	  	  	  	  	  	  	  	  	  level++;
					 break;
				 case 6:								  PTB-> PCOR |= 1<<PTB16; /* Clear Output on port B16 (LED on) */

	  	  	  	  	  	  	  	  	  	  	  	  	  	  EnableTimer400ms ();

	  	  	  	  	  	  	  	  	  	  	  	  	  	  while (lpit0_ch0_flag_counter<1){}

	  	  	  	  	  	  	  	  	  	  	  	  	  	  DisableTimer400ms ();
	  	  	  	  	  	  	  	  	  	  	  	  	  	  lpit0_ch0_flag_counter=0;
	  	  	  	  	  	  	  	  	  	  	  	  	  	  level++;
					 break;
				 case 7:								  PTB-> PCOR |= 1<<PTB15; /* Clear Output on port B15 (LED on) */

		  	  	  	  	  	  	  	  	  	  	  	  	  EnableTimer400ms ();

		  	  	  	  	  	  	  	  	  	  	  	  	  while (lpit0_ch0_flag_counter<1){}

		  	  	  	  	  	  	  	  	  	  	  	  	  DisableTimer400ms ();
		  	  	  	  	  	  	  	  	  	  	  	  	  lpit0_ch0_flag_counter=0;
		  	  	  	  	  	  	  	  	  	  	  	  	  level++;
					 break;
				 case 8:								  PTB-> PCOR |= 1<<PTB14; /* Clear Output on port B14 (LED on) */

				 	 	 	 	 	 	 	 	 	 	  EnableTimer400ms ();

				 	 	 	 	 	 	 	 	 	 	  while (lpit0_ch0_flag_counter<1){}

				 	 	 	 	 	 	 	 	 	 	  DisableTimer400ms ();
				 	 	 	 	 	 	 	 	 	 	  lpit0_ch0_flag_counter=0;
				 	 	 	 	 	 	 	 	 	 	  level++;
					 break;
				 case 9:								  PTB-> PCOR |= 1<<PTB17; /* Clear Output on port B17 (LED on) */

		 	 	 	 	  	  	  	  	  	  	  	  	  EnableTimer400ms ();

		 	 	 	 	  	  	  	  	  	  	  	  	  while (lpit0_ch0_flag_counter<1){}

		 	 	 	 	  	  	  	  	  	  	  	  	  DisableTimer400ms ();
		 	 	 	 	  	  	  	  	  	  	  	  	  lpit0_ch0_flag_counter=0;
		 	 	 	 	  	  	  	  	  	  	  	  	  level++;
					 break;
				 case 10:								  PTC-> PCOR |= 1<<PTC7; /* Clear Output on port C7 (LED on) */

		  	  	  	  	  	  	  	  	  	  	  	  	  EnableTimer400ms ();

		  	  	  	  	  	  	  	  	  	  	  	  	  while (lpit0_ch0_flag_counter<1){}

		  	  	  	  	  	  	  	  	  	  	  	  	  DisableTimer400ms ();
		  	  	  	  	  	  	  	  	  	  	  	  	  lpit0_ch0_flag_counter=0;
		  	  	  	  	  	  	  	  	  	  	  	  	  level=0;
		  	  	  	  	  	  	  	  	 			 	  pushup=0;

					 break;

				 default:
					 level=0;
					 break;

				 }
}
