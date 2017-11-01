/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: main.c $
 * $Revision: version 1 $
 * $Author: Guillermo Hern�ndez $
 * $Date: 10/31/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/**

    "main.c"Main File of the Window Lifter Code.
    Here�s the logical sequences of the code.

*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  AUTHOR             |       VERSION      |          DESCRIPTION            */
/*----------------------------------------------------------------------------*/
/* Guillermo Hern�ndez |         1          | Template & Description Added    */
/*                     |                    |         to the file             */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: main.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/

#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "HAL/initproyect.h"
#include "MAL/time100ms.h"
#include "MAL/time400ms.h"
#include "Mode_Routine.h"
#include "MAL/LEDS_IDLE.h"

#include "APP/Window_Lifter_Routine.h"

/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/

T_UBYTE lpit0_ch0_flag_counter = 0; /* LPIT0 chan 0 timeout counter */
int level=0;
T_UBYTE pushup=0;
T_UBYTE pushdown=0;


/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/

/** Check if action is allowed by overload protection.
 To avoid overheating of the door locking motors and hardware failure
 the software shall limit the number of activations in a short period.
 This function checks if the limitation algorithm allows or not
 a certain activation of the motors.
 \returns TRUE if the activation is allowed, FALSE if not
*/



/* Exported functions */
/*============================================================================*/

