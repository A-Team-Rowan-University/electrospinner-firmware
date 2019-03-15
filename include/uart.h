/**
 * @file uart.h
 * @desc provides functions for UART communication
 * @author John McAvoy
 * @date 14 Mar 2019
 */

#ifndef _UART_H
#define _UART_H

#include <stdint.h>

/**
 * configures UART for baud 9600
 */
void init_uart(void);

/**
 * sends bytes via uart
 * @param bytes     pointer to a byte buffer
 * @param length    the length of the byte buffer to be transmitted
 */
void send_bytes( uint8_t* bytes, uint8_t length);

#endif // _UART_H
