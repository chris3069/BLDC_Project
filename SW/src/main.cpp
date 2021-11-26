#include <Arduino_FreeRTOS.h>
#include <Arduino.h>
#include <semphr.h>  // add the FreeRTOS functions for Semaphores (or Flags).
#include "Encoder.h"
#include "main.hpp"

#include "../Arduino-FOC/src/SimpleFOC.h"

#include "BLDCMotor.h"
#include "sensors/HallSensor.h"
#include "drivers/BLDCDriver3PWM.h"
#include "current_sense/InlineCurrentSense.h"
#include "current_sense/LowsideCurrentSense.h"






///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Regular program without RTOS

Encoder Speed_encoder(12, 13);
static int32_t old_target_speed = INT32_MIN;
static int32_t new_target_speed = INT32_MAX;


BLDCMotor motor = BLDCMotor(3);
// BLDCDriver3PWM driver = BLDCDriver3PWM(pwmA, pwmB, pwmC, Enable(optional));
BLDCDriver3PWM driver = BLDCDriver3PWM(9, 10, 11, 6);

   
int main(void)
{
  mein_setup();

  while (1)
  {
    meine_loop();
  }
}

void mein_setup()
{
    // initialize serial communication at 9600 bits per second:
   Serial.begin(9600);



  // driver config
  // power supply voltage [V]
  driver.voltage_power_supply = 12;
  driver.init();
  // link the motor and the driver
  motor.linkDriver(&driver);

  // limiting motor movements
  motor.voltage_limit = 3;   // [V]
  motor.velocity_limit = 5; // [rad/s] cca 50rpm

  motor.controller = MotionControlType::velocity_openloop;

  // init motor hardware
  motor.init();

}

void meine_loop()
{
  // Read Target Speed
  new_target_speed = Speed_encoder.read();
  if (new_target_speed != old_target_speed) 
  {
    old_target_speed = new_target_speed;
    Serial.println(new_target_speed);
  }
  static float target_velocity = new_target_speed;

  motor.move(target_velocity);

}





// // Declare a mutex Semaphore Handle which we will use to manage the Serial Port.
// // It will be used to ensure only one Task is accessing this resource at any time.
// SemaphoreHandle_t xSerialSemaphore;

// // define two Tasks for DigitalRead & AnalogRead
// void TaskDigitalRead( void *pvParameters );
// void TaskAnalogRead( void *pvParameters );
// void TaskCalculateDirection(void *pvParamters);

//   static int32_t oldDirection = INT32_MIN;
//   static int32_t newDirection = INT32_MAX;

// // the setup function runs once when you press reset or power the board
// void setup() {

//   // initialize serial communication at 9600 bits per second:
//   Serial.begin(9600);
  
//   while (!Serial) {
//     ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
//   }

//   // Semaphores are useful to stop a Task proceeding, where it should be paused to wait,
//   // because it is sharing a resource, such as the Serial port.
//   // Semaphores should only be used whilst the scheduler is running, but we can set it up here.
//   if ( xSerialSemaphore == NULL )  // Check to confirm that the Serial Semaphore has not already been created.
//   {
//     xSerialSemaphore = xSemaphoreCreateMutex();  // Create a mutex semaphore we will use to manage the Serial Port
//     if ( ( xSerialSemaphore ) != NULL )
//       xSemaphoreGive( ( xSerialSemaphore ) );  // Make the Serial Port available for use, by "Giving" the Semaphore.
//   }

//   // Now set up two Tasks to run independently.
// //   xTaskCreate(
// //     TaskDigitalRead
// //     ,  "DigitalRead"  // A name just for humans
// //     ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
// //     ,  NULL //Parameters for the task
// //     ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
// //     ,  NULL ); //Task Handle

// //   xTaskCreate(
// //     TaskAnalogRead
// //     ,  "AnalogRead" // A name just for humans
// //     ,  128  // Stack size
// //     ,  NULL //Parameters for the task
// //     ,  1  // Priority
// //     ,  NULL ); //Task Handle

// //   // Now the Task scheduler, which takes over control of scheduling individual Tasks, is automatically started.
// // }

//   xTaskCreate(
//     TaskCalculateDirection
//     ,  "CalcualteDirection" // A name just for humans
//     ,  128  // Stack size
//     ,  NULL //Parameters for the task
//     ,  1  // Priority
//     ,  NULL ); //Task Handle

//   // Now the Task scheduler, which takes over control of scheduling individual Tasks, is automatically started.
// }


// void loop()
// {
//   // Empty. Things are done in Tasks.
// }

// /*--------------------------------------------------*/
// /*---------------------- Tasks ---------------------*/
// /*--------------------------------------------------*/


// void TaskCalculateDirection(void *pvParameters __attribute__((unused)) )
// {

//     Encoder encoder(12, 13);

//   for (;;) // A Task shall never return or exit.
//   {
//     // read the input pin:

//     newDirection = encoder.read();

//     if (newDirection != oldDirection) {
//     oldDirection = newDirection;
//     Serial.println(newDirection);
//     }

//     // See if we can obtain or "Take" the Serial Semaphore.
//     // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
//     // if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
//     // {
//     //   // We were able to obtain or "Take" the semaphore and can now access the shared resource.
//     //   // We want to have the Serial Port for us alone, as it takes some time to print,
//     //   // so we don't want it getting stolen during the middle of a conversion.
//     //   // print out the state of the button:
//     //   // Serial.println(buttonState);

//     //   xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
//     // }

//     vTaskDelay(4);  // one tick delay (15ms) in between reads for stability
//   }
// }

// void TaskDigitalRead( void *pvParameters __attribute__((unused)) )  // This is a Task.
// {
//   /*
//     DigitalReadSerial
//     Reads a digital input on pin 2, prints the result to the serial monitor

//     This example code is in the public domain.
//   */

//   // digital pin 2 has a pushbutton attached to it. Give it a name:
//   uint8_t pushButton = 2;

//   // make the pushbutton's pin an input:
//   pinMode(pushButton, INPUT);

//   for (;;) // A Task shall never return or exit.
//   {
//     // read the input pin:
    

//     // See if we can obtain or "Take" the Serial Semaphore.
//     // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
//     if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
//     {
//       // We were able to obtain or "Take" the semaphore and can now access the shared resource.
//       // We want to have the Serial Port for us alone, as it takes some time to print,
//       // so we don't want it getting stolen during the middle of a conversion.
//       // print out the state of the button:
//       // Serial.println(buttonState);

//       xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
//     }

//     vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
//   }
// }

// void TaskAnalogRead( void *pvParameters __attribute__((unused)) )  // This is a Task.
// {

//   for (;;)
//   {
//     // read the input on analog pin 0:
//     int sensorValue = analogRead(A0);

//     // See if we can obtain or "Take" the Serial Semaphore.
//     // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
//     if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
//     {
//       // We were able to obtain or "Take" the semaphore and can now access the shared resource.
//       // We want to have the Serial Port for us alone, as it takes some time to print,
//       // so we don't want it getting stolen during the middle of a conversion.
//       // print out the value you read:
//       // Serial.println(sensorValue);

//       xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
//     }

//     vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
//   }
// }