int main(void) {
 WDOG_DISABLE(); /*WathcDog Config*/
 FREQ_Config(); /*Freq. Config*/
 NVIC_init_IRQs(); /* Enable desired interrupts and priorities */
 LPIT0_init(); /* Initialize PIT0 (TIMER)*/
 EnablePCC (); /*Enable clock to Ports*/
 WindowInit ();/*Enable & Configure Window Ports (LED�s)*/
 IndicatorsInit();/*Enable & Configure Ports (Indicator LED�s)*/
 ButtonsInit ();/*Enable & Configure Buttons*/
 LEDS_IDLE();/*Configure LEDS as IDLE (Off)*/

 for (;;) {

while ( ( pushup == 0 ) && ( pushdown == 0 )  ) /*While non Mode_Routine is selected*/
{
	 if (PUSHUP) /*If PushButton UP was pressed */
	 {
		 EnableTimer100ms(); /*Enable Timer with freq. 100ms*/

		 while ( ( (PUSHUP) && (lpit0_ch0_flag_counter<5)) ) {} /*Do Nothing*/
		 	 	 DisableTimer100ms ();  /*Disable Timer with freq. 100ms*/
		 		 if(lpit0_ch0_flag_counter>=5) /*If the TIMER counter>5 (500ms)*/
		 		 {
		 		 pushup=2; /*MANUAL_MODE_FLAG*/
		 		 }
		 		 else if( (lpit0_ch0_flag_counter<5) && (lpit0_ch0_flag_counter != 0) ) /*If the TIMER counter<5 (500ms) && the TIMER counter!=0 (0ms) */
		 		 {
		 			 pushup=1; /*ONE_TOUCH_MODE_FLAG*/
		 		 }

	}


	 if (PUSHDOWN) /*If PushButton Down was pressed */
	 		 {

	 			 EnableTimer100ms(); /*Enable Timer with freq. 100ms*/

	 			 		 while ( ( (PUSHDOWN) && (lpit0_ch0_flag_counter<5)) ) {} /*Do Nothing*/
	 			 		 	 	 DisableTimer100ms (); /*Disable Timer with freq. 100ms*/
	 			 		 		 if(lpit0_ch0_flag_counter>=5) /*If the TIMER counter>5 (500ms)*/
	 			 		 		 {
	 			 		 		 pushdown=2; /*MANUAL_MODE_FLAG*/
	 			 		 		 }
	 			 		 		 else if( (lpit0_ch0_flag_counter<5) && (lpit0_ch0_flag_counter != 0) ) /*If the TIMER counter<5 (500ms) && the TIMER counter!=0 (0ms) */
	 			 		 		 {
	 			 		 			 pushdown=1; /*ONE_TOUCH_MODE_FLAG*/
	 			 		 		 }
	 		 }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	 if(pushup==1) /*One_Touch_Mode Activation*/
	 {
		 while(level<11 && pushup==1) /*While the window level (level) < 11 (All Up) && (One_Touch_Mode_Flag==1)*/
		 {
			 PTD-> PCOR |= 1<<PTD0; /* Clear Output on port D0 (LED BLUE on) as Indicator */
			 DisableTimer100ms(); /*Disable Timer with freq. 100ms*/
			 lpit0_ch0_flag_counter=0; /*Clear Timer Counter*/
			 	 	 	 	 	 Up_Mode_Routine (&level); /*Activate Up mode Routine "Switch-case" (evaluating the level)*/
		 		 		 		 EnableTimer400ms(); /*Enable Timer 400ms*/
		 		 		 		 while (lpit0_ch0_flag_counter<1){} /*Do Nothing*/
		 		 		 		 DisableTimer400ms(); /*Disable Timer 400ms*/
		 		 		 		 lpit0_ch0_flag_counter=0; /*Clear Time Counter*/
		 		 		 		 level++; /*Variable that indicate the level of the Window (level++) */
		 	if(ANTIPINCH) /*Evaluate if the AntiPinch was Activated and if it is a valid press*/
		 	{
		 		DisableTimer100ms();/*Disable Timer with freq. 100ms*/
		 		lpit0_ch0_flag_counter=0; /*Clear Time Counter*/
		 		EnableTimer100ms(); /*Enable Timer with freq. 100ms*/

		 		while ( ( (ANTIPINCH) && (lpit0_ch0_flag_counter<1)) ) {} /*Do Nothing*/
		 		DisableTimer100ms (); /*Enable Timer with freq. 100ms*/
		 		if(ANTIPINCH)  /*If the AntiPinch still activated*/
		 		{
		 			while(level>=1)  /*While the Window Level>=1 (Because the Window must be fully open by the AntiPinch)*/
		 					 				 		 {
		 												 PTD-> PSOR |= 1<<PTD0; /* Clear Output on port D0 (LED BLUE off) */
		 												 PTD-> PCOR |= 1<<PTD15; /* Clear Output on port D15 (LED RED on) */
		 					 				 			 DisableTimer100ms(); /*Disable Timer with freq. 100ms*/
		 					 				 			 lpit0_ch0_flag_counter=0; /*Clear Time Counter*/
		 					 				 			 	 	 	 	 	 Down_Mode_Routine (&level); /*Activate Down Mode Routine "Switch-case" (evaluating the level)*/
		 					 				 		 		 		 		 EnableTimer400ms(); /*Enable Timer with freq. 400ms*/
		 					 				 		 		 		 		 while (lpit0_ch0_flag_counter<1){}
		 					 				 		 		 		 		 DisableTimer400ms(); /*Disable Timer with freq. 400ms*/
		 					 				 		 		 		 		 lpit0_ch0_flag_counter=0; /*Clear Time Counter*/
		 					 				 		 		 		 		 level--; /*Variable that indicate the level of the Window (level--) */
		 					 				 		 }

		 					 				 		 if(level==0) /*Evaluate if the Window Level == 0*/
		 					 				 		 {
		 					 				 			 pushdown=0; /*Refresh the variable that indicate the working Mode*/
		 					 				 			 level=0; /*Window Level =0;*/
		 					 				 			PTD-> PSOR |= 1<<PTD15; /* Clear Output on port D15 (LED RED on) */
		 					 				 			pushup=0; /*Refresh the variable that indicate the working Mode*/

		 					 				 		 }
		 			DisableTimer100ms();  /*Disable Timer with freq. 100ms*/
		 			lpit0_ch0_flag_counter=0; /*Clear Time Counter*/
		 			EnableTimer100ms(); /*Enable Timer with freq. 100ms*/
		 			while (lpit0_ch0_flag_counter<50) /*While to create a loop of 5seconds (50*100 ms)*/
		 			{
		 				/*Do nothing*/
		 			}
		 			pushup=0; /*Refresh the variable that indicate the working Mode*/
		 			pushdown=0; /*Refresh the variable that indicate the working Mode*/
		 			DisableTimer100ms(); /*Disable Timer with freq. 100ms*/
		 			lpit0_ch0_flag_counter=0; /*Clear Time Counter*/
		 			level=0; /*Window Level =0*/
		 		}
		 	}
		 }

		 if(level>=11) /*If Window Level = 11 (Fully Open)*/
		 {
			 level=10; /*Window Level = 10*/
			 pushup=0; /*Refresh the variable that indicate the working Mode*/
			 PTD-> PSOR |= 1<<PTD0; /* Set Output on port D0 (LED off) */
		 }
	 }
/////////////////////                                     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////                                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 else if(pushup==2) /*Manual_Mode Activation*/
	 {
		 DisableTimer100ms(); /*Disable Timer with freq. 100ms*/
		 lpit0_ch0_flag_counter=0; /*Clear Time Counter*/
		 while(PUSHUP) /*While the PushButton UP is pressed*/
		 		 {
			 	 PTD-> PCOR |= 1<<PTD0; /* Clear Output on port D0 (LED BLUE on) */
		 		 Up_Mode_Routine (&level); /*Activate Up mode Routine "Switch-case" (evaluating the level)*/
		 		 		 		 		 EnableTimer400ms(); /*Enable Timer with freq. 400ms*/
		 		 		 		 		 while (lpit0_ch0_flag_counter<1){} /*Wait to reach 400ms / Do Nothing*/
		 		 		 		 		 DisableTimer400ms(); /*Disable Timer with freq. 400ms*/
		 		 		 		 		 lpit0_ch0_flag_counter=0; /*Clear Time Counter*/
		 		 		 		 		 level++; /*Variable that indicate the level of the Window (level++) */
		 		 }
		 PTD-> PSOR |= 1<<PTD0; /* Clear Output on port D0 (LED BLUE off) */
		 if(level>=10) /*If Window Level >= 10 (Fully Open)*/
		 {
			 level=10; /*Window Level = 10*/
			 pushup=0; /*Refresh the variable that indicate the working Mode*/
		 }
		 else
		 {
			pushup=0; /*Refresh the variable that indicate the working Mode*/
		 }
	 }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	 else if (pushdown==1) /*One_Touch_Mode Activation*/
	 {

		 				 while(level>=1) /*If Window Level >= 1 (Open above the first level)*/
		 				 		 {
		 					 	 	 PTD-> PCOR |= 1<<PTD16; /* Clear Output on port D16 (LED GREEN on) */
		 				 			 DisableTimer100ms(); /*Disable Timer with freq. 100ms*/
		 				 			 lpit0_ch0_flag_counter=0; /*Clear Time Counter*/
		 				 			 	 	 	 	 	 Down_Mode_Routine (&level); /*Activate Down Mode Routine "Switch-case" (evaluating the level)*/
		 				 		 		 		 		 EnableTimer400ms(); /*Enable Timer with freq. 400ms*/
		 				 		 		 		 		 while (lpit0_ch0_flag_counter<1){}
		 				 		 		 		 		 DisableTimer400ms(); /*Disable Timer with freq. 400ms*/
		 				 		 		 		 		 lpit0_ch0_flag_counter=0; /*Clear Time Counter*/
		 				 		 		 		 		 level--; /*Variable that indicate the level of the Window (level++) */
		 				 		 } /*End if pushdown==1*/

		 				 		 if(level==0)  /*If Window Level ==0 (Fully Closed)*/
		 				 		 {
		 				 			 pushdown=0; /*Refresh the variable that indicate the working Mode*/
		 				 			 level=0; /*Window Level = 0*/
		 				 			PTD-> PSOR |= 1<<PTD16; /* Set Output on port D16 (LED GREEN off) */

		 				 		 }

	 }

	 else if (pushdown==2) /*Manual_Mode Activation*/
	 {
		 	 	 	 	 while(PUSHDOWN)
		 		 				 		 {
		 	 	 	 		 	 	 	 	 PTD-> PCOR |= 1<<PTD16; /* Clear Output on port D16 (LED GREEN on) */
		 	 	 	 		 	 	 	 	 if(level !=0) /*If Window Level !=0 (Level above the Close Level)*/
		 	 	 	 		 	 	 	 	 {
		 		 				 			 DisableTimer100ms(); /*Disable Timer with freq. 100ms*/
		 		 				 			 lpit0_ch0_flag_counter=0; /*Clear Time Counter*/
		 		 				 			 	 	 	 	 	 Down_Mode_Routine (&level); /*Activate Down Mode Routine "Switch-case" (evaluating the level)*/
		 		 				 		 		 		 		 EnableTimer400ms(); /*Enable Timer with freq. 400ms*/
		 		 				 		 		 		 		 while (lpit0_ch0_flag_counter<1){}
		 		 				 		 		 		 		 DisableTimer400ms(); /*Disable Timer with freq. 400ms*/
		 		 				 		 		 		 		 lpit0_ch0_flag_counter=0; /*Clear Time Counter*/
		 		 				 		 		 		 		 level--; /*Variable that indicate the level of the Window (level--) */
		 	 	 	 		 	 	 	 	 }
		 		 				 		 }
		 	 	 	 	 	 	 	 	 PTD-> PSOR |= 1<<PTD16; /* Set Output on port D16 (LED off) */

		 		 				 		 if(level==0) /*If Window Level 0=0 (Fully Closed)*/
		 		 				 		 {
		 		 				 			 pushdown=0; /*Refresh the variable that indicate the working Mode*/
		 		 				 			 level=0; /*Window Level = 0*/
		 		 				 			 pushup=0; /*Refresh the variable that indicate the working Mode*/

		 		 				 		 }
		 		 				 		 else
		 		 				 		 {
		 		 				 			 pushdown=0; /*Refresh the variable that indicate the working Mode*/
		 		 				 		 }
	 } /*End of : else if ( pushdown == 2 )*/

} /*End of: for(;;)*/


}  /*End of: int main (void)*/

void LPIT0_Ch0_IRQHandler (void) {
 lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter (TIMER)*/
 //PTD->PTOR |= 1<<0; /* Toggle output on port D0 (blue LED) */
 //PTC->PTOR |= 1<<7; //C7
 LPIT0->MSR |= LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
}

/* Notice: the file ends with a blank new line to avoid compiler warnings */

