// uart_hal.h — UART hardware abstraction layer.
// Helios SoC HAL — C++ interface header
#pragma once

/**
 * @file uart_hal.h
 * @brief UART hardware abstraction layer.
 */

#include <cstddef>
#include <cstdint>

#include "common/hal_types.h"

namespace helios::hal {

/**
 * @brief Thin driver over the UART SFR block providing blocking and asynchronous transfers.
 */
class UartHal {
 public:
    /**
     * @brief Initialize the UART controller and apply the given configuration.
     * @param config Initial configuration: baud rate, framing, FIFO thresholds.
     * @return HalStatus::Ok on success, HalStatus::InvalidArg on bad configuration.
     */
    HalStatus Init(const UartConfig& config);

    /**
     * @brief Disable the controller and release the instance.
     * @return HalStatus::Ok on success.
     */
    HalStatus Deinit();

    /**
     * @brief Reconfigure the controller at runtime.
     * @param config New configuration to apply.
     * @return HalStatus::Ok on success, HalStatus::Busy while a transfer is active.
     * @note The controller must be idle when reconfiguring.
     */
    HalStatus SetConfig(const UartConfig& config);

    /**
     * @brief Send a buffer over the UART (blocking).
     * @param data Pointer to the transmit buffer.
     * @param len Number of bytes to send.
     * @param timeout_ms Timeout in milliseconds.
     * @return Number of bytes sent, or a negative HalStatus on error.
     * @note Blocks until completion or timeout.
     */
    int32_t Send(const uint8_t* data, size_t len, uint32_t timeout_ms);

    /**
     * @brief Receive bytes from the UART (blocking).
     * @param data Pointer to the receive buffer.
     * @param len Maximum number of bytes to receive.
     * @param timeout_ms Timeout in milliseconds.
     * @return Number of bytes received, or a negative HalStatus on error.
     */
    int32_t Receive(uint8_t* data, size_t len, uint32_t timeout_ms);

    /**
     * @brief Start a non-blocking transmit.
     * @param data Pointer to the transmit buffer.
     * @param len Number of bytes to send.
     * @param cb Completion callback invoked from interrupt context.
     * @return HalStatus::Ok if the transfer was queued.
     * @warning The buffer must stay valid until the callback fires.
     */
    HalStatus SendAsync(const uint8_t* data, size_t len, UartCallback cb);

    /**
     * @brief Abort any in-flight transfer and flush FIFOs.
     * @return HalStatus::Ok on success.
     */
    HalStatus Abort();

    /**
     * @brief Read the live controller status.
     * @param timeout_ms Operation timeout in milliseconds.
     * @return Snapshot of the STAT register.
     */
    UartStatus GetStatus(uint32_t timeout_ms) const;

    /**
     * @brief Update the baud-rate divider.
     * @param baud Baud rate in bits per second.
     * @return HalStatus::Ok on success, HalStatus::InvalidArg if unachievable.
     */
    HalStatus SetBaudRate(uint32_t baud);

    /**
     * @brief Enable or disable internal loopback for self-test.
     * @param enable True to enable internal loopback.
     * @return HalStatus::Ok on success.
     */
    HalStatus EnableLoopback(bool enable);

    /**
     * @brief Configure hardware flow control.
     * @param flow RTS/CTS configuration.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetFlowControl(const UartFlowConfig& flow);

    /**
     * @brief Discard all pending data in the RX FIFO.
     * @return HalStatus::Ok on success.
     */
    HalStatus FlushRxFifo();

};

}  // namespace helios::hal
