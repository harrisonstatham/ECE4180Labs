
#ifndef NavigationSwitch_H
#define NavigationSwitch_H


#include "mbed.h"
#include "stdint.h"
 
 
namespace Common {


    //BusOut/In is faster than multiple DigitalOut/Ins
    class NavigationSwitch
    {
    
    private:
        BusIn _pins;

    public:

        NavigationSwitch (PinName up, PinName down, PinName left,PinName right,PinName fire): _pins(up, down, left, right, fire)
        {
            //_pins.mode(PullUp); //needed if pullups not on board or a bare nav switch is used - delete otherwise
            //wait(0.001); //delays just a bit for pullups to pull inputs high
        }

        inline int read()
        {
            return _pins.read();
        }

        //boolean functions to test each switch
        
        inline bool up()
        {
            return !(_pins.read() & 0x1);
        }

        inline bool down()
        {
            return !(_pins.read() & 0x2);
        }

        inline bool left()
        {
            return !(_pins.read() & 0x4);
        }

        inline bool right()
        {
            return !(_pins.read() & 0x8);
        }

        inline bool fire()
        {
            return !(_pins.read() & 0x10);
        }


        //automatic read on RHS
        inline operator int ()
        {
            return _pins.read();
        }

        //index to any switch array style
        bool operator[](int index) {
            return (_pins.read() & (0x1 << index));
        };

    }; // end class
 
} // end namespace

#endif