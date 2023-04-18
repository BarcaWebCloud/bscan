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
#include "hwares/scan_battery.h"

namespace bscan {

  Battery::Battery(int8_t id) { _id = id; }

  std::string& Battery::vendor() {
    if (_vendor.empty()) {
      _vendor = getVendor();
    }
    return _vendor;
  }

  std::string& Battery::model() {
    if (_model.empty()) {
      _model = getModel();
    }
    return _model;
  }

  std::string& Battery::serialNumber() {
    if (_serialNumber.empty()) {
      _serialNumber = getSerialNumber();
    }
    return _serialNumber;
  }

  std::string& Battery::technology() {
    if (_technology.empty()) {
      _technology = getTechnology();
    }
    return _technology;
  }

  uint32_t Battery::energyFull() {
    if (_energyFull == 0) {
      _energyFull = getEnergyFull();
    }
    return _energyFull;
  }

  uint32_t Battery::energyNow() {
    if (_energyNow == 0) {
      _energyNow = getEnergyNow();
    }
    return _energyNow;
  }

  uint32_t Battery::voltage() {
    if (_voltage == 0) {
      _voltage = getVoltage();
    }
    return _voltage;
  }

  uint32_t Battery::estimatedTime() {
    if (_estimatedTime == 0) {
      _estimatedTime = getEstimatedTime();
    }
    return _estimatedTime;
  }

  double Battery::capacity() { return static_cast<double>(energyNow()) / energyFull(); }

};