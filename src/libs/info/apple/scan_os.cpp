#include "platform.h"
#ifdef BSCAN_APPLE
#include <sys/sysctl.h>
#include <sstream>
#include <string>
#include "hwares/scan_os.h"

namespace bscan {

  std::string OS::getFullName() {
    std::string os_name;
    os_name.resize(1024);
    size_t size = sizeof(os_name);
    if (sysctlbyname("kern.os", os_name.data(), &size, nullptr, 0) == 0) {
      return os_name;
    }
    return "macOS <unknown version>";
  };

  std::string OS::getName() {
    std::string os_name;
    os_name.resize(1024);
    size_t size = sizeof(os_name);
    if (sysctlbyname("kern.os", os_name.data(), &size, nullptr, 0) == 0) {
      return os_name;
    }
    return "macOS";
  };

  std::string OS::getVersion() {
    std::string os_name;
    os_name.resize(1024);
    size_t size = sizeof(os_name);
    if (sysctlbyname("kern.osrelease", os_name.data(), &size, nullptr, 0) == 0) {
      return os_name;
    }
    return "<unknown version>";
  };

  std::string OS::getKernel() {
    // TODO: implement
    return "<unknown>";
  };

  bool OS::getIs64bit() { return true; };

};

#endif  // END BSCAN_APPLE