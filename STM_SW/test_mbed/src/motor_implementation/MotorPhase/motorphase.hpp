#ifndef Motorphase_h
#define Motorphase_h

#include "mbed.h"

class MotorPhase
{
    public: 
    MotorPhase(uint8_t);
    virtual ~MotorPhase();
    void next_step(int8_t);
    // void set_phase(float);
    void next_phase(void);
    void previous_phase(void);
    void resume(void);
    void suspend(void);
    private:
    PwmOut *IN;
    uint8_t phaseoffset;
    int8_t sine_step;

};



#endif
