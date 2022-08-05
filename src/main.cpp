/* mbed Microcontroller Library
 * Copyright (c) 2022 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "../encoderKRAI/encoderKRAI.h"
#include "../Joystick_PS3/JoystickPS3.h"
#include "../servo_KRAI/servoKRAI.h"
#include "../Motors/Motor.h"
#include "../pidLo/pidLo.h"

#define ENCODER1_CHA PC_1
#define ENCODER1_CHB PC_0
#define ENCODER1_PPR 538
#define ENCODER1_RES X4_ENCODING

#define ENCODER2_CHA PC_5
#define ENCODER2_CHB PC_4
#define ENCODER2_PPR 538
#define ENCODER2_RES X4_ENCODING

#define ENCODER3_CHA PB_14
#define ENCODER3_CHB PB_2
#define ENCODER3_PPR 538
#define ENCODER3_RES X4_ENCODING

#define ENCODER4_CHA PB_15
#define ENCODER4_CHB PC_8
#define ENCODER4_PPR 538
#define ENCODER4_RES X4_ENCODING

#define ENCODER5_CHA PA_13
#define ENCODER5_CHB PA_12
#define ENCODER5_PPR 538
#define ENCODER5_RES X4_ENCODING


#define KP 0.005
#define KI 0.00005
#define KD 0
#define TS 0.001

#define MAXOUT 1
#define VFF 0
#define RPF 1000
#define MAXIN 100

// DigitalOut led(LED1);
// servoKRAI servo(SERVO);
// JoystickPS3 StickPS(PC_12,PD_2);
Motor motor(PB_9, PC_2, PC_3);
pidLo PID(KP, KI, KD, TS, MAXOUT, VFF, RPF, MAXIN);
encoderKRAI enc1(ENCODER1_CHA, ENCODER1_CHB, ENCODER1_PPR, Encoding::X4_ENCODING);
encoderKRAI enc2(ENCODER2_CHA, ENCODER2_CHB, ENCODER2_PPR, Encoding::X4_ENCODING);
encoderKRAI enc3(ENCODER3_CHA, ENCODER3_CHB, ENCODER3_PPR, Encoding::X4_ENCODING);
encoderKRAI enc4(ENCODER4_CHA, ENCODER4_CHB, ENCODER4_PPR, Encoding::X4_ENCODING);
encoderKRAI enc5(ENCODER5_CHA, ENCODER5_CHB, ENCODER5_PPR, Encoding::X4_ENCODING);

float B1, B2, B3;
int target = 2000;

int pulse = 0;
float pwm = 0;


FileHandle *mbed::mbed_override_console(int fd)
{
    static BufferedSerial serial_port(USBTX, USBRX, 115200);
    return &serial_port;
}


int main()
{
    int timer = 0;
    
    while(true){
        
        if((us_ticker_read() - timer) > TS*1000){
            timer = us_ticker_read();

            pulse = enc2.getPulses();

            pwm = PID.createpwm(target, pulse, 0.5);

            motor.speed(pwm);
            printf("%d %d %f\n", pulse, target, pwm);
            // printf("%d %d %d %d %d\n", enc1.getPulses(), enc2.getPulses(), enc3.getPulses(), enc4.getPulses(), enc5.getPulses());
        }
    }
    // printf("Hello, Mbed!\n");
    return 0;
}