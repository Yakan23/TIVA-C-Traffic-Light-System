#include "stdint.h"
#include "stdbool.h"
#include "stdio.h"
#include "Bitwise_Operation.h"
#include "driverlib/interrupt.h"
#include "driverlib/systick.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "Timers.h"
#include "inc/hw_memmap.h"
#include "tm4c123gh6pm.h"


#define Car_BASE GPIO_PORTA_BASE
#define GreenNS GPIO_PIN_2
#define YellowNS GPIO_PIN_3
#define RedNS GPIO_PIN_4

#define GreenEW GPIO_PIN_5
#define YellowEW GPIO_PIN_6
#define RedEW GPIO_PIN_7

enum States
{
  Green1,
  Yellow1,
  Red1,
  Green2,
  Yellow2,
  Red2
};


struct CarFSM
{
  uint8_t Out;  // output bits for car traffic led
  uint16_t Time; // delay in Milli Second
  uint8_t Next;// The next state
};

/*
    function: initLight_EW
    parameters: void
    return type: void
    description: 
    initializes GPIO ports used inside the East West traffic light.
    initializes timer used inside the East West traffic light.
*/



void initLight_EW(void); 



/*
    function: initLight_NS
    parameters: void
    return type: void
    description: 
    initializes GPIO ports used inside the North South traffic light.
    initializes timer used inside the North South traffic light.
*/
void initLight_NS(void); 



void EW_Light(void);
void NS_Light(void);



