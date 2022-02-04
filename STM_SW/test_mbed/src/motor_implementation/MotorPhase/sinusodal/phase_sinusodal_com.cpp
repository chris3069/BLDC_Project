#include "phase_sinusodal_com.hpp"

const float commutation_table[120] = {0.0, 0.02639, 0.0527, 0.07887, 0.10482, 0.13047, 0.15576, 0.18062, 0.20497, 0.22876, 0.2519, 0.27435, 0.29602, 0.31688, 0.33685, 0.35588, 0.37392, 0.39092, 0.40682, 0.4216, 0.4352, 0.44758, 0.45872, 0.46858, 0.47713, 0.48436, 0.49023, 0.49474, 0.49787, 0.49961, 0.49996, 0.49891, 0.49648, 0.49266, 0.48746, 0.48091, 0.47302, 0.46381, 0.45331, 0.44154, 0.42855, 0.41435, 0.39901, 0.38255, 0.36503, 0.34648, 0.32698, 0.30656, 0.28528, 0.26322, 0.24041, 0.21694, 0.19287, 0.16825, 0.14317, 0.11769, 0.09187, 0.06581, 0.03956, 0.0132, -0.0132, -0.03956, -0.06581, -0.09187, -0.11769, -0.14317, -0.16825, -0.19287, -0.21694, -0.24041, -0.26322, -0.28528, -0.30656, -0.32698, -0.34648, -0.36503, -0.38255, -0.39901, -0.41435, -0.42855, -0.44154, -0.45331, -0.46381, -0.47302, -0.48091, -0.48746, -0.49266, -0.49648, -0.49891, -0.49996, -0.49961, -0.49787, -0.49474, -0.49023, -0.48436, -0.47713, -0.46858, -0.45872, -0.44758, -0.4352, -0.4216, -0.40682, -0.39092, -0.37392, -0.35588, -0.33685, -0.31688, -0.29602, -0.27435, -0.2519, -0.22876, -0.20497, -0.18062, -0.15576, -0.13047, -0.10482, -0.07887, -0.0527, -0.02639, 0.0};

Sinusodal_commutation::Sinusodal_commutation(uint8_t motorphase)
    :MotorPhase(motorphase)
{
     switch (motorphase)
    {
        case 1:
            phaseoffset = 0;
            break;
        case 2:
            phaseoffset = 39;
            break;
        case 3:
            phaseoffset = 79;
            break; 
    }
    this->commutation_step = phaseoffset;
    factor = 0.5F;
}

void Sinusodal_commutation::next_step(int8_t direction)
{
    if(direction > 0)
    {
        ++commutation_step;
    }
    else
    {
        --commutation_step;
    }
        
    if (commutation_step > 119)
    {
        commutation_step = commutation_step -120;
    }
    else if(commutation_step < 0)
    {
        commutation_step = commutation_step + 120;
    }    
    IN->write(0.5 + factor * commutation_table[commutation_step]);
}

void Sinusodal_commutation::increase_factor(void)
{
    factor += 0.1;
}
void Sinusodal_commutation::decrease_factor(void)
{
    factor-= 0.1;
}

Sinusodal_commutation::~Sinusodal_commutation()
{
    
}
