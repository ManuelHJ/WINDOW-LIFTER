/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: PCC_Config.h $
 * $Revision: 1 $
 * $Author: Guillermo Hernández $
 * $Date: 11/03/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** 
    "PCC_Config.h" file from the Window Lifter code.

    Contains the prototypes of the functions of "enable_PCC_PORTA.c" file
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
#ifndef MAL_PCC_CONFIG_H_
#define MAL_PCC_CONFIG_H_

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

//void enable_PCC_PORTA(void);
void PCC_PORTB(void);
void PCC_PORTC(void);
void PCC_PORTD(void);
void PCC_PORTE(void);
void PCC_LPIT(void);

#endif /* MAL_LIB_PCC_H_ */
