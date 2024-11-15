#include "codecs.h"
namespace esphome {
namespace open3e {
namespace codec {

std::vector<uint8_t> RawCodec::encode(std::vector<uint8_t> data) { return data; }
std::vector<uint8_t> RawCodec::decode(std::vector<uint8_t> payload) { return payload; };

template<typename T> std::vector<uint8_t> O3EInt<T>::encode(T data) {}

template<typename T> T O3EInt<T>::decode(std::vector<uint8_t> payload) {}
}  // namespace codec
}  // namespace open3e
}  // namespace esphome
