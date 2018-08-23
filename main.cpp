//--------------------------------------------------------------------------
//
//
//
//
//

#include "stdint.h"
#include "mbed.h"   

//#include "Lab1.hpp"

#include "LEDBinaryCounter.hpp"


int main() {
	
    using namespace Examples;
	//Lab1::RunLab();
    
    Examples::LEDBinaryCounter TheCounter;

    // Count up
    TheCounter.Run(true);

    // Now count down
    TheCounter.Run(false);


    while(1) {}

    return 0;
}

