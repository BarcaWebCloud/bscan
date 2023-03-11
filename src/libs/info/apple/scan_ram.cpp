#include "../../../include/platform.h"
#ifdef BSCAN_APPLE
#include <sys/sysctl.h>
#include <string>
#include <vector>
#include "../../../include/hwares/scan_ram.h"

namespace bscan {

  std::string RAM::getVendor() {
    // TODO: implement
    return "<unknown>";
  }

  std::string RAM::getName() {
    // TODO: implement
    return "<unknown>";
  }

  std::string RAM::getModel() {
    // TODO: implement
    return "<unknown>";
  }

  std::string RAM::getSerialNumber() {
    // TODO: implement
    return "<unknown>";
  }

  int64_t RAM::getTotalSize_Bytes() {
    int64_t memsize = 0;
    size_t size = sizeof(memsize);
    if (sysctlbyname("hw.memsize", &memsize, &size, nullptr, 0) == 0) {
      return memsize;
    }
    return -1;
  }

  int64_t RAM::getAvailableMemory() { return -1; }

};

#endif  // END BSCAN_APPLE