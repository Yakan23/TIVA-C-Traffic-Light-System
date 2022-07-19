#pragma once

#include "stdio.h"
#include "TrafficLights/CarTraffic.h"
#include "Timers/Timers.h"
#include "Buttons/Buttons.h"
#include "TrafficLights/PedTraffic.h"

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
