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
#include <iostream>
#include "platform.h"

#ifdef BSCAN_WINDOWS

#include "WMIwrapper.h"
#include "hwares/scan_battery.h"

namespace bscan {

  std::string Battery::getVendor() const { return "<unknwon>"; }
  std::string Battery::getModel() const { return _model; }
  std::string Battery::getSerialNumber() const { return "<unknwon>"; }
  std::string Battery::getTechnology() const { return "<unknwon>"; }
  uint32_t Battery::getEnergyFull() const { return 0; }
  uint32_t Battery::energyNow() const { return 0; }
  bool Battery::charging() const { return false; }
  bool Battery::discharging() const { return false; }
  std::vector<Battery> getAllBatteries() {
    std::vector<Battery> batteries;
    std::vector<const wchar_t*> res{};
    wmi::queryWMI("Win32_Battery", "Name", res);
    if (res.empty() || res.at(0) == nullptr) {
      return {};
    }
    std::cout << res.size() << std::endl;
    int8_t counter = 0;
    for (const auto& v : res) {
      std::wstring tmp(v);
      batteries.emplace_back(counter++);
      batteries.back()._model = {tmp.begin(), tmp.end()};
    }
    res.clear();
    return batteries;
  }

};

#endif