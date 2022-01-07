#include "CarTraffic.h"



enum States  State;

void initLight_EW(void)
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA);
  GPIOPinTypeGPIOOutput(Car_BASE, GreenEW | YellowEW | RedEW);
  
}

void initLight_NS(void)
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA);
  GPIOPinTypeGPIOOutput(Car_BASE, GreenNS | YellowNS | RedNS);
}

void EW_Light(void)
{
  switch (State)
  {

  case Green1:
    
    GPIOPinWrite(Car_BASE, GreenNS|YellowNS,0);
    GPIOPinWrite(Car_BASE, YellowEW | RedEW, 0);
    GPIOPinWrite(Car_BASE, GreenEW, GreenEW);
    CarEW_Delay(5000);
    //while(TimerIntStatus(CarTimerEW,TIMER_TIMA_TIMEOUT)!=1);
    State = Yellow1;

    break;

  case Yellow1:
    GPIOPinWrite(Car_BASE, GreenEW | RedEW, 0);
    GPIOPinWrite(Car_BASE, YellowEW, YellowEW);
    CarEW_Delay(2000);
    
    State = Red1;
    break;

  case Red1:
    GPIOPinWrite(Car_BASE, GreenEW | YellowEW, 0);
    GPIOPinWrite(Car_BASE, RedEW, RedEW);
    CarEW_Delay(1000);
    State = Green2;

    
    break;

  default:
    
    break;
  }
}

void NS_Light(void)
{
  switch (State)
  {

  case Green2:

    GPIOPinWrite(Car_BASE, GreenEW|YellowEW , 0);
    GPIOPinWrite(Car_BASE, YellowNS | RedNS, 0);
    GPIOPinWrite(Car_BASE, GreenNS, GreenNS);
    CarNS_Delay(5000);
    State = Yellow2;
    break;

  case Yellow2:
    GPIOPinWrite(Car_BASE, GreenNS | RedNS, 0);
    GPIOPinWrite(Car_BASE, YellowNS, YellowNS);
    CarNS_Delay(2000);
    State = Red2;
    break;

  case Red2:
    GPIOPinWrite(Car_BASE, GreenNS | YellowNS, 0);
    GPIOPinWrite(Car_BASE, RedNS, RedNS);
    CarNS_Delay(1000);
    State = Green1;
    break;

  default:
    break;
  }
}



