#ifndef Block_comm_h
#define Block_comm_h

#include "../motorphase.hpp"
#include "mbed.h"

class Block_commutation : public MotorPhase
{
    public: 
    // Block_commutation(uint8_t);
    Block_commutation(uint8_t, uint8_t);
    ~Block_commutation();
    // void next_phase(void);
    // void previous_phase(void);
    // void resume(void);
    // void suspend(void);

    // void increase_factor(void);  // only for sinusodal control
    // void decrease_factor(void);  // only for sinusodal control

    private:
    void next_step(int8_t);
    uint8_t phase_control; 
};

#endif
