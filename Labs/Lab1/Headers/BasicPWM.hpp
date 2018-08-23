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

#ifndef BasicPWM_hpp
#define BasicPWM_hpp

#include "stdint.h"
#include "mbed.h"

#include "PinDetect.hpp"

namespace Lab1 {

    void BasicPWM();

}


#endif /* BasicPWM_hpp */
