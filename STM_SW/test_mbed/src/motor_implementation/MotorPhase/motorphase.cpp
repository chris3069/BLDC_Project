#include "motorphase.hpp"


const float sine_wave[120] = {0.5, 0.52639, 0.5527, 0.57887, 0.60482, 0.63047, 0.65576, 0.68062, 0.70497, 0.72876, 0.7519, 0.77435, 0.79602, 0.81688, 0.83685, 0.85588, 0.87392, 0.89092, 0.90682, 0.9216, 0.9352, 0.94758, 0.95872, 0.96858, 0.97713, 0.98436, 0.99023, 0.99474, 0.99787, 0.99961, 0.99996, 0.99891, 0.99648, 0.99266, 0.98746, 0.98091, 0.97302, 0.96381, 0.95331, 0.94154, 0.92855, 0.91435, 0.89901, 0.88255, 0.86503, 0.84648, 0.82698, 0.80656, 0.78528, 0.76322, 0.74041, 0.71694, 0.69287, 0.66825, 0.64317, 0.61769, 0.59187, 0.56581, 0.53956, 0.5132, 0.4868, 0.46044, 0.43419, 0.40813, 0.38231, 0.35683, 0.33175, 0.30713, 0.28306, 0.25959, 0.23678, 0.21472, 0.19344, 0.17302, 0.15352, 0.13497, 0.11745, 0.10099, 0.08565, 0.07145, 0.05846, 0.04669, 0.03619, 0.02698, 0.01909, 0.01254, 0.00734, 0.00352, 0.00109, 4e-05, 0.00039, 0.00213, 0.00526, 0.00977, 0.01564, 0.02287, 0.03142, 0.04128, 0.05242, 0.0648, 0.0784, 0.09318, 0.10908, 0.12608, 0.14412, 0.16315, 0.18312, 0.20398, 0.22565, 0.2481, 0.27124, 0.29503, 0.31938, 0.34424, 0.36953, 0.39518, 0.42113, 0.4473, 0.47361, 0.5};


MotorPhase::MotorPhase(uint8_t motorphase)
{
    switch (motorphase)
    {
        case 1:
            phaseoffset = 0;
            IN = new PwmOut(D9);
            break;
        case 2:
            phaseoffset = 40;
            IN = new PwmOut(D10);
            break;
        case 3:
            phaseoffset = 80;
            IN = new PwmOut(D11);
            break; 
    }
    this->sine_step = phaseoffset;
    IN->period_us(100);
}

void MotorPhase::previous_phase(void)
{
    next_step(-1);
}

void MotorPhase::next_phase(void)
{
    next_step(1);
}

// void MotorPhase::set_phase(float velocity)
// {
//     IN->write(sine_wave[sine_step]);
// }

void MotorPhase::resume(void)
{
    IN->resume();
}

void MotorPhase::suspend(void)
{
    IN->suspend();
}


void MotorPhase::next_step(int8_t direction)
{
    if(direction > 0)
    {
        ++sine_step;
    }
    else
    {
        --sine_step;
    }
        
    if (sine_step > 119)
    {
        sine_step = 0;
    }
    else if(sine_step < 0)
    {
        sine_step = 119;
    }    
    IN->write(sine_wave[sine_step]);
}

MotorPhase::~MotorPhase()
{
    delete IN;
}
