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
  initPedTimer();
  initButtons();
  initPedLights();

  __asm("CPSIE I");

  while (1)
  {
    SysCtlSleep();
  }
}
