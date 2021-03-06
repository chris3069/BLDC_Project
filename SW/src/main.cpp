// Open Loop Control
//////////////////////////////////////////////////////////////////////////////////////

// #include "main.hpp"

// void (*pReset_target_speed)(void) = reset_target_speed;

// void (*restart_motor)(void) = Motor_Implementation::start_motor_control;

// float (*desired_speed)(void) = getTargetSpeed;

// //  Motor_Implementation *Abstarct_motor;

// void setup() 
// {
//   Serial.begin(115200);
// Serial.println("1 Main Setup");
// _delay(100);

//   // Open_Loop *Abstract_motor = new Open_Loop;
// Closed_Loop *Abstract_motor = new Closed_Loop;
// _delay(100);
// Serial.println("2");
//   // Abstarct_motor = new Open_Loop;
//   // Closed_Loop Abstract_motor;

//   Abstract_motor->motor_implementation_init();
// Serial.println("3 Setup");
//   init_button(pReset_target_speed);

//   while(1)
//   {
//   read_buttons(restart_motor); 
//   Abstract_motor->motor_control(desired_speed());
//   }
// }

////////////////////////////////////////////////////////////////////////////////////////////

/**
 *
 * Velocity motion control example
 * Steps:
 * 1) Configure the motor and sensor
 * 2) Run the code
 * 3) Set the target velocity (in radians per second) from serial terminal
 *
 *
 *
 * NOTE :
 * > Specifically for Arduino UNO example code for running velocity motion control using a hall sensor
 * > Since Arduino UNO doesn't have enough interrupt pins we have to use software interrupt library PciManager.
 *
 * > If running this code with Nucleo or Bluepill or any other board which has more than 2 interrupt pins
 * > you can supply doC directly to the sensor.enableInterrupts(doA,doB,doC) and avoid using PciManger
 *
 */

// Closed Loop Control

#include "pin_config.hpp"
#include "button_implementation/button_implementation.hpp"
#include "encoder_implementation/encoder_implementation.hpp"

#include <SimpleFOC.h>
// software interrupt library
#include <PciManager.h>
#include <PciListenerImp.h>

// BLDC motor & driver instance
BLDCMotor motor = BLDCMotor(11);
BLDCDriver3PWM driver = BLDCDriver3PWM(9, 10, 11, 6);
// Stepper motor & driver instance
//StepperMotor motor = StepperMotor(50);
//StepperDriver4PWM driver = StepperDriver4PWM(9, 5, 10, 6,  8);

// hall sensor instance
HallSensor sensor = HallSensor(2, 3, 4, 11);

InlineCurrentSense currentsense(1, 1, IS0, IS1, IS2);;

void (*pReset_target_speed)(void) = reset_target_speed;
float (*desired_speed)(void) = getTargetSpeed;
void restart_motor(void)
{
  digitalWrite(INH, true);
}


// Interrupt routine intialisation
// channel A and B callbacks
void doA(){sensor.handleA();}
void doB(){sensor.handleB();}
void doC(){sensor.handleC();}
// If no available hadware interrupt pins use the software interrupt
PciListenerImp listenerIndex(sensor.pinC, doC);

// velocity set point variable
float target_velocity = 0;
// instantiate the commander
Commander command = Commander(Serial);
void doTarget(char* cmd) { command.scalar(&target_velocity, cmd); }

void setup() {

  // initialize sensor sensor hardware
  sensor.init();
  sensor.enableInterrupts(doA, doB); //, doC);
  // software interrupts
  PciManager.registerListener(&listenerIndex);
  // link the motor to the sensor
  motor.linkSensor(&sensor);

  currentsense.init();

  // driver config
  // power supply voltage [V]
  driver.voltage_power_supply = 12;
  driver.init();
  // link the motor and the driver
  motor.linkDriver(&driver);

  // aligning voltage [V]
  motor.voltage_sensor_align = 3;

  // set motion control loop to be used
  motor.controller = MotionControlType::velocity;

  // contoller configuration
  // default parameters in defaults.h

  // velocity PI controller parameters
  motor.PID_velocity.P = 0.2f;
  motor.PID_velocity.I = 2;
  motor.PID_velocity.D = 0;
  // default voltage_power_supply
  motor.voltage_limit = 12;
  // jerk control using voltage voltage ramp
  // default value is 300 volts per sec  ~ 0.3V per millisecond
  motor.PID_velocity.output_ramp = 1000;
  motor.velocity_limit = 500; // [rad/s] cca 500rpm
  motor.current_limit = 200; // 2 A 

  // velocity low pass filtering time constant
  motor.LPF_velocity.Tf = 0.01f;

  // use monitoring with serial
  Serial.begin(115200);
  // comment out if not needed
  // motor.useMonitoring(Serial);
motor.linkCurrentSense(&currentsense);     // include this function 
  // initialize motor
  motor.init();
  // align sensor and start FOC
  motor.initFOC();

  // add target command T
  // command.add('T', doTarget, "target voltage");

  Serial.println(F("Motor ready."));
  Serial.println(F("Set the target velocity using serial terminal:"));

    init_button(pReset_target_speed);

  _delay(1000);
}


void loop() {
  // main FOC algorithm function
  // the faster you run this function the better
  // Arduino UNO loop  ~1kHz
  // Bluepill loop ~10kHz
  motor.loopFOC();

  // Motion control function
  // velocity, position or voltage (defined in motor.controller)
  // this function can be run at much lower frequency than loopFOC() function
  // You can also use motor.move() and set the motor.target in the code
  motor.move(target_velocity);

  // function intended to be used with serial plotter to monitor motor variables
  // significantly slowing the execution down!!!!
  // motor.monitor();
  read_buttons(restart_motor); 
  target_velocity = desired_speed();
  // user communication
  // command.run();
}




