/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: LEDS_IDLE.c $
 * $Revision: 1 $
 * $Author: Guillermo Hernández $
 * $Date: 11/01/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/**

	"LEDS_IDLE.c" file from the Window Lifter code.

    Contains a default configuration of the Outputs (LED´s Off)
	"LEDS_IDLE"
	Actions of the LEDS_IDLE function:Seat an specific Output(Turn Off the LED
	used to simulate the Window Level)

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
/* Guillermo Hernández |           1        |  Template & Description Added   */
/*                     |                    |          to this file           */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/

#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "MAL/LEDS_IDLE.h"
#include "HAL/initproyect.h"

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

void LEDS_IDLE (void){

 PTD-> PSOR |= 1<<PTD0; /* Set Output on port D0 (LED off) */
 PTD-> PSOR |= 1<<PTD16; /* Set Output on port D16 (LED off) */	
 PTD-> PSOR |= 1<<PTD15; /* Set Output on port D16 (LED off) */
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

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
