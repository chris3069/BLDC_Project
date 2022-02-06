#ifndef Motorphase_h
#define Motorphase_h

#include "mbed.h"
#include <vector>

class MotorPhase
{
    public: 
    MotorPhase(uint8_t);
    virtual ~MotorPhase();
    void next_phase(void);
    void previous_phase(void);
    void resume(void);
    void suspend(void);
    void power_current_state(int8_t, uint8_t);

    // void increase_factor(void);  // only for sinusodal control
    // void decrease_factor(void);  // only for sinusodal control

    protected:
    virtual void next_step(int8_t) = 0;
    virtual float getPWM_Level(int8_t, int8_t) = 0;

    
    protected: 
    uint8_t phaseoffset;
    int8_t sine_step;

    int8_t commutation_step;
    uint32_t switching_frequency;
    DigitalOut *INH;
    PwmOut *IN;
    //INH Pin for every Phase

};

#endif
