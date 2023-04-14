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

#include "apheres/scan_temperature.h"

namespace bscan {

  Temperature::Temperature(const std::string& description, const std::string& name, const std::string& pnpdeviceID, const std::string& deviceID, const std::string& status, const std::string& errorDescription, bool isLinear, bool errorCleared, int64_t tolerance, int64_t currentReading, int64_t lowerThresholdCritical, int64_t lowerThresholdFatal, int64_t lowerThresholdNonCritical, int64_t maxReadable, int64_t minReadable, int64_t nominalReading, int64_t normalMax, int64_t normalMin,int64_t accuracy, int64_t desiredSpeed, int64_t lastErrorCode, int64_t availability, int64_t statusInfo)
      : _description(description), 
        _name(name),
        _pnpdeviceID(pnpdeviceID),
        _deviceID(deviceID),
        _status(status),
        _errorDescription(errorDescription) {
    _isLinear = isLinear,
    _errorCleared = errorCleared,
    _tolerance = tolerance,
    _currentReading = currentReading,
    _statusInfo = statusInfo,
    _lowerThresholdCritical = lowerThresholdCritical,
    _lowerThresholdFatal = lowerThresholdFatal,
    _lowerThresholdNonCritical = lowerThresholdNonCritical,
    _maxReadable = maxReadable,
    _minReadable = minReadable,
    _nominalReading = nominalReading,
    _normalMax = normalMax,
    _normalMin = normalMin,
    _lastErrorCode = lastErrorCode,
    _availability = availability,
    _accuracy = accuracy;
  }

  std::string& Temperature::description() {
    if (_description.empty()) {
      _description = getDescription();
    }
    return _description;
  }

  std::string& Temperature::name() {
    if (_name.empty()) {
      _name = getName();
    }
    return _name;
  }

  std::string& Temperature::pnpdeviceID() {
    if (_pnpdeviceID.empty()) {
      _pnpdeviceID = getPNPDeviceID();
    }
    return _pnpdeviceID;
  }

  std::string& Temperature::deviceID() {
    if (_deviceID.empty()) {
      _deviceID = getDeviceID();
    }
    return _deviceID;
  }

  std::string& Temperature::status() {
    if (_status.empty()) {
      _status = getStatus();
    }
    return _status;
  }

  std::string& Temperature::errorDescription() {
    if (_errorDescription.empty()) {
      _errorDescription = getErrorDescription();
    }
    return _errorDescription;
  }

  bool Temperature::isLinear() {
    _isLinear = getIsLinear();  
    return _isLinear;
  }

  bool Temperature::errorCleared() {
   _errorCleared = getErrorCleared();   
    return _errorCleared;
  }

  int64_t Temperature::tolerance() {
    if (_tolerance == -1) {
      _tolerance = getTolerance();
    }
    return _tolerance;
  }

  int64_t Temperature::currentReading() {
    if (_currentReading == -1) {
      _currentReading = getCurrentReading();
    }
    return _currentReading;
  }
  
  int64_t Temperature::statusInfo() {
    if (_statusInfo == -1) {
      _statusInfo = getStatusInfo();
    }
    return _statusInfo;
  }

  int64_t Temperature::lastErrorCode() {
    if (_lastErrorCode == -1) {
      _lastErrorCode = getLastErrorCode();
    }
    return _lastErrorCode;
  }

  int64_t Temperature::lowerThresholdCritical() {
    if (_lowerThresholdCritical == -1) {
      _lowerThresholdCritical = getLowerThresholdCritical();
    }
    return _lowerThresholdCritical;
  }

  int64_t Temperature::lowerThresholdFatal() {
    if (_lowerThresholdFatal == -1) {
      _lowerThresholdFatal = getLowerThresholdFatal();
    }
    return _lowerThresholdFatal;
  }

  int64_t Temperature::lowerThresholdNonCritical() {
    if (_lowerThresholdNonCritical == -1) {
      _lowerThresholdNonCritical = getLowerThresholdNonCritical();
    }
    return _lowerThresholdNonCritical;
  }

  int64_t Temperature::maxReadable() {
    if (_maxReadable == -1) {
      _maxReadable = getMaxReadable();
    }
    return _maxReadable;
  }

  int64_t Temperature::minReadable() {
    if (_minReadable == -1) {
      _minReadable = getMinReadable();
    }
    return _minReadable;
  }

  int64_t Temperature::nominalReading() {
    if (_nominalReading == -1) {
      _nominalReading = getNominalReading();
    }
    return _nominalReading;
  }

  int64_t Temperature::normalMax() {
    if (_normalMax == -1) {
      _normalMax = getNormalMax();
    }
    return _normalMax;
  }

  int64_t Temperature::normalMin() {
    if (_normalMin == -1) {
      _normalMin = getNormalMin();
    }
    return _normalMin;
  }

  int64_t Temperature::availability() {
    if (_availability == -1) {
      _availability = getAvailability();
    }
    return _availability;
  }

  int64_t Temperature::accuracy() {
    if (_accuracy == -1) {
      _accuracy = getAccuracy();
    }
    return _accuracy;
  }

};