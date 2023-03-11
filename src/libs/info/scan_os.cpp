#include "swares/scan_os.h"
#include <string>

namespace bscan {

  OS::OS() {
    _32bit = getIs32bit();
    _64bit = getIs64bit();
    _bigEndian = getIsBigEndian();
    _littleEndian = !_bigEndian;
  }

  std::string OS::fullName() {
    if (_fullName.empty()) {
      _fullName = getFullName();
    }
    return _fullName;
  }

  std::string OS::name() {
    if (_name.empty()) {
      _name = getName();
    }
    return _name;
  }

  std::string OS::version() {
    if (_version.empty()) {
      _version = getVersion();
    }
    return _version;
  }

  std::string OS::kernel() {
    if (_kernel.empty()) {
      _kernel = getKernel();
    }
    return _kernel;
  }

  bool OS::is32bit() const { return _32bit; }
  bool OS::is64bit() const { return _64bit; }
  bool OS::isBigEndian() const { return _bigEndian; }
  bool OS::isLittleEndian() const { return _littleEndian; }
  bool OS::getIs32bit() { return !getIs64bit(); }
  bool OS::getIsBigEndian() {
    char16_t dummy = 0x0102;
    return ((char*)&dummy)[0] == 0x01;
  }
  bool OS::getIsLittleEndian() {
    char16_t dummy = 0x0102;
    return ((char*)&dummy)[0] == 0x02;
  }

};