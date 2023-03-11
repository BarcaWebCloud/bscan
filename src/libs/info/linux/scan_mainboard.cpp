#include "platform.h"
#ifdef BSCAN_UNIX
#include <fstream>
#include "hwares/scan_mainboard.h"

namespace bscan {

  std::string MainBoard::getVendor() {
    std::string manufacturer;
    for (const auto& path : _candidates) {
      std::string full_path = path + "id/board_vendor";
      std::ifstream f(full_path);
      if (f) {
        getline(f, manufacturer);
        if (!manufacturer.empty()) {
          return manufacturer;
        }
      }
    }
    return "<unknown>";
  }

  std::string MainBoard::getName() {
    std::string name;
    for (const auto& path : _candidates) {
      std::string full_path = path + "id/board_name";
      std::ifstream f(full_path);
      if (f) {
        getline(f, name);
        if (!name.empty()) {
          return name;
        }
      }
    }
    return "<unknown>";
  }

  std::string MainBoard::getVersion() {
    std::string version;
    for (const auto& path : _candidates) {
      std::string full_path = path + "id/board_version";
      std::ifstream f(full_path);
      if (f) {
        getline(f, version);
        if (!version.empty()) {
          return version;
        }
      }
    }
    return "<unknown>";
  }

  std::string MainBoard::getSerialNumber() {
    std::string serialNumber;
    for (const auto& path : _candidates) {
      std::string full_path = path + "id/board_serial";
      std::ifstream f(full_path);
      if (f) {
        getline(f, serialNumber);
        if (serialNumber.empty()) {
          return serialNumber;
        }
      }
    }
    return "<unknown>";
  }

  std::vector<std::string> MainBoard::_candidates = {"/sys/devices/virtual/dmi/", "/sys/class/dmi/"};

};

#endif  // END BSCAN_UNIX