/**
 * @file stepper_motor.c
 * @desc provides functions for controlling the stepper motor using the A4988 stepper driver
 * @author John McAvoy
 * @date 12 Mar 2019
 */
#include <msp430.h>
#include <stdint.h>
#include "stepper_motor.h"

#define ENABLE_PIN  BIT6 // P1.6
#define RESET_PIN   BIT7 // P1.7
#define SLEEP_PIN   BIT0 // P2.0
#define STEP_PIN    BIT1 // P2.1
#define MS1_PIN     BIT2 // P2.2
#define MS2_PIN     BIT3 // P2.3
#define MS3_PIN     BIT4 // P2.4
#define DIR_PIN     BIT5 // P2.5

/**
 * initializes the stepper driver pins
 */
void init_stepper_driver(void)
{
    // set pins to I/O mode
    P1SEL |= (ENABLE_PIN + RESET_PIN);
    P2SEL |= (SLEEP_PIN + STEP_PIN + MS1_PIN + MS2_PIN + MS3_PIN + DIR_PIN);

    // set pins to output mode
    P1DIR |= (ENABLE_PIN + RESET_PIN);
    P2DIR |= (SLEEP_PIN + STEP_PIN + MS1_PIN + MS2_PIN + MS3_PIN + DIR_PIN);

    // set pins to logic low
    P1OUT |= (ENABLE_PIN + RESET_PIN);
    P2OUT |= (SLEEP_PIN + STEP_PIN + MS1_PIN + MS2_PIN + MS3_PIN + DIR_PIN);

}

/**
 * configures the stepper driver in the mode corresponding to the desired stepper rate
 * @param *stepper  pointer to the desired stepper state
 */
void set_stepper(Stepper *stepper)
{
    // TODO
}

/**
 * enables stepper driver
 */
void enable_stepper()
{
    P1OUT &= ~(ENABLE_PIN);
}
