#include "CarTraffic.h"

volatile uint8_t FSM_Car_State;

void initCarLight(void)
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA);
  GPIOPinTypeGPIOOutput(Car_BASE, GreenEW | YellowEW | RedEW | GreenNS | YellowNS | RedNS);
  GPIOPinWrite(Car_BASE, GreenNS | YellowNS | RedNS, FSM_CarTL[FSM_Car_State].Out);
  GPIOPinWrite(Car_BASE, GreenEW | YellowEW | RedEW, FSM_CarTL[FSM_Car_State].Out);
  CarTraffic_Delay(FSM_CarTL[FSM_Car_State].Time);
}

const struct CarFSM FSM_CarTL[6] =
    {
        //led output   time delay  nextstate
        {Led_CarGreenEW, 5000, FSM_CarYellowEW},
        {Led_CarYellowEW, 2000, FSM_CarRedEW},
        {Led_CarRedEW, 1000, FSM_CarGreenNS},
        {Led_CarGreenNS, 5000, FSM_CarYellowNS},
        {Led_CarYellowNS, 2000, FSM_CarRedNS},
        {Led_CarRedNS, 1000, FSM_CarGreenEW}};
