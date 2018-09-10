
//--------------------------------------------------------------------------
// Lab2.x 
//
// 
//
// 
//

#include "L23_SerialULCD.hpp" 

extern Serial pc;

namespace Lab2 
{

	void L23_SerialULCD()
	{ 
		uLCD_4DGL uLCD(p27,p28,p30);

		DigitalOut myled(LED1);
		
		LSM9DS1 imu(p9, p10, 0xD6, 0x3C);


		imu.begin();

		if (!imu.begin()) {
			pc.printf("Failed to communicate with LSM9DS1.\n");
		}
		
		imu.calibrate();

		while(1) {
			imu.readTemp();
			imu.readMag();
			imu.readGyro();

			uLCD.text_string("Harrison", '\x0F', '\x00', FONT_7X8, GREEN);

			pc.printf("gyro: %d %d %d\n\r", imu.gx, imu.gy, imu.gz);
			pc.printf("accel: %d %d %d\n\r", imu.ax, imu.ay, imu.az);
			pc.printf("mag: %d %d %d\n\n\r", imu.mx, imu.my, imu.mz);
			wait(1);
		}

		
	} 

} // end namespace Lab2 
