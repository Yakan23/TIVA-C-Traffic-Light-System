#include "PedTraffic.h"
#include "CarTraffic.h"
#include "Timers.h"

extern volatile uint8_t FSM_Ped_State;

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

const struct PedFSM FSM_PedTL[4] =
    {{Led_PedGreenEW,FSM_PedRed_EW},
     {Led_PedRedEW, FSM_PedRed_EW},
     {Led_PedGreenNS,  FSM_PedRed_NS},
     {Led_PedRedNS, FSM_PedRed_NS}};
