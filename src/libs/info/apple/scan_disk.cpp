#include "platform.h"
#ifdef BSCAN_APPLE
#include <filesystem>
#include <fstream>
#include "hwares/scan_disk.h"
#include "utils/stringutils.h"

namespace bscan {

	std::vector<Disk> getAllDisks() {
	  // TODO: implement
	  std::vector<Disk> disks;
	  return disks;
	}

};

#endif  // END BSCAN_APPLE