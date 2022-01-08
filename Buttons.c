#include "Buttons.h"
#include "Timers.h"
#include "CarTraffic.h"
#include "PedTraffic.h"
extern volatile uint8_t FSM_Ped_State=0;

void initButton_EW(void)
{

  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  GPIOUnlockPin(GPIO_PORTF_BASE,GPIO_PIN_0|GPIO_PIN_4);
  
  while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
  GPIOPinTypeGPIOInput(PedButtons, ButtonEW);
  GPIOPadConfigSet(PedButtons, ButtonEW, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
  GPIOIntTypeSet(PedButtons, ButtonEW, GPIO_FALLING_EDGE);
  GPIOIntRegister(PedButtons, ButtonINT_EW);
  GPIOIntEnable(PedButtons, GPIO_INT_PIN_0);



  
}





void ButtonINT_EW(void)
{
  GPIOIntClear(GPIO_PORTF_BASE, GPIO_INT_PIN_0);
  TimerDisable(CarTimer,TIMER_A);
      
    //Change The FSM state of pedestrian
    FSM_Ped_State=FSM_PedGreen_EW;  

    GPIOPinWrite(Ped_BASE, PedGreen_NS|PedRed_NS, FSM_PedTL[FSM_Ped_State].PedOut);
    GPIOPinWrite(Ped_BASE, PedGreen_EW|PedRed_EW, FSM_PedTL[FSM_Ped_State].PedOut);    
    PedTimer_Delay(2000); 
}
