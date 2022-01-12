#include "PedTraffic.h"
#include "CarTraffic.h"
#include "Timers.h"

extern volatile uint8_t FSM_Ped_State;

void initPedLights(void)
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
  SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC);
  GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
}

/*
We have defined 4 states for the Pedestrian Traffic Lights

each index has 
  1) Output of the pedestrian
  2) Output of the Car Traffic Lights which depends on the current Pedestrian Traffic Light [Array of States]
    and the current state of the Car
  3) Next state of Pedestrian Traffic Lights

Inside the handler of the Pedestrian timer
We write on the North-South and East-West Car Traffic lights based on their current state
Also we write on the Pedestrian Traffic Lights based on their state.

for example We were in the state Green North-South, and we want to turn on the North South Pedestrian
so that we will set the North South Car Traffic lights output to Led_CarRedNS since this state has an index 3
while the East-West Car Traffic Lights will operate normally since it is not related to the North-South pedestrian


Same goes for the pedestrian traffic, we will turn on the light based on the output of the current state
which will be green in the North-South, while the East-West direction will not be affected since it is not related
to the North-South direction.

*/
const struct PedFSM FSM_PedTL[4] =

    { //Current state of ped//  //current state of Car depending on the ped// //ARRAY                            //next of the ped
        {Led_PedGreenEW, {Led_CarRedEW, Led_CarRedEW, Led_CarRedEW, Led_CarGreenNS, Led_CarYellowNS, Led_CarRedNS}, FSM_PedRed_EW},
        {Led_PedRedEW, {Led_CarGreenEW, Led_CarYellowEW, Led_CarRedNS, Led_CarGreenNS, Led_CarYellowNS, Led_CarRedNS}, FSM_PedRed_EW},
        {Led_PedGreenNS, {Led_CarGreenEW, Led_CarYellowEW, Led_CarRedNS, Led_CarRedNS, Led_CarRedNS, Led_CarRedNS}, FSM_PedRed_NS},
        {Led_PedRedNS, {Led_CarGreenEW, Led_CarYellowEW, Led_CarRedNS, Led_CarGreenNS, Led_CarYellowNS, Led_CarRedEW}, FSM_PedRed_NS}

};
