/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: TIMERS.c $
 * $Revision: 1 $
 * $Author: Guillermo Hernández $
 * $Date: 11/03/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** "TIMERS.c" file from the Window Lifter code.

    Contains a function ms_TIMER (), used to configure the values of the TIMER
   
    TIMER_ENABLE(void)
    This function enable the Timer
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
/*                     |                    |           to this file          */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/

#include "HAL/TIMERS.h"

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

void ms_TIMER(T_ULONG t_uTime){
	PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(6);
	PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK;
	LPIT0->MCR = 0x00000001;
	LPIT0->TMR[0].TVAL = 40000*t_uTime;
	LPIT0->TMR[0].TCTRL = 0x00000001;
}

void TIMER_ENABLE(void){
	while(0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)){}
	LPIT0->MSR |= LPIT_MSR_TIF0_MASK;
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
