#include <reg51.h>
#include "uart.h"

void UART_Init() {
    TMOD = 0x20;    // Timer1 mode 2
    TH1 = 0xFD;     // 9600 baud (11.0592 MHz)
    SCON = 0x50;    // 8-bit UART
    TR1 = 1;        // Start Timer
}

char UART_Read() {
    while(RI == 0);
    RI = 0;
    return SBUF;
}
