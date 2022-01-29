#ifndef own_rotary_h
#define own_rotary_h

#include "mbed.h"
#include "encoder_implementation.hpp"

class Encoder : Encoder_Implementation
{
  public:
    Encoder();
    ~Encoder();

    int32_t get_rotary_angle(void);
    void reset_rotary_angle(void);

    private:
    void rise_A(void);
    void rise_B(void);
    void fall_A(void);
    void fall_B(void);

    private:
    InterruptIn rotary_encoderA;  
    InterruptIn rotary_encoderB;
    // Timeout synchronous_rpm;

    volatile int32_t rotary_angle;
    // _interrupt.rise(callback(this, &Encoder::change_angle));
};



#endif
