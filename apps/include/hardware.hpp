#pragma once

#include "ICM42670Driver.hpp"
#include "i2c.hpp"
#include "fwd.hpp"

namespace hw
{
    /**
     * @defgroup Hardware peripherals.
     * @brief Class for managing hardware peripherals.
     */
    class Hardware
    {
    public:
        /**
         * @brief Construct a new Hardware object.
         */
        Hardware();

        /**
         * @brief Returns instance of the I2C.
         *
         * @return Reference to the I2C.
         */
        i2c::I2C &GetI2CDriver();

        /**
         * @brief Returns instance of the ICM42670Driver.
         *
         * @return Reference to the ICM42670Driver.
         */
        icm::ICM42670Driver &GetICMdriver();

    private:
        i2c::I2C _i2cDriver;
        icm::ICM42670Driver _icm;
    };
    /**@} */
}