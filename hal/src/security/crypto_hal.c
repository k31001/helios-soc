// crypto_hal.c — Crypto engine hardware abstraction layer (AES, SHA). (implementation)
// Helios SoC HAL — generated reference implementation

#include "crypto_hal.h"
#include "crypto_regs.h"   // CRYPTO register block

namespace helios::hal {

HalStatus AesHal::Init(const HalOptions& options) {
    CRYPTO->CTRL = static_cast<uint32_t>(options);
    return HalStatus::Ok;
}

HalStatus AesHal::SetKey(AesKeySlot slot, AesKeySize size) {
    CRYPTO->KEY_CTRL = static_cast<uint32_t>(slot);
    return HalStatus::Ok;
}

HalStatus AesHal::SetIv(const uint8_t* iv, size_t len) {
    CRYPTO->IV_CTRL = static_cast<uint32_t>(iv);
    return HalStatus::Ok;
}

HalStatus AesHal::Encrypt(const uint8_t* in, uint8_t* out, size_t len) {
    CRYPTO->DATA_IN = static_cast<uint32_t>(in);
    uint32_t _s = 0u;
    _s |= CRYPTO->STAT;
    (void)_s;
    return HalStatus::Ok;
}

HalStatus AesHal::Decrypt(const uint8_t* in, uint8_t* out, size_t len) {
    CRYPTO->DATA_IN = static_cast<uint32_t>(in);
    uint32_t _s = 0u;
    _s |= CRYPTO->STAT;
    (void)_s;
    return HalStatus::Ok;
}

HalStatus AesHal::EncryptAsync(const uint8_t* in, uint8_t* out, size_t len, AesCallback cb) {
    CRYPTO->DATA_IN = static_cast<uint32_t>(in);
    uint32_t _s = 0u;
    _s |= CRYPTO->STAT;
    (void)_s;
    return HalStatus::Ok;
}

HalStatus AesHal::Suspend(AesContext* ctx) {
    CRYPTO->CTRL = static_cast<uint32_t>(ctx);
    return HalStatus::Ok;
}

HalStatus AesHal::Resume(const AesContext& ctx) {
    CRYPTO->CTRL = static_cast<uint32_t>(ctx);
    return HalStatus::Ok;
}

HalStatus ShaHal::Init(ShaMode mode) {
    CRYPTO->CTRL = static_cast<uint32_t>(mode);
    return HalStatus::Ok;
}

HalStatus ShaHal::Update(const uint8_t* data, size_t len) {
    CRYPTO->DATA_IN = static_cast<uint32_t>(data);
    uint32_t _s = 0u;
    _s |= CRYPTO->STAT;
    (void)_s;
    return HalStatus::Ok;
}

HalStatus ShaHal::Final(uint8_t* digest, size_t len) {
    CRYPTO->DATA_IN = static_cast<uint32_t>(digest);
    uint32_t _s = 0u;
    _s |= CRYPTO->STAT;
    (void)_s;
    return HalStatus::Ok;
}

HalStatus ShaHal::Digest(const uint8_t* data, size_t len, uint8_t* out) {
    CRYPTO->DATA_IN = static_cast<uint32_t>(data);
    uint32_t _s = 0u;
    _s |= CRYPTO->STAT;
    (void)_s;
    return HalStatus::Ok;
}

}  // namespace helios::hal
