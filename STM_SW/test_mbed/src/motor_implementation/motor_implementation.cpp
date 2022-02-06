#include "motor_implementation.hpp"
// #include "pin_config.hpp"

Motor_Implementation::Motor_Implementation()
    :previousvelocity(0), m_target_speed(0), switching_frequency(0), max_target_speed(500000)
{
    
}

void Motor_Implementation::control_motor(int32_t velocity)
{
    m_target_speed = velocity;
    if (velocity == 0 && previousvelocity != 0) 
    {
        quit_motor_control();
    }
    else if(previousvelocity == 0 && velocity != 0)
    {

        start_motor_control();
    }

    limit_target_speed(velocity);
    previousvelocity = velocity;
}

void Motor_Implementation::limit_target_speed(int32_t target_speed)
{
    if(abs(target_speed) > max_target_speed)
    {
        if (target_speed > 0)
        {
            m_target_speed = max_target_speed;
        }
        else // target_speed < 0
        {
            m_target_speed = - max_target_speed;
        }
    }
}

void Motor_Implementation::start_motor_control(void)
{
    calculate_switching_frequency();

    IN1->resume();
    IN2->resume();
    IN3->resume();

    attach_commutation_timer(switching_frequency);
}

void Motor_Implementation::calculate_switching_frequency(void)
{
    if (m_target_speed != 0)
    {
        switching_frequency = (float) 1000000 /abs(m_target_speed);
    }
}

void Motor_Implementation::quit_motor_control(void)
{
    synchronous_rpm.detach();
    IN1->suspend();
    IN2->suspend();
    IN3->suspend();
}

Motor_Implementation::~Motor_Implementation()
{
    delete IN1;
    delete IN2;
    delete IN3;
}
