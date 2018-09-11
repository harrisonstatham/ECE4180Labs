//--------------------------------------------------------------------------
// Lab2.1 I2C IMU
//
// 
// https://developer.mbed.org/components/LSM9DS1-IMU/
// https://os.mbed.com/users/4180_1/code/LSM9DS1_Library/
// https://www.sparkfun.com/products/12636
// https://developer.mbed.org/components/LSM9DS1-IMU/
// 
//

#include "L21_I2CIMU.hpp" 

extern Serial pc;

namespace Lab2 
{

	void L21_I2CIMU()
	{ 
		DigitalOut myled(LED1);
		
		LSM9DS1 imu(p9, p10, 0xD6, 0x3C);

		imu.begin();

		if (!imu.begin()) {
			pc.printf("Failed to communicate with LSM9DS1.\n");
		}
		imu.calibrate();
		while(1) {
			//imu.readTemp();
			//imu.readMag();
			imu.readGyro();
	
			pc.printf("gyro: %d %d %d\n\r", imu.gx, imu.gy, imu.gz);
			//pc.printf("accel: %d %d %d\n\r", imu.ax, imu.ay, imu.az);
			//pc.printf("mag: %d %d %d\n\n\r", imu.mx, imu.my, imu.mz);
			wait(1);
		}
	} 

} // end namespace Lab2 
