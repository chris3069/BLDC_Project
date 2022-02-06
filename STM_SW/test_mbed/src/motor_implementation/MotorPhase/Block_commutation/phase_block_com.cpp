#include "phase_block_com.hpp"

// const float commutation_table[6] = {0.5, 0, 0, 0.5, 1, 1}; 

Block_commutation::Block_commutation(uint8_t motorphase, uint8_t current_position)
    :MotorPhase(motorphase)
{
    // m_commutation_table(sizeof(commutation_table)/sizeof(commutation_table[0]), 0);
     switch (motorphase)
    {
        case 1:
            phaseoffset = 0;
            break;
        case 2:
            phaseoffset = 2;
            break;
        case 3:
            phaseoffset = 4;
            break; 
    }

    commutation_step = limit_value( 0, 6, phaseoffset + current_position);

    // if ((current_position + phaseoffset) > 5)
    // {
    //     commutation_step = phaseoffset + current_position - 6;
    // }
    // else // current_postion + phaseoffset is in boundries
    // {
    // commutation_step = phaseoffset + current_position;
    // }
}

// void Block_commutation::power_current_state(uint8_t direction, uint8_t current_position)
// {
//     IN->write(0.25 * commutation_table[(commutation_step + direction) % 6]); // 0,5 vorsichtshalber mal
// }

void Block_commutation::next_step(int8_t direction)
{
    if(direction > 0)
    {
        ++commutation_step;
    }
    else
    {
        --commutation_step;
    }
    
    commutation_step = limit_value(0, 6, commutation_step);

    // if (commutation_step > 5)
    // {
    //     commutation_step = commutation_step - 6;
    // }
    // else if(commutation_step < 0)
    // {
    //     commutation_step = commutation_step + 6;
    // }    

    // IN->write(0.25 * commutation_table[commutation_step]); // 0,5 vorsichtshalber mal
}

uint8_t Block_commutation::limit_value(uint8_t lower_value, uint8_t upper_value, int8_t data)
// exclusive upper value
{
    if (data >= upper_value)
    {
        data = data - upper_value;
    }
    else if(data < lower_value)
    {
        data = data + upper_value;
    }    
    
    return data;
}

float Block_commutation::getPWM_Level(int8_t direction, int8_t current_position)
{
    int8_t target_position = current_position + phaseoffset + direction;
    //  + phaseoffset + direction*2;
    uint8_t com_step = limit_value( 0, 6, target_position);
    //  = (commutation_step + direction) % 6;

    return commutation_table[com_step];
}

Block_commutation::~Block_commutation()
{

}