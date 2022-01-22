#include <mbed.h>

#include "motor_implementation/own_open_loop/open_loop.hpp"

#define MAXIMUM_BUFFER_SIZE 32

// Open Loop Betrieb
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

void start_button_press(void)
{
  MotorControl->start_motor_control();
}

void stop_button_press(void)
{
  MotorControl->quit_motor_control();
}

Ticker synchronous_rpm;

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


  button_start.fall(&start_button_press);
  button_stop.fall(&stop_button_press);

   MotorControl = new Own_Open_Loop();

   MotorControl->start_motor_control();

  synchronous_rpm.attach(&next_pwm_step, 0.2);


// IN1.pulsewidth_us(sine_wave[sine_step]);
// uint32_t periodlength = TIM3->CCR2;
// serial_port.write(buf, periodlength);

  while(1) {

    MotorControl->next_pwm_step(pwmstep);
MotorControl->motor_control((float)pwmstep);

  // serial_port.write(buf, periodlength);  
  // put your main code here, to run repeatedly:
    ThisThread::sleep_for(100);
  }
}