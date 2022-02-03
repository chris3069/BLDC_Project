#ifndef own_closed_loop_motor_implementation_h
#define own_closed_loop_motor_implementation_h

#include "mbed.h"
#include "../motor_implementation.hpp"
#include "../MotorPhase/Block_commutation/phase_block_com.hpp"
#include "../Hall_Sensor/hall_sensor.hpp"


class Own_Closed_Loop : public Motor_Implementation
{
    public:
    Own_Closed_Loop();

    void control_motor(int32_t velocity);
    ~Own_Closed_Loop();

  private:
    void start_motor_control(void);
    void quit_motor_control(void);
    void next_pwm_step(void);

  private:

  Timeout synchronous_rpm;

  Block_commutation IN1;
  Block_commutation IN2;
  Block_commutation IN3;
  // Hall_Sensor;

  int32_t target_speed;
  int32_t previousvelocity;
};

#endif
