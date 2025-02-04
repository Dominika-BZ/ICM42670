#include "hardware.hpp"

namespace hw
{
    std::uint8_t i2cAddress = 0b1101000;

    Hardware::Hardware() : _i2cDriver{_i2cDriver}, _icm{_i2cDriver, i2cAddress}
    {
    }

    i2c::I2C &Hardware::GetI2CDriver()
    {
        return _i2cDriver;
    }

    icm::ICM42670Driver &Hardware::GetICMdriver()
    {
        return _icm;
    }
}