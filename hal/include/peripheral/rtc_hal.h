// rtc_hal.h — Real-time clock hardware abstraction layer.
// Helios SoC HAL — C++ interface header
#pragma once

/**
 * @file rtc_hal.h
 * @brief Real-time clock hardware abstraction layer.
 */

#include <cstddef>
#include <cstdint>

#include "common/hal_types.h"

namespace helios::hal {

/**
 * @brief RTC driver with alarm and calibration support.
 */
class RtcHal {
 public:
    /**
     * @brief Initialize the RTC and start the counter if not running.
     * @return HalStatus::Ok on success.
     */
    HalStatus Init();

    /**
     * @brief Set the current time.
     * @param unix_sec Seconds since the Unix epoch.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetTime(uint32_t unix_sec);

    /**
     * @brief Read the current time (thread-safe).
     * @return Seconds since the Unix epoch.
     */
    uint32_t GetTime() const;

    /**
     * @brief Arm the alarm.
     * @param unix_sec Alarm time in seconds since epoch.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetAlarm(uint32_t unix_sec);

    /**
     * @brief Disarm the alarm and clear any pending flag.
     * @param timeout_ms Operation timeout in milliseconds.
     * @return HalStatus::Ok on success.
     */
    HalStatus ClearAlarm(uint32_t timeout_ms);

    /**
     * @brief Apply digital frequency calibration.
     * @param ppm Signed correction in parts-per-million.
     * @return HalStatus::Ok on success.
     */
    HalStatus Calibrate(int16_t ppm);

};

}  // namespace helios::hal
