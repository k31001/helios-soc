// wdt_hal.c — Watchdog hardware abstraction layer. (implementation)
// Helios SoC HAL — generated reference implementation

#include "wdt_hal.h"
#include "wdt_regs.h"   // WDT register block

namespace helios::hal {

HalStatus WdtHal::Init(const WdtConfig& config) {
    WDT->CTRL = static_cast<uint32_t>(config);
    return HalStatus::Ok;
}

HalStatus WdtHal::Start() {
    WDT->CTRL = 0u;
    return HalStatus::Ok;
}

HalStatus WdtHal::Kick() {
    WDT->KICK = 0u;
    return HalStatus::Ok;
}

HalStatus WdtHal::SetTimeout(uint32_t timeout_ms) {
    WDT->CTRL = static_cast<uint32_t>(timeout_ms);
    return HalStatus::Ok;
}

HalStatus WdtHal::Lock() {
    WDT->CTRL = 0u;
    return HalStatus::Ok;
}

uint32_t WdtHal::GetRemaining() const {
    WDT->CTRL = 0u;
    return 0;
}

}  // namespace helios::hal
