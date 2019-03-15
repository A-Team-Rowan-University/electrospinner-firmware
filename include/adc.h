/**
 * @file adc.h
 * @desc provides functions for operating the 10-bit analog digital converter
 * @author John McAvoy
 * @date 12 Mar 2019
 */

#ifndef _ADC_H
#define _ADC_H

/**
 * configures adc v ref and interrupt
 */
void setup_adc(void);

/**
 * starts adc sampling/conversion
 */
void start_sampling_conversion(void);

#endif // _ADC_H
