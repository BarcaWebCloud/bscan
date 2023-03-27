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
#ifdef BSCAN_WINDOWS
#include <Windows.h>
#include <string>
#include <vector>
#include "WMIwrapper.h"
#include "hwares/scan_ram.h"
#include "utils/stringutils.h"

#define  GBYTES  1073741824
#define  MBYTES  1048576
#define  KBYTES  1024  
#define  DKBYTES 1024.0
static const int kMaxInfoBuffer = 256;

namespace bscan {

std::string RAM::getVendor() {
  std::vector<const wchar_t*> names{};
  wmi::queryWMI("WIN32_PhysicalMemory", "Manufacturer", names);
  auto ret = names[0];
  if (!ret) {
    return "<unknown>";
  }
  return wstring_to_std_string(ret);
}

std::string RAM::getName() {
  std::vector<const wchar_t*> names{};
  wmi::queryWMI("WIN32_PhysicalMemory", "Name", names);
  auto ret = names[0];
  if (!ret) {
    return "<unknown>";
  }
  return wstring_to_std_string(ret);
}

std::string RAM::getModel() {
  std::vector<const wchar_t*> names{};
  wmi::queryWMI("WIN32_PhysicalMemory", "PartNumber", names);
  auto ret = names[0];
  if (!ret) {
    return "<unknown>";
  }
  return wstring_to_std_string(ret);
}

std::string RAM::getSerialNumber() {
  std::vector<const wchar_t*> names{};
  wmi::queryWMI("WIN32_PhysicalMemory", "SerialNumber", names);
  auto ret = names[0];
  if (!ret) {
    return "<unknown>";
  }
  std::wstring tmp(ret);
  return {tmp.begin(), tmp.end()};
}

std::string RAM::getTotal() {
  std::string memory_info_total;
  MEMORYSTATUSEX statusex;
  statusex.dwLength = sizeof(statusex);
  if (GlobalMemoryStatusEx(&statusex)) {
    unsigned long long total = 0, remain_total = 0, avl = 0, remain_avl = 0;
    double decimal_total = 0, decimal_avl = 0;
    remain_total = statusex.ullTotalPhys % GBYTES;
    total = statusex.ullTotalPhys / GBYTES;
    avl = statusex.ullAvailPhys / GBYTES;
    remain_avl = statusex.ullAvailPhys % GBYTES;
    if (remain_total > 0)
      decimal_total = (remain_total / MBYTES) / DKBYTES;
    if (remain_avl > 0)
      decimal_avl = (remain_avl / MBYTES) / DKBYTES;

    decimal_total += (double)total;
    decimal_avl += (double)avl;
    
    char  buffer[kMaxInfoBuffer];
    sprintf_s(buffer, kMaxInfoBuffer, "%.2f GB (%.2f GB available)", decimal_total, decimal_avl);
    memory_info_total.append(buffer);
  }
   return std::string(memory_info_total);
}

std::string RAM::getFree() {
  std::string memory_info_available;
  MEMORYSTATUSEX statusex;
  statusex.dwLength = sizeof(statusex);
  if (GlobalMemoryStatusEx(&statusex)) {
    unsigned long long avl = 0, remain_avl = 0;
    double decimal_total = 0, decimal_avl = 0;
    
    avl = statusex.ullAvailPhys / GBYTES;
    remain_avl = statusex.ullAvailPhys % GBYTES;
    if (remain_avl > 0)
      decimal_avl = (remain_avl / MBYTES) / DKBYTES;
      decimal_avl += (double)avl;
        
      char  buffer[kMaxInfoBuffer];
      sprintf_s(buffer, kMaxInfoBuffer, "%.2f GB", decimal_avl);
      memory_info_available.append(buffer);
  }
  return std::string(memory_info_available);
}

int64_t RAM::getTotalSize_Bytes() {
 MEMORYSTATUSEX status;
 status.dwLength = sizeof(status);
 GlobalMemoryStatusEx(&status);
 return static_cast<int64_t>(status.ullTotalPhys);
}

int64_t RAM::getAvailableMemory_Bytes() {
  // it will return L"FreePhysicalMemory" Str
  std::vector<wchar_t*> memories{};
  // Number of kilobytes of physical memory currently unused and available.
  wmi::queryWMI("CIM_OperatingSystem", "FreePhysicalMemory", memories);
  if (memories.size() > 0) {
    // keep it as totalSize_Bytes
    return std::stoll(wstring_to_std_string(memories[0])) * 1024;
  }
  return -1;
}

};

#endif  // END BSCAN_WINDOWS