#include <libopencm3/cm3/common.h>

#include "rtos-rigel.h"

#include "debug.h"

/* NOTE: these handlers are different to
 * libopencm3's default null/blocking handlers -
 * each isr gets its own function, making it
 * easier to figure out which isr was fired.
 * Additionally they spit out the isr ID.*/

#define BLOCKING_HANDLER(NAME_ISR) \
    void NAME_ISR(void) \
    { \
        debug_println(#NAME_ISR " - blocking..."); \
        for(;;); \
    }

#define NULL_HANDLER(NAME_ISR) \
    void NAME_ISR(void) \
    { \
    }

/* This 'fatal' handler is called by the RTOS
 * if any internal logic checks fail. Possible
 * causes are often memory corruption or
 * impossible scheduling deadlines */

void
fatal(const RtosErrorId error_id)
{
    debug_print("RTOS FATAL ERROR: ");
    debug_printhex32(error_id);
    debug_println("");
    for (;;)
    {
    }
}

void
systick_isr(void)
{
    debug_println("systick");
    rtos_timer_tick();
}

/* TODO: Remove the below handlers and redeclare
 * your own handler to use an ISR for your own purposes. */

/* CORTEX-M GENERIC ISRS */

BLOCKING_HANDLER(nmi_isr)
BLOCKING_HANDLER(hardfault_isr)
BLOCKING_HANDLER(memmanage_isr)
BLOCKING_HANDLER(busfault_isr)
BLOCKING_HANDLER(usagefault_isr)
BLOCKING_HANDLER(svcall_isr)
BLOCKING_HANDLER(debug_monitor_isr)
BLOCKING_HANDLER(pendsv_isr)

/* PERIPHERAL/EXTERNAL ISRS (automatically populated)*/

BLOCKING_HANDLER(GPIOA_isr)
BLOCKING_HANDLER(GPIOB_isr)
BLOCKING_HANDLER(GPIOC_isr)
BLOCKING_HANDLER(GPIOD_isr)
BLOCKING_HANDLER(GPIOE_isr)
BLOCKING_HANDLER(UART0_isr)
BLOCKING_HANDLER(UART1_isr)
BLOCKING_HANDLER(SSI0_isr)
BLOCKING_HANDLER(I2C0_isr)
BLOCKING_HANDLER(PWM0_FAULT_isr)
BLOCKING_HANDLER(PWM0_0_isr)
BLOCKING_HANDLER(PWM0_1_isr)
BLOCKING_HANDLER(PWM0_2_isr)
BLOCKING_HANDLER(QEI0_isr)
BLOCKING_HANDLER(ADC0SS0_isr)
BLOCKING_HANDLER(ADC0SS1_isr)
BLOCKING_HANDLER(ADC0SS2_isr)
BLOCKING_HANDLER(ADC0SS3_isr)
BLOCKING_HANDLER(WATCHDOG_isr)
BLOCKING_HANDLER(TIMER0A_isr)
BLOCKING_HANDLER(TIMER0B_isr)
BLOCKING_HANDLER(TIMER1A_isr)
BLOCKING_HANDLER(TIMER1B_isr)
BLOCKING_HANDLER(TIMER2A_isr)
BLOCKING_HANDLER(TIMER2B_isr)
BLOCKING_HANDLER(COMP0_isr)
BLOCKING_HANDLER(COMP1_isr)
BLOCKING_HANDLER(COMP2_isr)
BLOCKING_HANDLER(SYSCTL_isr)
BLOCKING_HANDLER(FLASH_isr)
BLOCKING_HANDLER(GPIOF_isr)
BLOCKING_HANDLER(GPIOG_isr)
BLOCKING_HANDLER(GPIOH_isr)
BLOCKING_HANDLER(UART2_isr)
BLOCKING_HANDLER(SSI1_isr)
BLOCKING_HANDLER(TIMER3A_isr)
BLOCKING_HANDLER(TIMER3B_isr)
BLOCKING_HANDLER(I2C1_isr)
BLOCKING_HANDLER(QEI1_isr)
BLOCKING_HANDLER(CAN0_isr)
BLOCKING_HANDLER(CAN1_isr)
BLOCKING_HANDLER(CAN2_isr)
BLOCKING_HANDLER(ETH_isr)
BLOCKING_HANDLER(HIBERNATE_isr)
BLOCKING_HANDLER(USB0_isr)
BLOCKING_HANDLER(PWM0_3_isr)
BLOCKING_HANDLER(UDMA_isr)
BLOCKING_HANDLER(UDMAERR_isr)
BLOCKING_HANDLER(ADC1SS0_isr)
BLOCKING_HANDLER(ADC1SS1_isr)
BLOCKING_HANDLER(ADC1SS2_isr)
BLOCKING_HANDLER(ADC1SS3_isr)
BLOCKING_HANDLER(I2S0_isr)
BLOCKING_HANDLER(EPI0_isr)
BLOCKING_HANDLER(GPIOJ_isr)
BLOCKING_HANDLER(GPIOK_isr)
BLOCKING_HANDLER(GPIOL_isr)
BLOCKING_HANDLER(SSI2_isr)
BLOCKING_HANDLER(SSI3_isr)
BLOCKING_HANDLER(UART3_isr)
BLOCKING_HANDLER(UART4_isr)
BLOCKING_HANDLER(UART5_isr)
BLOCKING_HANDLER(UART6_isr)
BLOCKING_HANDLER(UART7_isr)
BLOCKING_HANDLER(I2C2_isr)
BLOCKING_HANDLER(I2C3_isr)
BLOCKING_HANDLER(TIMER4A_isr)
BLOCKING_HANDLER(TIMER4B_isr)
BLOCKING_HANDLER(TIMER5A_isr)
BLOCKING_HANDLER(TIMER5B_isr)
BLOCKING_HANDLER(WTIMER0A_isr)
BLOCKING_HANDLER(WTIMER0B_isr)
BLOCKING_HANDLER(WTIMER1A_isr)
BLOCKING_HANDLER(WTIMER1B_isr)
BLOCKING_HANDLER(WTIMER2A_isr)
BLOCKING_HANDLER(WTIMER2B_isr)
BLOCKING_HANDLER(WTIMER3A_isr)
BLOCKING_HANDLER(WTIMER3B_isr)
BLOCKING_HANDLER(WTIMER4A_isr)
BLOCKING_HANDLER(WTIMER4B_isr)
BLOCKING_HANDLER(WTIMER5A_isr)
BLOCKING_HANDLER(WTIMER5B_isr)
BLOCKING_HANDLER(SYSEXC_isr)
BLOCKING_HANDLER(PECI0_isr)
BLOCKING_HANDLER(LPC0_isr)
BLOCKING_HANDLER(I2C4_isr)
BLOCKING_HANDLER(I2C5_isr)
BLOCKING_HANDLER(GPIOM_isr)
BLOCKING_HANDLER(GPION_isr)
BLOCKING_HANDLER(FAN0_isr)
BLOCKING_HANDLER(GPIOP0_isr)
BLOCKING_HANDLER(GPIOP1_isr)
BLOCKING_HANDLER(GPIOP2_isr)
BLOCKING_HANDLER(GPIOP3_isr)
BLOCKING_HANDLER(GPIOP4_isr)
BLOCKING_HANDLER(GPIOP5_isr)
BLOCKING_HANDLER(GPIOP6_isr)
BLOCKING_HANDLER(GPIOP7_isr)
BLOCKING_HANDLER(GPIOQ0_isr)
BLOCKING_HANDLER(GPIOQ1_isr)
BLOCKING_HANDLER(GPIOQ2_isr)
BLOCKING_HANDLER(GPIOQ3_isr)
BLOCKING_HANDLER(GPIOQ4_isr)
BLOCKING_HANDLER(GPIOQ5_isr)
BLOCKING_HANDLER(GPIOQ6_isr)
BLOCKING_HANDLER(GPIOQ7_isr)
BLOCKING_HANDLER(PWM1_0_isr)
BLOCKING_HANDLER(PWM1_1_isr)
BLOCKING_HANDLER(PWM1_2_isr)
BLOCKING_HANDLER(PWM1_3_isr)
BLOCKING_HANDLER(PWM1_FAULT_isr)