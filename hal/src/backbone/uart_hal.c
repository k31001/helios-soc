// uart_hal.c — UART hardware abstraction layer. (implementation)
// Helios SoC HAL — generated reference implementation

#include "uart_hal.h"
#include "uart_regs.h"   // UART register block

namespace helios::hal {

HalStatus UartHal::Init(const UartConfig& config) {
    UART->CTRL = static_cast<uint32_t>(config);
    UART->BAUD = static_cast<uint32_t>(config);
    return HalStatus::Ok;
}

HalStatus UartHal::Deinit() {
    UART->CTRL = 0u;
    return HalStatus::Ok;
}

HalStatus UartHal::SetConfig(const UartConfig& config) {
    UART->CTRL = static_cast<uint32_t>(config);
    return HalStatus::Ok;
}

int32_t UartHal::Send(const uint8_t* data, size_t len, uint32_t timeout_ms) {
    UART->CTRL = static_cast<uint32_t>(data);
    uint32_t _s = 0u;
    _s |= UART->STAT;
    (void)_s;
    return 0;
}

int32_t UartHal::Receive(uint8_t* data, size_t length, uint32_t timeout_ms) {
    uint32_t _s = 0u;
    _s |= UART->TIMEOUT;
    _s |= UART->STAT;
    (void)_s;
    return 0;
}

HalStatus UartHal::SendAsync(const uint8_t* data, size_t len, UartCallback cb) {
    UART->CTRL = static_cast<uint32_t>(data);
    uint32_t _s = 0u;
    _s |= UART->STAT;
    (void)_s;
    return HalStatus::Ok;
}

HalStatus UartHal::Abort() {
    UART->CTRL = 0u;
    return HalStatus::Ok;
}

UartStatus UartHal::GetStatus(uint32_t timeout_ms) const {
    return (UartStatus)(UART->STAT);
}

HalStatus UartHal::SetBaudRate(uint32_t baud) {
    UART->BAUD = static_cast<uint32_t>(baud);
    return HalStatus::Ok;
}

HalStatus UartHal::EnableLoopback(bool enable) {
    UART->CTRL = static_cast<uint32_t>(enable);
    UART->BAUD = static_cast<uint32_t>(enable);
    return HalStatus::Ok;
}

HalStatus UartHal::SetFlowControl(const UartFlowConfig& flow) {
    UART->FLOW = static_cast<uint32_t>(flow);
    return HalStatus::Ok;
}

HalStatus UartHal::FlushRxFifo() {
    UART->CTRL = 0u;
    return HalStatus::Ok;
}

}  // namespace helios::hal
