// i2c_hal.h — I2C hardware abstraction layer.
// Helios SoC HAL — C++ interface header
#pragma once

/**
 * @file i2c_hal.h
 * @brief I2C hardware abstraction layer.
 */

#include <cstddef>
#include <cstdint>

#include "common/hal_types.h"

namespace helios::hal {

/**
 * @brief Master-mode oriented I2C driver with combined transactions.
 */
class I2cHal {
 public:
    /**
     * @brief Initialize the I2C controller.
     * @param config Bus speed and addressing configuration.
     * @return HalStatus::Ok on success.
     */
    HalStatus Init(const I2cConfig& config);

    /**
     * @brief Disable the controller.
     * @return HalStatus::Ok on success.
     */
    HalStatus Deinit();

    /**
     * @brief Write a buffer to a target device.
     * @param addr 7/10-bit target address.
     * @param data Bytes to write.
     * @param len Number of bytes.
     * @return HalStatus::Ok, HalStatus::Nack if the target did not acknowledge.
     */
    HalStatus MasterWrite(uint16_t addr, const uint8_t* data, size_t len);

    /**
     * @brief Read a buffer from a target device.
     * @param addr 7/10-bit target address.
     * @param data Receive buffer.
     * @param length Number of bytes.
     * @return HalStatus::Ok on success.
     */
    HalStatus MasterRead(uint16_t addr, uint8_t* data, size_t length);

    /**
     * @brief Combined write-then-read with repeated START.
     * @param addr 7/10-bit target address.
     * @param tx Bytes to write first.
     * @param tx_len Write length.
     * @param rx Receive buffer.
     * @param rx_len Read length.
     * @return HalStatus::Ok on success.
     * @note Uses a repeated START between phases; the bus is never released.
     */
    HalStatus WriteRead(uint16_t addr, const uint8_t* tx, size_t tx_len, uint8_t* rx, size_t rx_len);

    /**
     * @brief Check whether a device acknowledges the given address.
     * @param addr Address to probe.
     * @return True if the device ACKed.
     */
    bool Probe(uint16_t addr);

    /**
     * @brief Change the bus speed class.
     * @param speed Standard/Fast/Fast+/High-speed.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetSpeed(I2cSpeed speed);

    /**
     * @brief Issue a bus recovery sequence (9 clock pulses + STOP).
     * @return HalStatus::Ok on success.
     * @warning Only call when the bus is stuck; ongoing transfers are aborted.
     */
    HalStatus Reset();

    /**
     * @brief Read controller status flags.
     * @return Snapshot of the STAT register.
     */
    I2cStatus GetStatus() const;

};

}  // namespace helios::hal
