/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: initproyect.h $
 * $Revision: 2 $
 * $Author: Guillermo Hernández $
 * $Date: 11/05/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** "initproyect.h" file from the Window Lifter code.

    Contains the typedefs and definitions used @ "initproyect.c" file
    
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
/* Guillermo Hernández |          2         |    Changes on Functions Names   */
/*                     |                    |   to create a naming convention */
/*----------------------------------------------------------------------------*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef HAL_INITPROYECT_H
#define HAL_INITPROYECT_H

/* Includes */
/*============================================================================*/


/* Constants and types */
/*============================================================================*/
#define PTC7 7
#define PTC6 6
#define PTB17 17
#define PTB14 14
#define PTB15 15
#define PTB16 16
#define PTC14 14
#define PTC3 3
#define PTE16 16
#define PTE15 15
#define PTE14 14
#define PTE13 13
#define PTE1 1
#define PTD7 7
#define PTD15 15



#define PTD0 0 // Blue Led indicator UP
#define PTD16 16 // Green Led indicator DOWN

#define PTC12 12 /* Port PTC12, bit 12:  BTN0 [SW0] */
#define PTC13 13 /* Port PTC13, bit 13:  BTN1 [SW1] */

#define PUSHUP_Read (PTC->PDIR & (1<<PTC12))
#define PUSHDOWN_Read (PTC->PDIR & (1<<PTC13))
#define ANTIPINCH_Read (PTD->PDIR & (1<<PTD7))

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

void NVIC_init_IRQs (void);
void LPIT0_Init (void);
void WINDOW_Init (void);
void INDICATORS_Init (void);
void PCC_Enable (void);
void BUTTONS_Init (void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
