#include "phase_block_com.hpp"

const float commutation_table[6] = {0.5, 0, 0, 0.5, 1, 1}; 

Block_commutation::Block_commutation(uint8_t motorphase, uint8_t current_position)
    :MotorPhase(motorphase)
{
     switch (motorphase)
    {
        case 1:
            phaseoffset = 0;
            break;
        case 2:
            phaseoffset = 4;
            break;
        case 3:
            phaseoffset = 2;
            break; 
    }

    if ((current_position + phaseoffset) > 5)
    {
        commutation_step = phaseoffset + current_position - 6;
    }
    else // current_postion + phaseoffset is in boundries
    {
    commutation_step = phaseoffset + current_position;
    }
}

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
        
    if (commutation_step > 5)
    {
        commutation_step = commutation_step - 6;
    }
    else if(commutation_step < 0)
    {
        commutation_step = commutation_step + 6;
    }    
    IN->write(0.25 * commutation_table[commutation_step]); // 0,5 vorsichtshalber mal
}

Block_commutation::~Block_commutation()
{

}