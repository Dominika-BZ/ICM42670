#pragma once

#include <cstdint>
#include "fwd.hpp"
#include "i2c.hpp"

namespace icm
{

// datasheet 15.27
enum struct ConfigGyroScale : std::uint8_t
{
  GyroScale2kDPS = 0b00000000,
  GyroScale1kDPS = 0b00100000,
  GyroScale500DPS = 0b01000000,
  GyroScale250DPS = 0b01100000
};

// datasheet 15.28
enum struct ConfigAccelScale : std::uint8_t
{
  AccelScale16G = 0b00000000,
  AccelScale8G = 0b00100000,
  AccelScale4G = 0b01000000,
  AccelScale2G = 0b01100000
};

// datasheet
enum struct ConfigGyroRate : std::uint8_t
{
  SensorRate1p6kHz = 0b00000101,
  SensorRate800Hz = 0b00000110,
  SensorRate400Hz = 0b00000111,
  SensorRate200Hz = 0b00001000,
  SensorRate100Hz = 0b00001001,
  SensorRate50Hz = 0b00001010,
  SensorRate25Hz = 0b00001011,
  SensorRate12p5Hz = 0b00001100
};

//TODO: do uzupelnienia
enum struct ConfigAccelRate : std::uint8_t
{
  SensorRate1p6kHz = 0b00000101,
  SensorRate800Hz = 0b00000110,
  SensorRate400Hz = 0b00000111,
  SensorRate200Hz = 0b00001000,
  SensorRate100Hz = 0b00001001,
  SensorRate50Hz = 0b00001010,
  SensorRate25Hz = 0b00001011,
  SensorRate12p5Hz = 0b00001100

};

// user gyro configuration
struct GyroConfiguration
{
  ConfigGyroScale gyroScale;
  ConfigGyroRate gyroRate;
};

struct AccelConfiguration
{
  ConfigAccelScale accelScale;
  ConfigAccelRate accelRate;
};

class ICM42670Driver
{
 public:
  // static constexpr std::uint8_t IcmAddress = 0x68;

  ICM42670Driver(i2c::I2C& i2cDriver, std::uint8_t address);

  bool Initialize();

  bool ConfigureGyro(const GyroConfiguration& config);

  bool ConfigureAccel(const AccelConfiguration& config);

  int GetData();

 private:
  i2c::I2C& _i2cDriver;
  std::uint8_t _address;
};
}