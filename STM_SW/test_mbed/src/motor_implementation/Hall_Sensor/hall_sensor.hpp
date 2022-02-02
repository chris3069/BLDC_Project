#ifndef hall_sensor
#define hall_sensor

#include "mbed.h"
// #include "../motor_implementation.hpp"
// #include "../MotorPhase/motorphase.hpp"

// enum Hall_states 
// // u * 100 + v*10 +b *1
// // either enum from 0 to 5 or u * 100 + v*10 +b *1
// {
//     UvW = 101,
//     Uvw = 100,
//     UVw = 110,
//     uVw = 10,
//     uVW = 11,
//     uvW = 1
// } hall_position;

// u * 100 + v*10 +b *1

using Hall_state = uint8_t;

class Hall_Sensor
{
public:
    Hall_Sensor();
    ~Hall_Sensor();

    Hall_state getCurrentState(void);
    int8_t Hall_direction(void);
    // Hall_states getNextState(void);
    // Hall_states getPreviousState(void);

private:
    void rise_U(void);
    void rise_V(void);
    void rise_W(void);
    void fall_U(void);
    void fall_V(void);
    void fall_W(void);

    void calculate_current_state(void);
    Hall_state current_position_possible(uint8_t);
    bool current_position_plausible(Hall_state );
    void change_state(void);

private:
    InterruptIn senseU;
    InterruptIn senseV;
    InterruptIn senseW;
    const uint8_t hall_position[6] = { 101 ,100 ,110 ,10 ,11 ,1 };
    bool u, v, w;
    int8_t direction;
    // uint8_t current_hall_state;

    Hall_state previous_hall_position_index;
    Hall_state current_hall_position_index;
};

#endif
