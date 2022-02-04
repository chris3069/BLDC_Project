#include "closed_loop.hpp"


Own_Closed_Loop::Own_Closed_Loop()
    :Motor_Implementation(), sensor()
{ 
    position_index = sensor.getCurrentState();

    IN1 = new Block_commutation(1, position_index);
    IN2 = new Block_commutation(2, position_index);
    IN3 = new Block_commutation(3, position_index);

}

void Own_Closed_Loop::next_pwm_step(void)
{
    uint8_t new_position = sensor.getCurrentState();

    if (m_target_speed > 0)
    {
        torque_direction = 1;
    }
    else if (m_target_speed < 0)
    {
        torque_direction = -1;
    }

    if(1)
    // if (((position_index + torque_direction) % 6 ) == new_position) // dreht in der richtigen Zeit wie erwartet
    {
        if (m_target_speed > 0)
        {
            IN1->next_phase();
            IN2->next_phase();
            IN3->next_phase();
        }
        else if (m_target_speed < 0)
        {
            IN1->previous_phase();
            IN2->previous_phase();
            IN3->previous_phase();
        }
    calculate_switching_frequency();
    synchronous_rpm.detach();
    synchronous_rpm.attach_us(callback(this, &Own_Closed_Loop::next_pwm_step), switching_frequency*2);

    }
    else // dreht zu langsam
    {
    synchronous_rpm.detach();
    calculate_switching_frequency(); 
    synchronous_rpm.attach_us(callback(this, &Own_Closed_Loop::next_pwm_step), switching_frequency/20);
    }

}

void Own_Closed_Loop::attach_commutation_timer(void)
{
synchronous_rpm.attach_us(callback(this, &Own_Closed_Loop::next_pwm_step) ,switching_frequency);
}

Own_Closed_Loop::~Own_Closed_Loop()
{
}
