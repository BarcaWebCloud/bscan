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
#include <dirent.h>
#include <sys/types.h>

#define STATUS_SUCCESS 0x00000000

#include "swares/scan_os.h"
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <sqlite3.h>
#include "WMIwrapper.h"
#pragma comment(lib, "wbemuuid.lib")
#include "swares/scan_datasource.h"
#include "config.h"
#include "utils/directory.h"
#include "utils/string.h"
#include "utils/subprocess.h"
#include "utils/rapidjson/document.h"
#include "utils/rapidjson/filereadstream.h"
#include "utils/rapidjson/filewritestream.h"
#include "utils/rapidjson/writer.h"
#include "utils/rapidjson/ostreamwrapper.h"
#include <utils/stringutils.h>

using namespace std;
using namespace rapidjson;
namespace fs = std::filesystem;

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
    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_Account", "Domain", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return lower({tmp.begin(), tmp.end()});
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

  std::string OS::listDesktop() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("USERPROFILE");
    return std::string(listDir(content));
  }

  std::string OS::listHomeDir() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("USERPROFILE");
    return std::string(listDir(content));
  }

  std::string OS::listRecentItems() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("USERPROFILE");
    return std::string(listDir(strcat(content, "\\AppData\\Roaming\\Microsoft\\Windows\\Recent")));
  }

  std::string OS::listProgramFiles() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("HOMEDRIVE");
    return std::string(listDir(strcat(content, "\\Program Files")));
  }

  std::string OS::listDocuments() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("USERPROFILE");
    return std::string(listDir(strcat(content, "\\AppData\\Roaming\\Microsoft\\Windows\\Libraries\\Documents.library-ms")));
  }

  std::string OS::listPersonalDocuments() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("USERPROFILE");
    return std::string(listDir(strcat(content, "\\Documents")));
  }

  std::string OS::listPublicDocuments() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("HOMEDRIVE");
    return std::string(listDir(strcat(content, "\\Users\\Public\\Documents")));
  }

  std::string OS::listDownloads() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("USERPROFILE");
    return std::string(listDir(strcat(content, "\\Downloads")));
  }

  std::string OS::listMusics() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("USERPROFILE");
    return std::string(listDir(strcat(content, "\\AppData\\Roaming\\Microsoft\\Windows\\Libraries\\Music.library-ms")));
  }

  std::string OS::listVideos() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("USERPROFILE");
    return std::string(listDir(strcat(content, "\\AppData\\Roaming\\Microsoft\\Windows\\Libraries\\Videos.library-ms")));
  }

  std::string OS::listSearchesEverywhere() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("USERPROFILE");
    return std::string(listDir(strcat(content, "\\Searches\\Everywhere.search-ms")));
  }

  std::string OS::listStartMenu() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("USERPROFILE");
    return std::string(listDir(strcat(content, "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs")));
  }

  std::string OS:: getImagesCAM() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("USERPROFILE");
    return std::string(listDir(strcat(content, "\\AppData\\Roaming\\Microsoft\\Windows\\Libraries\\CameraRoll.library-ms")));
  }

  std::string OS:: getImagesSaved() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("USERPROFILE");
    return std::string(listDir(strcat(content, "\\AppData\\Roaming\\Microsoft\\Windows\\Libraries\\SavedPictures.library-ms")));
  }

  std::string OS:: getImages() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("USERPROFILE");
    return std::string(listDir(strcat(content, "\\AppData\\Roaming\\Microsoft\\Windows\\Libraries\\Pictures.library-ms")));
  }

  std::string OS:: getHistoryPowerShell() {
   SetConsoleCP(1252);
   SetConsoleOutputCP(1252);
   char* path;
   std::ifstream openFile;

   const char *pathEnd = "\\AppData\\Roaming\\Microsoft\\Windows\\PowerShell\\PSReadLine";
   path = getenv("USERPROFILE");
    
   openFile.open(std::string(strcat(path, pathEnd)) + "\\ConsoleHost_history.txt");
   std::string lineInFile;
   std::string contentFile;
   if (openFile.is_open()) {
     while (openFile) {
       std::getline (openFile, lineInFile);
       contentFile += std::string("\n") + std::string(lineInFile);
     }
   }
   else {
     contentFile = "Path to PowerShell was not found. Make sure it is installed on your Windows System.";
   }
   return contentFile;
  }

  std::vector<std::string> OS::getProgramsAndResources() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char path_barca_pkgs[100]= "";
    // generator file model from apps installed in format json
    ofstream installed_default;
    installed_default.open(std::string(getenv("USERPROFILE")) + "\\AppData\\Local\\Temp\\bscanjhkyo\\default-installed.json");
    installed_default << "{\n  \"architecture\": \"\",\n  \"fullName\": \"\",\n  \"fullVersion\": \"\",\n  \"dateInstall\": \"\",\n  \"versionMajor\": \"\",\n  \"versionMinor\": \"\",\n  \"installDate\": \"\",\n  \"urlHelp\": \"\",\n  \"urlAbout\": \"\",\n  \"urlUpdate\": \"\",\n  \"urlUninstall\": \"\",\n  \"company\": \"\",\n  \"phone\": \"\",\n  \"contact\": \"\",\n  \"location\": \"\",\n  \"origin\": \"\",\n  \"size\": \"\",\n  \"readme\": \"\"\n}";
    installed_default.close();
    // sets the path to where the default json file is
    char path_d[300] = "";
    strcat(path_d, getenv("USERPROFILE"));
    strcat(path_d, "\\AppData\\Local\\Temp\\bscanjhkyo\\default-installed.json");
  
    char* content;
    std::ofstream ofs;
    content = getenv("ProgramFiles");
    
    fs::path filepath = std::string(strcat(content, "\\PostgreSQL"));

    std::ifstream ifs;
    std::string str;
    ifs.open(strcat(getenv("TEMP"), "\\binstalrkop"),std::ios::in);  // input file stream
    std::vector<std::string> result;
    if(ifs) {
      int x = 0;
      while (!ifs.eof()) {
       std::getline(ifs, str);
       if (!str.empty()) {
         result.push_back(str);
       };
       x++;
     }
     ifs.close();
    };
    // pre-writter out file json
    FILE* fout;
    char writeBuffer[65536];
    // read file default json
    FILE* fin = fopen(path_d, "rb"); // non-Windows use "r"
    char readBuffer[65536];
    FileReadStream is(fin, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);
    fclose(fin);

    for (auto y: result) {
      strcat(path_barca_pkgs, getenv("USERPROFILE"));
      strcat(path_barca_pkgs, "\\AppData\\Local\\Barca\\packages\\");
      strcat(path_barca_pkgs, PROJECT_NAME);
      strcat(path_barca_pkgs, "\\");
      strcat(path_barca_pkgs, PROJECT_VERSION);
      strcat(path_barca_pkgs, "\\storage\\cache\\");
      strcat(path_barca_pkgs, randstr(7).c_str());
      
      std::string delimiter = ",";
      std::vector<std::string> val = split(y, delimiter);

      string value_architecture = val[0].c_str();
      value_architecture.erase(remove(value_architecture.begin(), value_architecture.end(), '"'), value_architecture.end());
      // modify the json data
      Value& architecture = d["architecture"];
      architecture.SetString(value_architecture.c_str(), d.GetAllocator());
   
      string value_fullname = val[1].c_str();
      value_fullname.erase(remove(value_fullname.begin(), value_fullname.end(), '"'), value_fullname.end());
      Value& fullname = d["fullName"];
      fullname.SetString(value_fullname.c_str(), d.GetAllocator());

      string value_fullversion = val[2].c_str();
      value_fullversion.erase(remove(value_fullversion.begin(), value_fullversion.end(), '"'), value_fullversion.end());
      Value& fullversion = d["fullVersion"];
      fullversion.SetString(value_fullversion.c_str(), d.GetAllocator());

      string value_dateinstall = val[3].c_str();
      value_dateinstall.erase(remove(value_dateinstall.begin(), value_dateinstall.end(), '"'), value_dateinstall.end());
      Value& dateinstall = d["dateInstall"];
      dateinstall.SetString(value_dateinstall.c_str(), d.GetAllocator());

      string value_urlhelp = val[4].c_str();
      value_urlhelp.erase(remove(value_urlhelp.begin(), value_urlhelp.end(), '"'), value_urlhelp.end());
      Value& urlhelp = d["urlHelp"];
      urlhelp.SetString(value_urlhelp.c_str(), d.GetAllocator());

      string url_about = val[5].c_str();
      url_about.erase(remove(url_about.begin(), url_about.end(), '"'), url_about.end());
      Value& urlabout = d["urlAbout"];
      urlabout.SetString(url_about.c_str(), d.GetAllocator());

      string url_update = val[6].c_str();
      url_update.erase(remove(url_update.begin(), url_update.end(), '"'), url_update.end());
      Value& urlupdate = d["urlUpdate"];
      urlupdate.SetString(url_update.c_str(), d.GetAllocator());

      string value_company = val[7].c_str();
      value_company.erase(remove(value_company.begin(), value_company.end(), '"'), value_company.end());
      Value& company = d["company"];
      company.SetString(value_company.c_str(), d.GetAllocator());

      string value_phone = val[8].c_str();
      value_phone.erase(remove(value_phone.begin(), value_phone.end(), '"'), value_phone.end());
      Value& phone = d["phone"];
      phone.SetString(value_phone.c_str(), d.GetAllocator());
     
      string value_contact = val[9].c_str();
      value_contact.erase(remove(value_contact.begin(), value_contact.end(), '"'), value_contact.end());
      Value& contact = d["contact"];
      contact.SetString(value_contact.c_str(), d.GetAllocator());
     
      string value_location = val[10].c_str();
      value_location.erase(remove(value_location.begin(), value_location.end(), '"'), value_location.end());
      Value& location = d["location"];
      location.SetString(value_location.c_str(), d.GetAllocator());
     
      string value_origin = val[11].c_str();
      value_origin.erase(remove(value_origin.begin(), value_origin.end(), '"'), value_origin.end());
      Value& origin = d["origin"];
      origin.SetString(value_origin.c_str(), d.GetAllocator());
      
      string value_versionmajor = val[12].c_str();
      value_versionmajor.erase(remove(value_versionmajor.begin(), value_versionmajor.end(), '"'), value_versionmajor.end());
      Value& versionmajor = d["versionMajor"];
      versionmajor.SetString(value_versionmajor.c_str(), d.GetAllocator());
     
      string value_minor = val[13].c_str();
      value_minor.erase(remove(value_minor.begin(), value_minor.end(), '"'), value_minor.end());
      Value& versionminor = d["versionMinor"];
      versionminor.SetString(value_minor.c_str(), d.GetAllocator());

      string value_uninstall = val[14].c_str();
      value_uninstall.erase(remove(value_uninstall.begin(), value_uninstall.end(), '"'), value_uninstall.end());
      Value& urluninstall = d["urlUninstall"];
      urluninstall.SetString(value_uninstall.c_str(), d.GetAllocator());
     
      string value_size = val[15].c_str();
      value_size.erase(remove(value_size.begin(), value_size.end(), '"'), value_size.end());
      Value& size = d["size"];
      size.SetString(value_size.c_str(), d.GetAllocator());
     
      string value_readme = val[16].c_str();
      value_readme.erase(remove(value_readme.begin(), value_readme.end(), '"'), value_readme.end());
      Value& readme = d["readme"];
      readme.SetString(value_readme.c_str(), d.GetAllocator());
      // save list apps installed file in format json
      fout = fopen(path_barca_pkgs,"wb"); // non-Windows use "w"
      
      FileWriteStream os(fout, writeBuffer, sizeof(writeBuffer));
      Writer<FileWriteStream> writer(os);
      d.Accept(writer);
      fclose(fout);
      // clear path
      memset(path_barca_pkgs, 0, sizeof path_barca_pkgs);
    }

    return result;
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

  std::string OS::getAccountName() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_ComputerSystem", "UserName", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);  
    std::string delimiter = "\\";
    std::vector<std::string> val = split({tmp.begin(), tmp.end()}, delimiter);
    
    return val[1];
  }

  std::string OS::getAccountLoginID() {
    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_LogonSession", "LogonId", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);

    return {tmp.begin(), tmp.end()};
  }

  std::string OS::getType() {
    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_ComputerSystem", "PrimaryOwnerName", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string OS::getFullType() {
    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_ComputerSystem", "BootupState", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string OS::getStatus() {
    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_ComputerSystem", "Status", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }

  std::string OS::getServicePath() {
    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_BaseService", "PathName", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);
    return {tmp.begin(), tmp.end()};
  }
  
  std::string OS::getBootDir() {
    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_BootConfiguration", "BootDirectory", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);

    return {tmp.begin(), tmp.end()};
  }

  std::string OS::getBootTempDir() {
    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_BootConfiguration", "TempDirectory", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);

    return {tmp.begin(), tmp.end()};
  }

  std::string OS::getBootLastDrive() {
    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_BootConfiguration", "LastDrive", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);

    return {tmp.begin(), tmp.end()};
  }

  std::string OS::getProductIdentificationCode() {
    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_ComputerSystemProduct", "IdentifyingNumber", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);

    return {tmp.begin(), tmp.end()};
  }

  std::string OS::getProductIdentificationName() {
    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_ComputerSystemProduct", "Name", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);

    return {tmp.begin(), tmp.end()};
  }

  std::string OS::getProductIdentificationVersion() {
    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_ComputerSystemProduct", "Version", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);

    return {tmp.begin(), tmp.end()};
  }


  std::string OS::getProductIdentificationUUID() {
    std::vector<const wchar_t*> vendor{};
    wmi::queryWMI("WIN32_ComputerSystemProduct", "UUID", vendor);
    auto ret = vendor[0];
    if (!ret) {
      return "<unknown>";
    }
    std::wstring tmp(ret);

    return {tmp.begin(), tmp.end()};
  }

  std::string OS::getKernel() { return "<unknown>"; }
  
  bool OS::getIs64bit() {
    BOOL bWow64Process = FALSE;
    return IsWow64Process(GetCurrentProcess(), &bWow64Process) && bWow64Process;
  };

};

#endif  // END BSCAN_WINDOWS