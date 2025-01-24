#pragma once

#include "fwd.hpp"
#include "i2c.hpp"
#include <cstdint>

namespace icm
{
  /**
   * @defgroup Driver for IMU ICM42670-P sensor.
   * @brief Driver for ICM42670-P.
   * @{
   */

  /**
   * @brief Full scale select for gyroscope - datasheet 15.27.
   */
  enum struct ConfigGyroScale : std::uint8_t
  {
    GyroScale2kDPS = 0b00000000,
    GyroScale1kDPS = 0b00100000,
    GyroScale500DPS = 0b01000000,
    GyroScale250DPS = 0b01100000
  };

  /**
   * @brief Gyroscope ODR selection for - datasheet 15.27.
   */
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

  /**
   * @brief Full scale select for accelerometer - datasheet 15.28.
   */
  enum struct ConfigAccelScale : std::uint8_t
  {
    AccelScale16G = 0b00000000,
    AccelScale8G = 0b00100000,
    AccelScale4G = 0b01000000,
    AccelScale2G = 0b01100000
  };

  /**
   * @brief Accelerometer ODR selection - datasheet 15.28.
   */
  enum struct ConfigAccelRate : std::uint8_t
  {
    SensorRate1p6kHz = 0b00000101,
    SensorRate800Hz = 0b00000110,
    SensorRate400Hz = 0b00000111,
    SensorRate200Hz = 0b00001000,
    SensorRate100Hz = 0b00001001,
    SensorRate50Hz = 0b00001010,
    SensorRate25Hz = 0b00001011,
    SensorRate12p5Hz = 0b00001100,
    SensorRate6p25Hz = 0b00001101,
    SensorRate3p125Hz = 0b00001110,
    SensorRate1p5625Hz = 0b00001111
  };

  /**
   * @brief User gyroscope configuration.
   */
  struct GyroConfiguration
  {
    ConfigGyroScale gyroScale;
    ConfigGyroRate gyroRate;
  };

  /**
   * @brief User accelerometer configuration.
   */
  struct AccelConfiguration
  {
    ConfigAccelScale accelScale;
    ConfigAccelRate accelRate;
  };

  /**
   * @brief Struct for sensor data.
   */
  typedef struct
  {
    std::uint8_t x;
    std::uint8_t y;
    std::uint8_t z;
  } imuXYZ;

  class ICM42670Driver
  {
  public:
    /**
     * @brief Construct a new ICM42670Driver.
     *
     * @param i2cDriver I2C driver.
     * @param address I2C device address.
     */
    ICM42670Driver(i2c::I2C &i2cDriver, std::uint8_t address);

    /**
     * @brief Simplified configuration function - datasheet 15.26
     */
    bool Initialize();

    /**
     * @brief Sets the data acquisition options of the gyroscope.
     * Read datasheet chapter 15.27 for configuration values.
     * @param config Configuration values from GyroConfiguration.
     */
    bool ConfigureGyro(const GyroConfiguration &config);

    /**
     * @brief Sets the data acquisition options of the accelerometer.
     * Read datasheet chapter 15.28 for configuration values.
     * @param config Configuration values from AccelConfiguration.
     */
    bool ConfigureAccel(const AccelConfiguration &config);

    imuXYZ GetAccelData();

  private:
    i2c::I2C &_i2cDriver;
    std::uint8_t _address;
  };
  /**@} */
}