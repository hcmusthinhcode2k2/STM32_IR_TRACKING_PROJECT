#include <stm32f103c8t6.h>

void main()
{
  RCC_BITBAND.APB2_ENR.IOPB = 1;
  GPIO_Mode(&GPIOB, BIT12, GPIO_MODE_OUTPUT_PUSHPULL_50MHz);
  GPIO_Mode(&GPIOB, BIT13, GPIO_MODE_OUTPUT_PUSHPULL_50MHz);
  while (1)
  {
     GPIOB_BITBAND.ODR.b12 = !GPIOB_BITBAND.ODR.b12;
     for (unsigned long i = 0; i < 200000; i++);
     GPIOB_BITBAND.ODR.b13 = !GPIOB_BITBAND.ODR.b13;
     for (unsigned long i = 0; i < 200000; i++);
  }
}



