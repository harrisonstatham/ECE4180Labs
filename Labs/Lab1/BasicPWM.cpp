//--------------------------------------------------------------------------
// 1.2 Basic PWM with LED Dimming
//
// Use two pushbuttons to dim one of mbed’s builtin LEDs using PWM
//
// The dimmer program must work in the following manner:
// 
// - One pushbutton switch makes the LED brighter and the other one makes it dimmer.
// 
// - Each pushbutton click adjusts the PWM level (up or down) by 0.1,
//    but once the PWM value reaches 1.0 or 0.0, it stays at the limit 
//    until the other button is hit. Pushbuttons must use internal pullups 
//    and must be debounced with PinDetect
// 
// - Pushbuttons use interrupt callbacks setup using the PinDetect class 
//    (see pushbutton wiki last example).
//
// Harrison Statham 
//

#include "BasicPWM.hpp"

namespace Lab1 {

	// The incremental increase/decrease in the PWM level.
	#define PWM_LEVEL_DELTA 0.1

	// Stuff everything in BasicPWMNS to avoid namespace collisions with 
	// anything that might be using similar names.
	namespace BasicPWMNS
	{
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
		BrighterButton.attach_asserted( &BasicPWMNS::BrighterButtonPressed );

		//BrighterButton.attach_deasserted( &BrighterButtonReleased );

		BrighterButton.setSampleFrequency(); // Defaults to 20ms.



		//-----------------------------------------------------------
		// Setup a push button to turn down the brightness.
		Common::PinDetect DimmerButton(p13);

		// Setup the pull down.
		DimmerButton.mode( PullDown );		

		// Setup the pressed handler.
		DimmerButton.attach_asserted( &BasicPWMNS::DimmerButtonPressed );

		//DimmerButton.attach_deasserted( &DimmerButtonReleased );

		DimmerButton.setSampleFrequency(); // Defaults to 20ms.



		//-----------------------------------------------------------
		// Setup the PWM output on the LED.
		PwmOut led(LED1);

		DigitalOut led2(LED2);

		//Serial pc(USBTX, USBRX); // tx, rx

		led2 = 1;

		while(true) 
		{
			led = BasicPWMNS::CurrentPWMLevel;

			wait( 0.1 );
	    }

	}

}