/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Mode_Routine.h $
 * $Revision: 1 $
 * $Author: Guillermo Hernández $
 * $Date: 11/01/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/**
    "Mode_Routine.h" file from the Window Lifter code.

    Contains the prototype of the functions of "Mode_Routine.c" file

    Down_Mode_Routine()
    Up_Mode_Routine

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
/*                     |                    |          to this file           */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef MODE_ROUTINE_H
#define MODE_ROUTINE_H

/* Includes */
/*============================================================================*/


/* Constants and types */
/*============================================================================*/


/* Exported Variables */
/*============================================================================*/

void Down_Mode_Routine (int *window_level);

void Up_Mode_Routine (int *window_level);

/* Exported functions prototypes */
/*============================================================================*/
void Down_Mode_Routine (int *window_level);

void Up_Mode_Routine (int *window_level);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
