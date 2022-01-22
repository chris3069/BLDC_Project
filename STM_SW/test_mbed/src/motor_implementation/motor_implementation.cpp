#include "motor_implementation.hpp"
// #include "pin_config.hpp"

// Motor_Implementation::Motor_Implementation()
//   // :motor(BLDCMotor(3)), driver(BLDCDriver3PWM(9, 10, 11, 6))
// {
//   motor = new BLDCMotor(11);
//   driver = new BLDCDriver3PWM(9, 10, 11, 6);
//       // driver config
//   // power supply voltage [V]
//   // driver->voltage_power_supply = 12;
//   // driver->init();
//   // // link the motor and the driver
//   // motor->linkDriver(driver);

//   // // limiting motor movements
//   // motor->voltage_limit = 3;   // [V]
//   // motor->velocity_limit = 5; // [rad/s] cca 500rpm
// }


// Motor_Implementation::Motor_Implementation(BLDCMotor *ext_motor, BLDCDriver3PWM *ext_driver)
//   :motor(ext_motor), driver(ext_driver)
// {
//   // motor = new BLDCMotor(3);
//   // driver = new BLDCDriver3PWM(9, 10, 11, 6);
//       // driver config
//   // power supply voltage [V]
//   driver->voltage_power_supply = 12;
//   driver->init();
//   // link the motor and the driver
//   motor->linkDriver(driver);

//   // limiting motor movements
//   motor->voltage_limit = 3;   // [V]
//   motor->velocity_limit = 50; // [rad/s] cca 500rpm
//   motor->current_limit = 200; // 2 A 
// }

// Motor_Implementation::~Motor_Implementation()
// {
//   delete driver;
//   delete motor;
// }

  
// void Motor_Implementation::start_motor_control(void)
// {
//   digitalWrite(INH, true);
// }


// void Motor_Implementation::motor_control(float velocity)
// {
//   motor->move(velocity);
// }










//   BLDCMotor motor = BLDCMotor(3);
//   BLDCDriver3PWM driver = BLDCDriver3PWM(9, 10, 11, 6);

// void motor_implementation_init(void)
// {
//   // driver config
//   // power supply voltage [V]
//   driver.voltage_power_supply = 12;
//   driver.init();
//   // link the motor and the driver
//   motor.linkDriver(&driver);

//   // limiting motor movements
//   motor.voltage_limit = 3;   // [V]
//   motor.velocity_limit = 5; // [rad/s] cca 50rpm
 
//   // open loop control config
//   motor.controller = MotionControlType::velocity_openloop;

//   // init motor hardware
//   motor.init();

//   // add target command T
//   // command.add('T', doTarget, "target velocity");


//   Serial.println("Motor ready!");
//   Serial.println("Set target velocity [rad/s]");
//   _delay(1000);
// }

// void motor_implementation_control(float velocity)
// {
//   motor.move(velocity);
// }

// // void reset_motor_control(void (*pResetTargetSpeed)())
// void reset_motor_control(void)
// {
//     // set desired speed to 0
//   // digitalWrite(INH, false);
//   // pResetTargetSpeed();
//   // Serial.println("Reset Button Ṕressed -> Reset Motor Control");

// }

// void start_motor_control(void)
// {
//   digitalWrite(INH, true);
// }



