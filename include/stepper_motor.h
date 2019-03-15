/**
 * @file stepper+motor.h
 * @desc provides functions for controlling the stepper motor using the A4988 stepper driver
 * @author John McAvoy
 * @date 12 Mar 2019
 */

#ifndef _STEPPER_MOTOR_H
#define _STEPPER_MOTOR_H

#include <stdint.h>

/**
 * represents the direction the motor
 */
typedef enum Direction
{
    UP, ///< the motor is moving the apparatus upward
    DOWN ///< the motor is moving the apparatus downward (aka pulling down the fibers)
} Direction;

/**
 * represents the 5 different microstep modes
 */
typedef enum MicrostepResolution
{
    FULL_STEP,      ///< 360 degrees per step
    HALF_STEP,      ///< 180 degrees per step
    QUARTER_STEP,   ///< 90 degrees per step
    EIGHTH_STEP,    ///< 45 degrees per step
    SIXTEENTH_STEP  ///< 22.5 degrees per step
} MicrostepResolution;

/**
 * represents a valid stepper rate
 */
typedef struct Stepper
{
    MicrostepResolution microstepResoution; ///< TODO
    Direction direction; ///< TODO
} Stepper;

/**
 * initilizes the stepper driver pins
 */
void init_stepper_driver(void);

/**
 * configures the stepper driver in the mode corresponding to the desired stepper rate
 * @param rate  the desired stepper rate
 */
void set_stepper(Stepper *stepper);

#endif // _STEPPER_MOTOR_H
