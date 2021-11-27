#include "button_implementation.hpp"

#include "OneButton.h"
#include "pin_config.hpp"

OneButton reset_button(reset_pin, true, false);

void init_button(void (*pReset_motor)())
{
  reset_button.attachClick(pReset_motor);
}


	void read_swtich(void)
	{
  	bool start_pushbutton = digitalRead(stop_pin);
  	if (start_pushbutton == true)
  	{
  	  digitalWrite(stop_pin, true);
  	}
	}


  // Serial.println("Reset push button pressed");


	void read_buttons(void)
{

	read_swtich();

  reset_button.tick();

}