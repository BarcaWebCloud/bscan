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
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <winsock.h>
#include <stdio.h>
#include <vector>
#include <cstdio>
#include <stdlib.h>  
#include <sstream>
#include <string>
#include <dirent.h>
#include <sys/types.h>
#include <sqlite3.h>


#include "WMIwrapper.h"

#define STATUS_SUCCESS 0x00000000


#include "swares/scan_datasource.h"
#include "utils/directory.h"
#include "config.h"
#include "utils/string.h"
#include "utils/rapidjson/document.h"
#include "utils/rapidjson/filereadstream.h"
#include "utils/rapidjson/filewritestream.h"
#include "utils/rapidjson/writer.h"
#include "utils/rapidjson/ostreamwrapper.h"

// #include "utils/subprocess.h"
#include "config.h"

using namespace std;
using namespace rapidjson;
namespace fs = std::filesystem;
  



namespace bscan {
  // TO POSTGRESQL
  std::string Datasource::getPostgresqlDatabases() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    char* content;
    content = getenv("USERPROFILE");
    return std::string(listDir(content));
  }

  std::string Datasource::getPostgresqlVersion() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    // generator file model from apps installed in format json
    ofstream installed_default;
    installed_default.open(std::string(getenv("USERPROFILE")) + "\\AppData\\Local\\Temp\\bscanjhkyo\\default-installed.json");
    installed_default << "{\n  \"architecture\": \"\",\n  \"fullName\": \"\",\n  \"fullVersion\": \"\",\n  \"dateInstall\": \"\",\n  \"versionMajor\": \"\",\n  \"versionMinor\": \"\",\n  \"installDate\": \"\",\n  \"urlHelp\": \"\",\n  \"urlAbout\": \"\",\n  \"urlUpdate\": \"\",\n  \"urlUninstall\": \"\",\n  \"company\": \"\",\n  \"phone\": \"\",\n  \"contact\": \"\",\n  \"location\": \"\",\n  \"origin\": \"\",\n  \"size\": \"\",\n  \"readme\": \"\"\n}";
    installed_default.close();
    // define path to packages local
    char path_barca_pkgs[100] = "\\AppData\\Local\\Barca\\packages\\";
    strcat(path_barca_pkgs, PROJECT_NAME);
    strcat(path_barca_pkgs, "\\");
    strcat(path_barca_pkgs, PROJECT_VERSION);
    strcat(path_barca_pkgs, "\\storage\\installed.json");

  
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
        // std::cout << str << std::endl;
        // std::cout << x << std::endl;
        if (x > 0){
          // std::cout << str << std::endl;
          result.push_back(str);
        }

        x++;
       }
       ifs.close();
     };

    // for (int i = 0; i < result.size(); i++) {
    //     cout << result[i] << " ";
    // }
    cout << "\n\n\n" << sizeof(result) << "\n\n\n";
    // cout << result[3] << " ";

    for (auto y: result) {
      cout << "\n\n\n" << y << "\n\n\n";
    }


    std::string delimiter = ",";
    std::vector<std::string> v = split (result[3], delimiter);

    for (auto i : v) cout << i << endl;


    // sets the path to where the default json file is
    char path_d[300] = "";
    strcat(path_d, getenv("USERPROFILE"));
    strcat(path_d, "\\AppData\\Local\\Temp\\bscanjhkyo\\default-installed.json");

    // read model file json to list apps installed    
    FILE* fp = fopen(path_d, "rb"); // non-Windows use "r"
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);
    fclose(fp);



    string value_architecture = v[0].c_str();
    value_architecture.erase(remove(value_architecture.begin(), value_architecture.end(), '"'), value_architecture.end());
    // Modify the JSON data
    Value& architecture = d["architecture"];
    architecture.SetString(value_architecture.c_str(), d.GetAllocator());
 

    string value_fullname = v[1].c_str();
    value_fullname.erase(remove(value_fullname.begin(), value_fullname.end(), '"'), value_fullname.end());
    Value& fullname = d["fullName"];
    fullname.SetString(value_fullname.c_str(), d.GetAllocator());
 

    string value_fullversion = v[2].c_str();
     value_fullversion.erase(remove(value_fullversion.begin(), value_fullversion.end(), '"'), value_fullversion.end());
     Value& fullversion = d["fullVersion"];
     fullversion.SetString(value_fullversion.c_str(), d.GetAllocator());

   string value_dateinstall = v[3].c_str();
   value_dateinstall.erase(remove(value_dateinstall.begin(), value_dateinstall.end(), '"'), value_dateinstall.end());
   Value& dateinstall = d["dateInstall"];
   dateinstall.SetString(value_dateinstall.c_str(), d.GetAllocator());


    string value_urlhelp = v[4].c_str();
   value_urlhelp.erase(remove(value_urlhelp.begin(), value_urlhelp.end(), '"'), value_urlhelp.end());
   Value& urlhelp = d["urlHelp"];
   urlhelp.SetString(value_urlhelp.c_str(), d.GetAllocator());

    string url_about = v[5].c_str();
   url_about.erase(remove(url_about.begin(), url_about.end(), '"'), url_about.end());
   Value& urlabout = d["urlAbout"];
   urlabout.SetString(url_about.c_str(), d.GetAllocator());


   string url_update = v[6].c_str();
   url_update.erase(remove(url_update.begin(), url_update.end(), '"'), url_update.end());
   Value& urlupdate = d["urlUpdate"];
   urlupdate.SetString(url_update.c_str(), d.GetAllocator());

    string value_company = v[7].c_str();
   value_company.erase(remove(value_company.begin(), value_company.end(), '"'), value_company.end());
   Value& company = d["company"];
   company.SetString(value_company.c_str(), d.GetAllocator());

    string value_phone = v[8].c_str();
   value_phone.erase(remove(value_phone.begin(), value_phone.end(), '"'), value_phone.end());
   Value& phone = d["phone"];
   phone.SetString(value_phone.c_str(), d.GetAllocator());
 
   string value_contact = v[9].c_str();
   value_contact.erase(remove(value_contact.begin(), value_contact.end(), '"'), value_contact.end());
   Value& contact = d["contact"];
   contact.SetString(value_contact.c_str(), d.GetAllocator());
 
   string value_location = v[10].c_str();
   value_location.erase(remove(value_location.begin(), value_location.end(), '"'), value_location.end());
   Value& location = d["location"];
   location.SetString(value_location.c_str(), d.GetAllocator());
 
   string value_origin = v[11].c_str();
   value_origin.erase(remove(value_origin.begin(), value_origin.end(), '"'), value_origin.end());
   Value& origin = d["origin"];
   origin.SetString(value_origin.c_str(), d.GetAllocator());
  
  
   string value_versionmajor = v[12].c_str();
   value_versionmajor.erase(remove(value_versionmajor.begin(), value_versionmajor.end(), '"'), value_versionmajor.end());
   Value& versionmajor = d["versionMajor"];
   versionmajor.SetString(value_versionmajor.c_str(), d.GetAllocator());
 
   string value_minor = v[13].c_str();
   value_minor.erase(remove(value_minor.begin(), value_minor.end(), '"'), value_minor.end());
   Value& versionminor = d["versionMinor"];
   versionminor.SetString(value_minor.c_str(), d.GetAllocator());

   string value_uninstall = v[14].c_str();
   value_uninstall.erase(remove(value_uninstall.begin(), value_uninstall.end(), '"'), value_uninstall.end());
   Value& urluninstall = d["urlUninstall"];
   urluninstall.SetString(value_uninstall.c_str(), d.GetAllocator());
 

   string value_size = v[15].c_str();
   value_size.erase(remove(value_size.begin(), value_size.end(), '"'), value_size.end());
   Value& size = d["size"];
   size.SetString(value_size.c_str(), d.GetAllocator());
 
   string value_readme = v[16].c_str();
   value_readme.erase(remove(value_readme.begin(), value_readme.end(), '"'), value_readme.end());
   Value& readme = d["readme"];
   readme.SetString(value_readme.c_str(), d.GetAllocator());



   // save list apps installed file in format json
    FILE* fp2 = fopen(strcat(getenv("USERPROFILE"), path_barca_pkgs),"wb"); // non-Windows use "w"
    char writeBuffer[65536];
    FileWriteStream os(fp2, writeBuffer, sizeof(writeBuffer));
    Writer<FileWriteStream> writer(os);
    d.Accept(writer);
    fclose(fp2);




    // std::cout << filepathExists << endl;
    return std::string("dad");

  };
