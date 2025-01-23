#pragma once

#include <cstdint>
#include "fwd.hpp"


namespace i2c
{
//hardware layer of the driver
typedef struct i2c_instance_t
{
  /* data */
};


class I2C
{
 public:
  I2C(i2c_instance_t& i2cInstance);

  void Initialize();

  bool Write(std::uint8_t address, std::uint8_t* inputData);
  bool Read(std::uint8_t address, std::uint8_t* outputData);
  bool WriteRead(std::uint8_t address, std::uint8_t* outputData);

 private:
  i2c_instance_t& _i2cInstance;
};
}