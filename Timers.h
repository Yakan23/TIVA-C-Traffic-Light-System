#include "stdint.h"
#include "stdbool.h"
#include "Bitwise_Operation.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "inc/hw_memmap.h"
#include "tm4c123gh6pm.h"

#define CarTimer TIMER1_BASE
#define PedTimer TIMER2_BASE

void initCarTimer(void);
void initPedTimer(void);

void CarTimer_Delay(uint32_t delay);
void PedTimer_Delay(uint32_t delay);


void CarTimer_TIMA(void);

void PedTimer_TIMER(void);
