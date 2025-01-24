#include "ICM42670Driver.hpp"
#include <cstdint>

namespace icm
{

  enum struct Registers : std::uint8_t
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

  ICM42670Driver::ICM42670Driver(i2c::I2C &i2cDriver, std::uint8_t address)
      : _i2cDriver(i2cDriver), _address(address) {}

  bool ICM42670Driver::Initialize()
  {
    std::uint8_t configValue = 0b00001111;

    return _i2cDriver.Write(
        _address, static_cast<std::uint8_t>(Registers::PWR_MGMT0), &configValue);
  }

  bool ICM42670Driver::ConfigureGyro(const GyroConfiguration &config)
  {
    std::uint8_t configValue = 0;
    configValue |= static_cast<std::uint8_t>(config.gyroScale);
    configValue |= static_cast<std::uint8_t>(config.gyroRate);

    auto result = _i2cDriver.Write(
        _address, static_cast<std::uint8_t>(Registers::GYRO_CONFIG0),
        &configValue);

    return result;
  }

  bool ICM42670Driver::ConfigureAccel(const AccelConfiguration &config)
  {
    std::uint8_t configValue = 0;
    configValue |= static_cast<std::uint8_t>(config.accelScale);
    configValue |= static_cast<std::uint8_t>(config.accelRate);

    auto result = _i2cDriver.Write(
        _address, static_cast<std::uint8_t>(Registers::ACCEL_CONFIG0),
        &configValue);

    return result;
  }

  imuXYZ ICM42670Driver::GetAccelData() {}

}
