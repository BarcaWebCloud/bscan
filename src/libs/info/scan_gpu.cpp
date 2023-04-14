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

#include "hwares/scan_gpu.h"

namespace bscan {

  GPU::GPU(const std::string& vendor, const std::string& name, const std::string& processor, const std::string& driverVersion, const std::string& deviceID, const std::string& status,  const std::string& modedescription, const std::string& installedDriversPath,  int64_t architecture, int64_t type, int64_t mode, int64_t availability, int64_t maxMemory, int64_t memoryBytes)
      : _vendor(vendor), 
        _name(name),
        _processor(processor),
        _deviceID(deviceID),
        _status(status),
        _modedescription(modedescription),
        _installedDriversPath(installedDriversPath),
        _driverVersion(driverVersion) {
    _architecture = architecture,
    _type = type,
    _mode = mode,
    _memoryBytes = memoryBytes,
    _maxMemory = maxMemory,
    _availability = availability;
  }

  std::string& GPU::vendor() {
    if (_vendor.empty()) {
      _vendor = getVendor();
    }
    return _vendor;
  }

  std::string& GPU::name() {
    if (_name.empty()) {
      _name = getName();
    }
    return _name;
  }

  std::string& GPU::processor() {
    if (_processor.empty()) {
      _processor = getProcessor();
    }
    return _processor;
  }

  std::string& GPU::driverVersion() {
    if (_driverVersion.empty()) {
      _driverVersion = getDriverVersion();
    }
    return _driverVersion;
  }

  std::string& GPU::deviceID() {
    if (_deviceID.empty()) {
      _deviceID = getDeviceID();
    }
    return _deviceID;
  }

  std::string& GPU::status() {
    if (_status.empty()) {
      _status = getStatus();
    }
    return _status;
  }

  std::string& GPU::modedescription() {
    if (_modedescription.empty()) {
      _modedescription = getModeDescription();
    }
    return _modedescription;
  }

  std::string& GPU::installedDriversPath() {
    if (_installedDriversPath.empty()) {
      _installedDriversPath = getInstalledDriversPath();
    }
    return _installedDriversPath;
  }

  int64_t GPU::type() {
    if (_type == -1) {
      _type = getType();
    }
    return _type;
  }

  int64_t GPU::mode() {
    if (_mode == -1) {
      _mode = getMode();
    }
    return _mode;
  }

  int64_t GPU::architecture() {
    if (_architecture == -1) {
      _architecture = getArchitecture();
    }
    return _architecture;
  }

  int64_t GPU::availability() {
    if (_availability == -1) {
      _availability = getAvailability();
    }
    return _availability;
  }

  int64_t GPU::maxMemory() {
    if (_maxMemory == -1) {
      _maxMemory = getMaxMemory();
    }
    return _maxMemory;
  }

  int64_t GPU::memoryBytes() {
    if (_memoryBytes == -1) {
      _memoryBytes = getMemoryBytes();
    }
    return _memoryBytes;
  }

};