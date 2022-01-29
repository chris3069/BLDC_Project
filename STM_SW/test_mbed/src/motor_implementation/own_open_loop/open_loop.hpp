#ifndef own_motor_implementation_h
#define own_motor_implementation_h

#include "mbed.h"
#include "../motor_implementation.hpp"
#include "../MotorPhase/motorphase.hpp"


class Own_Open_Loop : Motor_Implementation
{
    public:
    Own_Open_Loop();

    void control_motor(int32_t velocity);
    ~Own_Open_Loop();

  private:
    void start_motor_control(void);
    void quit_motor_control(void);
    void next_pwm_step(void);

  private:

  Timeout synchronous_rpm;

  MotorPhase IN1;
  MotorPhase IN2;
  MotorPhase IN3;

  int32_t target_speed;
  int32_t previousvelocity;
};

#endif



// Timeout synchronous_rpm;
// synchronous_rpm.attach(callback(this, &Encoder::increase_time), 0.001));
// time_step = 0;
// void Encoder::increase_time(void)
// {
//   ++time_step;
// }

// void next_sine_step(void)
// {
//   ++pwmstep;
// }

// bool Encoder::has_angle_changed()
// {
//   static int32_t previous_angle = 0;
//   bool has_angle_chaged;
//   if (previous_angle != rotary_angle)
//   {
//     has_angle_chaged = true;
//   }
//   else 
//   {
//     has_angle_chaged = false;
//   }
//   return has_angle_chaged;
// }

  // void angle_at_end(void);
  // synchronous_rpm.detach();
  // synchronous_rpm.attach(&next_sine_step, (float)1/angle);

// // header
//     bool has_angle_changed(void);

//     static uint32_t time_step;
//     static void increase_time(void);

