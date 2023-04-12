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
#include "hwares/scan_gpu.h"

namespace bscan {

  std::string GPU::getVendor() {
    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_VideoController", "AdapterCompatibility", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string GPU::getName() {
    std::vector<const wchar_t*> name{};
    wmi::queryWMI("WIN32_VideoController", "Name", name);
    auto ret = name[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string GPU::getProcessor() {
    std::vector<const wchar_t*> processor{};
    wmi::queryWMI("WIN32_VideoController", "VideoProcessor", processor);
    auto ret = processor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string GPU::getInstalledDriversPath() {
    std::vector<const wchar_t*> installedDriversPath{};
    wmi::queryWMI("WIN32_VideoController", "InstalledDisplayDrivers", installedDriversPath);
    auto ret = installedDriversPath[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string GPU::getDriverVersion() {
    std::vector<const wchar_t*> driverVersion{};
    wmi::queryWMI("WIN32_VideoController", "DriverVersion", driverVersion);
    auto ret = driverVersion[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string GPU::getDeviceID() {
    std::vector<const wchar_t*> deviceID{};
    wmi::queryWMI("WIN32_VideoController", "DeviceID", deviceID);
    auto ret = deviceID[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string GPU::getStatus() {
    std::vector<const wchar_t*> status{};
    wmi::queryWMI("WIN32_VideoController", "Status", status);
    auto ret = status[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  int64_t GPU::getArchitecture() {
    std::vector<unsigned long long> architecture{};
    wmi::queryWMI("WIN32_VideoController", "VideoArchitecture", architecture);
    return static_cast<int64_t>(architecture[0] * 2);
  }

  int64_t GPU::getType() {
    std::vector<unsigned long long> type{};
    wmi::queryWMI("WIN32_VideoController", "VideoMemoryType", type);
    return static_cast<int64_t>(type[0] * 2);
  }

  int64_t GPU::getMode() {
    std::vector<unsigned long long> mode{};
    wmi::queryWMI("WIN32_VideoController", "VideoMode", mode);
    return static_cast<int64_t>(mode[0] * 2);
  }

  int64_t GPU::getAvailability() {
    std::vector<unsigned long long> availability{};
    wmi::queryWMI("WIN32_VideoController", "Availability", availability);
    return static_cast<int64_t>(availability[0] * 2);
  }

  int64_t GPU::getMaxMemory() {
    std::vector<unsigned long long> maxMemory{};
    wmi::queryWMI("WIN32_VideoController", "MaxMemorySupported", maxMemory);
    return static_cast<int64_t>(maxMemory[0] * 2);
  }

  int64_t GPU::getMemoryBytes() {
    std::vector<unsigned long long> memoryBytes{};
    wmi::queryWMI("WIN32_VideoController", "AdapterRam", memoryBytes);
    return static_cast<int64_t>(memoryBytes[0] * 2);
  }

};

#endif  // END BSCAN_WINDOWS