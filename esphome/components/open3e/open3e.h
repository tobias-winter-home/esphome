#pragma once

#include "esphome/core/component.h"
#include "esphome/components/canbus/canbus.h"

namespace esphome {
namespace open3e {

static const char *const TAG = "open3e";

class Open3EComponent : public canbus::CanbusTrigger, public PollingComponent {
 public:
  void setup() override;
  void update() override;

  void set_canbus(canbus::Canbus *canbus) { this->canbus_ = canbus; }

 protected:
  canbus::Canbus *canbus_;
};

}  // namespace open3e
}  // namespace esphome
