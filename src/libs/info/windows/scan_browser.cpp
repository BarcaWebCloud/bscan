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
#include "swares/scan_browser.h"

#define STATUS_SUCCESS 0x00000000


#include "utils/subprocess.h"
#include "config.h"
using namespace std;
namespace fs = std::filesystem;

namespace bscan {

  std::string Browser::getChromeHistory() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    pathBSCAN = getenv("USERPROFILE");
    string line;
    //todo:
    //std::ofstream("C:\\BSCAN\\bscan.config.json").put('a');
    //fs::copy(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/History",
     //   pathBSCAN + "/AppData/Local/Barca/packages/" +MODULE_NAME+ "/" + MODULE_VERSION + "/cache/chrome-history.db");
    fs::copy(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/History","C:\\Windows\\Temp\\bscan-chrome.db");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;
    const char* data = "Callback function called";
    char chromedb[] = "C:\\Windows\\Temp\\bscan-chrome.db";
    // todo:
    //char fig[100] = "\\AppData\\Local\\Barca\\packages\\bscan\\0.1.5\\cache\\chrome-history.db";
    //std::string ft = getenv("USERPROFILE");
    //std::cout << MODULE_NAME << std::endl;

    // open db
    rc = sqlite3_open(chromedb, &bscanDB);
    if(rc) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(bscanDB));
      return(0);
    }
    else {
      fprintf(stderr, "Opened database successfully\n");
    }
    // create script SQL
    sql = "SELECT * FROM urls;";
    // exec script SQL
    rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
      std::cerr << "Error find" << std::endl;
      sqlite3_free(zErrMsg);
    }
    else
      std::cout << "Find Successfully!" << std::endl;
      std::cout << stdout << std::endl;

    sqlite3_close(bscanDB);
    return "dada";
  }

};

#endif  // END BSCAN_WINDOWS