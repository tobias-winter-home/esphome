#pragma once
#include "vector"
#include "cstdlib"
#include "string"

namespace esphome {
namespace open3e {
namespace codec {

template<typename T> class DidCodec {
 protected:
  uint8_t length_;
  std::string id_;

 public:
  DidCodec(uint8_t length, std::string id) : length_(length), id_(id){};
  ~DidCodec();
  virtual std::vector<uint8_t> encode(T data) = 0;
  virtual T decode(std::vector<uint8_t> payload) = 0;
  uint16_t length() { return length_; }
};

class RawCodec : public DidCodec<std::vector<uint8_t>> {
 public:
  RawCodec(uint16_t length, std::string id) : DidCodec(length, id){};
  ~RawCodec();
  std::vector<uint8_t> encode(std::vector<uint8_t> data) override;
  std::vector<uint8_t> decode(std::vector<uint8_t> payload) override;
};

template<typename T> class O3EInt : public DidCodec<T> {
 protected:
  float scale_;
  uint8_t offset_;

 public:
  O3EInt(uint8_t length, std::string id, float scale, uint8_t offset)
      : DidCodec(length, id), scale_(scale), offset_(offset){};
  std::vector<uint8_t> encode(T data);
  T decode(std::vector<uint8_t> payload);
};

typedef O3EInt<int8_t> O3EInt8;
typedef O3EInt<int16_t> O3EInt16;
typedef O3EInt<int32_t> O3EInt32;
typedef O3EInt<uint8_t> O3EUInt8;
typedef O3EInt<uint16_t> O3EUInt16;
typedef O3EInt<uint32_t> O3EUInt32;

}  // namespace codec
}  // namespace open3e
}  // namespace esphome
