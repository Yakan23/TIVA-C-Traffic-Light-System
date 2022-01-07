#include "stdio.h"
#include "CarTraffic.h"
#include "Timers.h"
#include "Buttons.h"
#include "PedTraffic.h"
#include "Bitwise_Operation.h"

int main()

{

  __asm("CPSID I");
  SysCtlDelay(3);
  IntPrioritySet(INT_TIMER2A, 0);
  IntPrioritySet(INT_GPIOF,1);
  IntPrioritySet(INT_TIMER1A, 2);
  IntPrioritySet(INT_TIMER0A, 3);
  initCar_NS(); //timers
  initCar_EW(); //timers
  initPedTimer();  
  initLight_NS(); //gpio
  initLight_EW(); //gpio
  initPedLight_EW(); //gpio
  initPedLight_NS(); //gpio
  initButton_EW(); //gpio
  CarEW_Delay(2);
  CarNS_Delay(2);

  __asm("CPSIE I");

  while (1)
  {
    
  }
}
