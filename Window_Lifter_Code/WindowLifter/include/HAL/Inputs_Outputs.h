#ifndef HAL_INPUTS_OUTPUTS_H_
#define HAL_INPUTS_OUTPUTS_H_

#include "MAL/GPIO_Config.h"
#include "MAL/PCC_Config.h"
#include "MAL/PORT_Config.h"

#define input 0x00000110
#define output 0x00000100

#define high	1
#define low		0

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

#endif /* HAL_IO_H_ */
