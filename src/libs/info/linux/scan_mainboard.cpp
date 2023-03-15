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
#ifdef BSCAN_UNIX
#include <fstream>
#include "hwares/scan_mainboard.h"

namespace bscan {

  std::string MainBoard::getVendor() {
    std::string manufacturer;
    for (const auto& path : _candidates) {
      std::string full_path = path + "id/board_vendor";
      std::ifstream f(full_path);
      if (f) {
        getline(f, manufacturer);
        if (!manufacturer.empty()) {
          return manufacturer;
        }
      }
    }
    return "<unknown>";
  }

  std::string MainBoard::getName() {
    std::string name;
    for (const auto& path : _candidates) {
      std::string full_path = path + "id/board_name";
      std::ifstream f(full_path);
      if (f) {
        getline(f, name);
        if (!name.empty()) {
          return name;
        }
      }
    }
    return "<unknown>";
  }

  std::string MainBoard::getVersion() {
    std::string version;
    for (const auto& path : _candidates) {
      std::string full_path = path + "id/board_version";
      std::ifstream f(full_path);
      if (f) {
        getline(f, version);
        if (!version.empty()) {
          return version;
        }
      }
    }
    return "<unknown>";
  }

  std::string MainBoard::getSerialNumber() {
    std::string serialNumber;
    for (const auto& path : _candidates) {
      std::string full_path = path + "id/board_serial";
      std::ifstream f(full_path);
      if (f) {
        getline(f, serialNumber);
        if (serialNumber.empty()) {
          return serialNumber;
        }
      }
    }
    return "<unknown>";
  }

  std::vector<std::string> MainBoard::_candidates = {"/sys/devices/virtual/dmi/", "/sys/class/dmi/"};

};

#endif  // END BSCAN_UNIX