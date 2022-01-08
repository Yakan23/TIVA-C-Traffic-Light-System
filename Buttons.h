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
#define ButtonEW GPIO_PIN_0  //el 3al yemeen law el debugger cable foa2
#define ButtonNS GPIO_PIN_4  // el 3al shemal



void initButton_EW(void);

void initButton_NS(void);

void ButtonINT_EW(void);