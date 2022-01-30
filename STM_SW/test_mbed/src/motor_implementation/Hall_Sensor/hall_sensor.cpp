#include "hall_sensor.hpp"

    Hall_Sensor::Hall_Sensor()
        :senseU(D2), senseV(D3), senseW(D4)
    {
        senseU.fall(callback(this, &Hall_Sensor::fall_U));
        senseV.fall(callback(this, &Hall_Sensor::fall_V));
        senseW.fall(callback(this, &Hall_Sensor::fall_W));
        senseU.rise(callback(this, &Hall_Sensor::rise_U));
        senseV.rise(callback(this, &Hall_Sensor::rise_V));
        senseW.rise(callback(this, &Hall_Sensor::rise_W));
    }

    Hall_Sensor::~Hall_Sensor()
    {

    }

    void Hall_Sensor::rise_U(void)
    {
        u = 1;

    }
    void Hall_Sensor::rise_V(void)
    {
        v = 1;

    }
    void Hall_Sensor::rise_W(void)
    {
        w = 1;

    }
    void Hall_Sensor::fall_U(void)
    {
        u = 0;

    }
    void Hall_Sensor::fall_V(void)
    {
        v = 0;

    }
    void Hall_Sensor::fall_W(void)
    {
        w = 0;

    }

    void Hall_Sensor::change_state(void)
    {
        // rotorposition = u*100 + v* 10 + w;

    }

    Hall_states Hall_Sensor::getCurrentState(void)
    {
        return rotorposition;
    }

    Hall_states Hall_Sensor::getNextState(void)
    {
        // return Hall_states[rotorposition];
        // if 
    }

    Hall_states Hall_Sensor::getPreviousState(void)
    {

    }
