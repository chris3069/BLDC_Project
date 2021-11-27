#ifndef motor_implementation_h
#define motor_implementation_h

#include <Arduino.h>

void motor_implementation_init(void);
void motor_implementation_control(float velocity);
void reset_motor_control(void);
// void reset_motor_control(void (*pResetTargetSpeed)());
void start_motor_control(void);

#endif



