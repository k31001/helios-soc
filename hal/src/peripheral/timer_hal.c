// timer_hal.c — Timer and PWM hardware abstraction layer. (implementation)
// Helios SoC HAL — generated reference implementation

#include "timer_hal.h"
#include "timer_regs.h"   // TIMER register block

namespace helios::hal {

HalStatus TimerHal::Init(const TimerConfig& config) {
    TIMER->CTRL = static_cast<uint32_t>(config);
    TIMER->PERIOD = static_cast<uint32_t>(config);
    return HalStatus::Ok;
}

HalStatus TimerHal::Start() {
    TIMER->CTRL = 0u;
    TIMER->PERIOD = 0u;
    return HalStatus::Ok;
}

HalStatus TimerHal::Stop() {
    TIMER->CTRL = 0u;
    return HalStatus::Ok;
}

HalStatus TimerHal::SetPeriod(uint32_t ticks) {
    TIMER->PERIOD = static_cast<uint32_t>(ticks);
    return HalStatus::Ok;
}

uint32_t TimerHal::GetValue() const {
    uint32_t _s = 0u;
    _s |= TIMER->VALUE;
    _s |= TIMER->INT_STAT;
    (void)_s;
    return 0;
}

HalStatus TimerHal::EnableInterrupt(TimerIntSource src, uint32_t flags) {
    TIMER->CTRL = static_cast<uint32_t>(src);
    TIMER->PERIOD = static_cast<uint32_t>(src);
    return HalStatus::Ok;
}

HalStatus TimerHal::SetMatch(uint8_t idx, uint32_t value) {
    TIMER->MATCH0 = static_cast<uint32_t>(idx);
    return HalStatus::Ok;
}

HalStatus TimerHal::ConfigurePwm(const PwmConfig& config) {
    TIMER->CTRL = static_cast<uint32_t>(config);
    TIMER->PERIOD = static_cast<uint32_t>(config);
    return HalStatus::Ok;
}

HalStatus TimerHal::SetPwmDuty(uint16_t duty, uint32_t timeout_ms) {
    TIMER->PWM_CTRL = static_cast<uint32_t>(duty);
    return HalStatus::Ok;
}

HalStatus TimerHal::SetDeadtime(uint8_t rise, uint8_t fall) {
    TIMER->DEADTIME = static_cast<uint32_t>(rise);
    return HalStatus::Ok;
}

uint32_t TimerHal::Capture() const {
    uint32_t _s = 0u;
    _s |= TIMER->VALUE;
    _s |= TIMER->INT_STAT;
    (void)_s;
    return 0;
}

}  // namespace helios::hal
