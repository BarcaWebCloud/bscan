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
#include "platform.h"
#ifdef BSCAN_WINDOWS
#include <string>
#include <vector>
#include "WMIwrapper.h"
#pragma comment(lib, "wbemuuid.lib")
#include "apheres/scan_temperature.h"

namespace bscan {

  std::string Temperature::getDescription() {
    std::vector<const wchar_t*> description{};
    wmi::queryWMI("WIN32_TemperatureProbe", "Description", description);
    auto ret = description[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string Temperature::getName() {
    std::vector<const wchar_t*> name{};
    wmi::queryWMI("WIN32_TemperatureProbe", "Name", name);
    auto ret = name[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string Temperature::getPNPDeviceID() {
    std::vector<const wchar_t*> pnpdeviceID{};
    wmi::queryWMI("WIN32_TemperatureProbe", "PNPDeviceID", pnpdeviceID);
    auto ret = pnpdeviceID[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string Temperature::getDeviceID() {
    std::vector<const wchar_t*> deviceID{};
    wmi::queryWMI("WIN32_TemperatureProbe", "DeviceID", deviceID);
    auto ret = deviceID[0];
    if (!ret) {
      return "<unknown>";
    } 
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string Temperature::getStatus() {
    std::vector<const wchar_t*> status{};
    wmi::queryWMI("WIN32_TemperatureProbe", "Status", status);
    auto ret = status[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string Temperature::getErrorDescription() {
    std::vector<const wchar_t*> errorDescription{};
    wmi::queryWMI("WIN32_TemperatureProbe", "ErrorDescription", errorDescription);
    auto ret = errorDescription[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  int64_t Temperature::getTolerance() {
    std::vector<unsigned long long> tolerance{};
    wmi::queryWMI("WIN32_TemperatureProbe", "Tolerance", tolerance);
    return static_cast<int64_t>(tolerance[0] * 2);
  }

  int64_t Temperature::getCurrentReading() {
    std::vector<unsigned long long> currentReading{};
    wmi::queryWMI("WIN32_TemperatureProbe", "CurrentReading", currentReading);
    return static_cast<int64_t>(currentReading[0] * 2);
  }

  int64_t Temperature::getStatusInfo() {
    std::vector<unsigned long long> statusInfo{};
    wmi::queryWMI("WIN32_TemperatureProbe", "StatusInfo", statusInfo);
    return static_cast<int64_t>(statusInfo[0] * 2);
  }

  int64_t Temperature::getLastErrorCode() {
    std::vector<unsigned long long> lastErrorCode{};
    wmi::queryWMI("WIN32_TemperatureProbe", "LastErrorCode", lastErrorCode);
    return static_cast<int64_t>(lastErrorCode[0] * 2);
  }

  int64_t Temperature::getLowerThresholdCritical() {
    std::vector<unsigned long long> lowerThresholdCritical{};
    wmi::queryWMI("WIN32_TemperatureProbe", "LowerThresholdCritical", lowerThresholdCritical);
    return static_cast<int64_t>(lowerThresholdCritical[0] * 2);
  }

  int64_t Temperature::getLowerThresholdFatal() {
    std::vector<unsigned long long> lowerThresholdFatal{};
    wmi::queryWMI("WIN32_TemperatureProbe", "LowerThresholdFatal", lowerThresholdFatal);
    return static_cast<int64_t>(lowerThresholdFatal[0] * 2);
  }

  int64_t Temperature::getLowerThresholdNonCritical() {
    std::vector<unsigned long long> lowerThresholdNonCritical{};
    wmi::queryWMI("WIN32_TemperatureProbe", "LowerThresholdNonCritical", lowerThresholdNonCritical);
    return static_cast<int64_t>(lowerThresholdNonCritical[0] * 2);
  }

  int64_t Temperature::getMaxReadable() {
    std::vector<unsigned long long> maxReadable{};
    wmi::queryWMI("WIN32_TemperatureProbe", "MaxReadable", maxReadable);
    return static_cast<int64_t>(maxReadable[0] * 2);
  }

  int64_t Temperature::getMinReadable() {
    std::vector<unsigned long long> minReadable{};
    wmi::queryWMI("WIN32_TemperatureProbe", "MinReadable", minReadable);
    return static_cast<int64_t>(minReadable[0] * 2);
  }

  int64_t Temperature::getNominalReading() {
    std::vector<unsigned long long> nominalReading{};
    wmi::queryWMI("WIN32_TemperatureProbe", "NominalReading", nominalReading);
    return static_cast<int64_t>(nominalReading[0] * 2);
  }

  int64_t Temperature::getNormalMax() {
    std::vector<unsigned long long> normalMax{};
    wmi::queryWMI("WIN32_TemperatureProbe", "NormalMax", normalMax);
    return static_cast<int64_t>(normalMax[0] * 2);
  }

  int64_t Temperature::getNormalMin() {
    std::vector<unsigned long long> normalMin{};
    wmi::queryWMI("WIN32_TemperatureProbe", "NormalMin", normalMin);
    return static_cast<int64_t>(normalMin[0] * 2);
  }

  int64_t Temperature::getAvailability() {
    std::vector<unsigned long long> availability{};
    wmi::queryWMI("WIN32_TemperatureProbe", "Availability", availability);
    return static_cast<int64_t>(availability[0] * 2);
  }

  int64_t Temperature::getAccuracy() {
    std::vector<unsigned long long> accuracy{};
    wmi::queryWMI("WIN32_TemperatureProbe", "Accuracy", accuracy);
    return static_cast<int64_t>(accuracy[0] * 2);
  }

};

#endif  // END BSCAN_WINDOWS