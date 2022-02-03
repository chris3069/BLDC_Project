#include "open_loop.hpp"

Own_Open_Loop::Own_Open_Loop()
    : IN1(1), IN2(2), IN3(3)
{
    
}

void Own_Open_Loop::next_pwm_step(void)
{
    if (target_speed > 0)
    {
        IN1.next_phase();
        IN2.next_phase();
        IN3.next_phase();
    }
    else if (target_speed < 0)
    {
        IN1.previous_phase();
        IN2.previous_phase();
        IN3.previous_phase();
    }
    synchronous_rpm.detach();
    float switching_frequency = 1000000 /abs(target_speed); 
    synchronous_rpm.attach_us(callback(this, &Own_Open_Loop::next_pwm_step), switching_frequency);
}

void Own_Open_Loop::control_motor(int32_t velocity)
{
    target_speed = velocity;
    
    if (velocity == 0 && previousvelocity != 0) 
    {
        quit_motor_control();
    }
    else if(previousvelocity == 0 && velocity != 0)
    {
        start_motor_control();
    }
    previousvelocity = velocity;
}

void Own_Open_Loop::start_motor_control(void)
{
    synchronous_rpm.attach_us(callback(this, &Own_Open_Loop::next_pwm_step) ,1000000 / (float) this->target_speed);
    IN1.resume();
    IN2.resume();
    IN3.resume();
}

void Own_Open_Loop::quit_motor_control(void)
{
    synchronous_rpm.detach();
    IN1.suspend();
    IN2.suspend();
    IN3.suspend();
}

Own_Open_Loop::~Own_Open_Loop()
{
}
