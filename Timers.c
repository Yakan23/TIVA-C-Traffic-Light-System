#include "Timers.h"
#include "CarTraffic.h"



void initCar_NS(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    TimerDisable(CarTimerNS, TIMER_A);
    SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER0);
    TimerConfigure(CarTimerNS, TIMER_CFG_A_PERIODIC);

    IntEnable(INT_TIMER0A);
    TimerIntEnable(CarTimerNS, TIMER_TIMA_TIMEOUT);
    TimerEnable(CarTimerNS, TIMER_A);
    
    
}


      
void initCar_EW(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
    TimerDisable(CarTimerEW, TIMER_A);
    SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER1);
    TimerConfigure(CarTimerEW, TIMER_CFG_A_PERIODIC);

    //Enable interrupts after timeout
    IntEnable(INT_TIMER1A);
    TimerIntEnable(CarTimerEW, TIMER_TIMA_TIMEOUT);
    TimerEnable(CarTimerEW, TIMER_A);
    
    
}

void initPedTimer(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
    TimerDisable(PedTimer, TIMER_A);
    SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER2);
    TimerConfigure(PedTimer, TIMER_CFG_A_PERIODIC);
  
    IntEnable(INT_TIMER2A);
    TimerIntEnable(PedTimer, TIMER_TIMA_TIMEOUT);
    TimerEnable(PedTimer, TIMER_A);
    
}







void CarNS_Delay(uint32_t delay)
{
    delay = (delay * 16000) - 1;
    TimerLoadSet(CarTimerNS, TIMER_A, delay);
    while(TimerIntStatus(CarTimerNS,true)!=1);
     NS_Light();
     TimerIntClear(CarTimerNS,TIMER_TIMA_TIMEOUT);
            



}

void CarEW_Delay(uint32_t delay)
{
    delay = (delay * 16000) - 1;
    TimerLoadSet(CarTimerEW, TIMER_A, delay);

}
void PedTimer_Delay(uint32_t delay)
{
    delay = (delay * 16000) - 1;
    TimerLoadSet(PedTimer, TIMER_A, delay);
    while( TimerIntStatus(PedTimer,true)!=1);

         


}



void CarNS_TIMA(void)
{


}


void CarEW_TIMA(void)
{




}



void PedTimer_TIMA(void)
{
  TimerIntClear(PedTimer,TIMER_TIMA_TIMEOUT);
}
