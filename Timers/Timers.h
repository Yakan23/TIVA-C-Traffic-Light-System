#pragma once
#include "stdint.h"
#include "stdbool.h"
#include "../Helpers/Bitwise_Operation.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "inc/hw_memmap.h"
#include "../Helpers/tm4c123gh6pm.h"

#define CarTimer TIMER1_BASE
#define PedTimer TIMER2_BASE

void initCarTimer(void);
//**************************//
//      initCarTimer        //
//**************************//

/*
->  parameters: void
    return type: void
    description:
    ->  Setting the lowest priority interrupt for the Car Timer interrupt
        Enabling the timer 1 (Car timer)
        Disabling timer 1A for before configureation
        Configure timer 1A as a down periodic timer
        Enabling interrupt on timer 1A
        Enabling timer 1A
*/

void initPedTimer(void);
//**************************//
//      initPedTimer        //
//**************************//

/*
->  parameters: void
    return type: void
    description:
    ->  Setting the highest priority interrupt for the Ped Timer interrupt
        Enabling the timer 2 (Ped timer)
        Disabling timer 2A before configuration
        Configure timer 2A as a down periodic timer
        Enabling interrupt on timer 2A
        Enabling timer 2A
*/

void CarTimer_Delay(uint32_t delay);
//**************************//
//      CarTimer_Delay      //
//**************************//
/*
->  parameters: required delay in ms
    return type: void
    description:
    ->  Transform the delay from ms to number of ticks for our 16 MHZ clock
        Load the required delay in the load register for the Car Timer
*/

void PedTimer_Delay(uint32_t delay);
//**************************//
//      PedTimer_Delay      //
//**************************//
/*
->  parameters: required delay in ms
    return type: void
    description:
    ->  Transform the delay from ms to number of ticks for our 16 MHZ clock
        Load the required delay in the load register for the Ped Timer
*/

void CarTimer_TIMEOUT(void);
//**************************//
//      CarTimer_TIMEOUT    //
//**************************//
/*
->  parameters: void
    return type: void
    description:
    ->  The function that handles the timeout interrupt for the
            Car timer (timer1 subtimer A)
        Clears the Car timer Interrupt flag
        Changes the (FSM_Car_State) to the next state in the struct
        Loads the next state delay using the (CarTraffic_Delay) function
        Writes the changes on the pins as defined in the CarFSM struct on both
           Car traffic lights
        After configuring the state of the car fsm, enable the Car Timer
            (timer 1 subtimer A)
*/

void PedTimer_TIMEOUT(void);
//**************************//
//      PedTimer_TIMEOUT    //
//**************************//
/*
->  parameters: void
    return type: void
    description:
    ->  The function that handles the timeout interrupt for the
            Ped timer (timer2 subtimer A)
        Disable The Ped timer and clear the timer's interrupt flag
        Changes the (FSM_Ped_State) to the next state in the struct
        Writes the changes on the pins as defined in the struct PedFSM on both
            Car traffic lights
        Writes the changes on the pins as defined in the struct PedFSM on both
            Ped traffic lights
        Enable Car Timer (It get disabled when the button interrupt happens)
*/