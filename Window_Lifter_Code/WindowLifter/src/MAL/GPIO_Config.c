#include "MAL/GPIO_Config.h"

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
