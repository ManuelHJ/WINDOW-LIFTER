/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: WDOG.c $
 * $Revision: 1 $
 * $Author: Guillermo Hernández $
 * $Date:  11/01/17
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/**

    "WDOG.c" file from the Window Lifter code.

    Contains a function WDOG_DISABLE () , who calls the function "Disable_WDOG",
    which is located inside the MAL layer ("WDOG_Config.c" file)

    This function set the default values to the WhatchDog (Disable)
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

#include "HAL/WDOG.h"

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

void WDOG_DISABLE(){
	DISABLE_WDOG();
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
