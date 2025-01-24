#include <iostream>
#include "ICM42670Driver.hpp"
#include "i2c.hpp"

// icm::ICM42670Driver icm;

constexpr icm::GyroConfiguration config{icm::ConfigGyroScale::GyroScale250DPS,
                                        icm::ConfigGyroRate::SensorRate50Hz};

int main()
{
  // if (icm.Initialize())
  // {
  //   icm.ConfigureGyro(config);
  // }
}
