#include "motor_implementation.hpp"
// #include "pin_config.hpp"

Motor_Implementation::Motor_Implementation()
    :previousvelocity(0), target_speed(0)
{

}

void Motor_Implementation::control_motor(int32_t velocity)
{
    if (velocity == 0 && previousvelocity != 0) 
    {
        quit_motor_control();
    }
    else if(previousvelocity == 0 && velocity != 0)
    {
        start_motor_control();
    }
    previousvelocity = velocity;
    limit_target_speed(velocity);
}

void Motor_Implementation::limit_target_speed(int32_t target_speed)
{
    if(abs(target_speed) > max_target_speed)
    {
        if (target_speed > 0)
        {
            
        }
        else // target_speed < 0
        {
            target_speed = - max_target_speed;
        }
    }
}

Motor_Implementation::~Motor_Implementation()
{

}
