#include <reg51.h>
#include "uart.h"

// Motor Pins
sbit BASE_L = P2^0;
sbit BASE_R = P2^1;
sbit ARM_UP = P2^2;
sbit ARM_DN = P2^3;
sbit GRIP_OP = P2^4;
sbit GRIP_CL = P2^5;

void stop_all() {
    BASE_L = BASE_R = 0;
    ARM_UP = ARM_DN = 0;
    GRIP_OP = GRIP_CL = 0;
}

void main() {
    char cmd;
    UART_Init();

    while(1) {
        cmd = UART_Read();

        switch(cmd) {

            case 'F': BASE_L = 1; BASE_R = 0; break;
            case 'B': BASE_L = 0; BASE_R = 1; break;
            case 'S': BASE_L = BASE_R = 0; break;

            case 'U': ARM_UP = 1; ARM_DN = 0; break;
            case 'D': ARM_UP = 0; ARM_DN = 1; break;
            case 'A': ARM_UP = ARM_DN = 0; break;

            case 'O': GRIP_OP = 1; GRIP_CL = 0; break;
            case 'C': GRIP_OP = 0; GRIP_CL = 1; break;

            default: stop_all();
        }
    }
}
