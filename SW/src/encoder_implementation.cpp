#include "encoder_implementation.hpp"

#include "Encoder.h"


Encoder Speed_encoder(12, 13);




int32_t getTargetSpeed(void)
{ 
  static int32_t old_target_speed = INT32_MIN;
  static int32_t new_target_speed = INT32_MAX;
  
  new_target_speed = Speed_encoder.read();
  if (new_target_speed != old_target_speed) 
  {
    old_target_speed = new_target_speed;
    Serial.println(new_target_speed);
  }
  return new_target_speed;
}