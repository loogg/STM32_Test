#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    LedInit();
    DelayInit();
    while(1)
    {
        LedToggle(0);
        LedToggle(1);
        Delay(500);
    }
}    
