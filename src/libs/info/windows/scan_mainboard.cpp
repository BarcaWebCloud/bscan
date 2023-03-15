/************************************************************************************
      
 *      Copyright (C) 2021 - 2023, Barca Web Cloud, Inc. 
 *    Email: <opensource@barca.com>  GitHub: @BarcaWebCloud. 
 
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
#include "WMIwrapper.h"
#include "hwares/scan_mainboard.h"

namespace bscan {

  std::string MainBoard::getVendor() {
    std::vector<const wchar_t*> manufacturer{};
    wmi::queryWMI("Win32_BaseBoard", "Manufacturer", manufacturer);
    auto ret = manufacturer[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string MainBoard::getName() {
    std::vector<const wchar_t*> name{};
    wmi::queryWMI("Win32_BaseBoard", "Product", name);
    auto ret = name[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string MainBoard::getVersion() {
    std::vector<const wchar_t*> version{};
    wmi::queryWMI("Win32_BaseBoard", "Version", version);
    auto ret = version[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string MainBoard::getSerialNumber() {
    std::vector<const wchar_t*> serialNumber{};
    wmi::queryWMI("Win32_BaseBoard", "SerialNumber", serialNumber);
    auto ret = serialNumber[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

};

#endif  // END BSCAN_WINDOWS