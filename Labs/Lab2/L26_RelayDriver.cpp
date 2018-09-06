
//--------------------------------------------------------------------------
// Lab2.x 
//
// 
//
// 
//



#include "L26_RelayDriver.hpp" 

namespace Lab2 
{

	void L26_RelayDriver()
	{ 
		DigitalOut TheRelay(p21);
		DigitalIn TheSwitch(p20);

		// Turn on the pull up.
		TheSwitch.mode(PullUp);

		while(true)
		{
			TheRelay = !TheSwitch;
		}
	} 

} // end namespace Lab2 
