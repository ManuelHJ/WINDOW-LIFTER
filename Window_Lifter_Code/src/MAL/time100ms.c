/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: time100ms.c $
 * $Revision: 3 $
 * $Author: Guillermo Hernández $
 * $Date: 11/05/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/**
 * "time400ms.c" file from the Window Lifter code.

 Contains a function to set the values required to configure and enable
 a TIMER at 100ms. (EnableTimer100ms)

 Contains a function to set the values required to disable the TIMER
 (DisableTimer100ms)


 This function is related to the ID:
 DSD_05
 DSD_27
 DSD_28
 (ID Traceable to "DSD_Template" file)
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
/* Guillermo Hernández |          1         |  Template & Description Added   */
/*                     |                    |           to the file           */
/*----------------------------------------------------------------------------*/
/* Guillermo Hernández |          2         |      Add Traceability ID´s      */
/*                     |                    |           to the code           */
/*----------------------------------------------------------------------------*/
/* Guillermo Hernández |         3          |    Changes on Functions Names   */
/*                     |                    |   to create a naming convention */
/*----------------------------------------------------------------------------*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
 ============================================================================*/

/* Includes */
/*============================================================================*/

#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "MAL/time100ms.h"

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

void TIMER100ms_Enable(void) {

	LPIT0->TMR[0].TVAL = 4000000; /* Chan 0 Timeout period: clocks */ //1 segundo es 40000000 POR LO QUE 10ms es 400000
	LPIT0->TMR[0].TCTRL = 0x00000001; /* T_EN=1: Timer channel is enabled 0x00000001 */

}

void TIMER100ms_Disable(void) {

	LPIT0->TMR[0].TCTRL = 0x00000000; /* T_EN=1: Timer channel is enabled 0x00000001 */

}

/* Notice: the file ends with a blank new line to avoid compiler warnings */
