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

  initCarTimer();
  initCarLight();
  IntPrioritySet(INT_TIMER2A,0x10);
  IntPrioritySet(INT_GPIOF, 0x20);
  IntPrioritySet(INT_TIMER1A, 0x30);
  initButton_EW(); //gpio
  initPedLight_EW();
  initPedTimer();


  __asm("CPSIE I");

  while (1)
  {
    SysCtlSleep();
  
  }
}
