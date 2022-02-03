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

    void control_motor(int32_t velocity);
    

  private:
    void start_motor_control(void);
    void quit_motor_control(void);
    void next_pwm_step(void);

  private:

  Sinusodal_commutation IN1;
  Sinusodal_commutation IN2;
  Sinusodal_commutation IN3;


};

#endif

