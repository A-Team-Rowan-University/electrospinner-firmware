/**
 * @file adc.c
 * @desc provides functions for operating the 10-bit analog digital converter
 * @author John McAvoy
 * @date 12 Mar 2019
 */

#include <msp430.h>
#include "adc.h"

/**
 * initilizes ADC12
 */
void setup_adc(void)
{
    // Enable A/D channel A0
    P6SEL |= 0x01;
    // Turn on ADC12, set sampling time
    ADC12CTL0 = ADC12ON + ADC12SHT0_8 + ADC12MSC;
    // set multiple sample conversion
    // Use sampling timer, set mode
    ADC12CTL1 = ADC12SHP + ADC12CONSEQ_2;
    ADC12CTL0 |= ADC12ENC; // Enable conversions
    ADC12CTL0 |= ADC12SC;  // Start conversion
}


void start_sampling_conversion(void) {
    // TODO
}
