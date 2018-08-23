//
//  Lab1.cpp
//  ECE4180Projects
//
//  Created by Harrison on 8/21/18.
//  Copyright © 2018 HarrisonStatham. All rights reserved.
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