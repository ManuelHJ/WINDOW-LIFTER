/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: ClOCKS.c $
 * $Revision: 1 $
 * $Author: Guillermo Hern�ndez $
 * $Date: 11/01/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/**

 "CLOCKS.c" file from the Window Lifter code.

 Contains a function FREQ_Config () ,who calls the functions "SOSC_INIT_8MHZ",
 "SPLL_INIT_160MHZ" and "NORMAL_RUN_MODE_80MHZ"
 This are located inside the MAL layer ("SCG_Config.c" file)

 This function set the default values to the Timer (Disable)

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
/* Guillermo Hern�ndez |           1        |  Template & Description Added   */
/*                     |                    |           to this file          */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
 ============================================================================*/

/* Includes */
/*============================================================================*/

#include "HAL/CLOCKS.h"

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

void FREQ_Config() {
	SOSC_INIT_8MHZ();
	SPLL_INIT_160MHZ();
	NORMAL_RUN_MODE_80MHZ();
}

/* Notice: the file ends with a blank new line to avoid compiler warnings */
