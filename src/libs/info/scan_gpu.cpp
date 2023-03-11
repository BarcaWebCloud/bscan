#include <regex>
#include <string>
#include <vector>

#if defined(unix) || defined(__unix) || defined(__unix__)
#include "../../../include/utils/subprocess.h"
#elif defined(__APPLE__)
#elif defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#include "WMIwrapper.h"
#pragma comment(lib, "wbemuuid.lib")
#endif

#include "../../../include/hwares/scan_gpu.h"

namespace bscan {

  GPU::GPU(const std::string& vendor, const std::string& name, const std::string& driverVersion, int64_t memory_Bytes)
      : _vendor(vendor), _name(name), _driverVersion(driverVersion) {
    _memory_Bytes = memory_Bytes;
  }

  std::string& GPU::vendor() {
    if (_vendor.empty()) {
      _vendor = getVendor();
    }
    return _vendor;
  }

  std::string& GPU::name() {
    if (_name.empty()) {
      _name = getName();
    }
    return _name;
  }

  std::string& GPU::driverVersion() {
    if (_driverVersion.empty()) {
      _driverVersion = getDriverVersion();
    }
    return _driverVersion;
  }

  int64_t GPU::memory_Bytes() {
    if (_memory_Bytes == -1) {
      _memory_Bytes = getMemory_Bytes();
    }
    return _memory_Bytes;
  }

};