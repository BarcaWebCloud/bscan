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
#ifdef BSCAN_APPLE
#include <sys/sysctl.h>
#include <sstream>
#include <string>
#include "hwares/scan_os.h"

namespace bscan {

  std::string OS::getFullName() {
    std::string os_name;
    os_name.resize(1024);
    size_t size = sizeof(os_name);
    if (sysctlbyname("kern.os", os_name.data(), &size, nullptr, 0) == 0) {
      return os_name;
    }
    return "macOS <unknown version>";
  };

  std::string OS::getName() {
    std::string os_name;
    os_name.resize(1024);
    size_t size = sizeof(os_name);
    if (sysctlbyname("kern.os", os_name.data(), &size, nullptr, 0) == 0) {
      return os_name;
    }
    return "macOS";
  };

  std::string OS::getVersion() {
    std::string os_name;
    os_name.resize(1024);
    size_t size = sizeof(os_name);
    if (sysctlbyname("kern.osrelease", os_name.data(), &size, nullptr, 0) == 0) {
      return os_name;
    }
    return "<unknown version>";
  };

  std::string OS::getKernel() {
    // TODO: implement
    return "<unknown>";
  };

  bool OS::getIs64bit() { return true; };

};

#endif  // END BSCAN_APPLE