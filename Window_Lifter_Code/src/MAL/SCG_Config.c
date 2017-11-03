/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: SCG_Config.c $
 * $Revision: 1 $
 * $Author: Guillermo Hernández $
 * $Date: 11/03/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** "SCG_Config.c" file from the Window Lifter Code

  Contains the functions that configure the freq. of the clock 
  (8,80,160 MHz)
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
/* Guillermo Hernández |          1         |  Template & Description Added   */
/*                     |                    |          to this file           */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/

#include "MAL/SCG_Config.h"

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

void SOSC_INIT_8MHZ(){
	SCG->SOSCDIV=0x00000101; //Divide by 1
	SCG->SOSCCFG=0x00000024; //Medium frequency
	while(SCG->SOSCCSR & SCG_SOSCCSR_LK_MASK); //Ensure SOSCCSR unlocked
	SCG->SOSCCSR=0x00000001;
	while(!(SCG->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK));
}

void SPLL_INIT_160MHZ(){
	while(SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK);
	SCG->SPLLCSR = 0x00000000;
	SCG->SPLLDIV = 0x00000302;
	SCG->SPLLCFG = 0x00180000;
	while(SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK);
	SCG->SPLLCSR = 0x00000001;
	while(!(SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD_MASK));
}

void NORMAL_RUN_MODE_80MHZ(){
	SCG->RCCR=SCG_RCCR_SCS(6)
		|SCG_RCCR_DIVCORE(0b01)
		|SCG_RCCR_DIVBUS(0b01)
		|SCG_RCCR_DIVSLOW(0b10);
	while (((SCG->CSR & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT ) != 6) {}
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
