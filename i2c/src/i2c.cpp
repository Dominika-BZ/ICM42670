#include "i2c.hpp"
#include "fwd.hpp"

namespace i2c
{
I2C::I2C(i2c_instance_t& i2cInstance) : _i2cInstance(i2cInstance) {}

bool I2C::Read(std::uint8_t address, std::uint8_t reg, std::uint8_t* outputData)
{
  if (outputData == NULL) {
    return false;
  }

  //Tutaj funkcja z warstwy sprzetowej
}
}