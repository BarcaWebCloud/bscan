#include "../../../include/platform.h"
#ifdef BSCAN_UNIX
#include <unistd.h>
#include <string>
#include <vector>
#include "../../../include/hwares/scan_ram.h"

namespace bscan {

  std::string RAM::getVendor() { return "<unknown>"; }
  std::string RAM::getName() { return "<unknown>"; }
  std::string RAM::getModel() { return "<unknown>"; }
  std::string RAM::getSerialNumber() { return "<unknown>"; }

  int64_t RAM::getTotalSize_Bytes() {
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGESIZE);
    if ((pages > 0) && (page_size > 0)) {
      return pages * page_size;
    }
    return -1;
  }

  int64_t RAM::getAvailableMemory() {
    long pages = sysconf(_SC_AVPHYS_PAGES);
    long page_size = sysconf(_SC_PAGESIZE);
    if (0 <= pages && 0 <= page_size) {
      return pages * page_size;
    }
    return -1;
  }

};

#endif  // END BSCAN_UNIX