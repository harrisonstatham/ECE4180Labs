//--------------------------------------------------------------------------
// 1.8 Basic Analog In
//
// Read the analog voltage input from a potentiometer and use the input value to dim an LED with PWM
//
// Kristina Beck
//

#include "BasicAnalogIn.hpp"

namespace Lab1 
{
	void BasicAnalogIn()
	{
	   PwmOut myled(LED1);
       AnalogIn mypotentiometer(p20);
	   while(1) 
		{
          myled = mypotentiometer;
          wait(0.01);
        }
	 
	}
}

