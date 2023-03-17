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
#include <regex>
#include <string>
#include <vector>

#if defined(unix) || defined(__unix) || defined(__unix__)
#include "utils/subprocess.h"
#elif defined(__APPLE__)
#elif defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#include "WMIwrapper.h"
#pragma comment(lib, "wbemuuid.lib")
#endif

#include "hwares/scan_gpu.h"

namespace bscan {

  GPU::GPU(const std::string& vendor, const std::string& name, const std::string& driverVersion, int64_t memory_Bytes)
      : _vendor(vendor), _name(name), _driverVersion(driverVersion) {
    _memory_Bytes = memory_Bytes;
  }

  std::string& GPU::vendor() {
    if (_vendor.empty()) {
      _vendor = getVendor();
    }
    return _vendor;
  }

  std::string& GPU::name() {
    if (_name.empty()) {
      _name = getName();
    }
    return _name;
  }

  std::string& GPU::driverVersion() {
    if (_driverVersion.empty()) {
      _driverVersion = getDriverVersion();
    }
    return _driverVersion;
  }

  int64_t GPU::memory_Bytes() {
    if (_memory_Bytes == -1) {
      _memory_Bytes = getMemory_Bytes();
    }
    return _memory_Bytes;
  }

};