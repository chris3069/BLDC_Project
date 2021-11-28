#include "../motor_implementation.hpp"
#include <PciManager.h>
#include <PciListenerImp.h>
class Closed_Loop : Motor_Implementation
{
  public: 
  void motor_implementation_init(void);
  Closed_Loop::Closed_Loop(BLDCMotor *ext_motor, BLDCDriver3PWM *ext_driver);
  Closed_Loop();
  virtual ~Closed_Loop();

  private:

    void doA(void);
    void doB(void);
    void doC(void);

  private:
  // hall sensor instance
    HallSensor *sensor;
    PciListenerImp listenerIndex;




};