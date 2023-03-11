#include "../../../include/platform.h"
#ifdef BSCAN_WINDOWS
#include <Windows.h>
#include <string>
#include <vector>
#include "../../../include/WMIwrapper.h"
#include "../../../include/hwares/scan_ram.h"
#include "../../../include/utils/stringutils.h"

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

int64_t RAM::getTotalSize_Bytes() {
  MEMORYSTATUSEX status;
  status.dwLength = sizeof(status);
  GlobalMemoryStatusEx(&status);
  return static_cast<int64_t>(status.ullTotalPhys);
}

int64_t RAM::getAvailableMemory() {
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