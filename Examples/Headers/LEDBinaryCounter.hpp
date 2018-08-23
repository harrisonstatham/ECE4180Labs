//--------------------------------------------------------------------------
// LED Binary Counter
//
// Counts up in binary using the LEDs on the MBED board as a "display".
//
// Harrison Statham
//

/*
int main()
{
    Examples::LEDBinaryCounter TheCounter;

    // Count up
    TheCounter.Run(true);

    // Now count down
    TheCounter.Run(false);

    // Do something forever.
    while(true) {}
}
*/

#ifndef LEDBINARYCOUNTER_HPP
#define LEDBINARYCOUNTER_HPP

#include "stdint.h"
#include "mbed.h"

namespace Examples
{
    class LEDBinaryCounter
    {
        private:
            DigitalOut Led1;
            DigitalOut Led2;
            DigitalOut Led3;
            DigitalOut Led4;

            void Zeros();
            void Ones();

        public:

            LEDBinaryCounter();

            void Run(bool DirectionIncreasing);

            void Flash(int Times);
    };

}

#endif