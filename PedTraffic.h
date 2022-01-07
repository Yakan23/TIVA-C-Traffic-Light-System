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

void PedNS_Light(void);

void PedEW_Light(void);
