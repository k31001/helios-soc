// gpio_hal.h — GPIO hardware abstraction layer.
// Helios SoC HAL — C++ interface header
#pragma once

/**
 * @file gpio_hal.h
 * @brief GPIO hardware abstraction layer.
 */

#include <cstddef>
#include <cstdint>

#include "common/hal_types.h"

namespace helios::hal {

/**
 * @brief Pin-level GPIO driver for one 32-pin bank.
 */
class GpioHal {
 public:
    /**
     * @brief Initialize the GPIO bank to reset defaults.
     * @return HalStatus::Ok on success.
     */
    HalStatus Init();

    /**
     * @brief Configure a pin's direction.
     * @param pin Pin index 0-31.
     * @param dir Input or output.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetDirection(uint8_t pin, GpioDir dir);

    /**
     * @brief Drive an output pin.
     * @param pin Pin index 0-31.
     * @param level Output level.
     * @return HalStatus::Ok on success.
     */
    HalStatus Write(uint8_t pin, bool level);

    /**
     * @brief Sample an input pin.
     * @param pin Pin index 0-31.
     * @return Current pin level.
     */
    bool Read(uint8_t pin) const;

    /**
     * @brief Toggle an output pin.
     * @param pin Pin index 0-31.
     * @return HalStatus::Ok on success.
     */
    HalStatus Toggle(uint8_t pin);

    /**
     * @brief Configure the pin pull resistor.
     * @param pin Pin index 0-31.
     * @param pull None, up or down.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetPull(uint8_t pin, GpioPull pull);

    /**
     * @brief Enable an interrupt on the pin.
     * @deprecated Use WritePort() instead.
     * @param pin Pin index 0-31.
     * @param type Edge/level and polarity.
     * @return HalStatus::Ok on success.
     */
    HalStatus EnableInterrupt(uint8_t pin, GpioIntType type);

    /**
     * @brief Disable the pin interrupt.
     * @param pin Pin index 0-31.
     * @return HalStatus::Ok on success.
     */
    HalStatus DisableInterrupt(uint8_t pin);

    /**
     * @brief Configure input debouncing for the pin.
     * @param pin Pin index 0-31.
     * @param cycles Filter length in slow-clock cycles.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetDebounce(uint8_t pin, uint16_t cycles);

    /**
     * @brief Write multiple pins atomically.
     * @param mask Pins to affect.
     * @param value Levels for masked pins.
     * @return HalStatus::Ok on success.
     */
    HalStatus WritePort(uint32_t mask, uint32_t value);

};

}  // namespace helios::hal
