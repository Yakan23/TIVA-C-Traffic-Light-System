#include "Buttons.h"
#include "Timers.h"
#include "CarTraffic.h"
#include "PedTraffic.h"

void initButton_EW(void)
{

  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  GPIOUnlockPin(GPIO_PORTF_BASE,GPIO_PIN_0|GPIO_PIN_4);
  
  while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
  GPIOPinTypeGPIOInput(PedButtons, ButtonEW);
  GPIOPadConfigSet(PedButtons, ButtonEW, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

  
  GPIOIntRegister(PedButtons, ButtonINT_EW);
  GPIOIntEnable(PedButtons, GPIO_INT_PIN_0);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);


  
}

void ButtonINT_EW(void)
{
  GPIOIntClear(GPIO_PORTF_BASE, GPIO_INT_PIN_0);
  PedEW_Light();
  
}
