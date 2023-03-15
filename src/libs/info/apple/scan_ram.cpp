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
#ifdef BSCAN_APPLE
#include <sys/sysctl.h>
#include <string>
#include <vector>
#include "hwares/scan_ram.h"

namespace bscan {

  std::string RAM::getVendor() {
    // TODO: implement
    return "<unknown>";
  }

  std::string RAM::getName() {
    // TODO: implement
    return "<unknown>";
  }

  std::string RAM::getModel() {
    // TODO: implement
    return "<unknown>";
  }

  std::string RAM::getSerialNumber() {
    // TODO: implement
    return "<unknown>";
  }

  int64_t RAM::getTotalSize_Bytes() {
    int64_t memsize = 0;
    size_t size = sizeof(memsize);
    if (sysctlbyname("hw.memsize", &memsize, &size, nullptr, 0) == 0) {
      return memsize;
    }
    return -1;
  }

  int64_t RAM::getAvailableMemory() { return -1; }

};

#endif  // END BSCAN_APPLE