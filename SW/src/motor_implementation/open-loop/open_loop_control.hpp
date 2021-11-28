#include "../motor_implementation.hpp"

class Open_Loop : Motor_Implementation
{
    public:
    void motor_implementation_init(void);
    Open_Loop();
    void motor_control(float velocity);
    virtual ~Open_Loop();

  private:

};

