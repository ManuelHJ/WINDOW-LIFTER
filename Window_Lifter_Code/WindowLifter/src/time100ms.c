#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "time100ms.h"


void EnableTimer100ms (void){

 LPIT0->TMR[0].TVAL = 4000000; /* Chan 0 Timeout period: clocks */ //1 segundo es 40000000 POR LO QUE 10ms es 400000
 LPIT0->TMR[0].TCTRL = 0x00000001; /* T_EN=1: Timer channel is enabled 0x00000001 */

}

void DisableTimer100ms (void){

LPIT0->TMR[0].TCTRL = 0x00000000; /* T_EN=1: Timer channel is enabled 0x00000001 */

}
