    // To unclock port
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    // To enable changes
    GPIO_PORTF_CR_R = 0x01;
    // Set input pins

    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
    // Set to pull up

    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    // Set output pins
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    // Priority

    // Enable the Timer0 peripheral //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    // Wait for the Timer0 module to be ready. //
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER0))
        ;
    // // Configure TimerA as a full-width periodic //
    TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
    TimerClockSourceSet(TIMER0_BASE, TIMER_CLOCK_SYSTEM);
    // // Set the count time //
    TimerLoadSet(TIMER0_BASE, TIMER_A, 15999999);
    TimerEnable(TIMER0_BASE, TIMER_A);
    TimerIntRegister(TIMER0_BASE, TIMER_A, timer0_handler);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    __asm("CPSID I");
    //initialization
    __asm("CPSIE I");
    IntEnable(INT_TIMER0A);