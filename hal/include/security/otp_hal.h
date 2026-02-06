// otp_hal.h — OTP fuse controller hardware abstraction layer.
// Helios SoC HAL — C++ interface header
#pragma once

/**
 * @file otp_hal.h
 * @brief OTP fuse controller hardware abstraction layer.
 */

#include <cstddef>
#include <cstdint>

#include "common/hal_types.h"

namespace helios::hal {

/**
 * @brief Fuse array access driver with region locking.
 */
class OtpHal {
 public:
    /**
     * @brief Read a fuse word (ECC corrected).
     * @param addr Fuse word address.
     * @return Fuse word value.
     */
    uint32_t Read(uint16_t addr) const;

    /**
     * @brief Program a fuse word.
     * @param addr Fuse word address.
     * @param value Bits to program (OR semantics).
     * @return HalStatus::Ok, HalStatus::Locked if the region is locked.
     * @warning Programming is irreversible.
     */
    HalStatus Write(uint16_t addr, uint32_t value);

    /**
     * @brief Lock a region until the next reset.
     * @param region Region to lock.
     * @param options Extended options block.
     * @return HalStatus::Ok on success.
     */
    HalStatus LockRegion(OtpRegion region, const HalOptions& options);

    /**
     * @brief Check whether a region is locked.
     * @param region Region to query.
     * @param flags Reserved option flags, pass 0.
     * @return True if locked.
     */
    bool GetLockStatus(OtpRegion region, uint32_t flags = 0) const;

};

}  // namespace helios::hal
