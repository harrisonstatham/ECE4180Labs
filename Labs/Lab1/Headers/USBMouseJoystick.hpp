//--------------------------------------------------------------------------
// 1.5 USB Mouse using the Joystick (Navigation Switch)
//
// Use the mbed as a USB mouse on a PC using the navigation switch for user input.
//
// Kristina Beck
//

#ifndef USBJOYSTICK_HPP
#define USBJOYSTICK_HPP

#include "mbed.h"
#include "stdint.h"

#include "NavigationSwitch.hpp"
#include "USBMouse.h"

namespace Lab1
{
    void USBJoystick();
}

#endif