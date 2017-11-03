/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Inputs_Outputs.h $
 * $Revision: 1 $
 * $Author: Guillermo Hernández $
 * $Date: 11/03/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** "Inputs_Outputs.h" file from the Window Lifter code.

    Contains the prototype of the functions of "Inputs_Outputs.c" file
   enable_PORTA();
   enable_PORTB();
   enable_PORTC();
   enable_PORTD();
   enable_PORTE();

   set_PORTB_AS(T_ULONG LVL,T_ULONG PIN);
   set_PORTC_AS(T_ULONG LVL,T_ULONG PIN);
   set_PORTD_AS(T_ULONG LVL,T_ULONG PIN);
   set_PORTE_AS(T_ULONG LVL,T_ULONG PIN);

   put_PORTA();
   put_PORTB_PIN(T_ULONG PIN,T_ULONG LVL);
   put_PORTC_PIN(T_ULONG PIN,T_ULONG LVL);
   put_PORTD_PIN(T_ULONG PIN,T_ULONG LVL);
   put_PORTE_PIN(T_ULONG PIN,T_ULONG LVL);
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
#ifndef HAL_INPUTS_OUTPUTS_H_
#define HAL_INPUTS_OUTPUTS_H_

/* Includes */
/*============================================================================*/

#include "MAL/GPIO_Config.h"
#include "MAL/PCC_Config.h"
#include "MAL/PORT_Config.h"

/* Constants and types */
/*============================================================================*/

#define input 0x00000110
#define output 0x00000100

#define high	1
#define low		0

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
//void enable_PORTA();
void enable_PORTB();
void enable_PORTC();
void enable_PORTD();
void enable_PORTE();

void set_PORTB_AS(T_ULONG LVL,T_ULONG PIN);
void set_PORTC_AS(T_ULONG LVL,T_ULONG PIN);
void set_PORTD_AS(T_ULONG LVL,T_ULONG PIN);
void set_PORTE_AS(T_ULONG LVL,T_ULONG PIN);

//void put_PORTA();
void put_PORTB_PIN(T_ULONG PIN,T_ULONG LVL);
void put_PORTC_PIN(T_ULONG PIN,T_ULONG LVL);
void put_PORTD_PIN(T_ULONG PIN,T_ULONG LVL);
void put_PORTE_PIN(T_ULONG PIN,T_ULONG LVL);

#endif /* HAL_INPUTS_OUTPUTS_H_ */
