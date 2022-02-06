#ifndef motor_implementation_h
#define motor_implementation_h

#include "mbed.h"
#include "MotorPhase/motorphase.hpp"

class Motor_Implementation
{
  public:
    // virtual void motor_control(float velocity) = 0;

    void control_motor(int32_t velocity);
    Motor_Implementation();
    virtual ~Motor_Implementation();

  protected:
  
  void start_motor_control(void);
  void quit_motor_control(void);
  virtual void next_pwm_step(void) = 0;
  virtual void attach_commutation_timer(float) = 0;
  void calculate_switching_frequency(void);
  void limit_target_speed(int32_t);

  protected:

  Timeout synchronous_rpm;
  int32_t m_target_speed;
  int32_t previousvelocity;
  int32_t max_target_speed;
  float switching_frequency;

  MotorPhase *IN1;
  MotorPhase *IN2;
  MotorPhase *IN3;
  
};


#endif



