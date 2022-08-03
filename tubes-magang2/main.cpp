/* mbed Microcontroller Library
 * Copyright (c) 2022 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "../Joystick_PS3/JoystickPS3.h"
#include "../servo_KRAI/servoKRAI.h"

#define SERVO PB_3

DigitalOut led(LED1);
servoKRAI servo(SERVO, 0.0);
JoystickPS3 StickPS(PC_12,PD_2);

float B1, B2, B3;


FileHandle *mbed::mbed_override_console(int fd)
{
    static BufferedSerial serial_port(USBTX, USBRX, 115200);
    return &serial_port;
}


int main()
{
    led=0;
    StickPS.setup();
    StickPS.stickState(&B1, &B2, &B3);
    while(true){
        StickPS.baca_data();

        if (StickPS.getButtonDown() && StickPS.getLingkaran()){
            led=0;   
        }

        if (StickPS.getButtonUp())
            led=1; 

        // if (StickPS.getLingkaran())

        // servo.position(50.0);

        // printf("Nigel Sahl\n");
        
        // wait_us(1000000);
        // servo.position(0.0);

        // printf("Nigel\n");

        // wait_us(1000000);

        // printf("%d %d %d/n", B1, B2, B3);

    }
    // printf("Hello, Mbed!\n");
    return 0;
}