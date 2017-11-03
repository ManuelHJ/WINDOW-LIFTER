/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: GPIO_Config.c $
 * $Revision: 1 $
 * $Author: Guillermo Hern�ndez $
 * $Date:  11/03/17 $/
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** "GPIO_Config.c" file from the Window Lifter Code

  Contains the functions that configure the ports as INPUTS/OUTPUTS
  Contains the functions that set the ports as HIGH or LOW

  
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
/* Guillermo Hern�ndez |          1         |  Template & Description Added   */
/*                     |                    |          to this file           */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/

#include "MAL/GPIO_Config.h"

/* Constants /and types  */
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

//Data direction as input
/*void PORTA_SET_INPUT(T_ULONG PIN){
	PTA->PDDR &= ~(1<<PIN);
}/*/

void PORTB_AS_INPUT(T_ULONG PIN){
	PTB->PDDR &= ~(1<<PIN);
}

void PORTC_AS_INPUT(T_ULONG PIN){
	PTC->PDDR &= ~(1<<PIN);
}

void PORTD_AS_INPUT(T_ULONG PIN){
	PTD->PDDR &= ~(1<<PIN);
}

void PORTE_AS_INPUT(T_ULONG PIN){
	PTE->PDDR &= ~(1<<PIN);
}

//Data direction as output
/*void PORTA_SET_OUTPUT(T_ULONG PIN){
	PTA->PDDR |= (1<<PIN);
}*/

void PORTB_AS_OUTPUT(T_ULONG PIN){
	PTB->PDDR |= (1<<PIN);
}

void PORTC_AS_OUTPUT(T_ULONG PIN){
	PTC->PDDR |= (1<<PIN);
}

void PORTD_AS_OUTPUT(T_ULONG PIN){
	PTD->PDDR |= (1<<PIN);
}

void PORTE_AS_OUTPUT(T_ULONG PIN){
	PTE->PDDR |= (1<<PIN);
}

//output high
/*void PORTA_OUTPUT_HIGH(T_ULONG PIN){
	PTA->PSOR |= 1<<PIN;
}*/

void PORTB_HIGH(T_ULONG PIN){
	PTB->PSOR |= 1<<PIN;
}

void PORTC_HIGH(T_ULONG PIN){
	PTC->PSOR |= 1<<PIN;
}

void PORTD_HIGH(T_ULONG PIN){
	PTD->PSOR |= 1<<PIN;
}

void PORTE_HIGH(T_ULONG PIN){
	PTE->PSOR |= 1<<PIN;
}

//OUTPUT LOW
/*void PORTA_OUTPUT_LOW(T_ULONG PIN){
	PTA->PCOR |= 1<<PIN;
}*/

void PORTB_LOW(T_ULONG PIN){
	PTB->PCOR |= 1<<PIN;
}

void PORTC_LOW(T_ULONG PIN){
	PTC->PCOR |= 1<<PIN;
}

void PORTD_LOW(T_ULONG PIN){
	PTD->PCOR |= 1<<PIN;
}

void PORTE_LOW(T_ULONG PIN){
	PTE->PCOR |= 1<<PIN;
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
