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

#ifndef PWMRGBLED_hpp
#define PWMRGBLED_hpp

#include "stdint.h"
#include "mbed.h"

#include "PinDetect.hpp"

namespace Lab1 {

    void PwmRgbLed();

}


#endif /* PWMRGBLED_hpp */
