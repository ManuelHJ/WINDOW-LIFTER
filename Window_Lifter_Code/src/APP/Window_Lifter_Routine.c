#include "APP/Window_Lifter_Routine.h"

void WL_INIT(){
	enable_PORTB();
	enable_PORTC();
	enable_PORTD();
	enable_PORTE();

	set_PORTE_AS(input,UP);
	set_PORTE_AS(input,DOWN);
	set_PORTC_AS(input,AP);

	set_PORTC_AS(output,BAR10);
	set_PORTC_AS(output,BAR9);
	set_PORTE_AS(output,BAR8);
	set_PORTE_AS(output,BAR7);
	set_PORTE_AS(output,BAR6);
	set_PORTE_AS(output,BAR5);
	set_PORTE_AS(output,BAR4);
	set_PORTD_AS(output,BAR3);
	set_PORTD_AS(output,BAR2);
	set_PORTC_AS(output,BAR1);

	set_PORTB_AS(output,LED_BLUE);
	set_PORTB_AS(output,LED_GREEN);
}


void LED_BLUE_ON(){
	put_PORTD_PIN(LED_BLUE,high);
}

void LED_BLUE_OFF(){
	put_PORTD_PIN(LED_BLUE,low);
}

void LED_GREEN_ON(){
	put_PORTB_PIN(LED_GREEN,high);
}

void LED_GREEN_OFF(){
	put_PORTB_PIN(LED_GREEN,low);
}

T_ULONG BTN_UP(){
	return get_PORTE_PIN(UP);
}

T_ULONG BTN_DOWN(){
	return get_PORTE_PIN(DOWN);
}

T_ULONG ANTI_PINCH(){
	return get_PORTC_PIN(AP);
}
