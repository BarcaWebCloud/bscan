#include "hwares/scan_mainboard.h"
#include <fstream>
#include <utility>
#include "WMIwrapper.h"

namespace bscan {

  MainBoard::MainBoard(std::string vendor, std::string product, std::string version, std::string serialNumber)
      : _vendor(std::move(vendor)),
        _name(std::move(product)),
        _version(std::move(version)),
        _serialNumber(std::move(serialNumber)) {}

  std::string& MainBoard::vendor() {
    if (_vendor.empty()) {
      _vendor = getVendor();
    }
    return _vendor;
  }

  std::string& MainBoard::name() {
    if (_name.empty()) {
      _name = getName();
    }
    return _name;
  }

  std::string& MainBoard::version() {
    if (_version.empty()) {
      _version = getVersion();
    }
    return _version;
  }

  std::string& MainBoard::serialNumber() {
    if (_serialNumber.empty()) {
      _serialNumber = getSerialNumber();
    }
    return _serialNumber;
  }

};