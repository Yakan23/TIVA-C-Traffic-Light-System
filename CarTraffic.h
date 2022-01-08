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

#define Car_BASE GPIO_PORTA_BASE


#define GreenNS GPIO_PIN_2
#define YellowNS GPIO_PIN_3
#define RedNS GPIO_PIN_4

#define GreenEW GPIO_PIN_5
#define YellowEW GPIO_PIN_6
#define RedEW GPIO_PIN_7

#define Led_CarGreenEW (RedNS | GreenEW)
#define Led_CarYellowEW (RedNS | YellowEW)
#define Led_CarRedEW (RedNS | RedEW)
#define Led_CarGreenNS (GreenNS | RedEW)
#define Led_CarYellowNS (YellowNS | RedEW)
#define Led_CarRedNS (RedNS | RedEW)

#define FSM_CarGreenEW (0)
#define FSM_CarYellowEW (1)
#define FSM_CarRedEW (2)
#define FSM_CarGreenNS (3)
#define FSM_CarYellowNS (4)
#define FSM_CarRedNS (5)

struct CarFSM
{
  uint8_t Out;   // output bits for car traffic led
  uint16_t Time; // delay in Milli Second
  uint8_t Next;  // The next state
};

extern const struct CarFSM FSM_CarTL[6];
extern volatile uint8_t FSM_Car_State;

/*
    function: initCarLight
    parameters: void
    return type: void
    description: 
    initializes GPIO ports used inside the East West traffic light.
    initializes timer used inside the East West traffic light.
*/

void initCarLight(void);
