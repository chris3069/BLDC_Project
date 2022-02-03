#include "phase_block_com.hpp"

const float commutation_table[6] = {0.5, 0, 0, 0.5, 1, 1}; 

Block_commutation::Block_commutation(uint8_t motorphase)
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
    this->commutation_step = phaseoffset;
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
        commutation_step = 0;
    }
    else if(commutation_step < 0)
    {
        commutation_step = 5;
    }    
    IN->write(0.5 * commutation_table[commutation_step]);
}