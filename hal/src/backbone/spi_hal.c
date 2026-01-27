// spi_hal.c — SPI hardware abstraction layer. (implementation)
// Helios SoC HAL — generated reference implementation

#include "spi_hal.h"
#include "spi_regs.h"   // SPI register block

namespace helios::hal {

HalStatus SpiHal::Init(const SpiConfig& config) {
    SPI->CTRL = static_cast<uint32_t>(config);
    SPI->CLK_DIV = static_cast<uint32_t>(config);
    return HalStatus::Ok;
}

HalStatus SpiHal::Deinit() {
    SPI->CTRL = 0u;
    return HalStatus::Ok;
}

HalStatus SpiHal::Transfer(const uint8_t* tx, uint8_t* rx, size_t len) {
    SPI->DATA = static_cast<uint32_t>(tx);
    uint32_t _s = 0u;
    _s |= SPI->STAT;
    (void)_s;
    return HalStatus::Ok;
}

HalStatus SpiHal::TransferAsync(const uint8_t* tx, uint8_t* rx, size_t len, SpiCallback cb) {
    SPI->DATA = static_cast<uint32_t>(tx);
    uint32_t _s = 0u;
    _s |= SPI->STAT;
    (void)_s;
    return HalStatus::Ok;
}

HalStatus SpiHal::SetMode(SpiMode mode, const HalOptions& options) {
    SPI->CTRL = static_cast<uint32_t>(mode);
    return HalStatus::Ok;
}

HalStatus SpiHal::SetClockDiv(uint32_t div) {
    SPI->CTRL = static_cast<uint32_t>(div);
    return HalStatus::Ok;
}

HalStatus SpiHal::ChipSelect(uint8_t cs, bool assert) {
    SPI->CTRL = static_cast<uint32_t>(cs);
    return HalStatus::Ok;
}

SpiStatus SpiHal::GetStatus() const {
    return (SpiStatus)(SPI->STAT);
}

}  // namespace helios::hal
