/* mbed Microcontroller Library
 * Copyright (c) 2022 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "../JoystickPS3/JoystickPS3.h"
#include "../servoKRAI/servoKRAI.h"

#define SERVO PB_3

servoKRAI servo(SERVO, 0.0);

FileHandle *mbed::mbed_override_console(int fd)
{
    static BufferedSerial serial_port(USBTX, USBRX, 115200);
    return &serial_port;
}

int main()
{
    while(true){
        servo.position(50.0);

        printf("Nigel Sahl\n");
        
        wait_us(1000000);
        servo.position(0.0);

        printf("Nigel\n");

        wait_us(1000000);

    }
    // printf("Hello, Mbed!\n");
    return 0;
}