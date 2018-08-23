//--------------------------------------------------------------------------
//
//
//
//
//

#include "Joystick.hpp"

namespace Lab1 {

    void NavigationSwitchDemo()
    {

        BusOut LEDS(LED1,LED2,LED3,LED4);

        Common::NavigationSwitch NavSwitch( p9, p6, p7, p5, p8); //pin order on Sparkfun breakout

        while(1) {
            //with pullups a button hit is a "0" - "~" inverts data to leds
            LEDS = ~(NavSwitch & 0x0F); //update leds with nav switch direction inputs
            if(NavSwitch.fire()) LEDS = 0x0F; //special all leds on case for fire (center button)
            //or use - if(myNav[4]==0) mbedleds = 0x0F; //can index a switch bit like this
            wait(0.02);
        }
    }

}






