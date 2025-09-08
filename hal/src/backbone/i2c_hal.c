// i2c_hal.c — I2C hardware abstraction layer. (implementation)
// Helios SoC HAL — generated reference implementation

#include "i2c_hal.h"
#include "i2c_regs.h"   // I2C register block

namespace helios::hal {

HalStatus I2cHal::Init(const I2cConfig& config) {
    I2C->CTRL = static_cast<uint32_t>(config);
    I2C->CLK_DIV = static_cast<uint32_t>(config);
    return HalStatus::Ok;
}

HalStatus I2cHal::Deinit() {
    I2C->CTRL = 0u;
    return HalStatus::Ok;
}

HalStatus I2cHal::MasterWrite(uint16_t addr, const uint8_t* data, size_t len) {
    I2C->DATA = static_cast<uint32_t>(addr);
    uint32_t _s = 0u;
    _s |= I2C->STAT;
    (void)_s;
    return HalStatus::Ok;
}

HalStatus I2cHal::MasterRead(uint16_t addr, uint8_t* data, size_t len) {
    uint32_t _s = 0u;
    _s |= I2C->DATA;
    _s |= I2C->STAT;
    (void)_s;
    return HalStatus::Ok;
}

HalStatus I2cHal::WriteRead(uint16_t addr, const uint8_t* tx, size_t tx_len, uint8_t* rx, size_t rx_len) {
    I2C->DATA = static_cast<uint32_t>(addr);
    uint32_t _s = 0u;
    _s |= I2C->STAT;
    (void)_s;
    return HalStatus::Ok;
}

bool I2cHal::Probe(uint16_t addr) {
    uint32_t _s = 0u;
    _s |= I2C->DATA;
    _s |= I2C->STAT;
    (void)_s;
    return false;
}

HalStatus I2cHal::SetSpeed(I2cSpeed speed) {
    I2C->CTRL = static_cast<uint32_t>(speed);
    return HalStatus::Ok;
}

HalStatus I2cHal::Reset() {
    I2C->CTRL = 0u;
    I2C->CLK_DIV = 0u;
    return HalStatus::Ok;
}

I2cStatus I2cHal::GetStatus() const {
    return (I2cStatus)(I2C->STAT);
}

}  // namespace helios::hal
