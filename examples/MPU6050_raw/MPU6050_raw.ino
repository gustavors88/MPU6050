#include <i2c_t3.h>
#include "MPU6050.h"

MPU6050 imu;

void setup()
{
    Wire.begin(I2C_MASTER, 0x00, I2C_PINS_18_19, I2C_PULLUP_EXT, I2C_RATE_400);

    Serial.begin(38400);

    if (!imu.begin()) {
        Serial.println("MPU6050 is online...");
    }
    else {
        Serial.println("Failed to init MPU6050");
        while (true) 
            ;
    }
}

void loop()
{  
    int16_t ax, ay, az, gx, gy, gz;

    if (imu.getMotion6Counts(&ax, &ay, &az, &gx, &gy, &gz))
        Serial.printf("%+04d %+04d %+04d  %+04d %+04d %+04d\n", ax, ay, az, gx, gy, gz);
}
