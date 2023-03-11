#include "../../../include/hwares/scan_battery.h"

namespace bscan {

  Battery::Battery(int8_t id) { _id = id; }

  std::string& Battery::vendor() {
    if (_vendor.empty()) {
      _vendor = getVendor();
    }
    return _vendor;
  }

  std::string& Battery::model() {
    if (_model.empty()) {
      _model = getModel();
    }
    return _model;
  }

  std::string& Battery::serialNumber() {
    if (_serialNumber.empty()) {
      _serialNumber = getSerialNumber();
    }
    return _serialNumber;
  }

  std::string& Battery::technology() {
    if (_technology.empty()) {
      _technology = getTechnology();
    }
    return _technology;
  }

  uint32_t Battery::energyFull() {
    if (_energyFull == 0) {
      _energyFull = getEnergyFull();
    }
    return _energyFull;
  }

  double Battery::capacity() { return static_cast<double>(energyNow()) / energyFull(); }

};