#pragma once

#include "Buttons.h"
#include "../TrafficLights/CarTraffic.h"
#include "../TrafficLights/PedTraffic.h"

extern volatile uint8_t FSM_Ped_State = 0;

void initButtons(void)
{
  IntPrioritySet(INT_GPIOF, 0x20);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  GPIOUnlockPin(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4);
  while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    ;
  GPIOPinTypeGPIOInput(PedButtons, ButtonEW | ButtonNS);
  GPIOPadConfigSet(PedButtons, ButtonEW, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
  GPIOPadConfigSet(PedButtons, ButtonNS, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
  GPIOIntRegister(PedButtons, PedButtonINT);
  GPIOIntRegister(PedButtons, PedButtonINT);
  GPIOIntEnable(PedButtons, GPIO_INT_PIN_0);
  GPIOIntEnable(PedButtons, GPIO_INT_PIN_4);
}

void PedButtonINT(void)
{
  if ((Get_Bit(GPIO_PORTF_DATA_R, 0)) == 0)
  { // EW
    GPIOIntClear(GPIO_PORTF_BASE, GPIO_INT_PIN_0);
    TimerDisable(CarTimer, TIMER_A);

    // Change The FSM state of pedestrian
    FSM_Ped_State = FSM_PedGreen_EW;

    GPIOPinWrite(Car_BASE, GreenNS | YellowNS | RedNS, FSM_PedTL[FSM_Ped_State].CarOut[FSM_Car_State]);
    GPIOPinWrite(Car_BASE, GreenEW | YellowEW | RedEW, FSM_PedTL[FSM_Ped_State].CarOut[FSM_Car_State]);
    GPIOPinWrite(Ped_BASE, PedGreen_NS | PedRed_NS, FSM_PedTL[FSM_Ped_State].PedOut);
    GPIOPinWrite(Ped_BASE, PedGreen_EW | PedRed_EW, FSM_PedTL[FSM_Ped_State].PedOut);
    PedTimer_Delay(2000);
    TimerEnable(PedTimer, TIMER_A);
  }

  else if ((Get_Bit(GPIO_PORTF_DATA_R, 4)) == 0) // ns
  {
    GPIOIntClear(GPIO_PORTF_BASE, GPIO_INT_PIN_4);
    TimerDisable(CarTimer, TIMER_A);

    // Change The FSM state of pedestrian
    FSM_Ped_State = FSM_PedGreen_NS;

    GPIOPinWrite(Car_BASE, GreenNS | YellowNS | RedNS, FSM_PedTL[FSM_Ped_State].CarOut[FSM_Car_State]);
    GPIOPinWrite(Car_BASE, GreenEW | YellowEW | RedEW, FSM_PedTL[FSM_Ped_State].CarOut[FSM_Car_State]);
    GPIOPinWrite(Ped_BASE, PedGreen_NS | PedRed_NS, FSM_PedTL[FSM_Ped_State].PedOut);
    GPIOPinWrite(Ped_BASE, PedGreen_EW | PedRed_EW, FSM_PedTL[FSM_Ped_State].PedOut);
    PedTimer_Delay(2000);
    TimerEnable(PedTimer, TIMER_A);
  }
}
