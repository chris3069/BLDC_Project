#include <mbed.h>

#define MAXIMUM_BUFFER_SIZE 32

// Open Loop Betrieb

// Timer lauft, y Values verändern sich alle 100ms
// y-Value in pulsewidth laden
// IN2 startet von Value 20, 
// IN3 starte von Value 40

// mit Poti einstellbar


InterruptIn button_stop(D7); // Stop Taster, Falling Edge glaub ich
InterruptIn button_start(D8); // Start Taster, Falling Edge

InterruptIn rotary_encoder1(D12); // Rotary Encoder, Falling Edge glaub ich
InterruptIn rotary_encoder2(D13); // Rotary Encoder, Falling Edge

DigitalOut






uint8_t sine_wave[] = {49, 54, 59, 64, 69, 73, 78, 82, 85, 89, 91, 94, 95, 97, 97, 97, 97, 96, 95, 93, 90, 87, 84, 80, 76, 71, 66, 61, 56, 51, 46, 41, 36, 31, 26, 21, 17, 13, 10, 7, 4, 2, 1, 0, 0, 0, 0, 2, 3, 6, 8, 12, 15, 19, 24, 28, 33, 38, 43, 48}

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

  // put your setup code here, to run once:
  PwmOut IN1(D9);
  PwmOut IN2(D10);
  PwmOut IN3(D11);
  // DigitalOut
   
  
//   Timer t
// t.
IN1.period_us(100);
IN1.pulsewidth_us(10);
// uint32_t periodlength = TIM3->CCR2;
// serial_port.write(buf, periodlength);

  while(1) {
    
  serial_port.write(buf, periodlength);  
    // D9.
    // put your main code here, to run repeatedly:
  }
}