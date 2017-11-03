/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: time400ms.c $
 * $Revision: version 2 $
 * $Author: Guillermo Hernández $
 * $Date: 11/02/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/**
 *
    "time400ms.c" file from the Window Lifter code.

    Contains a function to set the values required to configure and enable
    a TIMER at 400ms. (EnableTimer400ms)

    Contains a function to set the values required to disable the TIMER
    (DisableTimer400ms)


    This function is related to the ID= DSD_05
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
/*----------------------------------------------------------------------------*/
/* Guillermo Hernández |          1         |  Template & Description Added   */
/*                     |                    |           to the file           */
/*----------------------------------------------------------------------------*/
/* Guillermo Hernández |          2         |      Add Traceability ID´s      */
/*                     |                    |           to the code           */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/

#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "MAL/time400ms.h"

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



void EnableTimer400ms (void){

 LPIT0->TMR[0].TVAL = 16000000; /* Chan 0 Timeout period: clocks */ //400 segundo es 40000000 por lo tanto 400 ms es 16000000*/
 LPIT0->TMR[0].TCTRL = 0x00000001; /* T_EN=1: Timer channel is enabled 0x00000101 */

}

void DisableTimer400ms (void){

LPIT0->TMR[0].TCTRL = 0x00000000; /* T_EN=1: Timer channel is disable 0x00000000 */

}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */

