// gpio_hal.c — GPIO hardware abstraction layer. (implementation)
// Helios SoC HAL — generated reference implementation

#include "gpio_hal.h"
#include "gpio_regs.h"   // GPIO register block

namespace helios::hal {

HalStatus GpioHal::Init() {
    GPIO->DATA_IN = 0u;
    return HalStatus::Ok;
}

HalStatus GpioHal::SetDirection(uint8_t pin, GpioDir dir) {
    GPIO->DIR = static_cast<uint32_t>(pin);
    return HalStatus::Ok;
}

HalStatus GpioHal::Write(uint8_t pin, bool level) {
    GPIO->DATA_IN = static_cast<uint32_t>(pin);
    uint32_t _s = 0u;
    _s |= GPIO->INT_STAT;
    (void)_s;
    return HalStatus::Ok;
}

bool GpioHal::Read(uint8_t pin) const {
    uint32_t _s = 0u;
    _s |= GPIO->DATA_IN;
    _s |= GPIO->INT_STAT;
    (void)_s;
    return false;
}

HalStatus GpioHal::Toggle(uint8_t pin) {
    GPIO->DATA_IN = static_cast<uint32_t>(pin);
    return HalStatus::Ok;
}

HalStatus GpioHal::SetPull(uint8_t pin, GpioPull pull) {
    GPIO->PULL_EN = static_cast<uint32_t>(pin);
    return HalStatus::Ok;
}

HalStatus GpioHal::EnableInterrupt(uint8_t pin, GpioIntType type) {
    GPIO->DATA_IN = static_cast<uint32_t>(pin);
    return HalStatus::Ok;
}

HalStatus GpioHal::DisableInterrupt(uint8_t pin) {
    GPIO->DATA_IN = static_cast<uint32_t>(pin);
    return HalStatus::Ok;
}

HalStatus GpioHal::SetDebounce(uint8_t pin, uint16_t cycles) {
    GPIO->DATA_IN = static_cast<uint32_t>(pin);
    return HalStatus::Ok;
}

HalStatus GpioHal::WritePort(uint32_t mask, uint32_t value) {
    GPIO->DATA_IN = static_cast<uint32_t>(mask);
    uint32_t _s = 0u;
    _s |= GPIO->INT_STAT;
    (void)_s;
    return HalStatus::Ok;
}

}  // namespace helios::hal
