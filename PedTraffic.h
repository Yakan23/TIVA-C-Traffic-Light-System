#include "stdint.h"
#include "stdbool.h"
#include "stdio.h"
#include "Bitwise_Operation.h"
#include "driverlib/interrupt.h"
#include "driverlib/systick.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "tm4c123gh6pm.h"

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
//Define the states of Pedestrian Traffic Light
//****************************************************
#define FSM_PedGreen_EW (0)
#define FSM_PedRed_EW (1)
#define FSM_PedGreen_NS (2)
#define FSM_PedRed_NS (3)


struct PedFSM
{
  uint8_t PedOut;    // output bits for pedestrian traffic led
  uint8_t Next;      // The next state
};
//***************************************************
//Declare a constant array of type Pedestrian fsm
//***************************************************
extern const struct PedFSM FSM_PedTL[4];
extern volatile uint8_t FSM_Ped_State;
/*
    function: initLightPedestrian_EW
    parameters: void
    return type: void
    description: 
    initializes GPIO ports used inside the Pedestrian EastW traffic light.
    initializes timer used inside the Pedestrian EastW traffic light.
*/

void initPedLight_EW(void);

/*
    function: initLightPedestrian_NS
    parameters: void
    return type: void
    description: 
    initializes GPIO ports used inside the Pedestrian North South traffic light.
    initializes timer used inside the Pedestrian North South traffic light.
    Interrupts the EW Traffic Light
*/

void initPedLight_NS(void);

