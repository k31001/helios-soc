// wdt_hal.h — Watchdog hardware abstraction layer.
// Helios SoC HAL — C++ interface header
#pragma once

/**
 * @file wdt_hal.h
 * @brief Watchdog hardware abstraction layer.
 */

#include <cstddef>
#include <cstdint>

#include "common/hal_types.h"

namespace helios::hal {

/**
 * @brief System watchdog driver.
 */
class WdtHal {
 public:
    /**
     * @brief Initialize the watchdog (does not start it) (thread-safe).
     * @param config Timeout and reset behaviour.
     * @return HalStatus::Ok on success.
     */
    HalStatus Init(const WdtConfig& config);

    /**
     * @brief Start the watchdog countdown (thread-safe).
     * @return HalStatus::Ok on success.
     * @warning Once started, the watchdog cannot be stopped until reset if the lock is engaged.
     */
    HalStatus Start();

    /**
     * @brief Service (feed) the watchdog.
     * @return HalStatus::Ok on success.
     * @note Safe to call from interrupt context.
     */
    HalStatus Kick();

    /**
     * @brief Change the timeout period.
     * @param timeout_ms Timeout in milliseconds.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetTimeout(uint64_t timeout_ms);

    /**
     * @brief Lock the configuration until the next system reset.
     * @return HalStatus::Ok on success.
     */
    HalStatus Lock();

    /**
     * @brief Read the remaining time before timeout.
     * @return Remaining milliseconds.
     */
    uint32_t GetRemaining() const;

};

}  // namespace helios::hal
