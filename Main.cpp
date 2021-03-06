//============================================================================
// Name        : Gpio_pins_C_plus_plus.cpp
// Author      : Ermiston
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
#include "GpioProcessor.h"

using namespace std;

int main() {
	cout << "Starting programming...." << endl;
	
	int count = 0;
	char* value;
	


	
	GpioProcessor *gpioProcessor = new GpioProcessor();

	
	/* Get reference of GPIO27 and GPIO29.* */
	Gpio *pin27 = gpioProcessor->getPin27();
	Gpio *pin29 = gpioProcessor->getPin29();
	
	//Set pin 27 to out.
	pin27->out();
	//Set pin 29 to input.
	pin29->in();

	while(1) {

	    

		/*Get pin 29 value.*/
		value = pin29->getValue();
		cout << "Pin value: " << value << endl;

		if (*value == '1')
	       	{
			//pin27->low();
			//usleep(30000);
			//pin27->high();
			//usleep(30000);
			pin27->low();
		}
	       	else
	       	{
			pin27->high();
			sleep(1);
			pin27->low();
			sleep(1);
			pin27->high();
			sleep(1);
			pin27->low();
			// cout << "It's working" << endl;
		}

		free(value);
		fflush(stdout);

		sleep(1);

	}

	gpioProcessor->cleanPins();
	delete (gpioProcessor);
	delete (pin27);
	delete (pin29);
	return 0;
}
