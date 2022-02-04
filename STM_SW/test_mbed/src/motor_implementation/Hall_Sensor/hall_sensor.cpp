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
        direction = 0;
        u = senseU.read();
        v = senseV.read();
        w = senseW.read();
        calculate_current_state();
    }

    Hall_Sensor::~Hall_Sensor()
    {

    }

    void Hall_Sensor::rise_U(void)
    {
        u = 1;
        change_state();
    }
    void Hall_Sensor::rise_V(void)
    {
        v = 1;
        change_state();
    }
    void Hall_Sensor::rise_W(void)
    {
        w = 1;
        change_state();
    }
    void Hall_Sensor::fall_U(void)
    {
        u = 0;
        change_state();
    }
    void Hall_Sensor::fall_V(void)
    {
        v = 0;
        change_state();
    }
    void Hall_Sensor::fall_W(void)
    {
        w = 0;
        change_state();
    }

    void Hall_Sensor::calculate_current_state(void)
    {
        uint8_t hall_state = u*100 + v* 10 + w;
        Hall_state state = current_position_possible(hall_state);
        current_position_plausible(state);
        current_hall_position_index = state;
    }

    Hall_state Hall_Sensor::current_position_possible(uint8_t hall_state)
    {
        uint8_t position_index = UINT8_MAX;
        for (uint8_t potential_position = 0; potential_position < 6; ++potential_position)
        {
            if (hall_position[potential_position] == hall_state)
            {
                position_index = potential_position;
                return position_index;
            }
        }
        // no valid position
        MBED_ASSERT( (bool) ( position_index != UINT8_MAX ));
    }

    bool Hall_Sensor::current_position_plausible(Hall_state state)
    {
        bool position_plausible = false;
        if ( previous_hall_position_index +1 == state)
        {
            position_plausible = true;
            direction = 1;
        }
        else if ( previous_hall_position_index -1 == state )
        {
            position_plausible = true;
            direction = -1;
        }
        else if (previous_hall_position_index == 5 && state == 0)
        {
            position_plausible = true;
            direction = 1;
        }
        else if (previous_hall_position_index == 0 && state == 5)
        {
            position_plausible = true;
            direction = -1;
        }
        else 
        {
            // MBED_ASSERT ( (bool) position_plausible );
        }
        previous_hall_position_index = state;
        return position_plausible;
    }

    void Hall_Sensor::change_state(void)
    {
        calculate_current_state();
    }

    const Hall_state Hall_Sensor::getCurrentState(void)
    {
        return current_hall_position_index;
    }


    const int8_t Hall_Sensor::getHall_direction(void)
    {
        return direction;
    }

