#include "HAL/Inputs_Outputs.h"

void enable_PORTB(){
	PCC_PORTB();
}

void enable_PORTC(){
	PCC_PORTC();
}

void enable_PORTD(){
	PCC_PORTD();
}

void enable_PORTE(){
	PCC_PORTE();
}

//Set as input
void set_PORTB_AS(T_ULONG LVL,T_ULONG PIN){
	if(LVL == 0x00000110){
		PORTB_AS_INPUT(PIN);
		SET_PORTB(PIN,LVL);
	}else{
		if(LVL == 0x00000100){
			PORTB_AS_OUTPUT(PIN);
			SET_PORTB(PIN,LVL);
		}
	}
}
void set_PORTC_AS(T_ULONG LVL,T_ULONG PIN){
	if(LVL == 0x00000110){
		PORTC_AS_INPUT(PIN);
		SET_PORTC(PIN,LVL);
	}else{
		if(LVL == 0x00000100){
			PORTC_AS_OUTPUT(PIN);
			SET_PORTC(PIN,LVL);
		}
	}
}
void set_PORTD_AS(T_ULONG LVL,T_ULONG PIN){
	if(LVL == 0x00000110){
		PORTD_AS_INPUT(PIN);
		SET_PORTD(PIN,LVL);
	}else{
		if(LVL == 0x00000100){
			PORTD_AS_OUTPUT(PIN);
			SET_PORTD(PIN,LVL);
		}
	}
}
void set_PORTE_AS(T_ULONG LVL,T_ULONG PIN){
	if(LVL == 0x00000110){
		PORTE_AS_INPUT(PIN);
		SET_PORTE(PIN,LVL);
	}else{
		if(LVL == 0x00000100){
			PORTE_AS_OUTPUT(PIN);
			SET_PORTE(PIN,LVL);
		}
	}
}

/*T_UBYTE get_PORTA_PIN(T_UBYTE PIN){

}*/

void put_PORTB_PIN(T_ULONG PIN,T_ULONG LVL){
	if(LVL){
		PORTB_HIGH(PIN);
	}else{
		PORTB_LOW(PIN);
	}
}

void put_PORTC_PIN(T_ULONG PIN,T_ULONG LVL){
	if(LVL){
		PORTC_HIGH(PIN);
	}else{
		PORTC_LOW(PIN);
	}
}

void put_PORTD_PIN(T_ULONG PIN,T_ULONG LVL){
	if(LVL){
		PORTD_HIGH(PIN);
	}else{
		PORTD_LOW(PIN);
	}
}

void put_PORTE_PIN(T_ULONG PIN,T_ULONG LVL){
	if(LVL){
		PORTE_HIGH(PIN);
	}else{
		PORTE_LOW(PIN);
	}
}
