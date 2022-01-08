#include "PedTraffic.h"
#include "CarTraffic.h"
#include "Timers.h"

extern volatile uint8_t FSM_Ped_State;

void initPedLight_EW(void)
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
  SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC);
  GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5|GPIO_PIN_6 | GPIO_PIN_7);
}

const struct PedFSM FSM_PedTL[4] =

{{Led_PedGreenEW,{Led_CarRedEW, Led_CarRedEW, Led_CarGreenNS, Led_CarGreenNS, Led_CarYellowNS, Led_CarRedNS},FSM_PedRed_EW},
     {Led_PedRedEW,{Led_CarGreenEW, Led_CarYellowEW, Led_CarRedNS, Led_CarGreenNS, Led_CarYellowNS, Led_CarRedNS}, FSM_PedRed_EW},
     {Led_PedGreenNS,   {Led_CarGreenEW, Led_CarYellowEW, Led_CarRedNS, Led_CarRedNS, Led_CarRedNS, Led_CarRedNS},FSM_PedRed_NS},
     {Led_PedRedNS, {Led_CarGreenEW, Led_CarYellowEW, Led_CarRedNS, Led_CarGreenNS, Led_CarYellowNS, Led_CarRedEW},FSM_PedRed_NS}};


