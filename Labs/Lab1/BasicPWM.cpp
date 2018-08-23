//
//  BasicPWM.cpp
//  ECE4180Projects
//
//  Created by Harrison on 8/21/18.
//  Copyright © 2018 HarrisonStatham. All rights reserved.
//

#include "BasicPWM.hpp"

namespace Lab1 {

	// The incremental increase/decrease in the PWM level.
	#define PWM_LEVEL_DELTA 0.1

	// Store the CurrentPWMLevel in a register -- might be unnecessary.
	volatile double CurrentPWMLevel = 0;

	// Turn up the brightness.
	void BrighterButtonPressed(void)
	{
		if(CurrentPWMLevel < 1.0)
		{
			CurrentPWMLevel += PWM_LEVEL_DELTA;
		}
	}

	// Turn down the brightness.
	void DimmerButtonPressed(void)
	{
		if(CurrentPWMLevel > 0)
		{
			CurrentPWMLevel -= PWM_LEVEL_DELTA;
		}
	}



	void BasicPWM()
	{
		//-----------------------------------------------------------
		// Setup a push button to turn the brightness up.
		//
		Common::PinDetect BrighterButton(p12);

		// Setup the pull down.
		BrighterButton.mode( PullDown );

		// Setup the pressed handler.
		BrighterButton.attach_asserted( &BrighterButtonPressed );

		//BrighterButton.attach_deasserted( &BrighterButtonReleased );

		BrighterButton.setSampleFrequency(); // Defaults to 20ms.



		//-----------------------------------------------------------
		// Setup a push button to turn down the brightness.
		Common::PinDetect DimmerButton(p13);

		// Setup the pull down.
		DimmerButton.mode( PullDown );		

		// Setup the pressed handler.
		DimmerButton.attach_asserted( &DimmerButtonPressed );

		//DimmerButton.attach_deasserted( &DimmerButtonReleased );

		DimmerButton.setSampleFrequency(); // Defaults to 20ms.



		//-----------------------------------------------------------
		// Setup the PWM output on the LED.
		PwmOut led(LED1);

		   
		while(true) 
		{
			led = !led;
			wait( 0.2 );
	    }

	}

}