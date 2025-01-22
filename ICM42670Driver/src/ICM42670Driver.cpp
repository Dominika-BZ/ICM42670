#include "ICM42670Driver.hpp"

namespace icm {
enum struct Registers // underlyingtype?
{
    // rejestry
    ACCEL_DATA_X1   = 0x0b,
    ACCEL_DATA_X0   = 0x0c,
    ACCEL_DATA_Y1   = 0x0d,
    ACCEL_DATA_Y0   = 0x0e,
    ACCEL_DATA_Z1   = 0x0f,
    ACCEL_DATA_Z0   = 0x10,
    GYRO_DATA_X1    = 0x11,
    GYRO_DATA_X0    = 0x12,
    GYRO_DATA_Y1    = 0x13,
    GYRO_DATA_Y0    = 0x14,
    GYRO_DATA_Z1    = 0x15,
    GYRO_DATA_Z0    = 0x16,
    GYRO_CONFIG0    = 0x20,
    ACCEL_CONFIG0   = 0x21,
    PWR_MGMT0       = 0x1f,
    INT_STATUS_DRDY = 0x39,

};

ICM42670Driver::ICM42670Driver(i2c_instance_t &i2cDriver, std::uint8_t address) :
    _i2cDriver{i2cDriver}, _address{address}
    {
    }

int ICM42670Driver::StartAccel(std::uint16_t odr, std::uint16_t fsr)
{

}
} // namespace icm
