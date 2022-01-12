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

/*
We have defined 6 states in our program  
each state defined as an index in the FSM_CarTL

FSM_CarGreenEW (0)
FSM_CarYellowEW (1)
FSM_CarRedEW (2)
FSM_CarGreenNS (3)
FSM_CarYellowNS (4)
FSM_CarRedNS (5)

Each state represents the output of a Car traffic
for example FSM_CarGreenEW represents Green (Led_CarGreenEW) light working in the East West car traffic
In addition to the output of the Car Traffic light, we added the time it takes, and its next state

for example FSM_CarGreenEW has a time delay of 5 seconds and has a next state which the yellow traffic light (Led_CarYellowEW)
which is another state called FSM_CarYellowEW which will have a delay of 2 seconds and a next state FSM_CarRedEW

*/
const struct CarFSM FSM_CarTL[6] =
    {
        //led output   time delay  nextstate
        {Led_CarGreenEW, 5000, FSM_CarYellowEW},
        {Led_CarYellowEW, 2000, FSM_CarRedEW},
        {Led_CarRedEW, 1000, FSM_CarGreenNS},
        {Led_CarGreenNS, 5000, FSM_CarYellowNS},
        {Led_CarYellowNS, 2000, FSM_CarRedNS},
        {Led_CarRedNS, 1000, FSM_CarGreenEW}};
