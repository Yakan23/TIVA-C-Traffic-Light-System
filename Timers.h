#include "stdint.h"
#include "stdbool.h"
#include "Bitwise_Operation.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "inc/hw_memmap.h"
#include "tm4c123gh6pm.h"

#define CarTimerNS TIMER0_BASE
#define CarTimerEW TIMER1_BASE
#define PedTimer TIMER2_BASE

void initCar_NS(void);
void initCar_EW(void);
void initPedTimer(void);
void initTimer3A(void);

void CarNS_Delay(uint32_t delay);
void CarEW_Delay(uint32_t delay);
void PedTimer_Delay(uint32_t delay);
void Timer3A_Delay(uint32_t delay);

void CarNS_TIMA(void);

void CarEW_TIMA(void);

void PedTimer_TIMA(void);
