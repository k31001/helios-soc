// dma_hal.h — DMA engine hardware abstraction layer.
// Helios SoC HAL — C++ interface header
#pragma once

/**
 * @file dma_hal.h
 * @brief DMA engine hardware abstraction layer.
 */

#include <cstddef>
#include <cstdint>

#include "common/hal_types.h"

namespace helios::hal {

/**
 * @brief Channel-based DMA driver with per-channel callbacks.
 */
class DmaHal {
 public:
    /**
     * @brief Initialize the DMA engine and reset all channels.
     * @return HalStatus::Ok on success.
     */
    HalStatus Init();

    /**
     * @brief Halt the engine and release all channels.
     * @return HalStatus::Ok on success.
     */
    HalStatus Deinit();

    /**
     * @brief Program a channel with a transfer descriptor.
     * @param ch Channel index.
     * @param config Source, destination, length and shape.
     * @return HalStatus::Ok on success, HalStatus::Busy if the channel is active.
     */
    HalStatus ConfigureChannel(uint8_t ch, const DmaChannelConfig& config);

    /**
     * @brief Arm and start a configured channel.
     * @param ch Channel index.
     * @return HalStatus::Ok on success.
     */
    HalStatus Start(uint8_t ch);

    /**
     * @brief Stop a channel at the next beat boundary.
     * @param ch Channel index.
     * @return HalStatus::Ok on success.
     */
    HalStatus Stop(uint8_t ch);

    /**
     * @brief Read the number of bytes already transferred.
     * @param ch Channel index.
     * @return Bytes transferred so far.
     */
    uint32_t GetTransferCount(uint8_t ch) const;

    /**
     * @brief Change a channel's arbitration priority.
     * @param ch Channel index.
     * @param prio Arbitration priority.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetPriority(uint8_t ch, DmaPriority prio);

    /**
     * @brief Register a per-channel completion callback.
     * @param ch Channel index.
     * @param cb Invoked on done/error from interrupt context.
     * @return HalStatus::Ok on success.
     */
    HalStatus RegisterCallback(uint8_t ch, DmaCallback cb);

    /**
     * @brief Read live channel status.
     * @param ch Channel index.
     * @return Snapshot of the CH_STAT register.
     */
    DmaChannelStatus GetChannelStatus(uint8_t ch) const;

};

}  // namespace helios::hal
