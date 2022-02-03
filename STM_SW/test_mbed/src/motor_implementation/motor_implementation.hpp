#ifndef motor_implementation_h
#define motor_implementation_h

#include "mbed.h"

class Motor_Implementation
{
  public:
    // virtual void motor_control(float velocity) = 0;
    virtual void start_motor_control(void) = 0;
    virtual void quit_motor_control(void) = 0;
    virtual void control_motor(int32_t velocity);
    Motor_Implementation();
    virtual ~Motor_Implementation();

  protected:
  
  void limit_target_speed(int32_t);

  Timeout synchronous_rpm;
  int32_t target_speed;
  int32_t previousvelocity;
  int32_t max_target_speed;
  
};


#endif



