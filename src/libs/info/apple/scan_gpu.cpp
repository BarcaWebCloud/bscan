#include "../../../include/platform.h"
#ifdef BSCAN_APPLE
#include <regex>
#include <string>
#include <vector>

#include "../../../include/hwares/scan_gpu.h"

namespace bscan {

	std::string GPU::getVendor() {
	  // TODO: implement
	  return "<unknown>";
	}

	std::string GPU::getName() {
	  // TODO: implement
	  return "<unknown>";
	}

	std::string GPU::getDriverVersion() {
	  // TODO: implement
	  return "<unknown>";
	}

	int64_t GPU::getMemory_Bytes() {
	  // TODO: implement
	  return -1;
	}

};

#endif  // END BSCAN_APPLE