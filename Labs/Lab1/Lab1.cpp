//--------------------------------------------------------------------------
//
//
//
//
//

#include "Lab1.hpp"
#include "BasicDigitalIO.hpp"
#include "BasicPWM.hpp"
#include "PwmRgbLed.hpp"
#include "Joystick.hpp"

namespace Lab1 {

	void RunLab()
	{
		BasicDigitalIO();
		
		BasicPWM();

		PwmRgbLed();

		NavigationSwitchDemo();
	}

}