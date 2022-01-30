#ifndef hall_sensor
#define hall_sensor

#include "mbed.h"
// #include "../motor_implementation.hpp"
// #include "../MotorPhase/motorphase.hpp"

enum Hall_states 
// u * 100 + v*10 +b *1
// either enum from 0 to 5 or u * 100 + v*10 +b *1
{
    UvW = 101,
    Uvw = 100,
    UVw = 110,
    uVw = 10,
    uVW = 11,
    uvW = 1
} hall_position;

class Hall_Sensor
{
public:
    Hall_Sensor();
    ~Hall_Sensor();

    Hall_states getCurrentState(void);
    Hall_states getNextState(void);
    Hall_states getPreviousState(void);

private:
    void rise_U(void);
    void rise_V(void);
    void rise_W(void);
    void fall_U(void);
    void fall_V(void);
    void fall_W(void);

    void change_state(void);

private:
    InterruptIn senseU;
    InterruptIn senseV;
    InterruptIn senseW;
    Hall_states rotorposition;
    bool u, v, w;
};

// class Own_Closed_Loop : Motor_Implementation
// {
//     public:
//     Own_Closed_Loop();

//     void control_motor(int32_t velocity);
//     ~Own_Closed_Loop();

//   private:
//     void start_motor_control(void);
//     void quit_motor_control(void);
//     void next_pwm_step(void);

//   private:

//   Timeout synchronous_rpm;

//   MotorPhase IN1;
//   MotorPhase IN2;
//   MotorPhase IN3;

//   int32_t target_speed;
//   int32_t previousvelocity;
// };

#endif
