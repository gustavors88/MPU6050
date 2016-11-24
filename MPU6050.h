/*
   MPU6050.h : class header for MPU6050 library for Teensy 3.X and Teensy LC

   This file is part of MPU6050.

   MPU6050 is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   Hackflight is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with Hackflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <i2c_t3.h>
#include <stdint.h>

class MPU6050 {

    public:

        MPU6050(uint8_t address=0x68, uint8_t bus=0, i2c_pins pins=I2C_PINS_18_19, i2c_pullup=I2C_PULLUP_EXT);

        int   begin(void);

        bool  getMotion6Counts(int16_t * ax, int16_t * ay, int16_t * az, int16_t * gx, int16_t * gy, int16_t * gz);

    private:

        uint8_t    _address;
        uint8_t    _bus;
        i2c_pins   _pins;
        i2c_pullup _pullups;

        static void    readAccelData(int16_t * ax, int16_t * ay, int16_t *az);
        static void    readGyroData(int16_t * gx, int16_t * gy, int16_t *gz);
        static void    writeByte(uint8_t address, uint8_t subAddress, uint8_t data);
        static uint8_t readByte(uint8_t address, uint8_t subAddress);
        static void    readBytes(uint8_t address, uint8_t subAddress, uint8_t count, uint8_t * dest);
};
