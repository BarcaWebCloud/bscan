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
#include <winternl.h>
#include <iostream>
#include <winsock.h>
#include <stdio.h>
#include <vector>
#include <cstdio>
#include <stdlib.h>  
#include <sstream>
#include <string>
#define STATUS_SUCCESS 0x00000000

#include "swares/scan_os.h"
#include "utils/string.h"
#include <utils/subprocess.h>

namespace bscan {

  std::string OS::getFullName() {
    static NTSTATUS(__stdcall * RtlGetVersion)(OUT PRTL_OSVERSIONINFOEXW lpVersionInformation) =
        (NTSTATUS(__stdcall*)(PRTL_OSVERSIONINFOEXW))GetProcAddress(GetModuleHandle("ntdll.dll"), "RtlGetVersion");
    static void(__stdcall * GetNativeSystemInfo)(OUT LPSYSTEM_INFO lpSystemInfo) =
        (void(__stdcall*)(LPSYSTEM_INFO))GetProcAddress(GetModuleHandle("kernel32.dll"), "GetNativeSystemInfo");
    static BOOL(__stdcall * GetProductInfo)(IN DWORD dwOSMajorVersion, IN DWORD dwOSMinorVersion,
                                            IN DWORD dwSpMajorVersion, IN DWORD dwSpMinorVersion,
                                            OUT PDWORD pdwReturnedProductType) =
        (BOOL(__stdcall*)(DWORD, DWORD, DWORD, DWORD, PDWORD))GetProcAddress(GetModuleHandle("kernel32.dll"),
                                                                             "GetProductInfo");

    OSVERSIONINFOEXW osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEXW));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXW);

    if (RtlGetVersion != nullptr) {
      NTSTATUS ntRtlGetVersionStatus = RtlGetVersion(&osvi);
      if (ntRtlGetVersionStatus != STATUS_SUCCESS) {
        return "<windows>";
      }
    } else {
  #if defined(_MSC_VER)
  #pragma warning(push)
  #pragma warning(disable : 4996)  // C4996: 'function': was declared deprecated
  #endif
      BOOL bOsVersionInfoEx = GetVersionExW((OSVERSIONINFOW*)&osvi);
      if (bOsVersionInfoEx == 0) {
        return "<windows>";
      }
  #if defined(_MSC_VER)
  #pragma warning(pop)
  #endif
    }

    SYSTEM_INFO si;
    ZeroMemory(&si, sizeof(SYSTEM_INFO));

    if (GetNativeSystemInfo != nullptr) {
      GetNativeSystemInfo(&si);
    } else {
      GetSystemInfo(&si);
    }

    if ((osvi.dwPlatformId != VER_PLATFORM_WIN32_NT) || (osvi.dwMajorVersion <= 4)) {
      return "Windows <unknown version>";
    }

    std::stringstream os;
    os << "Microsoft ";
    if (osvi.dwMajorVersion >= 6) {
      if (osvi.dwMajorVersion == 10) {
        if (osvi.dwMinorVersion == 0) {
          if (osvi.wProductType == VER_NT_WORKSTATION) {
            if (osvi.dwBuildNumber >= 22000) {
              os << "Windows 11 ";
            } else {
              os << "Windows 10 ";
            }
          } else {
            if (osvi.dwBuildNumber >= 20348) {
              os << "Windows Server 2022 ";
            } else if (osvi.dwBuildNumber >= 17763) {
              os << "Windows Server 2019 ";
            } else {
              os << "Windows Server 2016 ";
            }
          }
        }
      } else if (osvi.dwMajorVersion == 6) {
        if (osvi.dwMinorVersion == 3) {
          if (osvi.wProductType == VER_NT_WORKSTATION) {
            os << "Windows 8.1 ";
          } else {
            os << "Windows Server 2012 R2 ";
          }
        } else if (osvi.dwMinorVersion == 2) {
          if (osvi.wProductType == VER_NT_WORKSTATION) {
            os << "Windows 8 ";
          } else {
            os << "Windows Server 2012 ";
          }
        } else if (osvi.dwMinorVersion == 1) {
          if (osvi.wProductType == VER_NT_WORKSTATION) {
            os << "Windows 7 ";
          } else {
            os << "Windows Server 2008 R2 ";
          }
        } else if (osvi.dwMinorVersion == 0) {
          if (osvi.wProductType == VER_NT_WORKSTATION) {
            os << "Windows Vista ";
          } else {
            os << "Windows Server 2008 ";
          }
        }
      }

      DWORD dwType;
      if ((GetProductInfo != nullptr) && GetProductInfo(osvi.dwMajorVersion, osvi.dwMinorVersion, 0, 0, &dwType)) {
        switch (dwType) {
          case PRODUCT_ULTIMATE:
            os << "Ultimate Edition";
            break;
          case PRODUCT_PROFESSIONAL:
            os << "Professional";
            break;
          case PRODUCT_HOME_PREMIUM:
            os << "Home Premium Edition";
            break;
          case PRODUCT_HOME_BASIC:
            os << "Home Basic Edition";
            break;
          case PRODUCT_ENTERPRISE:
            os << "Enterprise Edition";
            break;
          case PRODUCT_BUSINESS:
            os << "Business Edition";
            break;
          case PRODUCT_STARTER:
            os << "Starter Edition";
            break;
          case PRODUCT_CLUSTER_SERVER:
            os << "Cluster Server Edition";
            break;
          case PRODUCT_DATACENTER_SERVER:
            os << "Datacenter Edition";
            break;
          case PRODUCT_DATACENTER_SERVER_CORE:
            os << "Datacenter Edition (core installation)";
            break;
          case PRODUCT_ENTERPRISE_SERVER:
            os << "Enterprise Edition";
            break;
          case PRODUCT_ENTERPRISE_SERVER_CORE:
            os << "Enterprise Edition (core installation)";
            break;
          case PRODUCT_ENTERPRISE_SERVER_IA64:
            os << "Enterprise Edition for Itanium-based Systems";
            break;
          case PRODUCT_SMALLBUSINESS_SERVER:
            os << "Small Business Server";
            break;
          case PRODUCT_SMALLBUSINESS_SERVER_PREMIUM:
            os << "Small Business Server Premium Edition";
            break;
          case PRODUCT_STANDARD_SERVER:
            os << "Standard Edition";
            break;
          case PRODUCT_STANDARD_SERVER_CORE:
            os << "Standard Edition (core installation)";
            break;
          case PRODUCT_WEB_SERVER:
            os << "Web Server Edition";
            break;
          default:
            break;
        }
      }
    } else if ((osvi.dwMajorVersion == 5) && (osvi.dwMinorVersion == 2)) {
      if (GetSystemMetrics(SM_SERVERR2)) {
        os << "Windows Server 2003 R2, ";
      } else if (osvi.wSuiteMask & VER_SUITE_STORAGE_SERVER) {
        os << "Windows Storage Server 2003";
      } else if (osvi.wSuiteMask & VER_SUITE_WH_SERVER) {
        os << "Windows Home Server";
      } else if ((osvi.wProductType == VER_NT_WORKSTATION) &&
                 (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)) {
        os << "Windows XP Professional x64 Edition";
      } else {
        os << "Windows Server 2003, ";
      }
      if (osvi.wProductType != VER_NT_WORKSTATION) {
        if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64) {
          if (osvi.wSuiteMask & VER_SUITE_DATACENTER) {
            os << "Datacenter Edition for Itanium-based Systems";
          } else if (osvi.wSuiteMask & VER_SUITE_ENTERPRISE) {
            os << "Enterprise Edition for Itanium-based Systems";
          }
        } else if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64) {
          if (osvi.wSuiteMask & VER_SUITE_DATACENTER) {
            os << "Datacenter x64 Edition";
          } else if (osvi.wSuiteMask & VER_SUITE_ENTERPRISE) {
            os << "Enterprise x64 Edition";
          } else {
            os << "Standard x64 Edition";
          }
        } else {
          if (osvi.wSuiteMask & VER_SUITE_COMPUTE_SERVER) {
            os << "Compute Cluster Edition";
          } else if (osvi.wSuiteMask & VER_SUITE_DATACENTER) {
            os << "Datacenter Edition";
          } else if (osvi.wSuiteMask & VER_SUITE_ENTERPRISE) {
            os << "Enterprise Edition";
          } else if (osvi.wSuiteMask & VER_SUITE_BLADE) {
            os << "Web Edition";
          } else {
            os << "Standard Edition";
          }
        }
      }
    } else if ((osvi.dwMajorVersion == 5) && (osvi.dwMinorVersion == 1)) {
      os << "Windows XP ";
      if (osvi.wSuiteMask & VER_SUITE_PERSONAL) {
        os << "Home Edition";
      } else {
        os << "Professional";
      }
    } else if ((osvi.dwMajorVersion == 5) && (osvi.dwMinorVersion == 0)) {
      os << "Windows 2000 ";
      if (osvi.wProductType == VER_NT_WORKSTATION) {
        os << "Professional";
      } else {
        if (osvi.wSuiteMask & VER_SUITE_DATACENTER) {
          os << "Datacenter Server";
        } else if (osvi.wSuiteMask & VER_SUITE_ENTERPRISE) {
          os << "Advanced Server";
        } else {
          os << "Server";
        }
      }
    }
    os << " (build " << osvi.dwBuildNumber << ")";
    return os.str();
  }

  std::string OS::getName() { 
   OSVERSIONINFO osver = {sizeof(OSVERSIONINFO)};  
   GetVersionEx(&osver);  
   std::string os_name;  
   if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 0)  
       os_name = "Windows 2000";  
   else if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 1)  
      os_name = "Windows XP";  
   else if (osver.dwMajorVersion == 6 && osver.dwMinorVersion == 0)  
       os_name = "Windows 2003";  
   else if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 2)  
       os_name = "Windows vista";  
   else if (osver.dwMajorVersion == 6 && osver.dwMinorVersion == 1)  
       os_name = "Windows 7";  
   else if (osver.dwMajorVersion == 6 && osver.dwMinorVersion == 2)  
       os_name = "Windows 10";

   return std::string(os_name);
  }

  std::string OS::getVersion() { 
    OSVERSIONINFO version = {sizeof(OSVERSIONINFO)};  
    GetVersionEx(&version);
    
    return std::string(to_string(version.dwMajorVersion) + "." + to_string(version.dwMinorVersion)).c_str();
  }

  std::string OS::getHostname() {
    char *content = 0;
    std::string hostname;

    content = getenv("COMPUTERNAME");
    if (content != 0) {
      hostname = content;
      content = 0;
    }

   return std::string(lower(hostname));
  }

  std::string OS::getUser() {
    char* content = 0;
    std::string username;
 
    content = getenv("USERNAME");
    if (content != 0) {
      username = content;
      content = 0;
    }

    return std::string(lower(username));
  }

  std::string OS::getEnvVariables() {
  
   const char* env_vars[14] = {
     "HOMEDRIVE",
     "HOMEPATH",
     "APPDATA",
     "COMPUTERNAME",
     "TMP",
     "SystemRoot",
     "SystemDrive",
     "windir",
     "USERNAME",
     "USERPROFILE",
     "LOCALAPPDATA",
     "LOGONSERVER",
     "OneDrive",
     "PATH"
   };

   std::string env_res = "";
   for (int i = 0; i < 14; i++) {
    
     const char* content = getenv(env_vars[i]); 
    
     if (content != NULL){ 
       env_res+= std::string(env_vars[i]) + std::string("=") + std::string(content) + std::string("\n");
     }
     else{
       std::cout << env_vars[i] << " not found!";
     }
   }
   return std::string(env_res);
  }
  
  std::string OS::getKernel() { return "<unknown>"; }
  

  bool OS::getIs64bit() {
    BOOL bWow64Process = FALSE;
    return IsWow64Process(GetCurrentProcess(), &bWow64Process) && bWow64Process;
  };

};

#endif  // END BSCAN_WINDOWS