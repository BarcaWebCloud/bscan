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
#include "hwares/scan_fan.h"

namespace bscan {

  std::string FAN::getDescription() {
    std::vector<const wchar_t*> description{};
    wmi::queryWMI("WIN32_Fan", "Description", description);
    auto ret = description[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string FAN::getName() {
    std::vector<const wchar_t*> name{};
    wmi::queryWMI("WIN32_Fan", "Name", name);
    auto ret = name[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string FAN::getPNPDeviceID() {
    std::vector<const wchar_t*> pnpdeviceID{};
    wmi::queryWMI("WIN32_Fan", "PNPDeviceID", pnpdeviceID);
    auto ret = pnpdeviceID[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string FAN::getDeviceID() {
    std::vector<const wchar_t*> deviceID{};
    wmi::queryWMI("WIN32_Fan", "DeviceID", deviceID);
    auto ret = deviceID[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string FAN::getStatus() {
    std::vector<const wchar_t*> status{};
    wmi::queryWMI("WIN32_Fan", "Status", status);
    auto ret = status[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string FAN::getErrorDescription() {
    std::vector<const wchar_t*> errorDescription{};
    wmi::queryWMI("WIN32_Fan", "ErrorDescription", errorDescription);
    auto ret = errorDescription[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  int64_t FAN::getDesiredSpeed() {
    std::vector<unsigned long long> desiredSpeed{};
    wmi::queryWMI("WIN32_Fan", "DesiredSpeed", desiredSpeed);
    return static_cast<int64_t>(desiredSpeed[0] * 2);
  }

  int64_t FAN::getLastErrorCode() {
    std::vector<unsigned long long> lastErrorCode{};
    wmi::queryWMI("WIN32_Fan", "LastErrorCode", lastErrorCode);
    return static_cast<int64_t>(lastErrorCode[0] * 2);
  }

  int64_t FAN::getAvailability() {
    std::vector<unsigned long long> availability{};
    wmi::queryWMI("WIN32_Fan", "Availability", availability);
    return static_cast<int64_t>(availability[0] * 2);
  }

  int64_t FAN::getStatusInfo() {
    std::vector<unsigned long long> statusInfo{};
    wmi::queryWMI("WIN32_Fan", "StatusInfo", statusInfo);
    return static_cast<int64_t>(statusInfo[0] * 2);
  }

};

#endif  // END BSCAN_WINDOWS