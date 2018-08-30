//--------------------------------------------------------------------------
// 1.7 Expanding Digital I/O ports and SP
//
// Read a switch input and control an LED using an SPI serial bus I/O port expander IC.
//
// Harrison Statham
//


#include "SPIDigitalExpander.hpp"

namespace Lab1 {
	void SPIDigitalExpander()
	{
	// Create SPI bus
	SPI spi(p5, p6, p7);
	// 
	// Wiring Connections:
	// mbed p5,p6,p7 are tied to MCP23S17 SI, SO, SCK pins
	// mbed p20 to MCP23S17 CS
	// MCP23S17 reset pin pulled high
	// MCP23S17 GPA0 connected to GPB0 for loopback test
	// A0, A1, A2 of the MCP23S17  are tied to ground on the breadboard, so the 8-bit address for writes is 0x40
	// This is referred to as the opcode in the device datasheet
	char Opcode = 0x42;
 
	// Next create a MCP23S17
	// mbed p20 is connected to ~chipSelect on the MCP23S17
	MCP23S17 chip = MCP23S17(spi, p20, Opcode);
 
	// Optional software reset - mbed p14 to MCP23S17 reset pin
	DigitalOut reset(p14);
 
	DigitalOut led1(LED1); // mbed LED1 is used for test status display
	//  The MCP23S17 reset pin can just be pulled high, since it has a power on reset circuit.
	//  The reset pin can be used for a software forced reset by pulling it low with an mbed GPIO pin.
	//  But just leave it pulled high for this simple demo code.
	//  After a power on reset, both IO ports default to input mode
	//
	//  Here is the optional code for a software reset
	//  reset = 0;
	//  wait_us(1);
	//  reset = 1;
	//
	//  Set all 8 Port A bits to output direction
		chip.direction(PORT_A, 0x00);
	//  Set all 8 Port B bits to input direction
		chip.direction(PORT_B, 0xFF);
		led1=0;
	//  Start Loopback test sending out and reading back values
	//  loopback test uses A0 and B0 pins - so use a wire to jumper those two pins on MCP23S17 together
		while (1) {
			// write 0xAA to MCP23S17 Port A
			chip.write(PORT_A, 0xAA);
			wait(.5);
			// read back value from MCP23S17 Port B and display B0 on mbed led1
			led1 = chip.read(PORT_B)& 0x01;
			// write 0x55 to MCP23S17 Port A
			chip.write(PORT_A, 0x55);
			wait(.5);
			// read back value from MCP23S17 Port B and display B0 on mbed led1
			led1 = chip.read(PORT_B)& 0x01;
			// led1 should blink slowly when it is all working
			//To prove this part of the code is working:
			led1=0;
			wait(.2);
			led1=1;
			wait(.2);
		}
	}
}