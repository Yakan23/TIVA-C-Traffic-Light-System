#pragma once

#include "stdint.h"
#include "stdbool.h"
#include "stdio.h"
#include "../Helpers/Bitwise_Operation.h"
#include "driverlib/interrupt.h"
#include "driverlib/systick.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "../Helpers/tm4c123gh6pm.h"

#define Ped_BASE GPIO_PORTC_BASE
#define PedGreen_NS GPIO_PIN_4
#define PedRed_NS GPIO_PIN_5
#define PedGreen_EW GPIO_PIN_6
#define PedRed_EW GPIO_PIN_7

#define Led_PedGreenNS (PedGreen_NS | PedRed_EW)
#define Led_PedRedNS (PedRed_NS | PedRed_EW)
#define Led_PedGreenEW (PedRed_NS | PedGreen_EW)
#define Led_PedRedEW (PedRed_NS | PedRed_EW)

//****************************************************
// Define the states of Pedestrian Traffic Light
//****************************************************
#define FSM_PedGreen_EW (0)
#define FSM_PedRed_EW (1)
#define FSM_PedGreen_NS (2)
#define FSM_PedRed_NS (3)

//***************************************************
// Define Pedestrian Traffic Light Struct
//***************************************************
struct PedFSM
{
  uint8_t PedOut;    // output of Pedestrian Traffic Leds
  uint8_t CarOut[6]; // output of Car Traffic Leds
  uint8_t Next;      // Next State
};
//***************************************************
// Declare a constant array of type Pedestrian fsm
//***************************************************
extern const struct PedFSM FSM_PedTL[4];
extern volatile uint8_t FSM_Ped_State;

void initPedLights(void);
//**************************//
//      initPedLights       //
//**************************//

/*
->  function: initPedLights
    parameters: void
    return type: void
    description:
    ->  Assigning the system clock to the GPIO PortC.
        Setting the Pins 4, 5, 6, 7 as output pins.
*/
