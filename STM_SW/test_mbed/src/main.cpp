#include <mbed.h>

// #include "encoder_implementation/own_rotary.hpp"
#include "motor_implementation/own_open_loop/open_loop.hpp"
#include "motor_implementation/closed_loop/closed_loop.hpp"

class Encoder
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

    volatile int32_t m_rotary_angle;
    volatile bool voltage_level_a;
    volatile bool voltage_level_b;
    // _interrupt.rise(callback(this, &Encoder::change_angle));
};

void Encoder::rise_A(void)
{
  voltage_level_a = 1;
  if (voltage_level_b == 1)
  {
    m_rotary_angle = m_rotary_angle +1;
  }
  else
  {
    --m_rotary_angle;
  }
}

void Encoder::fall_A(void)
{
  voltage_level_a = 0;
  if (voltage_level_b == 1)
  {
    // --Encoder::rotary_angle;
    --m_rotary_angle;
  }
  else
  {
    ++m_rotary_angle;
  }
}

void Encoder::rise_B(void)
{
  voltage_level_b = 1;
  if (voltage_level_a == 1)
  {
    --m_rotary_angle;
  }
  else
  {
    ++m_rotary_angle;
  }
}

void Encoder::fall_B(void)
{
  voltage_level_b = 0;
  if (voltage_level_a == 1)
  {
    ++m_rotary_angle;
  }
  else
  {
    --m_rotary_angle;
  }
}

int32_t Encoder::get_rotary_angle(void)
{
    return this->m_rotary_angle;
}

void Encoder::reset_rotary_angle(void)
{
    m_rotary_angle = 0;
}

Encoder::Encoder()
    :rotary_encoderA(D12), rotary_encoderB(PA_11), m_rotary_angle(0)
{
    rotary_encoderA.rise(callback(this, &Encoder::rise_A));
    rotary_encoderA.fall(callback(this, &Encoder::fall_A));
    rotary_encoderB.rise(callback(this, &Encoder::rise_B));
    rotary_encoderB.fall(callback(this, &Encoder::fall_B));
}


#define MAXIMUM_BUFFER_SIZE 32

Motor_Implementation *MotorControl;
// Encoder *Rotary_Encoder;

InterruptIn button_stop(D7); // Stop Taster, Falling Edge glaub ich
InterruptIn button_start(D8); // Start Taster, Falling Edge

bool stop_motor = 0;

void start_button_press(void)
{
  // delete MotorControl;
  // if (button_start.read() == 0)
  // {
  //   MotorControl = new Own_Closed_Loop();
  // }
  // else
  // {
  //   MotorControl = new Own_Open_Loop();
  // }

  // MotorControl->start_motor_control();
}

void stop_button_press(void)
{
  stop_motor = 1;
}

// Create a BufferedSerial object with a default baud rate.
static BufferedSerial serial_port(USBTX, USBRX);

int main() 
{
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

 Encoder Rotary_Encoder;

 MotorControl = new Own_Closed_Loop();

//  MotorControl = new Own_Open_Loop();

// serial_port.write(buf, periodlength);

  while(1) {

    if (stop_motor == 1)
    {
      Rotary_Encoder.reset_rotary_angle();
      stop_motor = 0;
    }
    int32_t rotary_angle = Rotary_Encoder.get_rotary_angle();
    MotorControl->control_motor(rotary_angle);

  // serial_port.write(buf, periodlength);  
  // put your main code here, to run repeatedly:
    ThisThread::sleep_for(20);
  }
}