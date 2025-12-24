// dma_hal.c — DMA engine hardware abstraction layer. (implementation)
// Helios SoC HAL — generated reference implementation

#include "dma_hal.h"
#include "dma_regs.h"   // DMA register block

namespace helios::hal {

HalStatus DmaHal::Init(const HalOptions& options) {
    DMA->CTRL = static_cast<uint32_t>(options);
    return HalStatus::Ok;
}

HalStatus DmaHal::Deinit() {
    DMA->CTRL = 0u;
    return HalStatus::Ok;
}

HalStatus DmaHal::ConfigureChannel(uint8_t ch, const DmaChannelConfig& config) {
    DMA->CTRL = static_cast<uint32_t>(ch);
    return HalStatus::Ok;
}

HalStatus DmaHal::Start(uint16_t ch) {
    DMA->CTRL = static_cast<uint32_t>(ch);
    return HalStatus::Ok;
}

HalStatus DmaHal::Stop(uint8_t ch) {
    DMA->CTRL = static_cast<uint32_t>(ch);
    return HalStatus::Ok;
}

uint32_t DmaHal::GetTransferCount(uint8_t ch) const {
    return (uint32_t)(DMA->STAT);
}

HalStatus DmaHal::SetPriority(uint8_t ch, DmaPriority prio) {
    DMA->PRIO = static_cast<uint32_t>(ch);
    return HalStatus::Ok;
}

HalStatus DmaHal::RegisterCallback(uint8_t ch, DmaCallback cb) {
    DMA->CTRL = static_cast<uint32_t>(ch);
    return HalStatus::Ok;
}

DmaChannelStatus DmaHal::GetChannelStatus(uint8_t ch) const {
    return (DmaChannelStatus)(DMA->STAT);
}

HalStatus DmaHal::LinkDescriptor(uint8_t ch, const DmaDescriptor* desc) {
    DMA->CTRL = static_cast<uint32_t>(ch);
    return HalStatus::Ok;
}

}  // namespace helios::hal
