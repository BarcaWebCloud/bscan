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
#include "swares/scan_bios.h"

namespace bscan {

  std::string BIOS::getDescription() {
    std::vector<const wchar_t*> description{};
    wmi::queryWMI("CIM_Chassis", "Description", description);
    auto ret = description[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string BIOS::getName() {
    std::vector<const wchar_t*> name{};
    wmi::queryWMI("CIM_Chassis", "Name", name);
    auto ret = name[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string BIOS::getStatus() {
    std::vector<const wchar_t*> status{};
    wmi::queryWMI("CIM_Chassis", "Status", status);
    auto ret = status[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string BIOS::getManufacturer() {
    std::vector<const wchar_t*> manufacturer{};
    wmi::queryWMI("CIM_Chassis", "Manufacturer", manufacturer);
    auto ret = manufacturer[0];
    if (!ret) {
      return "<unknown>";
    } 
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string BIOS::getOtherIdentifyingInfo() {
    std::vector<const wchar_t*> otherIdentifyingInfo{};
    wmi::queryWMI("CIM_Chassis", "OtherIdentifyingInfo", otherIdentifyingInfo);
    auto ret = otherIdentifyingInfo[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string BIOS::getPartNumber() {
    std::vector<const wchar_t*> partNumber{};
    wmi::queryWMI("CIM_Chassis", "PartNumber", partNumber);
    auto ret = partNumber[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string BIOS::getSerialNumber() {
    std::vector<const wchar_t*> serialNumber{};
    wmi::queryWMI("CIM_Chassis", "SerialNumber", serialNumber);
    auto ret = serialNumber[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string BIOS::getSku() {
    std::vector<const wchar_t*> sku{};
    wmi::queryWMI("CIM_Chassis", "SKU", sku);
    auto ret = sku[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string BIOS::getBreachDescription() {
    std::vector<const wchar_t*> breachDescription{};
    wmi::queryWMI("CIM_Chassis", "BreachDescription", breachDescription);
    auto ret = breachDescription[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }
  
  std::string BIOS::getVersion() {
    std::vector<const wchar_t*> version{};
    wmi::queryWMI("CIM_Chassis", "Version", version);
    auto ret = version[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  bool BIOS::getPoweredOn() {
    std::vector<bool> poweredOn{};
    wmi::queryWMI("CIM_Chassis", "PoweredOn", poweredOn);
    return static_cast<bool>(poweredOn[0] * 2);
  };

  bool BIOS::getHotSwappable() {
    std::vector<bool> hotSwappable{};
    wmi::queryWMI("CIM_Chassis", "HotSwappable", hotSwappable);
    return static_cast<bool>(hotSwappable[0] * 2);
  };
  
  bool BIOS::getRemovable() {
    std::vector<bool> removable{};
    wmi::queryWMI("CIM_Chassis", "Removable", removable);
    return static_cast<bool>(removable[0] * 2);
  };

  bool BIOS::getReplaceable() {
    std::vector<bool> replaceable{};
    wmi::queryWMI("CIM_Chassis", "Replaceable", replaceable);
    return static_cast<bool>(replaceable[0] * 2);
  };

  bool BIOS::getAudibleAlarm() {
    std::vector<bool> audibleAlarm{};
    wmi::queryWMI("CIM_Chassis", "AudibleAlarm", audibleAlarm);
    return static_cast<bool>(audibleAlarm[0] * 2);
  };

  bool BIOS::getLockPresent() {
    std::vector<bool> lockPresent{};
    wmi::queryWMI("CIM_Chassis", "LockPresent", lockPresent);
    return static_cast<bool>(lockPresent[0] * 2);
  };

  bool BIOS::getVisibleAlarm() {
    std::vector<bool> visibleAlarm{};
    wmi::queryWMI("CIM_Chassis", "VisibleAlarm", visibleAlarm);
    return static_cast<bool>(visibleAlarm[0] * 2);
  };

  int64_t BIOS::getSecurityBreach() {
    std::vector<unsigned long long> securityBreach{};
    wmi::queryWMI("CIM_Chassis", "SecurityBreach", securityBreach);
    return static_cast<int64_t>(securityBreach[0] * 2);
  }

  int64_t BIOS::getHeatGeneration() {
    std::vector<unsigned long long> heatGeneration{};
    wmi::queryWMI("CIM_Chassis", "HeatGeneration", heatGeneration);
    return static_cast<int64_t>(heatGeneration[0] * 2);
  }

  int64_t BIOS::getNumberOfPowerCords() {
    std::vector<unsigned long long> numberOfPowerCords{};
    wmi::queryWMI("CIM_Chassis", "NumberOfPowerCords", numberOfPowerCords);
    return static_cast<int64_t>(numberOfPowerCords[0] * 2);
  }

};

#endif  // END BSCAN_WINDOWS