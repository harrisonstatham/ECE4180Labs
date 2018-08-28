//--------------------------------------------------------------------------
// 1.9 Basic Analog Out
//
// Send out a sine wave on the analog output pin using AnalogOut. 
// Capture the sine wave scope image and hand it in at checkout or show it 
// to the TA. Note the frequency of the sine wave.
//
// Kristina Beck
//

#include "BasicAnalogOut.hpp"

namespace Lab1{

	// The sinewave is created on this pin
	AnalogOut aout(p18);
 
	void BasicAnalogOut()
	{
		const double pi = 3.141592653589793238462;
		const double amplitude = 0.5f;
		const double offset = 65535/2;
		double rads = 0.0;
		uint16_t sample = 0;
    
		while(1) {
			// sinewave output
			for (int i = 0; i < 360; i++) {
				rads = (pi * i) / 180.0f;
				sample = (uint16_t)(amplitude * (offset * (cos(rads + pi))) + offset);
				aout.write_u16(sample);
			}
		}
	}

}