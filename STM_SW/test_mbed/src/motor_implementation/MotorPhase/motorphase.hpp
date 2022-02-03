#ifndef Motorphase_h
#define Motorphase_h

#include "mbed.h"

class MotorPhase
{
    public: 
    MotorPhase(uint8_t);
    virtual ~MotorPhase();
    void next_phase(void);
    void previous_phase(void);
    void resume(void);
    void suspend(void);

    // void increase_factor(void);  // only for sinusodal control
    // void decrease_factor(void);  // only for sinusodal control

    protected:
    virtual void next_step(int8_t) = 0;
    
    protected: 
    uint8_t phaseoffset;
    int8_t sine_step;
    int8_t commutation_step;
    DigitalOut *INH;
    PwmOut *IN;
    //INH Pin for every Phase

};

#endif
