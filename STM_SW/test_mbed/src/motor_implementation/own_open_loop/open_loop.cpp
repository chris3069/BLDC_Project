#include "open_loop.hpp"

Own_Open_Loop::Own_Open_Loop()
    : IN1(D9), IN2(D10), IN3(D11)
{
    sine_step1 = 0;
    sine_step2 = 40;
    sine_step3 = 80;

    IN1.period_us(100);
    IN2.period_us(100);
    IN3.period_us(100);
}

void Own_Open_Loop::next_pwm_step(uint32_t sinestep)
{
    static uint32_t previoussinestep = 0;
    if (sinestep != previoussinestep)
    {
        ++sine_step1;
        if (sine_step1 > 119)
        {
            sine_step1 = 0;
        }

        ++sine_step2;
        if (sine_step2 > 119)
        {
            sine_step2 = 0;
        }

        ++sine_step3;
        if (sine_step3 > 119)
        {
            sine_step3 = 0;
        }
    }
    previoussinestep = sinestep;
    // adapt_period_time();
}

void Own_Open_Loop::motor_control(float velocity)
{
    IN1.write(sine_wave[sine_step1]);
    IN2.write(sine_wave[sine_step2]);
    IN3.write(sine_wave[sine_step3]);
}

// void writephase(PwmOut &IN)
// {
//     IN->write(sine_wave[sine_step1]);
// }

void Own_Open_Loop::start_motor_control(void)
{
    IN1.resume();
    IN2.resume();
    IN3.resume();
}
void Own_Open_Loop::quit_motor_control(void)
{
    IN1.suspend();
}

Own_Open_Loop::~Own_Open_Loop()
{
}