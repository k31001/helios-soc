// hal_types.h — shared HAL types
// Helios SoC HAL — C++ interface header
#pragma once

#include <cstddef>
#include <cstdint>

namespace helios::hal {

enum class HalStatus : int32_t {
  Ok = 0,
  InvalidArg = -1,
  Busy = -2,
  Timeout = -3,
  Nack = -4,
  Locked = -5,
  Health = -6,
  Unsupported = -7,
};

// Forward declarations of configuration/status aggregates. Full definitions
// live in the platform configuration headers.
struct UartConfig;
struct UartFlowConfig;
struct UartStats;
struct UartStatus;
struct I2cConfig;
struct I2cStatus;
struct SpiConfig;
struct SpiDelayConfig;
struct SpiStatus;
struct DmaChannelConfig;
struct DmaChannelStatus;
struct DmaDescriptor;
struct TimerConfig;
struct PwmConfig;
struct WdtConfig;
struct AesContext;
struct OtpEccStatus;
struct PmuSeqConfig;
struct PllConfig;
struct SscConfig;

using UartCallback = void (*)(HalStatus, size_t);
using SpiCallback = void (*)(HalStatus, size_t);
using DmaCallback = void (*)(HalStatus, uint8_t);
using AesCallback = void (*)(HalStatus);

}  // namespace helios::hal
