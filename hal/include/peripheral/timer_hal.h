// timer_hal.h — Timer and PWM hardware abstraction layer.
// Helios SoC HAL — C++ interface header
#pragma once

/**
 * @file timer_hal.h
 * @brief Timer and PWM hardware abstraction layer.
 */

#include <cstddef>
#include <cstdint>

#include "common/hal_types.h"

namespace helios::hal {

/**
 * @brief General-purpose timer driver with match channels and a PWM output stage.
 */
class TimerHal {
 public:
    /**
     * @brief Initialize the timer.
     * @param config Clocking and mode configuration.
     * @return HalStatus::Ok on success.
     */
    HalStatus Init(const TimerConfig& config);

    /**
     * @brief Start the counter.
     * @return HalStatus::Ok on success.
     */
    HalStatus Start();

    /**
     * @brief Stop the counter, preserving the current value.
     * @return HalStatus::Ok on success.
     */
    HalStatus Stop();

    /**
     * @brief Set the auto-reload period.
     * @param ticks Period in timer ticks.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetPeriod(uint32_t ticks);

    /**
     * @brief Read the live counter value.
     * @return Current count.
     */
    uint32_t GetValue() const;

    /**
     * @brief Enable an interrupt source.
     * @param src Overflow or match channel.
     * @param flags Reserved option flags, pass 0.
     * @return HalStatus::Ok on success.
     */
    HalStatus EnableInterrupt(TimerIntSource src, uint32_t flags = 0);

    /**
     * @brief Program a match channel.
     * @param idx Match channel 0 or 1.
     * @param value Compare value.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetMatch(uint8_t idx, uint32_t value);

    /**
     * @brief Configure the PWM output stage.
     * @deprecated Use SetDeadtime() instead.
     * @param config Polarity, alignment and deadtime.
     * @return HalStatus::Ok on success.
     */
    HalStatus ConfigurePwm(const PwmConfig& config);

    /**
     * @brief Update the PWM duty cycle.
     * @param duty High time in timer ticks.
     * @return HalStatus::Ok on success.
     * @note Takes effect at the next period boundary.
     */
    HalStatus SetPwmDuty(uint16_t duty);

    /**
     * @brief Tune complementary output deadtime.
     * @param rise Rising-edge deadtime.
     * @param fall Falling-edge deadtime.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetDeadtime(uint8_t rise, uint8_t fall);

};

}  // namespace helios::hal