// https://en.cppreference.com/w/cpp/filesystem/exists
// https://i.stack.imgur.com/9PDzx.png
  //https://learn.microsoft.com/pt-br/windows/win32/cimwin32prov/win32-account
// https://learn.microsoft.com/pt-br/windows/win32/cimwin32prov/win32-baseboard
// https://www.intel.com/content/www/us/en/support/articles/000025060/intel-nuc.html
// https://powershell.one/wmi/root/cimv2/win32_baseboard
  // https://theitbros.com/how-to-get-list-of-installed-programs-in-windows-10/

  // https://support.ptc.com/help/thingworx_hc/thingworx_8_hc/en/index.html#page/ThingWorx/Help/Installation/Installation/install_and_configure_postgresql_windows.html
  std::string Datasource::getPostgresqlProfiles() {



    return "profiles";
  }

  std::string Datasource::getPostgresqlPreferencies() {
    return "preferencies";
  }

  std::string Datasource::getPostgresqlConfig() {
    return "config";
  }

  std::string Datasource::getPostgresqlPID() {
    return "pid";
  }

  std::string Datasource::getPostgresqlPath() {
    return "path";
  }

  std::string Datasource::getPostgresqlPort() {
    return "port";
  }

  std::string Datasource::getPostgresqlLogs() {

    return "logs";
  }
  // TO MYSQL
  // TO ORACLE
  // TO MSSERVER
  // TO MONGODB
  // TO REDIS
};

#endif  // END BSCAN_WINDOWS