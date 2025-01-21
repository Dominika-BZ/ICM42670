#pragma once

#include "fwd.hpp"
#include <cstdint>

namespace icm {

struct IcmConfiguration {};

class ICM42670Driver {
    public:
    ICM42670Driver (); // (i2cdriver, address)

    bool Initialize (); // whoami

    bool StartAccel (std::uint16_t odr, std::uint16_t fsr);

    bool StartGyro (std::uint16_t odr, std::uint16_t fsr);

    bool ConfigAccel ();

    bool ConfigGyro ();

    // typdanych GetData();

    private:
    //_i2cDriver
    //_address
};
} // namespace icm