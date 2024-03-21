#include <cortex_m3.h>

void STK_Init(unsigned int Load)
{  
  STK.LOAD = Load;
  STK.CTRL.REG = 7;
}