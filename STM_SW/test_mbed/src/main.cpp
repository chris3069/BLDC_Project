#include <mbed.h>

#include "motor_implementation/own_open_loop/open_loop.hpp"

#define MAXIMUM_BUFFER_SIZE 32

// Open Loop Betrieb

// Timer lauft, y Values verändern sich alle 100ms
// y-Value in pulsewidth laden
// IN2 startet von Value 20, 
// IN3 starte von Value 40

// mit Poti einstellbar

Own_Open_Loop *MotorControl;


InterruptIn button_stop(D7); // Stop Taster, Falling Edge glaub ich
InterruptIn button_start(D8); // Start Taster, Falling Edge

InterruptIn rotary_encoder1(D12); // Rotary Encoder, Falling Edge glaub ich
InterruptIn rotary_encoder2(D13); // Rotary Encoder, Falling Edge

// DigitalOut

uint32_t pwmstep = 0;

void next_pwm_step(void)
{
  ++pwmstep;
}


Ticker synchronous_rpm;
// uint8_t sine_step1 = 0;
// uint8_t sine_step2 = 40;
// uint8_t sine_step3 = 80;
// void adapt_period_time(void)
// {
  
// }


// void next_pwm_step(void)
// {
//   ++sine_step1;
//   if (sine_step1 > 119)
//   {
//     sine_step1 = 0;
//   }

//   ++sine_step2;
//   if (sine_step2 > 119)
//   {
//     sine_step2 = 0;
//   }

//   ++sine_step3;
//   if (sine_step3 > 119)
//   {
//     sine_step3 = 0;
//   }
//   // adapt_period_time();
// }


// Create a BufferedSerial object with a default baud rate.
static BufferedSerial serial_port(USBTX, USBRX);

int main() {

    // Set desired properties (9600-8-N-1).
    serial_port.set_baud(9600);
    serial_port.set_format(
        /* bits */ 8,
        /* parity */ BufferedSerial::None,
        /* stop bit */ 1
    );
   char buf[MAXIMUM_BUFFER_SIZE] = {0};

  // sine_step1 = 0;
  // sine_step2 = 40;
  // sine_step3 = 80;

  // put your setup code here, to run once:
  // PwmOut IN1(D9);
  // PwmOut IN2(D10);
  // PwmOut IN3(D11);
  // DigitalOut
   
   MotorControl = new Own_Open_Loop();



  synchronous_rpm.attach(&next_pwm_step, '200ms');

// IN1.period_us(100);
// IN2.period_us(100);
// IN3.period_us(100);
// IN1.pulsewidth_us(sine_wave[sine_step1]);
// IN2.pulsewidth_us(sine_wave[sine_step2]);
// IN3.pulsewidth_us(sine_wave[sine_step3]);


// IN1.pulsewidth_us(sine_wave[sine_step]);
// uint32_t periodlength = TIM3->CCR2;
// serial_port.write(buf, periodlength);

  while(1) {

    MotorControl->next_pwm_step(pwmstep);
MotorControl->motor_control((float)pwmstep);
    // IN1.pulsewidth_us(sine_wave[sine_step1]);
    // IN2.pulsewidth_us(sine_wave[sine_step2]);
    // IN3.pulsewidth_us(sine_wave[sine_step3]);
  // serial_port.write(buf, periodlength);  
    // D9.
    // put your main code here, to run repeatedly:
  }
}