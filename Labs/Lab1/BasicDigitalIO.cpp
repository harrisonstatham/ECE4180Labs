//--------------------------------------------------------------------------
// 1.1 Basic Digital IO
//
// Read a pushbutton input in a program loop using DigitalIn and 
// use the input value to control an external LED with DigitalOut. 
//
// This repeats forever in an infinite while loop. When the 
// pushbutton is held down the LED should stay on, and turn off 
// whenever it is released.
//
// Harrison Statham
//

#include "BasicDigitalIO.hpp"


namespace Lab1 {

	void BasicDigitalIO()
	{
		
		while(true)
		{
			// Create a de-bounced input for the switch.
			// Note, DebounceIn is in the Common namespace.
			DigitalIn TheSwitch(p12);
			
			// Create a digital out for the LED.
			DigitalOut TheLED(LED1);
			
			while(1)
			{
				// We can continuously set the value of the LED to the 
				// value of the switch.
				// Note the negation, because we hooked the pullup resistor to +5V.
				TheLED = !TheSwitch;
			}
		}
	}

}