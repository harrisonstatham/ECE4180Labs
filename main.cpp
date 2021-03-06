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

//#include "Lab1.hpp"

#include "Lab2.hpp"

Serial pc(USBTX, USBRX);

int main() {
    

    //-------------------------------------------------
    // Lab 1
    //
    // All code that calls Lab 1 goes here.
    // 

    #pragma region Lab 1

     //Lab1::BasicDigitalIO();

    //Lab1::BasicPWM();

	//Lab1::NavigationSwitchDemo();
	
	//Lab1::USBJoystick();
	
	//Lab1::BasicI2CTouchSwitch();
	
	//Lab1::SPIDigitalExpander();
	
	//Lab1::BasicAnalogIn();
	
	//Lab1::BasicAnalogOut();
	
    #pragma endregion





    //-------------------------------------------------
    // Lab 2
    //
    // All code that calls Lab 2 goes here.
    //

    #pragma region Lab 2

    Lab2::L21_I2CIMU();

    //Lab2::L23_SerialULCD();

    //Lab2::L26_RelayDriver();


    #pragma endregion






    // Trap here if we somehow get here...
    while(1) {}

    return 0;
}

