/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Mode_Routine.c $
 * $Revision: version 1 $
 * $Author: Guillermo Herández $
 * $Date: 11/01/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/**

 "Mode_Routine.c" file from the Window Lifter Code

  Contains the functions that emulate the behavior of the Window(LED´s Routines):

  Down_Mode_Routine() :
  Switch-Case structure that Evaluate a variable "*window_level", to enter to
  a specific case.
  Actions inside the cases: Seat an specific Output (Turn Off an specific LED)
  Actions inside the default cases: Do Nothing

  Up_Mode_Routine() :
  Switch-Case structure that Evaluate a variable "*window_level", to enter to
  	  a specific case.
  Actions inside the cases: Clear an specific Output (Turn On an specific LED)
  Actions inside the default cases: Set the variable "*window Level" == 10
  	  to avoid changes on the states (Maintain the window fully open)

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
/* Guillermo Hernández |           1        |   Template & Description Added  */
/*                     |                    |           to the file           */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
 ============================================================================*/

/* Includes */
/*============================================================================*/

#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "Mode_Routine.h"
#include "HAL/initproyect.h"
#include "MAL/Definitions.h"

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/

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

void Down_Mode_Routine(int *window_level)

{
	switch ((*window_level))

	{

	case 0: //PTD-> PSOR |= 1<<PTD0; /* Clear Output on port D0 (LED on) */
		break;
	case 1:
		PTE->PSOR |= 1 << PTE1; /* Clear Output on port C7 (LED on) */
		break;
	case 2:
		PTC->PSOR |= 1 << PTC14; /* Clear Output on port B17 (LED on) */
		break;
	case 3:
		PTE->PSOR |= 1 << PTE14; /* Clear Output on port B14 (LED on) */
		break;
	case 4:
		PTE->PSOR |= 1 << PTE15; /* Clear Output on port B15 (LED on) */
		break;
	case 5:
		PTE->PSOR |= 1 << PTE16; /* Clear Output on port B16 (LED on) */
		break;
	case 6:
		PTB->PSOR |= 1 << PTB16; /* Clear Output on port E16 (LED on) */
		break;
	case 7:
		PTB->PSOR |= 1 << PTB15; /* Clear Output on port E15 (LED on) */
		break;
	case 8:
		PTB->PSOR |= 1 << PTB14; /* Clear Output on port E14 (LED on) */
		break;
	case 9:
		PTB->PSOR |= 1 << PTB17; /* Clear output on port C14 (POT)  (LED on) */
		break;
	case 10:
		PTC->PSOR |= 1 << PTC7; /*Clear Output on port E1 (LED on) */
		break;
	default: //*window_level=0;
		break;

	}

}

void Up_Mode_Routine(int *window_level) {
	switch ((*window_level)) {
	case 0:
		//PTD-> PCOR |= 1<<PTD0; /* Clear Output on port D0 (LED on) */

		break;
	case 1:
		PTE->PCOR |= 1 << PTE1; /*Clear Output on port E1 (LED on) */

		break;
	case 2:
		PTC->PCOR |= 1 << PTC14; /* Clear output on port C14 (POT)  (LED on) */

		break;
	case 3:
		PTE->PCOR |= 1 << PTE14; /* Clear Output on port E14 (LED on) */

		break;
	case 4:
		PTE->PCOR |= 1 << PTE15; /* Clear Output on port E15 (LED on) */

		break;
	case 5:
		PTE->PCOR |= 1 << PTE16; /* Clear Output on port E16 (LED on) */

		break;
	case 6:
		PTB->PCOR |= 1 << PTB16; /* Clear Output on port B16 (LED on) */

		break;
	case 7:
		PTB->PCOR |= 1 << PTB15; /* Clear Output on port B15 (LED on) */

		break;
	case 8:
		PTB->PCOR |= 1 << PTB14; /* Clear Output on port B14 (LED on) */

		break;
	case 9:
		PTB->PCOR |= 1 << PTB17; /* Clear Output on port B17 (LED on) */

		break;
	case 10:
		PTC->PCOR |= 1 << PTC7; /* Clear Output on port C7 (LED on) */

		// *window_level=0;
		break;

	default:
		*window_level = 10;
		break;

	}
}

/* Notice: the file ends with a blank new line to avoid compiler warnings */

