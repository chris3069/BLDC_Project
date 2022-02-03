#include "closed_loop.hpp"


Own_Closed_Loop::Own_Closed_Loop()
    :Motor_Implementation()
{ 
    IN1 = new Block_commutation(1);
    IN2 = new Block_commutation(2);
    IN3 = new Block_commutation(3);

}

void Own_Closed_Loop::next_pwm_step(void)
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
    synchronous_rpm.detach();
    calculate_switching_frequency(); 
    synchronous_rpm.attach_us(callback(this, &Own_Closed_Loop::next_pwm_step), switching_frequency);
}

Own_Closed_Loop::~Own_Closed_Loop()
{
}
