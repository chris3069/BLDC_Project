#ifndef sinusodal_comm_h
#define sinusodal_comm_h

#include "../motorphase.hpp"
#include "mbed.h"

class Sinusodal_commutation : public MotorPhase
{
    public: 
    Sinusodal_commutation(uint8_t);
    ~Sinusodal_commutation();

    void increase_factor(void);
    void decrease_factor(void);
    float getPWM_Level(int8_t, int8_t); 

    private:
    void next_step(int8_t);
    

    float factor;
};

#endif
