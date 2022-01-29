#include "own_rotary.hpp"

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

// -----------------------------------------------------------------------------------

// void Encoder::rise_A(void)
// {
//   if (rotary_encoderB == 1)
//   {
//     rotary_angle = rotary_angle +1;
//   }
//   else
//   {
//     --rotary_angle;
//   }
// }

// void Encoder::fall_A(void)
// {
//   if (rotary_encoderB == 1)
//   {
//     --Encoder::rotary_angle;
//   }
//   else
//   {
//     ++rotary_angle;
//   }
// }

// void Encoder::rise_B(void)
// {
//   if (rotary_encoderA == 1)
//   {
//     --rotary_angle;
//   }
//   else
//   {
//     ++rotary_angle;
//   }
// }

// void Encoder::fall_B(void)
// {
// //   void angle_at_start(void);
//   if (rotary_encoderA == 1)
//   {
//     ++rotary_angle;
//   }
//   else
//   {
//     --rotary_angle;
//   }
// }

// int32_t Encoder::get_rotary_angle(void)
// {
//     return rotary_angle;
// }

// void Encoder::reset_rotary_angle(void)
// {
//     rotary_angle = 0;
// }

// Encoder::Encoder()
//     :rotary_encoderA(D12), rotary_encoderB(PA_11) 
// {
//     rotary_angle = 0;
//     rotary_encoderA.rise(callback(this, &Encoder::rise_A));
//     rotary_encoderA.fall(callback(this, &Encoder::fall_A));
//     rotary_encoderB.rise(callback(this, &Encoder::rise_B));
//     rotary_encoderB.fall(callback(this, &Encoder::fall_B));
// }
