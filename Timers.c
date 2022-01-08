#include "Timers.h"
#include "CarTraffic.h"
#include "PedTraffic.h"
void initCarTimer(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
    TimerDisable(CarTimer, TIMER_A);
    SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER1);
    TimerConfigure(CarTimer, TIMER_CFG_A_PERIODIC);

    IntEnable(INT_TIMER1A);
    TimerIntEnable(CarTimer, TIMER_TIMA_TIMEOUT);
    TimerEnable(CarTimer, TIMER_A);
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

void CarTraffic_Delay(uint32_t delay)
{
    delay = (delay * 16000) - 1;
    TimerLoadSet(CarTimer, TIMER_A, delay);
}

void PedTimer_Delay(uint32_t delay)
{
    delay = (delay * 16000) - 1;
    TimerLoadSet(PedTimer, TIMER_A, delay);
}

void CarTimer_TIMEOUT(void)
{
    TimerIntClear(CarTimer, TIMER_TIMA_TIMEOUT);
    FSM_Car_State = FSM_CarTL[FSM_Car_State].Next;
    CarTraffic_Delay(FSM_CarTL[FSM_Car_State].Time);
    GPIOPinWrite(Car_BASE, GreenNS | YellowNS | RedNS, FSM_CarTL[FSM_Car_State].Out);
    GPIOPinWrite(Car_BASE, GreenEW | YellowEW | RedEW, FSM_CarTL[FSM_Car_State].Out);
    TimerEnable(CarTimer, TIMER_A);
}

void PedTimer_TIMA(void)
{
    //Disable the timer and Clear Interrupt
    TimerIntClear(PedTimer,TIMER_TIMA_TIMEOUT);
    //Fsm state change
    FSM_Ped_State=FSM_PedTL[FSM_Ped_State].Next;

    //Write All traffic Light LEDs
  
    GPIOPinWrite(Ped_BASE, PedGreen_NS|PedRed_NS, FSM_PedTL[FSM_Ped_State].PedOut);
    GPIOPinWrite(Ped_BASE, PedGreen_EW|PedRed_EW, FSM_PedTL[FSM_Ped_State].PedOut);

}
