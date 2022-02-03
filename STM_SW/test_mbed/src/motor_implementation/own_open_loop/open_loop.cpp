#include "open_loop.hpp"

Own_Open_Loop::Own_Open_Loop()
    :Motor_Implementation()
{ 
    IN1 = new Sinusodal_commutation(1);
    IN2 = new Sinusodal_commutation(2);
    IN3 = new Sinusodal_commutation(3);
}

void Own_Open_Loop::next_pwm_step(void)
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
    attach_commutation_timer();
}

void Own_Open_Loop::attach_commutation_timer(void)
{
synchronous_rpm.attach_us(callback(this, &Own_Open_Loop::next_pwm_step) ,switching_frequency);
}

Own_Open_Loop::~Own_Open_Loop()
{
}
