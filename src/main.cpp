/* mbed Microcontroller Library
 * Copyright (c) 2022 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "../Joystick_PS3/JoystickPS3.h"
#include "../servo_KRAI/servoKRAI.h"
#include "../Motors/Motor.h"

#define SERVO PB_5

DigitalOut led(LED1);
servoKRAI servo(SERVO);
JoystickPS3 StickPS(PC_12,PD_2);
Motor motor(SERVO, PC_10, PC_13);

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

        if (StickPS.getButtonDown() && (StickPS.getR1() )){
            led=0;   
        }

        // if (StickPS.getButtonUp())
        //     led=1; 

        // if (StickPS.getRX()==-128) // analog kanan : kanan
        // servo.position(50);
        // wait_us(3000000);
        // servo.position(0);
        // wait_us(3000000);

        // motor.speed(0.5);
        // wait_us(1000000);
        // motor.speed(0);
        // wait_us(1000000);
        // if (StickPS.getRX()==127) // analog kanan : kanan
        // if (StickPS.getRX()==-128) // analog kanan : kiri 
        // if (StickPS.getRY()==127) // analog kanan : bawah
        // if (StickPS.getRY()==-128) // analog kanan : atas

        // if (StickPS.getLX()==127) // analog kiri : kanan
        // if (StickPS.getLX()==-128) // analog kiri : kiri 
        // if (StickPS.getLY()==127) // analog kiri : bawah
        // if (StickPS.getLY()==-128) // analog kiri : atas




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