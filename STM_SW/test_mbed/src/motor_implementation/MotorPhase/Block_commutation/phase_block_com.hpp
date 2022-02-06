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
    // void power_current_state(uint8_t, uint8_t );
    float getPWM_Level(int8_t, int8_t);
    // void next_phase(void);
    // void previous_phase(void);
    // void resume(void);
    // void suspend(void);

    // void increase_factor(void);  // only for sinusodal control
    // void decrease_factor(void);  // only for sinusodal control

    private:
    void next_step(int8_t);
    uint8_t limit_value(uint8_t lower_value, uint8_t upper_value, int8_t data);
    uint8_t phase_control; 
    const float commutation_table[6] = {0.5, 0, 0, 0.5, 1, 1}; 
};

#endif
