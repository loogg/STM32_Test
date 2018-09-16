#ifndef __DELAY
#define __DELAY
#include "stm32f10x.h"

void DelayInit(void);
void Delay(__IO uint32_t nTime);
void TimingDelay_Decrement(void);
#endif
