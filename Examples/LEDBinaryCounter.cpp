//--------------------------------------------------------------------------
// LED Binary Counter
//
// Counts up in binary using the LEDs on the MBED board as a "display".
//
// Harrison Statham
//

#include "LEDBinaryCounter.hpp"

namespace Examples
{

    //--------------------------------------------------
    // Constructors

    #pragma region

    LEDBinaryCounter::LEDBinaryCounter() : Led1(LED1), Led2(LED2), Led3(LED3), Led4(LED4)
    {

    }

    #pragma endregion


    //--------------------------------------------------
    // Private Method(s)

    #pragma region

    void LEDBinaryCounter::Zeros()
    {
        Led1 = 0;
        Led2 = 0;
        Led3 = 0;
        Led4 = 0;
    }

    void LEDBinaryCounter::Ones()
    {
        Led1 = 1;
        Led2 = 1;
        Led3 = 1;
        Led4 = 1;
    }

    #pragma endregion


    //--------------------------------------------------
    // Public Method(s)

    #pragma region

    void LEDBinaryCounter::Run(bool DirectionIncreasing)
    {
        Flash(1);

        if(DirectionIncreasing)
        {
            for(int i = 0; i < 16; i++)
            {
                Led4 = ((i >> 0) & 1) == 1;
                Led3 = ((i >> 1) & 1) == 1;
                Led2 = ((i >> 2) & 1) == 1;
                Led1 = ((i >> 3) & 1) == 1;
                wait(0.01);
            }
        }
        else
        {
            for(int i = 15; i >= 0; i--)
            {            
                Led4 = ((i >> 0) & 1) == 1;
                Led3 = ((i >> 1) & 1) == 1;
                Led2 = ((i >> 2) & 1) == 1;
                Led1 = ((i >> 3) & 1) == 1;
                wait(0.01);
            }
        }


        Flash(2);
    }

    void LEDBinaryCounter::Flash(int Times)
    {
        for(int i = 0; i < Times; i++)
        {
            wait(0.01);
            Zeros();
            wait(0.02);
            Ones();
            wait(0.02);
            Zeros();
            wait(0.01);
        }
    }

    #pragma endregion

} // end namespace