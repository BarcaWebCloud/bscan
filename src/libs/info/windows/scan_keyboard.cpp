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

  std::string Keyboard::getDeviceID() {
    std::vector<const wchar_t*> deviceid{};
    wmi::queryWMI("WIN32_Keyboard", "DeviceID", deviceid);
    auto ret = deviceid[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string Keyboard::getPNPDeviceID() {
    std::vector<const wchar_t*> pnpdeviceid{};
    wmi::queryWMI("WIN32_Keyboard", "PNPDeviceID", pnpdeviceid);
    auto ret = pnpdeviceid[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string Keyboard::getName() {
    std::vector<const wchar_t*> name{};
    wmi::queryWMI("WIN32_Keyboard", "Name", name);
    auto ret = name[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string Keyboard::getLayout() {
    std::vector<const wchar_t*> layout{};
    wmi::queryWMI("WIN32_Keyboard", "Layout", layout);
    auto ret = layout[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  uint16_t Keyboard::getNumberFunction() {
    std::vector<unsigned long long> numberfunction{};
    wmi::queryWMI("WIN32_Keyboard", "NumberOfFunctionKeys", numberfunction);
    return static_cast<uint16_t>(numberfunction[0] * 2);
  }

};

#endif  // END BSCAN_WINDOWS