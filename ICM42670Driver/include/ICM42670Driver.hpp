#pragma once

#include "fwd.hpp"
#include <cstdint>
#include "i2c.hpp"

namespace icm {

struct IcmConfiguration {};

class ICM42670Driver {
    public:
   // static constexpr std::uint8_t IcmAddress = 0x68;

    ICM42670Driver(i2c_instance_t &i2cDriver, std::uint8_t address);

    bool Initialize (); // whoami

    int StartAccel(std::uint16_t odr, std::uint16_t range); 
    //User selectable Accelerometer Full-scale//range (g): ± 2/4/8/16

    int StartGyro(std::uint16_t odr, std::uint16_t range); 
    //User selectable Gyro Full-scale range (dps):± 250/500/1000/2000 

    bool ConfigAccel ();

    bool ConfigGyro ();

    // typdanych GetData();

    private:
    i2c_instance_t &_i2cDriver;
    std::uint8_t _address;
};
} 