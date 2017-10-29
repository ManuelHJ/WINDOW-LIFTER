#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "MAL/time400ms.h"


void EnableTimer400ms (void){

 LPIT0->TMR[0].TVAL = 16000000; /* Chan 0 Timeout period: clocks */ //400 segundo es 40000000 por lo tanto 400 ms es 16000000
 LPIT0->TMR[0].TCTRL = 0x00000001; /* T_EN=1: Timer channel is enabled 0x00000101 */

}

void DisableTimer400ms (void){

LPIT0->TMR[0].TCTRL = 0x00000000; /* T_EN=1: Timer channel is disable 0x00000000 */

}
