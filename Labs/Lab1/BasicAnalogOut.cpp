//--------------------------------------------------------------------------
// 1.9 Basic Analog Out
//
// Send out a sine wave on the analog output pin using AnalogOut. 
// Capture the sine wave scope image and hand it in at checkout or show it 
// to the TA. Note the frequency of the sine wave.
//
// The analog sine wave output program must work in the following manner:
//		All output values and computations must be type float - no integer values allowed. <
//		Use the C sin() function to compute each value and scale output values from 0.0 to 1.0 for AnalogOut 
//		Use 20 samples per cycle and send out a complete cycle in a for loop. <
//		It should output a complete cycle, and repeat forever in an infinite while loop. <
//
// Kristina Beck
//

#include "BasicAnalogOut.hpp"

namespace Lab1{

	// The sinewave is created on this pin
	AnalogOut aout(p18);
 
	void BasicAnalogOut()
	{
		const float pi = 3.141592653589793238462;
		const float amplitude = 1.0f;
		const float offset = 65535/2;
		float rads = 0.0;
		uint16_t sample = 0;
    
		while(1) {
			// sinewave output
			for (float i = 0; i < 360; i+=18) {
            rads = (pi * i) / 180.0f;
            sample = (uint16_t)(amplitude * (offset * (sin(rads + pi))) + offset);
            aout.write_u16(sample);
			}
        }
	}

}