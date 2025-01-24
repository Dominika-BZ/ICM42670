#include "i2c.hpp"
#include "fwd.hpp"

namespace i2c
{
  I2C::I2C(i2c_instance_t &i2cInstance) : _i2cInstance(i2cInstance) {}

  void I2C::Initialize()
  {
    // For example settings for i2c.
  }

  bool I2C::Write(std::uint8_t address, std::uint8_t reg, std::uint8_t *inputData)
  {
    // Hardware function
  }

  bool I2C::Read(std::uint8_t address, std::uint8_t reg, std::uint8_t *outputData)
  {
    // Hardware function
  }

}