/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: tome400ms.h $
 * $Revision: 3 $
 * $Author: Guillermo Hernández $
 * $Date: 11/05/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** "time400ms.h" file from the Window Lifter code.

 Contains the prototype of the functions of "time400ms.c" file

 EnableTimer400ms()
 DisableTimer400ms()

 This function is related to the ID:
 DSD_05
 DSD_25
 DSD_26
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
/*       AUTHOR        |      VERSION       |          DESCRIPTION            */
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
 * $Log: filename.h  $
 ============================================================================*/
#ifndef TIME400MS_H
#define TIME400MS_H

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/

void TIMER400ms_Enable(void);
void TIMER400ms_Disable(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
