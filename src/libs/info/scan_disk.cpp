#include "../../../include/hwares/scan_disk.h"
#include "../../../include/utils/stringutils.h"

namespace bscan {

	Disk::Disk(std::string& vendor, std::string& model, std::string& serialNumber, int64_t size_Bytes)
	    : _vendor(vendor), _model(model), _serialNumber(serialNumber) {
	  _size_Bytes = size_Bytes;
	}

	const std::string& Disk::vendor() const { return _vendor; }

	const std::string& Disk::model() const { return _model; }

	const std::string& Disk::serialNumber() const { return _serialNumber; }

	int64_t Disk::size_Bytes() const { return _size_Bytes; }

};
