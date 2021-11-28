#include "closed_loop_control.hpp"


Closed_Loop::Closed_Loop()
    :Motor_Implementation(motor, driver)
{
  sensor = new HallSensor(2, 3, 4, 3);

  PciListenerImp listenerIndex(sensor->pinC, doC);
}

Closed_Loop::Closed_Loop(BLDCMotor *ext_motor, BLDCDriver3PWM *ext_driver)
  :Motor_Implementation(motor, driver)
{

}

 void Closed_Loop::motor_implementation_init(void)
 {
    sensor->init();
  sensor->enableInterrupts(doA, doB); //, doC);
  // software interrupts
  PciManager->registerListener(listenerIndex);
  // link the motor to the sensor
  motor->linkSensor(sensor);
 }

    void Closed_Loop::doA()
    {
        sensor->handleA();
    
    }
    void Closed_Loop::doB()
    {
        sensor->handleB();
    
    }
    void Closed_Loop::doC()
    {
        sensor->handleC();
    }


Closed_Loop::~Closed_Loop()
{

}