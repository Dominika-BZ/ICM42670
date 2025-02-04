#include <iostream>
#include "ICM42670Driver.hpp"
#include "i2c.hpp"
#include "hardware.hpp"

hw::Hardware hardware;

constexpr icm::GyroConfiguration config{icm::ConfigGyroScale::GyroScale250DPS,
                                        icm::ConfigGyroRate::SensorRate50Hz};

int main()
{
  hardware.GetI2CDriver().Initialize();

  if (hardware.GetICMdriver().Initialize())
  {
    hardware.GetICMdriver().ConfigureGyro(config);
  }
}
