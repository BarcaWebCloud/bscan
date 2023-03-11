#include "../../../include/platform.h"
#ifdef BSCAN_APPLE
#include "../../../include/hwares/scan_mainboard.h"

namespace bscan {

	std::string MainBoard::getVendor() {
	  // TODO: implement
	  return "<unknown>";
	}

	std::string MainBoard::getName() {
	  // TODO: implement
	  return "<unknown>";
	}

	std::string MainBoard::getVersion() {
	  // TODO: implement
	  return "<unknown>";
	}

	std::string MainBoard::getSerialNumber() {
	  // TODO: implement
	  return "<unknown>";
	}

};

#endif  // END BSCAN_APPLE