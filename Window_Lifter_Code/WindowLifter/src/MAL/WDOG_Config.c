#include "MAL/WDOG_Config.h"

void DISABLE_WDOG(){
	WDOG->CNT=0xD928C520; /*Unlock watchdog*/
	WDOG->TOVAL=0x0000FFFF; /*Maximum timeout value*/
	WDOG->CS = 0x00002100;
}
