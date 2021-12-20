#include "../motor_implementation.hpp"
#include <PciManager.h>
#include <PciListenerImp.h>
class Closed_Loop : Motor_Implementation
{
  public: 
  void motor_implementation_init(void);
  void Closed_Loop::motor_control(float velocity);
  Closed_Loop::Closed_Loop(BLDCMotor *ext_motor, BLDCDriver3PWM *ext_driver);
  Closed_Loop();
  virtual ~Closed_Loop();


  private:

   
    PciListenerImp *listenerIndex;

};



    void doA(void);
    void doB(void);
    void doC(void);