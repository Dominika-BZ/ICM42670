#include <iostream>
#include "ICM42670Driver.hpp"
#include "i2c.hpp"

constexpr icm::GyroConfiguration config{icm::ConfigGyroScale::GyroScale250DPS,
                                        icm::ConfigGyroRate::SensorRate50Hz};

int main()
{
  std::cout << "Hello, from ICM42670!\n";
}
