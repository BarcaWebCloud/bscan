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
#include <unistd.h>
#include <string>
#include <vector>
#include "hwares/scan_ram.h"

namespace bscan {

  std::string RAM::getVendor() { return "<unknown>"; }
  std::string RAM::getName() { return "<unknown>"; }
  std::string RAM::getModel() { return "<unknown>"; }
  std::string RAM::getSerialNumber() { return "<unknown>"; }

  int64_t RAM::getTotalSize_Bytes() {
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGESIZE);
    if ((pages > 0) && (page_size > 0)) {
      return pages * page_size;
    }
    return -1;
  }

  int64_t RAM::getAvailableMemory() {
    long pages = sysconf(_SC_AVPHYS_PAGES);
    long page_size = sysconf(_SC_PAGESIZE);
    if (0 <= pages && 0 <= page_size) {
      return pages * page_size;
    }
    return -1;
  }

};

#endif  // END BSCAN_UNIX