//--------------------------------------------------------------------------
// 1.3 Basic PWM with RGB LED Dimming
//
// Use PWM with two pushbuttons and a DIP switch to control the color and brightness of an RGB LED
// 
// The RGB LED color and dimmer control program must work in the following manner:
// - Use three PWM outputs to control the RGB LED (see RGB LED wiki)
// - Three DIP switch inputs select one of seven basic colors by each 
//    turning on/off one of the red, green, and blue LEDs. They must be 
//    digital inputs to the computer and not directly in the RGB LED circuit. 
//
// - The DIP switches should use internal pullups and do not need to be debounced.
//
// - One pushbutton switch makes the RGB LED brighter and the other one makes it dimmer.
//
// - Each pushbutton click adjusts the PWM level (up or down) by 0.1 on the DIP switch selected LEDs, 
//    but once the PWM value reaches 1.0 or 0.0, it stays at the limit until the other button is hit.
//
// - On LEDs not selected by DIP switch inputs, the PWM level should remain at 0.0 (off).
//
// - Pushbuttons must use internal pullups and must be debounced with PinDetect
//
// - Pushbuttons use interrupt callbacks setup using the PinDetect class (see pushbutton wiki last example).
//
// Harrison Statham
//


#include "PwmRgbLed.hpp"

namespace Lab1 {

	// The incremental increase/decrease in the PWM level.
	#define PWM_LEVEL_DELTA 0.1

	// Internal namespace to avoid namespace name collisions.
    namespace PWM_RGB
    {
        // Store the CurrentPWMLevel in a register -- might be unnecessary.
        volatile double CurrentPWMLevel = 0;

        // Turn up the brightness.
        void BrighterButtonPressed2(void)
        {
            if(CurrentPWMLevel < 1.0)
            {
                CurrentPWMLevel += PWM_LEVEL_DELTA;
            }
        }

        // Turn down the brightness.
        void DimmerButtonPressed2(void)
        {
            if(CurrentPWMLevel > 0)
            {
                CurrentPWMLevel -= PWM_LEVEL_DELTA;
            }
        }

    }


	void PwmRgbLed()
	{
		//-----------------------------------------------------------
		// Setup a push button to turn the brightness up.
		//
		Common::PinDetect BrighterButton(p12);

		// Setup the pull down.
		BrighterButton.mode( PullDown );

		// Setup the pressed handler.
		BrighterButton.attach_asserted( &PWM_RGB::BrighterButtonPressed2 );

		//BrighterButton.attach_deasserted( &BrighterButtonReleased );

		BrighterButton.setSampleFrequency(); // Defaults to 20ms.



		//-----------------------------------------------------------
		// Setup a push button to turn down the brightness.
		Common::PinDetect DimmerButton(p13);

		// Setup the pull down.
		DimmerButton.mode( PullDown );		

		// Setup the pressed handler.
		DimmerButton.attach_asserted( &PWM_RGB::DimmerButtonPressed2 );

		//DimmerButton.attach_deasserted( &DimmerButtonReleased );

		DimmerButton.setSampleFrequency(); // Defaults to 20ms.



		//-----------------------------------------------------------
		// Setup the PWM output on the LED.
		PwmOut TheLED(p25);

		   
		while(true) 
		{
			Red = !Red;
			wait( 0.2 );
	    }

	}

}