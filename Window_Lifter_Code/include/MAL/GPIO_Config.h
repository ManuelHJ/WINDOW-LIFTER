/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: GPIO_Config.h $
 * $Revision: 1 $
 * $Author: Guillermo Hernández $
 * $Date: 11/03/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** "GPIO_Config.h" file from the Window Lifter code.

    Contains the prototype of the functions of "GPIO_Config.c" file

    PORTA_SET_INPUT(T_ULONG PIN)
    PORTA_SET_OUTPUT(T_ULONG PIN)
    PORTA_OUTPUT_HIGH(T_ULONG PIN)
    PORTA_OUTPUT_LOW(T_ULONG PIN)    

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
/*       AUTHOR        |      VERSION       |          DESCRIPTION            */
/*----------------------------------------------------------------------------*/
/* Guillermo Hernández |          1         |  Template & Description Added   */
/*                     |                    |           to the file           */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef MAL_GPIO_CONFIG_H_
#define MAL_GPIO_CONFIG_H_

#include "S32K144.h"
#include "MAL/Definitions.h"

/* Includes */
/*============================================================================*/

#include "S32K144.h"
#include "MAL/Definitions.h"

/* Constants and types */
/*============================================================================*/


/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

//void PORTA_SET_INPUT(T_ULONG PIN);
void PORTB_AS_INPUT(T_ULONG PIN);
void PORTC_AS_INPUT(T_ULONG PIN);
void PORTD_AS_INPUT(T_ULONG PIN);
void PORTE_AS_INPUT(T_ULONG PIN);

//void PORTA_SET_OUTPUT(T_ULONG PIN);
void PORTB_AS_OUTPUT(T_ULONG PIN);
void PORTC_AS_OUTPUT(T_ULONG PIN);
void PORTD_AS_OUTPUT(T_ULONG PIN);
void PORTE_AS_OUTPUT(T_ULONG PIN);

//void PORTA_OUTPUT_HIGH(T_ULONG PIN);
void PORTB_HIGH(T_ULONG PIN);
void PORTC_HIGH(T_ULONG PIN);
void PORTD_HIGH(T_ULONG PIN);
void PORTE_HIGH(T_ULONG PIN);

//void PORTA_OUTPUT_LOW(T_ULONG PIN);
void PORTB_LOW(T_ULONG PIN);
void PORTC_LOW(T_ULONG PIN);
void PORTD_LOW(T_ULONG PIN);
void PORTE_LOW(T_ULONG PIN);

#endif /* MAL_LIB_GPIO_H_ */
