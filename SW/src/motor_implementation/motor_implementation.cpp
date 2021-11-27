#include "motor_implementation.hpp"
#include "pin_config.hpp"

#include <Wire.h>
#include <SPI.h>
#include <SimpleFOC.h>



BLDCMotor motor = BLDCMotor(3);

BLDCDriver3PWM driver = BLDCDriver3PWM(9, 10, 11, 6);


void motor_implementation_init(void)
{
  // driver config
  // power supply voltage [V]
  driver.voltage_power_supply = 12;
  driver.init();
  // link the motor and the driver
  motor.linkDriver(&driver);

  // limiting motor movements
  motor.voltage_limit = 3;   // [V]
  motor.velocity_limit = 5; // [rad/s] cca 50rpm
 
  // open loop control config
  motor.controller = MotionControlType::velocity_openloop;

  // init motor hardware
  motor.init();

  // add target command T
  // command.add('T', doTarget, "target velocity");


  Serial.println("Motor ready!");
  Serial.println("Set target velocity [rad/s]");
  _delay(1000);
}

void motor_implementation_control(float velocity)
{
  motor.move(velocity);
}

// void reset_motor_control(void (*pResetTargetSpeed)())
void reset_motor_control(void)
{
    // set desired speed to 0
  // digitalWrite(INH, false);
  // pResetTargetSpeed();
  // Serial.println("Reset Button Ṕressed -> Reset Motor Control");

}

void start_motor_control(void)
{
  digitalWrite(INH, true);
}



