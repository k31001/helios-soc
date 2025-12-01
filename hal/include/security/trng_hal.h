// trng_hal.h — True random number generator hardware abstraction layer.
// Helios SoC HAL — C++ interface header
#pragma once

/**
 * @file trng_hal.h
 * @brief True random number generator hardware abstraction layer.
 */

#include <cstddef>
#include <cstdint>

#include "common/hal_types.h"

namespace helios::hal {

/**
 * @brief Entropy source driver with health monitoring.
 */
class TrngHal {
 public:
    /**
     * @brief Start entropy collection and run startup health tests.
     * @return HalStatus::Ok on success.
     */
    HalStatus Init();

    /**
     * @brief Fill a buffer with conditioned random bytes.
     * @param out Output buffer.
     * @param len Bytes requested.
     * @param options Extended options block.
     * @return HalStatus::Ok, HalStatus::Health if a health test failed.
     */
    HalStatus GetRandom(uint8_t* out, size_t len, const HalOptions& options);

    /**
     * @brief Force an on-demand health test pass.
     * @return HalStatus::Ok if all tests pass.
     */
    HalStatus RunHealthTest();

    /**
     * @brief Read the running entropy estimate.
     * @return Estimated bits of entropy per 1024 samples.
     */
    uint32_t GetEntropyEstimate() const;

};

}  // namespace helios::hal
