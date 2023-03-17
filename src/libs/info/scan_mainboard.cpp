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
#include "hwares/scan_mainboard.h"
#include <fstream>
#include <utility>
#include "WMIwrapper.h"

namespace bscan {

  MainBoard::MainBoard(std::string vendor, std::string product, std::string version, std::string serialNumber)
      : _vendor(std::move(vendor)),
        _name(std::move(product)),
        _version(std::move(version)),
        _serialNumber(std::move(serialNumber)) {}

  std::string& MainBoard::vendor() {
    if (_vendor.empty()) {
      _vendor = getVendor();
    }
    return _vendor;
  }

  std::string& MainBoard::name() {
    if (_name.empty()) {
      _name = getName();
    }
    return _name;
  }

  std::string& MainBoard::version() {
    if (_version.empty()) {
      _version = getVersion();
    }
    return _version;
  }

  std::string& MainBoard::serialNumber() {
    if (_serialNumber.empty()) {
      _serialNumber = getSerialNumber();
    }
    return _serialNumber;
  }

};