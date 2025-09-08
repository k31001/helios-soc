// crypto_hal.h — Crypto engine hardware abstraction layer (AES, SHA).
// Helios SoC HAL — C++ interface header
#pragma once

/**
 * @file crypto_hal.h
 * @brief Crypto engine hardware abstraction layer (AES, SHA).
 */

#include <cstddef>
#include <cstdint>

#include "common/hal_types.h"

namespace helios::hal {

/**
 * @brief AES block cipher driver with key-ladder slots and context switching.
 */
class AesHal {
 public:
    /**
     * @brief Initialize the AES engine.
     * @return HalStatus::Ok on success.
     */
    HalStatus Init();

    /**
     * @brief Select a key from the hardware key ladder.
     * @param slot Key ladder slot.
     * @param size 128/192/256-bit.
     * @return HalStatus::Ok, HalStatus::Locked if the slot is locked.
     * @note Raw key material never crosses the bus.
     */
    HalStatus SetKey(AesKeySlot slot, AesKeySize size);

    /**
     * @brief Load the initialization vector.
     * @param iv Initialization vector.
     * @param len IV length in bytes.
     * @return HalStatus::Ok on success.
     */
    HalStatus SetIv(const uint8_t* iv, size_t len);

    /**
     * @brief Run a blocking encryption.
     * @param in Plaintext input.
     * @param out Ciphertext output.
     * @param len Length in bytes (multiple of 16).
     * @return HalStatus::Ok on success.
     */
    HalStatus Encrypt(const uint8_t* in, uint8_t* out, size_t len);

    /**
     * @brief Run a blocking decryption.
     * @param in Ciphertext input.
     * @param out Plaintext output.
     * @param len Length in bytes (multiple of 16).
     * @return HalStatus::Ok on success.
     */
    HalStatus Decrypt(const uint8_t* in, uint8_t* out, size_t len);

    /**
     * @brief Start a non-blocking encryption.
     * @param in Plaintext input.
     * @param out Ciphertext output.
     * @param len Length in bytes.
     * @param cb Completion callback.
     * @return HalStatus::Ok if queued.
     */
    HalStatus EncryptAsync(const uint8_t* in, uint8_t* out, size_t len, AesCallback cb);

    /**
     * @brief Suspend the current operation and save its context.
     * @param ctx Output context storage.
     * @return HalStatus::Ok on success.
     */
    HalStatus Suspend(AesContext* ctx);

    /**
     * @brief Resume a suspended operation.
     * @param ctx Previously saved context.
     * @return HalStatus::Ok on success.
     */
    HalStatus Resume(const AesContext& ctx);

};

/**
 * @brief SHA hash engine driver with streaming interface.
 */
class ShaHal {
 public:
    /**
     * @brief Start a new hash computation.
     * @param mode SHA-1/224/256/512.
     * @return HalStatus::Ok on success.
     */
    HalStatus Init(ShaMode mode);

    /**
     * @brief Absorb a message chunk.
     * @param data Message chunk.
     * @param len Chunk length in bytes.
     * @return HalStatus::Ok on success.
     */
    HalStatus Update(const uint8_t* data, size_t len);

    /**
     * @brief Finalize and read the digest.
     * @param digest Output digest buffer.
     * @param len Buffer size in bytes.
     * @return HalStatus::Ok on success.
     */
    HalStatus Final(uint8_t* digest, size_t len);

    /**
     * @brief One-shot convenience hash of a full buffer.
     * @param data Whole message.
     * @param len Message length.
     * @param out Output digest buffer.
     * @return HalStatus::Ok on success.
     */
    HalStatus Digest(const uint8_t* data, size_t len, uint8_t* out);

};

}  // namespace helios::hal
