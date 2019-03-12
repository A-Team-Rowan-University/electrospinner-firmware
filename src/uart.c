// uart.c

#include <msp430.h>
#include <stdint.h>
#include "uart.h"

void setup_uart() {
    /* Configure hardware UART */
    P4SEL |= BIT4+BIT5;                       // P3.3,4 = USCI_A0 TXD/RXD
    UCA1CTL1 |= UCSWRST;                      // **Put state machine in reset**
    UCA1CTL1 |= UCSSEL_2;                     // SMCLK
    UCA1BR0 = 9;                              // 1MHz 115200 (see User's Guide)
    UCA1BR1 = 0;                              // 1MHz 115200
    UCA1MCTL |= UCBRS_1 + UCBRF_0;            // Modulation UCBRSx=1, UCBRFx=0
    UCA1CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
    UCA1IE |= UCRXIE;                         // Enable USCI_A0 RX interrupt

}

void send_bytes(uint8_t *bytes, uint8_t length) {
    while(length--) {
        while (!(UCA1IFG & UCTXIFG));             // USCI_A1 TX buffer ready?
        UCA1TXBUF = *bytes; //Write the character
        bytes++; //Increment the bytes pointer to point to the next character
    }
}
