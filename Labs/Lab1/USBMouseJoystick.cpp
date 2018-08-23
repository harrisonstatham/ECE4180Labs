//--------------------------------------------------------------------------
// 1.5 USB Mouse using the Joystick (Navigation Switch)
//
// Use the mbed as a USB mouse on a PC using the navigation switch for user input.
//
// Kristina Beck
//

#include "USBJoystick.hpp"

namespace Lab1 
{

    void USBJoystick()
    {
        USBMouse mouse;
        Common::NavigationSwitch myNav( p9, p6, p7, p5, p8); //pin order on Sparkfun Nav SW breakout

        int16_t x = 0;
        int16_t y = 0;
        uint8_t left_click = 0;
        while (1) {
            //check relative mouse movement
            x=0;
            y=0;
            if (myNav.up()) x=-1;
            if (myNav.down()) x=1;
            if (myNav.left()) y=1;
            if (myNav.right()) y=-1;
            //check mouse left button click
            if (myNav.fire()) left_click = 1;
            if (!myNav.fire())left_click = 0;
            //send a mouse data packet to PC
            mouse.update(x, y, left_click, 0);
            wait(0.001);
        }
    }

}