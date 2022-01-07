#include "PedTraffic.h"
#include "CarTraffic.h"
#include "Timers.h"



void initPedLight_EW(void)
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
  SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC);
  GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5);
}

void initPedLight_NS(void)
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
  SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC);
  GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_6 | GPIO_PIN_7);
}

void PedNS_Light(void)
{

  GPIOPinWrite(Car_BASE, GreenNS | YellowNS | RedNS, 0 | 0 | RedNS);
  GPIOPinWrite(Ped_BASE, PedGreen_NS | PedRed_NS, PedGreen_NS | 0);
  Timer0A_Delay(2000);
}


void PedEW_Light(void)
{
  GPIOPinWrite(Car_BASE, GreenEW | YellowEW | RedEW, 0 | 0 | RedEW);
  GPIOPinWrite(Ped_BASE, PedGreen_NS,PedGreen_NS);
  PedTimer_Delay(2000);
  GPIOPinWrite(Ped_BASE, PedGreen_NS,0);
}