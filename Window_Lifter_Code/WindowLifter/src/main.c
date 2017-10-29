#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "HAL/initproyect.h"
#include "MAL/time100ms.h"
#include "MAL/time400ms.h"
#include "Mode_Routine.h"
#include "MAL/LEDS_IDLE.h"


#include "APP/Window_Lifter_Routine.h"


T_UBYTE lpit0_ch0_flag_counter = 0; /* LPIT0 chan 0 timeout counter */
int level=0;
T_UBYTE pushup=0;
T_UBYTE pushdown=0;



int main(void) {
 WDOG_DISABLE();
 FREQ_Config();
 NVIC_init_IRQs(); /* Enable desired interrupts and priorities */
 LPIT0_init(); /* Initialize PIT0*/
 EnablePCC ();
 WindowInit ();
 IndicatorsInit();
 ButtonsInit ();
 LEDS_IDLE();

 for (;;) {

while ( ( pushup == 0 ) && ( pushdown == 0 )  )
{
	 if (PUSHUP)
	 {
		 EnableTimer100ms();

		 while ( ( (PUSHUP) && (lpit0_ch0_flag_counter<5)) ) {} /*Do Nothing*/
		 	 	 DisableTimer100ms ();
		 		 if(lpit0_ch0_flag_counter>=5)
		 		 {
		 		 pushup=2; /*MANUAL_MODE_FLAG*/
		 		 }
		 		 else if( (lpit0_ch0_flag_counter<5) && (lpit0_ch0_flag_counter != 0) )
		 		 {
		 			 pushup=1; /*ONE_TOUCH_MODE_FLAG*/
		 		 }

	}


	 if (PUSHDOWN)
	 		 {

	 			 EnableTimer100ms();

	 			 		 while ( ( (PUSHDOWN) && (lpit0_ch0_flag_counter<5)) ) {} /*Do Nothing*/
	 			 		 	 	 DisableTimer100ms ();
	 			 		 		 if(lpit0_ch0_flag_counter>=5)
	 			 		 		 {
	 			 		 		 pushdown=2; /*MANUAL_MODE_FLAG*/
	 			 		 		 }
	 			 		 		 else if( (lpit0_ch0_flag_counter<5) && (lpit0_ch0_flag_counter != 0) )
	 			 		 		 {
	 			 		 			 pushdown=1; /*ONE_TOUCH_MODE_FLAG*/
	 			 		 		 }
	 		 }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	 if(pushup==1)
	 {
		 while(level<11 && pushup==1)
		 {
			 PTD-> PCOR |= 1<<PTD0; /* Clear Output on port D0 (LED on) */
			 DisableTimer100ms();
			 lpit0_ch0_flag_counter=0;
			 	 	 	 	 	 Up_Mode_Routine (&level);
		 		 		 		 EnableTimer400ms();
		 		 		 		 while (lpit0_ch0_flag_counter<1){}
		 		 		 		 DisableTimer400ms();
		 		 		 		 lpit0_ch0_flag_counter=0;
		 		 		 		 level++;
		 	if(ANTIPINCH)
		 	{
		 		DisableTimer100ms();
		 		lpit0_ch0_flag_counter=0;
		 		EnableTimer100ms();

		 		while ( ( (ANTIPINCH) && (lpit0_ch0_flag_counter<1)) ) {} /*Do Nothing*/
		 		DisableTimer100ms ();
		 		if(ANTIPINCH)
		 		{
		 			while(level>=1)
		 					 				 		 {
		 												 PTD-> PSOR |= 1<<PTD0; /* Clear Output on port D0 (LED on) */
		 												 PTD-> PCOR |= 1<<PTD15; /* Clear Output on port D16 (LED on) */
		 					 				 			 DisableTimer100ms();
		 					 				 			 lpit0_ch0_flag_counter=0;
		 					 				 			 	 	 	 	 	 Down_Mode_Routine (&level);
		 					 				 		 		 		 		 EnableTimer400ms();
		 					 				 		 		 		 		 while (lpit0_ch0_flag_counter<1){}
		 					 				 		 		 		 		 DisableTimer400ms();
		 					 				 		 		 		 		 lpit0_ch0_flag_counter=0;
		 					 				 		 		 		 		 level--;
		 					 				 		 }

		 					 				 		 if(level==0)
		 					 				 		 {
		 					 				 			 pushdown=0;
		 					 				 			 level=0;
		 					 				 			PTD-> PSOR |= 1<<PTD15; /* Clear Output on port D16 (LED on) */
		 					 				 			pushup=0;

		 					 				 		 }
		 			DisableTimer100ms();
		 			lpit0_ch0_flag_counter=0;
		 			EnableTimer100ms();
		 			while (lpit0_ch0_flag_counter<50)
		 			{
		 				/*Do nothing*/
		 			}
		 			pushup=0;
		 			pushdown=0;
		 			DisableTimer100ms();
		 			lpit0_ch0_flag_counter=0;
		 			level=0;
		 		}
		 	}
		 }

		 if(level>=11)
		 {
			 level=10;
			 pushup=0;
			 PTD-> PSOR |= 1<<PTD0; /* Clear Output on port D16 (LED on) */
		 }
	 }
/////////////////////                                     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////                                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 else if(pushup==2)
	 {
		 DisableTimer100ms();
		 lpit0_ch0_flag_counter=0;
		 while(PUSHUP)
		 		 {
			 	 PTD-> PCOR |= 1<<PTD0; /* Clear Output on port D0 (LED on) */
		 		 Up_Mode_Routine (&level);
		 		 		 		 		 EnableTimer400ms();
		 		 		 		 		 while (lpit0_ch0_flag_counter<1){}
		 		 		 		 		 DisableTimer400ms();
		 		 		 		 		 lpit0_ch0_flag_counter=0;
		 		 		 		 		 level++;
		 		 }
		 PTD-> PSOR |= 1<<PTD0; /* Clear Output on port D16 (LED on) */
		 if(level>=10)
		 {
			 level=10;
			 pushup=0;
		 }
		 else
		 {
			pushup=0;
		 }
	 }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	 else if (pushdown==1)
	 {

		 				 while(level>=1)
		 				 		 {
		 					 	 	 PTD-> PCOR |= 1<<PTD16; /* Clear Output on port D16 (LED on) */
		 				 			 DisableTimer100ms();
		 				 			 lpit0_ch0_flag_counter=0;
		 				 			 	 	 	 	 	 Down_Mode_Routine (&level);
		 				 		 		 		 		 EnableTimer400ms();
		 				 		 		 		 		 while (lpit0_ch0_flag_counter<1){}
		 				 		 		 		 		 DisableTimer400ms();
		 				 		 		 		 		 lpit0_ch0_flag_counter=0;
		 				 		 		 		 		 level--;
		 				 		 }

		 				 		 if(level==0)
		 				 		 {
		 				 			 pushdown=0;
		 				 			 level=0;
		 				 			PTD-> PSOR |= 1<<PTD16; /* Clear Output on port D16 (LED on) */

		 				 		 }

	 }

	 else if (pushdown==2)
	 {
		 	 	 	 	 while(PUSHDOWN)
		 		 				 		 {
		 	 	 	 		 	 	 	 	 PTD-> PCOR |= 1<<PTD16; /* Clear Output on port D16 (LED on) */
		 	 	 	 		 	 	 	 	 if(level !=0)
		 	 	 	 		 	 	 	 	 {
		 		 				 			 DisableTimer100ms();
		 		 				 			 lpit0_ch0_flag_counter=0;
		 		 				 			 	 	 	 	 	 Down_Mode_Routine (&level);
		 		 				 		 		 		 		 EnableTimer400ms();
		 		 				 		 		 		 		 while (lpit0_ch0_flag_counter<1){}
		 		 				 		 		 		 		 DisableTimer400ms();
		 		 				 		 		 		 		 lpit0_ch0_flag_counter=0;
		 		 				 		 		 		 		 level--;
		 	 	 	 		 	 	 	 	 }
		 		 				 		 }
		 	 	 	 	 	 	 	 	 PTD-> PSOR |= 1<<PTD16; /* Clear Output on port D16 (LED on) */

		 		 				 		 if(level==0)
		 		 				 		 {
		 		 				 			 pushdown=0;
		 		 				 			 level=0;
		 		 				 			 pushup=0;

		 		 				 		 }
		 		 				 		 else
		 		 				 		 {
		 		 				 			 pushdown=0;
		 		 				 		 }
	 }

}


}

void LPIT0_Ch0_IRQHandler (void) {
 lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
 //PTD->PTOR |= 1<<0; /* Toggle output on port D0 (blue LED) */
 //PTC->PTOR |= 1<<7; //C7
 LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
}
