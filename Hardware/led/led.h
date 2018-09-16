#ifndef __LED_H
#define __LED_H
#include "stm32f10x.h"

void LedInit(void);
void AlterLedState(u8 LedNum, u8 Value);
void LedToggle(u8 LedNum);
#endif
