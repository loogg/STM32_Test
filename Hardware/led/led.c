#include "led.h"
#include "mcu_gpio.h"

#define LED0_O(x) GPIO_WriteBit(GPIOA, GPIO_Pin_8, (BitAction)x)
#define LED1_O(x) GPIO_WriteBit(GPIOD, GPIO_Pin_2, (BitAction)x)

#define LED0_I GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_8)
#define LED1_I GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_2)

void LedInit(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    McuGpioInit(GPIOA, GPIO_Pin_8, GPIO_Speed_50MHz, GPIO_Mode_Out_PP);
    McuGpioInit(GPIOD, GPIO_Pin_2, GPIO_Speed_50MHz, GPIO_Mode_Out_PP);

    LED0_O(1);
    LED1_O(0);
}

void AlterLedState(u8 LedNum, u8 Value)
{
    switch (LedNum)
    {
    case 0:
        LED0_O(Value ? 1 : 0);
        break;
    case 1:
        LED1_O(Value ? 1 : 0);
        break;
    default:
        break;
    }
}

void LedToggle(u8 LedNum)
{
    u8 LedState[2];
    LedState[0] = LED0_I;
    LedState[1] = LED1_I;
    switch (LedNum)
    {
    case 0:
        LedState[0]++;
        if (LedState[0] == 2)
        {
            LedState[0] = 0;
        }
        LED0_O(LedState[0]);
        break;
    case 1:
        LedState[1]++;
        if (LedState[1] == 2)
        {
            LedState[1] = 0;
        }
        LED1_O(LedState[1]);
        break;
    default:
        break;
    }
}
