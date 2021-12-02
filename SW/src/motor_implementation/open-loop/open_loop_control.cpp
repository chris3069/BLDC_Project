#include "open_loop_control.hpp"

Open_Loop::Open_Loop(BLDCMotor *ext_motor, BLDCDriver3PWM *ext_driver)
  :Motor_Implementation(motor, driver)
{

}

Open_Loop::Open_Loop()
  :Motor_Implementation()
{

}



void Open_Loop::motor_implementation_init(void)
{
  driver->voltage_power_supply = 12;
  driver->init();
  // link the motor and the driver
  motor->linkDriver(driver);

  // limiting motor movements
  motor->voltage_limit = 3;   // [V]
  motor->velocity_limit = 5; // [rad/s] cca 500rpm


    // open loop control config
  motor->controller = MotionControlType::velocity_openloop;

  // init motor hardware
  motor->init();
  Serial.println("Motor ready!");
  Serial.println("Set target velocity [rad/s]");
  _delay(1000);
}


void Open_Loop::motor_control(float velocity)
{
  motor->move(velocity);
}

Open_Loop::~Open_Loop()
{

}