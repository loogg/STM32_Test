#include "mcu_gpio.h"

void McuGpioInit(GPIO_TypeDef *Gpiox, uint16_t GpioPin, GPIOSpeed_TypeDef GpioSpeed, GPIOMode_TypeDef GpioMode)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GpioPin;
    GPIO_InitStructure.GPIO_Speed = GpioSpeed;
    GPIO_InitStructure.GPIO_Mode = GpioMode;
    GPIO_Init(Gpiox, &GPIO_InitStructure);
}
