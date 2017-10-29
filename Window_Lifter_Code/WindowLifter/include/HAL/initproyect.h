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

#define PUSHUP (PTC->PDIR & (1<<PTC12))
#define PUSHDOWN (PTC->PDIR & (1<<PTC13))
#define ANTIPINCH (PTD->PDIR & (1<<PTD7))



void NVIC_init_IRQs (void);
void LPIT0_init (void);
void WindowInit (void);
void IndicatorsInit (void);
void EnablePCC (void);
void ButtonsInit (void);



