#ifndef motor_implementation_h
#define motor_implementation_h

#include <Arduino.h>

#include <Wire.h>
#include <SPI.h>
#include <SimpleFOC.h>

class Motor_Implementation
{
  public:
    virtual void motor_implementation_init(void) = 0;
    virtual void motor_control(float velocity) = 0;
    // virtual void reset_motor_control(void);
    static void start_motor_control(void);
    Motor_Implementation();
    virtual ~Motor_Implementation() = 0;

  protected:

    BLDCMotor motor;

    BLDCDriver3PWM driver;

};


// void motor_implementation_init(void);
// void motor_implementation_control(float velocity);
// void reset_motor_control(void);
// // void reset_motor_control(void (*pResetTargetSpeed)());
// void start_motor_control(void);

#endif



