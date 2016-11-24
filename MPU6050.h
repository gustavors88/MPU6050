#include <stdint.h>

class MPU6050 {

    public:

        MPU6050(uint8_t address=0x68, uint8_t bus=0);

        int   begin(void);

        bool  getMotion6Counts(int16_t * ax, int16_t * ay, int16_t * az, int16_t * gx, int16_t * gy, int16_t * gz);

    private:

        uint8_t _address;
        uint8_t _bus;

        static void    readAccelData(int16_t * ax, int16_t * ay, int16_t *az);
        static void    readGyroData(int16_t * gx, int16_t * gy, int16_t *gz);
        static void    writeByte(uint8_t address, uint8_t subAddress, uint8_t data);
        static uint8_t readByte(uint8_t address, uint8_t subAddress);
        static void    readBytes(uint8_t address, uint8_t subAddress, uint8_t count, uint8_t * dest);
};
