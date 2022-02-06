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
    ~Own_Closed_Loop();

  private:
    void attach_commutation_timer(float);
    void calculate_motor_direction(void);
    void next_pwm_step(void);
    void motorturnstoslow(void);
    void motorintime(void); 
    void turnright();
    void turnleft();

  private:
  Hall_Sensor sensor;
  uint8_t previous_position;
  uint8_t new_position;
  int8_t torque_direction;

};

#endif
