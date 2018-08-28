//--------------------------------------------------------------------------
// 1.6 Basic I2C Control of Touch Switch
//
// Kristina Beck
//

#include "BasicI2CTouchSwitch.hpp"

namespace Lab1 
{
    namespace BasicI2CTouch
    {
        DigitalOut led1(LED1);
        DigitalOut led2(LED2);
        DigitalOut led3(LED3);
        DigitalOut led4(LED4);
        // Create the interrupt receiver object on pin 26
        InterruptIn interrupt(p26);
        // Setup the i2c bus on pins 9 and 10
        I2C i2c(p9, p10);
        // Setup the Mpr121:
        // constructor(i2c object, i2c address of the mpr121)
        Mpr121 mpr121(&i2c, Mpr121::ADD_VSS);

        // Key hit/release interrupt routine
        void fallInterrupt() {
            int key_code=0;
            int i=0;
            int value=mpr121.read(0x00);
            value +=mpr121.read(0x01)<<8;
            // LED demo mod
            i=0;
            // puts key number out to LEDs for demo
            for (i=0; i<12; i++) {
            if (((value>>i)&0x01)==1) key_code=i+1;
            }
            led4=key_code & 0x01;
            led3=(key_code>>1) & 0x01;
            led2=(key_code>>2) & 0x01;
            led1=(key_code>>3) & 0x01;
        }

    }

    void BasicI2CTouchSwitch()
    {
        BasicI2CTouch::interrupt.fall(&BasicI2CTouch::fallInterrupt);
        BasicI2CTouch::interrupt.mode(PullUp);   
    }
}