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
#include <filesystem>
#include "WMIwrapper.h"
#include "hwares/disk.h"
#include "utils/stringutils.h"

namespace bscan {


std::vector<Disk> getAllDisks() {
  std::vector<Disk> disks;
  std::vector<const wchar_t*> res{};
  wmi::queryWMI("Win32_DiskDrive", "Manufacturer", res);
  if (res.empty()) {
    return {};
  }
  for (const auto& v : res) {
    disks.push_back(Disk());
    disks.back()._vendor = wstring_to_std_string(v);
  }
  res.clear();
  wmi::queryWMI("Win32_DiskDrive", "Model", res);
  for (int i = 0; i < res.size(); ++i) {
    if (i >= disks.size()) {
      break;
    }
    disks[i]._model = wstring_to_std_string(res[i]);
  }
  res.clear();
  wmi::queryWMI("Win32_DiskDrive", "SerialNumber", res);
  for (int i = 0; i < res.size(); ++i) {
    if (i >= disks.size()) {
      break;
    }
    std::wstring tmp(res[i]);
    disks[i]._serialNumber = wstring_to_std_string(res[i]);
  }
  std::vector<const wchar_t*> sizes;
  // it will return L"Size" Str
  wmi::queryWMI("Win32_DiskDrive", "Size", sizes);
  for (int i = 0; i < res.size(); ++i) {
    if (i >= disks.size()) {
      break;
    }
    disks[i]._size_Bytes = std::stoll(wstring_to_std_string(sizes[i]));
  }
  return disks;
}

};

#endif  // END BSCAN_WINDOWS