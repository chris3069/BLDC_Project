#ifndef own_open_loop_motor_implementation_h
#define own_open_loop_motor_implementation_h

#include "mbed.h"
#include "../motor_implementation.hpp"
#include "../MotorPhase/sinusodal/phase_sinusodal_com.hpp"


class Own_Open_Loop : public Motor_Implementation
{
    public:
    Own_Open_Loop();
    ~Own_Open_Loop();
   
  private:
    void attach_commutation_timer(float);
    void next_pwm_step(void);

};

#endif

