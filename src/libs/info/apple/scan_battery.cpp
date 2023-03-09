#include "platform.h"
#ifdef BSCAN_APPLE
#include "hwares/scan_battery.h"

namespace bscan {

	std::string Battery::getVendor() const { return "<unknwon>"; }
	std::string Battery::getModel() const { return "<unknwon>"; }
	std::string Battery::getSerialNumber() const { return "<unknwon>"; }
	std::string Battery::getTechnology() const { return "<unknwon>"; }
	uint32_t Battery::getEnergyFull() const { return 0; }
	uint32_t Battery::energyNow() const { return 0; }
	bool Battery::charging() const { return false; }
	bool Battery::discharging() const { return false; }

	std::vector<Battery> getAllBatteries() {
	  return {};
	}

}

#endif // END BSCAN APPLE