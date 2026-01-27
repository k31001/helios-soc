// spi_hal.h — SPI hardware abstraction layer.
// Helios SoC HAL — C++ interface header
#pragma once

/**
 * @file spi_hal.h
 * @brief SPI hardware abstraction layer.
 */

#include <cstddef>
#include <cstdint>

#include "common/hal_types.h"

namespace helios::hal {

/**
 * @brief Full-duplex SPI master driver.
 */
class SpiHal {
 public:
    /**
     * @brief Initialize the SPI master (thread-safe).
     * @param config Mode, clock and chip-select configuration.
     * @return HalStatus::Ok on success.
     */
    HalStatus Init(const SpiConfig& config);

    /**
     * @brief Disable the controller.
     * @return HalStatus::Ok on success.
     */
    HalStatus Deinit();

    /**
     * @brief Run a blocking full-duplex transfer.
     * @param tx Transmit buffer (may be null for read-only).
     * @param rx Receive buffer (may be null for write-only).
     * @param len Transfer length in bytes.
     * @return HalStatus::Ok on success.
     */
    HalStatus Transfer(const uint8_t* tx, uint8_t* rx, size_t len);

    /**
     * @brief Start a non-blocking full-duplex transfer.
     * @param tx Transmit buffer.
     * @param rx Receive buffer.
     * @param len Transfer length in bytes.
     * @param cb Completion callback.
     * @return HalStatus::Ok if queued.
     * @warning Buffers must remain valid until completion.
     */
    HalStatus TransferAsync(const uint8_t* tx, uint8_t* rx, size_t len, SpiCallback cb);

    /**
     * @brief Change the SPI mode.
     * @param mode CPOL/CPHA mode 0-3.
     * @param options Extended options block.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetMode(SpiMode mode, const HalOptions& options);

    /**
     * @brief Change the SCK divider.
     * @param div Even divider from the peripheral clock.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetClockDiv(uint32_t div);

    /**
     * @brief Manually drive a chip-select line.
     * @param cs Chip-select index.
     * @param assert True to assert (active).
     * @return HalStatus::Ok on success.
     * @note Only valid when CS_AUTO is disabled.
     */
    HalStatus ChipSelect(uint8_t cs, bool assert);

    /**
     * @brief Read engine status flags.
     * @return Snapshot of the STAT register.
     */
    SpiStatus GetStatus() const;

};

}  // namespace helios::hal
