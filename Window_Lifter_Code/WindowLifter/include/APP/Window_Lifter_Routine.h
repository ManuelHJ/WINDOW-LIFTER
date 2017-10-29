#ifndef APP_WINDOWLIFTER_H_
#define APP_WINDOWLIFTER_H_

#include "HAL/CLOCKS.h"
#include "HAL/TIMERS.h"
#include "HAL/Inputs_Outputs.h"
#include "HAL/WDOG.h"

#define BAR10	14
#define BAR9	3
#define BAR8	16
#define BAR7	15
#define BAR6	14
#define BAR5	13
#define BAR4	1
#define BAR3	7
#define BAR2	6
#define BAR1	15

#define LED_BLUE	0
#define LED_GREEN	16

#define UP	0
#define DOWN	9
#define AP	5

void WL_INIT();
void BAR_ON();
void BAR_CTRL(T_UBYTE t_uLed );
void LED_BLUE_ON();
void LED_BLUE_OFF();
void LED_GREEN_ON();
void LED_GREEN_OFF();

T_ULONG BTN_UP();
T_ULONG BTN_DOWN();
T_ULONG ANTI_PINCH();

#endif /* APP_WINDOWLIFTER_H_ */
