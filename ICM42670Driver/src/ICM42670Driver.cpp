#include "ICM42670Driver.hpp"
#include <cstdint>

namespace icm
{

enum struct Registers : std::uint8_t  // underlyingtype?
{
  ACCEL_DATA_X1 = 0x0b,
  ACCEL_DATA_X0 = 0x0c,
  ACCEL_DATA_Y1 = 0x0d,
  ACCEL_DATA_Y0 = 0x0e,
  ACCEL_DATA_Z1 = 0x0f,
  ACCEL_DATA_Z0 = 0x10,
  GYRO_DATA_X1 = 0x11,
  GYRO_DATA_X0 = 0x12,
  GYRO_DATA_Y1 = 0x13,
  GYRO_DATA_Y0 = 0x14,
  GYRO_DATA_Z1 = 0x15,
  GYRO_DATA_Z0 = 0x16,
  GYRO_CONFIG0 = 0x20,
  ACCEL_CONFIG0 = 0x21,
  PWR_MGMT0 = 0x1f,
  INT_STATUS_DRDY = 0x39,
};

ICM42670Driver::ICM42670Driver(i2c::I2C& i2cDriver, std::uint8_t address)
    : _i2cDriver(i2cDriver), _address(address)
{}

bool ICM42670Driver::Initialize()
{
  // uproszczenie - domyslnie uzytkownik wybiera zestaw konfiguracji wedlug datasheet 15.26
  std::uint8_t configuration = 0b00001111;
  //constexpr std::array config{{Registers::PWR_MGMT0}, configuration};
  //return _i2cDriver.Write(_address, &config);
}

bool ICM42670Driver::ConfigureGyro(const GyroConfiguration& config)
{
  std::uint8_t configValue = 0;
  configValue |= static_cast<std::uint8_t>(config.gyroScale);
  configValue |= static_cast<std::uint8_t>(config.gyroRate);

  //auto result = _i2cDriver.Write(_address, &configValue);  // na przyklad

  //return result;
}

}
