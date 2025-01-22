#pragma once

#include "fwd.hpp"
#include <cstdint>


namespace i2c
{

    typedef struct
    {
        //hardware instance

    }i2c_instance_t;

    class I2C
    {
        public:

        I2C(i2c_instance_t& i2cInstance);

        void Initialize();

        int Write(std::uint8_t address, char *data, int length);
        int Read(std::uint8_t address, char *data, int length);

        private:

        i2c_instance_t &_i2cInstance;

    };
}