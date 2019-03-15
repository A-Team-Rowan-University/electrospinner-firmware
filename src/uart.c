/**
 * @file uart.c
 * @desc provides functions for UART communication
 * @author John McAvoy
 * @date 14 Mar 2019
 */

#include <msp430.h>
#include <stdint.h>
#include "uart.h"

void init_uart()
{
    // P3.3,4 = USCI_A0 TXD/RXD
    P4SEL |= BIT4+BIT5;
    // Put state machine in reset, SMCLK
    UCA1CTL1 |= (UCSWRST + UCSSEL_2);
    // 1MHz 115200 (see User's Guide)
    UCA1BR0 = 9u;
    UCA1BR1 = 0u;
    // Modulation UCBRSx=1, UCBRFx=0
    UCA1MCTL |= (UCBRS_1 + UCBRF_0);
    // Initialize USCI state machine
    UCA1CTL1 &= ~UCSWRST;
    // Enable USCI_A0 RX interrupt
    UCA1IE |= UCRXIE;

}

void send_bytes(uint8_t *bytes, uint8_t length)
{
    while(length--)
        {
            while (!(UCA1IFG & UCTXIFG));             // USCI_A1 TX buffer ready?
            UCA1TXBUF = *bytes; //Write the character
            bytes++; //Increment the bytes pointer to point to the next character
        }
}
