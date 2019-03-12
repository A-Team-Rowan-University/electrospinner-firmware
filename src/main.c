/**
 * @file main.c
 * @author John McAvoy
 * @date 28 Feb 2019
 */

#include <msp430.h>
#include <stdint.h>
#include "uart.h" // setup_led, setup_timer, set_duty_cycle

void stop_wdt() {
    WDTCTL = WDTPW | WDTHOLD;  // stop watchdog timer
}

int main(void)
{
    stop_wdt();
    setup_uart();
    __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0, interrupts enabled

}

// Echo back RXed character, confirm TX buffer is ready first
void __attribute__((interrupt(USCI_A1_VECTOR))) USCI_A1_ISR (void)
{
    uint8_t byteIn = UCA1RXBUF;
    uint8_t *bytePtr = &byteIn;

    send_bytes(bytePtr, 1);
}
