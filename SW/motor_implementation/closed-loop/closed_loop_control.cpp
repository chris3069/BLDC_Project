#include "closed_loop_control.hpp"
#include "pin_config.hpp"

HallSensor *pSensor;
//  HallSensor sensor(2, 3, 4, 3);
//  HallSensor *pSensor = &sensor;
//  PciManager *manager = new PciManager();
InlineCurrentSense* currentsense;

Closed_Loop::Closed_Loop()
    :Motor_Implementation()
{

 listenerIndex = new PciListenerImp(pSensor->pinC, doC); 
//  currentsense= new InlineCurrentSense (1, 1, IS0, IS1, IS2);
}

Closed_Loop::Closed_Loop(BLDCMotor *ext_motor, BLDCDriver3PWM *ext_driver)
  :Motor_Implementation(motor, driver)
{
  // tbd
}

 void Closed_Loop::motor_implementation_init(void)
 {
   Serial.println("Pre_Init");

  pSensor = new HallSensor(2, 3, 4, 11);
  //  currentsense->init();
  pSensor->init();
  pSensor->enableInterrupts(doA, doB); //, doC);
  // software interrupts
  PciManager.registerListener(listenerIndex);
  // link the motor to the sensor
  motor->linkSensor(pSensor);
  driver->voltage_power_supply = 12;
  driver->init();
  motor->linkDriver(driver);
  motor->voltage_sensor_align = 3;
  motor->controller = MotionControlType::velocity;
  motor->PID_velocity.P = 1.0f;
  motor->PID_velocity.I = 0.01;
  motor->PID_velocity.D = 0;
  motor->voltage_limit = 6;

  // jerk control using voltage voltage ramp
  // default value is 300 volts per sec  ~ 0.3V per millisecond
  motor->PID_velocity.output_ramp = 10;

  // velocity low pass filtering time constant
  motor->LPF_velocity.Tf = 0.01f;

  motor->init();
  motor->initFOC();
  // motor->linkCurrentSense(currentsense);     // include this function 
_delay(1000);
Serial.println("Init done");
}















    void doA()
    {
        pSensor->handleA();
        // Serial.println("Reading Sensor A");
    }

    void doB()
    {
        pSensor->handleB();
    }
    
    void doC()
    {
        pSensor->handleC();
    }

// Closed_Loop::
void Closed_Loop::motor_control(float velocity)
{
  // Serial.println("Executing Regelung");
  motor->loopFOC();
  motor->move(velocity);
}

Closed_Loop::~Closed_Loop()
{
  delete pSensor;
  delete currentsense;
}