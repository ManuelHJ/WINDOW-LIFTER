/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.c $
 * $Revision: version $
 * $Author: author $
 * $Date: date $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    short description in one sentence end with dot.
    detailed
    multiline
    description of the file
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
/*                     |                    |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/

#ifndef MAL_PCC_CONFIG_C_
#define MAL_PCC_CONFIG_C_

#include "MAL/PCC_Config.h"

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

/*void enable_PCC_PORTA(void){
	PCC->PCCn[PCC_PORTA_INDEX]=0x40000000u;
}*/

void PCC_PORTB(void){
	PCC->PCCn[PCC_PORTB_INDEX]=0x40000000u;
}

void PCC_PORTC(void){
	PCC->PCCn[PCC_PORTC_INDEX]=0x40000000u;
}

void PCC_PORTD(void){
	PCC->PCCn[PCC_PORTD_INDEX]=0x40000000u;
}

void PCC_PORTE(void){
	PCC->PCCn[PCC_PORTE_INDEX]=0x40000000u;
}

void PCC_LPIT(void){
	PCC->PCCn[PCC_LPIT_INDEX]=PCC_PCCn_PCS(6);
	PCC->PCCn[PCC_LPIT_INDEX]=0x40000000u;
}

#endif /* MAL_PCC_CONFIG_C_ */

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
