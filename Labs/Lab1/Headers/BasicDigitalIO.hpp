//--------------------------------------------------------------------------
// 1.1 Basic Digital IO
//
// Read a pushbutton input in a program loop using DigitalIn and 
// use the input value to control an external LED with DigitalOut. 
//
// This repeats forever in an infinite while loop. When the 
// pushbutton is held down the LED should stay on, and turn off 
// whenever it is released.
//
// Harrison Statham
//

#ifndef BasicDigitalIO_hpp
#define BasicDigitalIO_hpp

#include "stdint.h"
#include "mbed.h"

//#include "DebounceIn.hpp"


namespace Lab1 {

    void BasicDigitalIO();
}


#endif /* BasicDigitalIO_hpp */
