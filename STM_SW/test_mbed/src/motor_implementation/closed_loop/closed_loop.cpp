#include "closed_loop.hpp"


Own_Closed_Loop::Own_Closed_Loop()
    :Motor_Implementation(), sensor(), torque_direction(1)
{ 
    previous_position = sensor.getCurrentState();

    IN1 = new Block_commutation(1, previous_position);
    IN2 = new Block_commutation(2, previous_position);
    IN3 = new Block_commutation(3, previous_position);
    
}

void Own_Closed_Loop::next_pwm_step(void)
{
    new_position = sensor.getCurrentState();
    
    calculate_motor_direction();

    // previous_position = ( previous_position + 1 ) % 6;
    // IN1->power_current_state( 0 , previous_position);
    // IN2->power_current_state( 0 , previous_position);
    // IN3->power_current_state( 0 , previous_position);

    
    new_position = ( new_position + 4 ) % 6;
    IN1->power_current_state(torque_direction, ( new_position ));
    IN2->power_current_state(torque_direction, ( new_position ));
    IN3->power_current_state(torque_direction, ( new_position ));

    synchronous_rpm.detach();
    calculate_switching_frequency(); 
    attach_commutation_timer(switching_frequency/2);

    // if (previous_position == new_position) 
    // // still in the same position -> turns to slow
    // {
    //     // motorturnstoslow();
    //     motorintime();
    //     previous_position = new_position;
    // }
    // // else
    // // previous_position != new_position
    // else if(((previous_position + torque_direction) % 6 ) == new_position) 
    // // dreht in der richtigen Zeit wie erwartet
    // {
    //     motorintime();
    //     previous_position = new_position;
    // }
    // else
    // {
    //     motorintime();
    //     previous_position = new_position;
    // }
}


    void Own_Closed_Loop::calculate_motor_direction(void)
    {
        torque_direction = 0;
    if (m_target_speed > 0)
    {
        torque_direction = 0;
    }
    else if (m_target_speed < 0)
    {
        torque_direction = -2;
    }
    }

    void Own_Closed_Loop::motorturnstoslow(void)
    {
    synchronous_rpm.detach();
    calculate_switching_frequency(); 
    attach_commutation_timer(switching_frequency/20);
    }

    void Own_Closed_Loop::motorintime(void)
    {
        if (torque_direction > 0)
        {
            turnright();
        }
        else if (torque_direction < 0)
        {
            turnleft();
        }

    calculate_switching_frequency();
    synchronous_rpm.detach();
    attach_commutation_timer(switching_frequency*2);
    }


    void Own_Closed_Loop::turnright()
    {
        IN1->next_phase();
        IN2->next_phase();
        IN3->next_phase();
    }

    void Own_Closed_Loop::turnleft()
    {
        IN1->previous_phase();
        IN2->previous_phase();
        IN3->previous_phase();
    }

void Own_Closed_Loop::attach_commutation_timer(float switching_freq)
{
synchronous_rpm.attach_us(callback(this, &Own_Closed_Loop::next_pwm_step) ,switching_freq);
}

Own_Closed_Loop::~Own_Closed_Loop()
{
}
