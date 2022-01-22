#ifndef own_motor_implementation_h
#define own_motor_implementation_h

#include "mbed.h"
#include "../motor_implementation.hpp"


class MotorPhase
{
    public: 
    MotorPhase(uint8_t);
    private:
    PwmOut IN;
    uint8_t sine_step = 0;
};


class Own_Open_Loop : Motor_Implementation
{
    public:
    // void motor_implementation_init(void);
    Own_Open_Loop();
    void motor_control(float velocity);
    void start_motor_control(void);
    void quit_motor_control(void);
    void next_pwm_step(uint32_t);
    virtual ~Own_Open_Loop();
    


  protected:


  private:

  PwmOut IN1;
  PwmOut IN2;
  PwmOut IN3;

const float sine_wave[120] = {0.5, 0.52639, 0.5527, 0.57887, 0.60482, 0.63047, 0.65576, 0.68062, 0.70497, 0.72876, 0.7519, 0.77435, 0.79602, 0.81688, 0.83685, 0.85588, 0.87392, 0.89092, 0.90682, 0.9216, 0.9352, 0.94758, 0.95872, 0.96858, 0.97713, 0.98436, 0.99023, 0.99474, 0.99787, 0.99961, 0.99996, 0.99891, 0.99648, 0.99266, 0.98746, 0.98091, 0.97302, 0.96381, 0.95331, 0.94154, 0.92855, 0.91435, 0.89901, 0.88255, 0.86503, 0.84648, 0.82698, 0.80656, 0.78528, 0.76322, 0.74041, 0.71694, 0.69287, 0.66825, 0.64317, 0.61769, 0.59187, 0.56581, 0.53956, 0.5132, 0.4868, 0.46044, 0.43419, 0.40813, 0.38231, 0.35683, 0.33175, 0.30713, 0.28306, 0.25959, 0.23678, 0.21472, 0.19344, 0.17302, 0.15352, 0.13497, 0.11745, 0.10099, 0.08565, 0.07145, 0.05846, 0.04669, 0.03619, 0.02698, 0.01909, 0.01254, 0.00734, 0.00352, 0.00109, 4e-05, 0.00039, 0.00213, 0.00526, 0.00977, 0.01564, 0.02287, 0.03142, 0.04128, 0.05242, 0.0648, 0.0784, 0.09318, 0.10908, 0.12608, 0.14412, 0.16315, 0.18312, 0.20398, 0.22565, 0.2481, 0.27124, 0.29503, 0.31938, 0.34424, 0.36953, 0.39518, 0.42113, 0.4473, 0.47361, 0.5};

uint8_t sine_step1 = 0;
uint8_t sine_step2 = 40;
uint8_t sine_step3 = 80;

};


#endif
