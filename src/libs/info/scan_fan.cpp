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

#include "hwares/scan_fan.h"

namespace bscan {

  FAN::FAN(const std::string& description, const std::string& name, const std::string& pnpdeviceID, const std::string& deviceID, const std::string& status, const std::string& errorDescription, int64_t desiredSpeed, int64_t lastErrorCode, int64_t availability, int64_t statusInfo)
      : _description(description), 
        _name(name),
        _pnpdeviceID(pnpdeviceID),
        _deviceID(deviceID),
        _status(status),
        _errorDescription(errorDescription) {
    _desiredSpeed = desiredSpeed,
    _lastErrorCode = lastErrorCode,
    _availability = availability,
    _statusInfo = statusInfo;
  }

  std::string& FAN::description() {
    if (_description.empty()) {
      _description = getDescription();
    }
    return _description;
  }

  std::string& FAN::name() {
    if (_name.empty()) {
      _name = getName();
    }
    return _name;
  }

  std::string& FAN::pnpdeviceID() {
    if (_pnpdeviceID.empty()) {
      _pnpdeviceID = getPNPDeviceID();
    }
    return _pnpdeviceID;
  }

  std::string& FAN::deviceID() {
    if (_deviceID.empty()) {
      _deviceID = getDeviceID();
    }
    return _deviceID;
  }

  std::string& FAN::status() {
    if (_status.empty()) {
      _status = getStatus();
    }
    return _status;
  }

  std::string& FAN::errorDescription() {
    if (_errorDescription.empty()) {
      _errorDescription = getErrorDescription();
    }
    return _errorDescription;
  }

  int64_t FAN::desiredSpeed() {
    if (_desiredSpeed == -1) {
      _desiredSpeed = getDesiredSpeed();
    }
    return _desiredSpeed;
  }

  int64_t FAN::lastErrorCode() {
    if (_architecture == -1) {
      _architecture = getLastErrorCode();
    }
    return _architecture;
  }

  int64_t FAN::availability() {
    if (_availability == -1) {
      _availability = getAvailability();
    }
    return _availability;
  }

  int64_t FAN::statusInfo() {
    if (_statusInfo == -1) {
      _statusInfo = getStatusInfo();
    }
    return _statusInfo;
  }

};