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
	
    //Lab1::BasicDigitalIO();
    
    Lab1::BasicPWM();

    while(1) {}

    return 0;
}

