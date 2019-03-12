// uart.h

#include <stdint.h>

// configures UART for baud 9600
void setup_uart();

void send_bytes(uint8_t* bytes, uint8_t length);
