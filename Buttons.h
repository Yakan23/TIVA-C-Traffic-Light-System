#include "stdint.h"
#include "stdbool.h"
#include "stdio.h"
#include "Timers.h"
#include "Bitwise_Operation.h"
#include "driverlib/interrupt.h"
#include "driverlib/systick.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "tm4c123gh6pm.h"

#define PedButtons GPIO_PORTF_BASE
#define ButtonEW GPIO_PIN_0
#define ButtonNS GPIO_PIN_4

void initButtons(void);

//**************************///
//      initButtons         //
//**************************//

/*
->  function: initButtons
    parameters: void
    return type: void
    description: 
    Setting GPIO PortF buttons priority interrupt handler as the highest priority.
    Assigning the system clock to the GPIO PortF. 
    Unlocking Pin0, and Pin4 in GPIO PortF to allow changes on it.
    Setting ButtonEW and ButtonNS as inputs.
    Configuring both ButtonEW and ButtonNS as Pull-up.
    Registers Interrupt handlers for PortF
    Enable Interrupts on both ButtonEW and ButtonNS
*/

void PedButtonINT(void);
//**************************//
//      PedButtonINT        //
//**************************//
/*
->  parameters: void
    return type: void
    description: 
    Check if ButtonEW is pressed
        ->
            Clear interrupt from ButtonEW
            Disable CarTraffic Timer so that we can continue from where we started
            Changing the Pedestrian State (FSM_PED_State) to Green.
            Changing the colors of the Car Traffic (GreenNS|YellowNS|RedNS) & (GreenEW|YellowEW|RedEW) 
                to Red based on the output of the FSM_PED_State car output
            Changing the colors of the Pedestrian Traffic (PedGreen_NS|PedYellow_NS|PedRed_NS) & (PedGreen_EW|PedYellow_EW|PedRed_EW)
                to Green based on the output of the  FSM_PED_State pedestrian output
            Wait for 2 seconds (Pedestrian Traffic Delay)
            Enable CarTraffic Timer back again.
    Else Check if ButtonEW is pressed
        ->
            Clear interrupt from ButtonEW
            Disable CarTraffic Timer so that we can continue from where we started
            Changing the Pedestrian State (FSM_PED_State) to Green.
            Changing the colors of the Car Traffic (GreenNS|YellowNS|RedNS) & (GreenEW|YellowEW|RedEW) 
                to Red based on the output of the FSM_PED_State car output
            Changing the colors of the Pedestrian Traffic (PedGreen_NS|PedYellow_NS|PedRed_NS) & (PedGreen_EW|PedYellow_EW|PedRed_EW)
                to Green based on the output of the  FSM_PED_State pedestrian output
            Wait for 2 seconds (Pedestrian Traffic Delay)
            Enable CarTraffic Timer back again.

*/