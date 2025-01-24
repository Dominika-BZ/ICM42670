#pragma once

#include <cstdint>
#include "fwd.hpp"

namespace i2c
{
  /**
   * @defgroup i2c driver.
   * @brief High-level driver for i2c.
   * @{
   */

  // Hardware layer of the driver - should be another file.
  typedef struct i2c_instance_t
  {
  };

  class I2C
  {
  public:
    /**
     * @brief Construct a new I2C driver.
     *
     * @param i2cInstance Hardware I2C instance.
     */
    I2C(i2c_instance_t &i2cInstance);

    /**
     * @brief Initializes the driver.
     *
     */
    void Initialize();

    /**
     * @brief Function for writing to registers.
     *
     * @param _address i2c device address.
     * @param reg Register address.
     * @param inputData Data to write.
     * @return true
     * @return false
     */
    bool Write(std::uint8_t _address, std::uint8_t reg, std::uint8_t *inputData);

    /**
     * @brief Function for reading from registers.
     *
     * @param _address i2c device address.
     * @param reg Register address.
     * @param outputData Data to read.
     * @return true
     * @return false
     */
    bool Read(std::uint8_t _address, std::uint8_t reg, std::uint8_t *outputData);

  private:
    i2c_instance_t &_i2cInstance;
  };
  /**@} */
}