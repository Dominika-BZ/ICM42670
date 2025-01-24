#pragma once

#include <cstdint>
#include "fwd.hpp"

namespace i2c
{

//Hardware layer of the driver
//Should be another file
typedef struct i2c_instance_t
{
  //
};

class I2C
{
 public:
  I2C(i2c_instance_t& i2cInstance);

  void Initialize();

  bool Write(std::uint8_t _address, std::uint8_t reg, std::uint8_t* inputData);
  bool Read(std::uint8_t _address, std::uint8_t reg, std::uint8_t* outputData);

 private:
  i2c_instance_t& _i2cInstance;
};
}