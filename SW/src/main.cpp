#include "main.hpp"

Open_Loop Abstract_motor;

// void (*pReset_motor) (void) = motor.reset_motor_control;

// void (*pReset_motor) (void) = reset_motor_control;

void (*pReset_target_speed)(void) = reset_target_speed;

void (*restart_motor)(void) = Motor_Implementation::start_motor_control;

// void (*restart_motor)(void) = start_motor_control;

float (*desired_speed)(void) = getTargetSpeed;



void setup() 
{
  Serial.begin(9600);

  Abstract_motor.motor_implementation_init();
  // motor_implementation_init();

  init_button(pReset_target_speed);


}

void loop() 
{
  read_buttons(restart_motor); 
  // Abstract_motor.motor_implementation_init();
  Abstract_motor.motor_control(desired_speed());
  // motor_implementation_control(desired_speed());

}



///////////////////////////////////////////////////////////////////////////////////////////////

// #include <Arduino_FreeRTOS.h>
// #include <semphr.h>  // add the FreeRTOS functions for Semaphores (or Flags).

// // // Declare a mutex Semaphore Handle which we will use to manage the Serial Port.
// // // It will be used to ensure only one Task is accessing this resource at any time.
// // SemaphoreHandle_t xSerialSemaphore;

// // // define two Tasks for DigitalRead & AnalogRead
// // void TaskDigitalRead( void *pvParameters );
// // void TaskAnalogRead( void *pvParameters );
// // void TaskCalculateDirection(void *pvParamters);

// //   static int32_t oldDirection = INT32_MIN;
// //   static int32_t newDirection = INT32_MAX;

// // // the setup function runs once when you press reset or power the board
// // void setup() {

// //   // initialize serial communication at 9600 bits per second:
// //   Serial.begin(9600);
  
// //   while (!Serial) {
// //     ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
// //   }

// //   // Semaphores are useful to stop a Task proceeding, where it should be paused to wait,
// //   // because it is sharing a resource, such as the Serial port.
// //   // Semaphores should only be used whilst the scheduler is running, but we can set it up here.
// //   if ( xSerialSemaphore == NULL )  // Check to confirm that the Serial Semaphore has not already been created.
// //   {
// //     xSerialSemaphore = xSemaphoreCreateMutex();  // Create a mutex semaphore we will use to manage the Serial Port
// //     if ( ( xSerialSemaphore ) != NULL )
// //       xSemaphoreGive( ( xSerialSemaphore ) );  // Make the Serial Port available for use, by "Giving" the Semaphore.
// //   }

// //   // Now set up two Tasks to run independently.
// // //   xTaskCreate(
// // //     TaskDigitalRead
// // //     ,  "DigitalRead"  // A name just for humans
// // //     ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
// // //     ,  NULL //Parameters for the task
// // //     ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
// // //     ,  NULL ); //Task Handle

// // //   xTaskCreate(
// // //     TaskAnalogRead
// // //     ,  "AnalogRead" // A name just for humans
// // //     ,  128  // Stack size
// // //     ,  NULL //Parameters for the task
// // //     ,  1  // Priority
// // //     ,  NULL ); //Task Handle

// // //   // Now the Task scheduler, which takes over control of scheduling individual Tasks, is automatically started.
// // // }

// //   xTaskCreate(
// //     TaskCalculateDirection
// //     ,  "CalcualteDirection" // A name just for humans
// //     ,  128  // Stack size
// //     ,  NULL //Parameters for the task
// //     ,  1  // Priority
// //     ,  NULL ); //Task Handle

// //   // Now the Task scheduler, which takes over control of scheduling individual Tasks, is automatically started.
// // }


// // void loop()
// // {
// //   // Empty. Things are done in Tasks.
// // }

// // /*--------------------------------------------------*/
// // /*---------------------- Tasks ---------------------*/
// // /*--------------------------------------------------*/


// // void TaskCalculateDirection(void *pvParameters __attribute__((unused)) )
// // {

// //     Encoder encoder(12, 13);

// //   for (;;) // A Task shall never return or exit.
// //   {
// //     // read the input pin:

// //     newDirection = encoder.read();

// //     if (newDirection != oldDirection) {
// //     oldDirection = newDirection;
// //     Serial.println(newDirection);
// //     }

// //     // See if we can obtain or "Take" the Serial Semaphore.
// //     // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
// //     // if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
// //     // {
// //     //   // We were able to obtain or "Take" the semaphore and can now access the shared resource.
// //     //   // We want to have the Serial Port for us alone, as it takes some time to print,
// //     //   // so we don't want it getting stolen during the middle of a conversion.
// //     //   // print out the state of the button:
// //     //   // Serial.println(buttonState);

// //     //   xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
// //     // }

// //     vTaskDelay(4);  // one tick delay (15ms) in between reads for stability
// //   }
// // }

// // void TaskDigitalRead( void *pvParameters __attribute__((unused)) )  // This is a Task.
// // {
// //   /*
// //     DigitalReadSerial
// //     Reads a digital input on pin 2, prints the result to the serial monitor

// //     This example code is in the public domain.
// //   */

// //   // digital pin 2 has a pushbutton attached to it. Give it a name:
// //   uint8_t pushButton = 2;

// //   // make the pushbutton's pin an input:
// //   pinMode(pushButton, INPUT);

// //   for (;;) // A Task shall never return or exit.
// //   {
// //     // read the input pin:
    

// //     // See if we can obtain or "Take" the Serial Semaphore.
// //     // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
// //     if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
// //     {
// //       // We were able to obtain or "Take" the semaphore and can now access the shared resource.
// //       // We want to have the Serial Port for us alone, as it takes some time to print,
// //       // so we don't want it getting stolen during the middle of a conversion.
// //       // print out the state of the button:
// //       // Serial.println(buttonState);

// //       xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
// //     }

// //     vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
// //   }
// // }

// // void TaskAnalogRead( void *pvParameters __attribute__((unused)) )  // This is a Task.
// // {

// //   for (;;)
// //   {
// //     // read the input on analog pin 0:
// //     int sensorValue = analogRead(A0);

// //     // See if we can obtain or "Take" the Serial Semaphore.
// //     // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
// //     if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
// //     {
// //       // We were able to obtain or "Take" the semaphore and can now access the shared resource.
// //       // We want to have the Serial Port for us alone, as it takes some time to print,
// //       // so we don't want it getting stolen during the middle of a conversion.
// //       // print out the value you read:
// //       // Serial.println(sensorValue);

// //       xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
// //     }

// //     vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
// //   }
// // }





//////////////////////////////////////////////////////////////////////////////////////////////////////////////



