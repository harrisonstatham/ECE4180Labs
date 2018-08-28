//--------------------------------------------------------------------------
// ECE 4180 Labs Main Entry Point
//  
// Kristina Beck
// Harrison Statham
//
// Fall 2018
//

#include "stdint.h"
#include "mbed.h"   

#include "Lab1.hpp"

int main() {
    

    //-------------------------------------------------
    // Lab 1
    //
    // All code that calls Lab 1 goes here.
    // 

    #pragma region Lab 1

   // Lab1::BasicDigitalIO();

    //Lab1::BasicPWM();

	//Lab1::NavigationSwitchDemo();
	
	//Lab1::USBJoystick();
	
	Lab1::BasicI2CTouchSwitch();
	
    #pragma endregion





    //-------------------------------------------------
    // Lab 2
    //
    // All code that calls Lab 2 goes here.
    //

    #pragma region Lab 2

    #pragma endregion






    // Trap here if we somehow get here...
    while(1) {}

    return 0;
}

