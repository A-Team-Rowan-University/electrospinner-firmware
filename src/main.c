/**
 * @file main.c
 * @author John McAvoy
 * @date 28 Feb 2019
 */

#include <msp430.h>
#include <stdint.h>
#include "adc.h"
#include "stepper_motor.h" // init_stepper_driver
#include "uart.h" // setup_timer, set_duty_cycle

/**
 * stops the watchdog timer
 */
void stop_wdt();

/**
 * USCI_A1 inntertupt service routine
 */
void __attribute__((interrupt(USCI_A1_VECTOR))) USCI_A1_ISR (void);

int main(void)
{
    stop_wdt();
    init_uart();
    init_stepper_driver();
    __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0, interrupts enabled

}

void stop_wdt()
{
    WDTCTL = WDTPW | WDTHOLD;  // stop watchdog timer
}

void __attribute__((interrupt(USCI_A1_VECTOR))) USCI_A1_ISR (void)
{
    uint8_t byteIn = UCA1RXBUF;
    uint8_t *bytePtr = &byteIn;

    send_bytes(bytePtr, 1);
}
