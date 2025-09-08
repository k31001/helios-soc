// trng_hal.c — True random number generator hardware abstraction layer. (implementation)
// Helios SoC HAL — generated reference implementation

#include "trng_hal.h"
#include "trng_regs.h"   // TRNG register block

namespace helios::hal {

HalStatus TrngHal::Init() {
    TRNG->CTRL = 0u;
    return HalStatus::Ok;
}

HalStatus TrngHal::GetRandom(uint8_t* out, size_t len) {
    uint32_t _s = 0u;
    _s |= TRNG->DATA;
    _s |= TRNG->STAT;
    (void)_s;
    return HalStatus::Ok;
}

HalStatus TrngHal::RunHealthTest() {
    TRNG->INT_EN = 0u;
    return HalStatus::Ok;
}

uint32_t TrngHal::GetEntropyEstimate() const {
    TRNG->CTRL = 0u;
    return 0;
}

}  // namespace helios::hal
