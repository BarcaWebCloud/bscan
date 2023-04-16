/************************************************************************************
      
 *                 Copyright (C) 2021 - 2023, Barca, Inc. 
 
 *    Email: <opensource@barca.com>  GitHub: @BarcaWebCloud. 
 *    Project: BSCAN to scanner MotherBoards. CPU, Memory Ram, SO and more
 
 * This software is licensed as described in the file COPYING, which                    
 * you should have received as part of this distribution. The terms                     
 * are also available at https://project-barca.github.io/docs/copyright.html.           
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell             
 * copies of the Software, and permit persons to whom the Software is                   
 * furnished to do so, under the terms of the COPYING file.                             
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY            
 * KIND, either express or implied.                                                      
 *
 **************************************************************************************/
#include <regex>
#include <string>
#include <vector>

#if defined(unix) || defined(__unix) || defined(__unix__)
#include "utils/subprocess.h"
#elif defined(__APPLE__)
#elif defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#include "WMIwrapper.h"
#pragma comment(lib, "wbemuuid.lib")
#endif

#include "swares/scan_bios.h"
using namespace std;

namespace bscan {

  BIOS::BIOS(const string& description, const std::string& name, const std::string& status, const std::string& manufacturer, const std::string& otherIdentifyingInfo, const std::string& partNumber, const std::string& serialNumber, const std::string& sku, const std::string& breachDescription, const std::string& version, const std::string& smbiosVersion, const std::string& buildNumber, const std::string& currentLanguage, bool poweredOn, bool hotSwappable, bool removable, bool replaceable, bool audibleAlarm, bool lockPresent,  bool visibleAlarm, int64_t securityBreach, int64_t heatGeneration, int64_t biosMajorVersion, int64_t biosMinorVersion, int64_t numberOfPowerCords)
      : _description(_description), 
        _name(_name),
        _status(_status),
        _manufacturer(_manufacturer),
        _otherIdentifyingInfo(_otherIdentifyingInfo),
        _partNumber(_partNumber),
        _serialNumber(_serialNumber),
        _sku(_sku),
        _breachDescription(_breachDescription),
        _version(_version),
        _smbiosVersion(_smbiosVersion),
        _buildNumber(_buildNumber),
        _currentLanguage(_currentLanguage) {
    _poweredOn = poweredOn,
    _hotSwappable = hotSwappable,
    _removable = removable,
    _replaceable = replaceable,
    _audibleAlarm = audibleAlarm,
    _lockPresent = lockPresent,
    _visibleAlarm = visibleAlarm,
    _securityBreach = securityBreach,
    _biosMajorVersion = biosMajorVersion,
    _biosMinorVersion = biosMinorVersion,
    _heatGeneration = heatGeneration,
    _numberOfPowerCords = numberOfPowerCords;
  }

  std::string& BIOS::description() {
    if (_description.empty()) {
      _description = getDescription();
    }
    return _description;
  }

  std::string& BIOS::name() {
    if (_name.empty()) {
      _name = getName();
    }
    return _name;
  }

  std::string& BIOS::status() {
    if (_status.empty()) {
      _status = getStatus();
    }
    return _status;
  }

  std::string& BIOS::manufacturer() {
    if (_manufacturer.empty()) {
      _manufacturer = getManufacturer();
    }
    return _manufacturer;
  }

  std::string& BIOS::otherIdentifyingInfo() {
    if (_otherIdentifyingInfo.empty()) {
      _otherIdentifyingInfo = getOtherIdentifyingInfo();
    }
    return _otherIdentifyingInfo;
  }

  std::string& BIOS::partNumber() {
    if (_partNumber.empty()) {
      _partNumber = getPartNumber();
    }
    return _partNumber;
  }

  std::string& BIOS::serialNumber() {
    if (_serialNumber.empty()) {
      _serialNumber = getSerialNumber();
    }
    return _serialNumber;
  }

  std::string& BIOS::sku() {
    if (_sku.empty()) {
      _sku = getPartNumber();
    }
    return _sku;
  }

  std::string& BIOS::breachDescription() {
    if (_breachDescription.empty()) {
      _breachDescription = getBreachDescription();
    }
    return _breachDescription;
  }

  std::string& BIOS::version() {
    if (_version.empty()) {
      _version = getVersion();
    }
    return _version;
  }

  std::string& BIOS::smbiosVersion() {
    if (_smbiosVersion.empty()) {
      _smbiosVersion = getSMBIOSVersion();
    }
    return _smbiosVersion;
  }

  std::string& BIOS::buildNumber() {
    if (_buildNumber.empty()) {
      _buildNumber = getBuildNumber();
    }
    return _buildNumber;
  }
  
  std::string& BIOS::currentLanguage() {
    if (_currentLanguage.empty()) {
      _currentLanguage = getCurrentLanguage();
    }
    return _currentLanguage;
  }

  bool BIOS::poweredOn() {
    _poweredOn = getPoweredOn();  
    return _poweredOn;
  }

  bool BIOS::hotSwappable() {
   _hotSwappable = getHotSwappable();   
    return _hotSwappable;
  }

  bool BIOS::removable() {
   _removable = getRemovable();   
    return _removable;
  }

  bool BIOS::replaceable() {
   _replaceable = getReplaceable();   
    return _replaceable;
  }

  bool BIOS::audibleAlarm() {
   _audibleAlarm = getAudibleAlarm();   
    return _audibleAlarm;
  }

  bool BIOS::lockPresent() {
   _lockPresent = getLockPresent();   
    return _lockPresent;
  }

  bool BIOS::visibleAlarm() {
   _visibleAlarm = getVisibleAlarm();   
    return _visibleAlarm;
  }

  int64_t BIOS::biosMajorVersion() {
    if (_biosMajorVersion == -1) {
      _biosMajorVersion = getBiosMajorVersion();
    }
    return _biosMajorVersion;
  }

  int64_t BIOS::biosMinorVersion() {
    if (_biosMinorVersion == -1) {
      _biosMinorVersion = getBiosMinorVersion();
    }
    return _biosMinorVersion;
  }

  int64_t BIOS::securityBreach() {
    if (_securityBreach == -1) {
      _securityBreach = getSecurityBreach();
    }
    return _securityBreach;
  }

  int64_t BIOS::heatGeneration() {
    if (_heatGeneration == -1) {
      _heatGeneration = getHeatGeneration();
    }
    return _heatGeneration;
  }
  
  int64_t BIOS::numberOfPowerCords() {
    if (_numberOfPowerCords == -1) {
      _numberOfPowerCords = getNumberOfPowerCords();
    }
    return _numberOfPowerCords;
  }

};