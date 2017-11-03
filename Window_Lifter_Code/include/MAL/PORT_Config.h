/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: PORT_Config.h $
 * $Revision: 1 $
 * $Author: Guillermo Hern�ndez $
 * $Date: 11/03/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** "PORT_Config.h" file from the Window Lifter code.

    Contains the prototypes of the functions of "PORT_Config.c" file
    set_PORTA()
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
/* Guillermo Hern�ndez |          1         |  Template & Description Added   */
/*                     |                    |           to the file           */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef MAL_PORT_CONFIG_H_
#define MAL_PORT_CONFIG_H_

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

//void set_PORTA(T_ULONG PIN,T_ULONG DIR);
void SET_PORTB(T_ULONG PIN,T_ULONG DIR);
void SET_PORTC(T_ULONG PIN,T_ULONG DIR);
void SET_PORTD(T_ULONG PIN,T_ULONG DIR);
void SET_PORTE(T_ULONG PIN,T_ULONG DIR);

#endif /* MAL_PORT_CONFIG_H_ */

