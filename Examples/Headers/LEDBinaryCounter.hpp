//--------------------------------------------------------------------------
//
//
//
//
//

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