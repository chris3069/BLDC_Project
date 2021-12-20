#include "../motor_implementation.hpp"

class Open_Loop : Motor_Implementation
{
    public:
    void motor_implementation_init(void);
    Open_Loop(BLDCMotor *ext_motor, BLDCDriver3PWM *ext_driver);
    Open_Loop();
    void motor_control(float velocity);
    virtual ~Open_Loop();

  private:

};

