#include "encoder_implementation.hpp"

#include "Encoder.h"


Encoder Speed_encoder(12, 13);

#define SPEED_DECREASE 0.1


float getTargetSpeed(void)
{ 
  static int32_t old_target_speed = INT32_MIN;
  static int32_t new_target_speed = INT32_MAX;
  
  new_target_speed = Speed_encoder.read();
  if (new_target_speed != old_target_speed) 
  {
    old_target_speed = new_target_speed;
    Serial.println(new_target_speed);
  }

  return (float)new_target_speed*SPEED_DECREASE;
}