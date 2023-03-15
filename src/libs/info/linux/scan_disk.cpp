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
#include <filesystem>
#include <fstream>
#include "hwares/scan_disk.h"
#include "utils/stringutils.h"

namespace bscan {

  std::vector<Disk> getAllDisks() {
    std::vector<Disk> disks;
    const std::string base_path("/sys/class/block/");
    std::string vendor;
    std::string model;
    std::string serialNumber;
    for (const auto& entry : std::filesystem::directory_iterator(base_path)) {
      std::string path = entry.path().string() + "/device/";
      if (!std::filesystem::exists(std::filesystem::path(path))) {
        continue;
      }
      std::ifstream f(path + "vendor");
      if (f) {
        getline(f, vendor);
      } else {
        vendor = "<unknown>";
      }
      f.close();
      f.open(path + "model");
      if (f) {
        getline(f, model);
      } else {
        vendor = "<unknown>";
      }
      f.close();
      f.open(path + "serial");
      if (f) {
        getline(f, serialNumber);
      } else {
        serialNumber = "<unknown>";
      }
      f.close();
      strip(vendor);
      strip(model);
      strip(serialNumber);
      int64_t size = -1;
      /*
      struct statvfs buf {};
      std::string mount_path("/dev/");
      mount_path.append(split_get_index(entry.path().string(), "/", -1));
      if (statvfs(mount_path.c_str(), &buf)) {
        size = static_cast<int64_t>(buf.f_bsize * buf.f_bfree);
      }
      */
      disks.emplace_back(vendor, model, serialNumber, size);
    }
    return disks;
  }

};

#endif  // END BSCAN_UNIX