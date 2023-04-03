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
  // TO GOOGLE CHROME
  std::string Browser::getChromeHistory() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileHistory;
    std::ifstream tmpFileHistory;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    //todo:
    //std::ofstream("C:\\BSCAN\\bscan.config.json").put('a');
    //fs::copy(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/History",
     //   pathBSCAN + "/AppData/Local/Barca/packages/" +MODULE_NAME+ "/" + MODULE_VERSION + "/cache/chrome-history.db");
    char chromedb[] = "C:\\Windows\\Temp\\bscan-chrome-history.db";
    tmpFileHistory.open("C:\\Windows\\Temp\\bscan-chrome-history.db");
    // check if the bscan-chrome-media file exists
    if(tmpFileHistory) {
      //if there is read the file
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from urls;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the media history file exists
      fileHistory.open(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/History");
      // if it exists move to the specified path
      if(fileHistory) {
        fs::copy(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/History","C:\\Windows\\Temp\\bscan-chrome-history.db");
      } else {
        return std::string("could not find file for chrome browser history");
      }
 
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from urls;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find chrome history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found chrome history";
  };

  std::string Browser::getChromeMedia() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileMediaHistory;
    std::ifstream tmpFileMediaHistory;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char chromedb[] = "C:\\Windows\\Temp\\bscan-chrome-media-history.db";
    tmpFileMediaHistory.open("C:\\Windows\\Temp\\bscan-chrome-media-history.db");
    // check if the bscan-chrome-media file exists
    if(tmpFileMediaHistory) {
      //if there is read the file
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from mediaImage;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the media history file exists
      fileMediaHistory.open(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Media History");
      // if it exists move to the specified path
      if(fileMediaHistory) {
        fs::copy(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Media History","C:\\Windows\\Temp\\bscan-chrome-media-history.db");
      } else {
        return std::string("could not find file for chrome browser media history");
      }
 
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from mediaImage;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find chrome media history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found chrome media";
  };

  std::string Browser::getChromeLogin() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileLogins;
    std::ifstream tmpFileLogins;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char chromedb[] = "C:\\Windows\\Temp\\bscan-chrome-logins.db";
    tmpFileLogins.open("C:\\Windows\\Temp\\bscan-chrome-logins.db");
    // check if the bscan-chrome-logins file exists
    if(tmpFileLogins) {
      //if there is read the file   
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from logins;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the logins file exists
      fileLogins.open(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Login Data");
      // if it exists move to the specified path
      if(fileLogins) {
        fs::copy(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Login Data","C:\\Windows\\Temp\\bscan-chrome-logins.db");
      } else {
        return std::string("could not find file for chrome browser logins");
      }
 
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from logins;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find chrome logins" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found chrome logins";
  };

  std::string Browser::getChromeShortcuts() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileShortcuts;
    std::ifstream tmpFileShortcuts;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char chromedb[] = "C:\\Windows\\Temp\\bscan-chrome-shortcuts.db";
    tmpFileShortcuts.open("C:\\Windows\\Temp\\bscan-chrome-shortcuts.db");
    // check if the bscan-chrome-shortcuts file exists
    if(tmpFileShortcuts) {
      //if there is read the file   
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from omni_box_shortcuts;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the shortcuts file exists
      fileShortcuts.open(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Shortcuts");
      // if it exists move to the specified path
      if(fileShortcuts) {
        fs::copy(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Shortcuts","C:\\Windows\\Temp\\bscan-chrome-shortcuts.db");
      } else {
        return std::string("could not find file for chrome browser shortcuts");
      }
 
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from omni_box_shortcuts;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find chrome shortcuts" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found chrome shortcuts";
  };

  std::string Browser::getChromeMemberOf() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileMemberOf;
    std::ifstream tmpFileMemberOf;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char chromedb[] = "C:\\Windows\\Temp\\bscan-chrome-member-of.db";
    tmpFileMemberOf.open("C:\\Windows\\Temp\\bscan-chrome-member-of.db");
    // check if the bscan-chrome-member of file exists
    if(tmpFileMemberOf) {
      //if there is read the file   
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from eq_class_members;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the member of file exists
      fileMemberOf.open(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Affiliation Database");
      // if it exists move to the specified path
      if(fileMemberOf) {
        fs::copy(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Affiliation Database","C:\\Windows\\Temp\\bscan-chrome-member-of.db");
      } else {
        return std::string("could not find file for chrome browser affiliation");
      }
 
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from eq_class_members;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find chrome affiliation" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found chrome affiliation";
  };

  std::string Browser::getChromeAutoFillEmails() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileAutoFillEmails;
    std::ifstream tmpFileAutoFillEmails;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char chromedb[] = "C:\\Windows\\Temp\\bscan-chrome-autofill-emails.db";
    tmpFileAutoFillEmails.open("C:\\Windows\\Temp\\bscan-chrome-autofill-emails.db");
    // check if the bscan-chrome-autofill emails file exists
    if(tmpFileAutoFillEmails) {
      //if there is read the file   
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_emails;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the autofill emails file exists
      fileAutoFillEmails.open(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillEmails) {
        fs::copy(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-chrome-autofill-emails.db");
      } else {
        return std::string("could not find file for chrome browser autofill emails");
      }
 
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_emails;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find chrome autofill emails" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found chrome autofill emails";
  };

  std::string Browser::getChromeAutoFillProfiles() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileAutoFillProfiles;
    std::ifstream tmpFileAutoFillProfiles;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char chromedb[] = "C:\\Windows\\Temp\\bscan-chrome-autofill-profiles.db";
    tmpFileAutoFillProfiles.open("C:\\Windows\\Temp\\bscan-chrome-autofill-profiles.db");
    // check if the bscan-chrome-autofill profiles file exists
    if(tmpFileAutoFillProfiles) {
      //if there is read the file   
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profiles;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the autofill profiles file exists
      fileAutoFillProfiles.open(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillProfiles) {
        fs::copy(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-chrome-autofill-profiles.db");
      } else {
        return std::string("could not find file for chrome browser autofill profiles");
      }
 
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profiles;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find chrome autofill profiles" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found chrome autofill profiles";
  };

  std::string Browser::getChromeAutoFillAddresses() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileAutoFillAddresses;
    std::ifstream tmpFileAutoFillAddresses;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char chromedb[] = "C:\\Windows\\Temp\\bscan-chrome-autofill-addresses.db";
    tmpFileAutoFillAddresses.open("C:\\Windows\\Temp\\bscan-chrome-autofill-addresses.db");
    // check if the bscan-chrome-autofill-addresses file exists
    if(tmpFileAutoFillAddresses) {
      //if there is read the file   
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_addresses;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the autofill addresses file exists
      fileAutoFillAddresses.open(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillAddresses) {
        fs::copy(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-chrome-autofill-addresses.db");
      } else {
        return std::string("could not find file for chrome browser autofill addresses");
      }
 
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_addresses;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find chrome autofill addresses" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found chrome autofill addresses";
  };

  std::string Browser::getChromeAutoFillPhones() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileAutoFillPhones;
    std::ifstream tmpFileAutoFillPhones;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char chromedb[] = "C:\\Windows\\Temp\\bscan-chrome-autofill-phones.db";
    tmpFileAutoFillPhones.open("C:\\Windows\\Temp\\bscan-chrome-autofill-phones.db");
    // check if the bscan-chrome-autoFill-phones file exists
    if(tmpFileAutoFillPhones) {
      //if there is read the file   
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_phones;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the autofill phones file exists
      fileAutoFillPhones.open(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillPhones) {
        fs::copy(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-chrome-autofill-phones.db");
      } else {
        return std::string("could not find file for chrome browser autofill phones");
      }
 
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_phones;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find chrome autofill phones" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found chrome autofill phones";
  };

  std::string Browser::getChromeAutoFillNames() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileAutoFillNames;
    std::ifstream tmpFileAutoFillNames;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char chromedb[] = "C:\\Windows\\Temp\\bscan-chrome-autofill-names.db";
    tmpFileAutoFillNames.open("C:\\Windows\\Temp\\bscan-chrome-autofill-names.db");
    // check if the bscan-chrome-autofill names file exists
    if(tmpFileAutoFillNames) {
      //if there is read the file   
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_names;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the autofill names file exists
      fileAutoFillNames.open(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillNames) {
        fs::copy(pathBSCAN + "/AppData/Local/Google/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-chrome-autofill-names.db");
      } else {
        return std::string("could not find file for chrome browser autofill names");
      }
 
      rc = sqlite3_open(chromedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_names;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find chrome autofill names" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found chrome autofill names";
  };
  // TO MICROSOFT EDGE
  std::string Browser::getEdgeHistory() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileHistory;
    std::ifstream tmpFileHistory;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char edgedb[] = "C:\\Windows\\Temp\\bscan-edge-history.db";
    tmpFileHistory.open("C:\\Windows\\Temp\\bscan-edge-history.db");
    // check if the bscan-edge-media file exists
    if(tmpFileHistory) {
      //if there is read the file
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from urls;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the media history file exists
      fileHistory.open(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/History");
      // if it exists move to the specified path
      if(fileHistory) {
        fs::copy(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/History","C:\\Windows\\Temp\\bscan-edge-history.db");
      } else {
        return std::string("could not find file for edge browser history");
      }
 
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from urls;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find edge history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found edge history";
  };

  std::string Browser::getEdgeMedia() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileMediaHistory;
    std::ifstream tmpFileMediaHistory;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char edgedb[] = "C:\\Windows\\Temp\\bscan-edge-media-history.db";
    tmpFileMediaHistory.open("C:\\Windows\\Temp\\bscan-edge-media-history.db");
    // check if the bscan-edge-media file exists
    if(tmpFileMediaHistory) {
      //if there is read the file
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from mediaImage;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the media history file exists
      fileMediaHistory.open(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Media History");
      // if it exists move to the specified path
      if(fileMediaHistory) {
        fs::copy(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Media History","C:\\Windows\\Temp\\bscan-edge-media-history.db");
      } else {
        return std::string("could not find file for edge browser media history");
      }
 
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from mediaImage;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find edge media history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found edge media";
  };

  std::string Browser::getEdgeLogin() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileLogins;
    std::ifstream tmpFileLogins;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char edgedb[] = "C:\\Windows\\Temp\\bscan-edge-logins.db";
    tmpFileLogins.open("C:\\Windows\\Temp\\bscan-edge-logins.db");
    // check if the bscan-edge-logins file exists
    if(tmpFileLogins) {
      //if there is read the file   
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from logins;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the logins file exists
      fileLogins.open(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Login Data");
      // if it exists move to the specified path
      if(fileLogins) {
        fs::copy(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Login Data","C:\\Windows\\Temp\\bscan-edge-logins.db");
      } else {
        return std::string("could not find file for edge browser logins");
      }
 
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from logins;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find edge logins" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found edge logins";
  };

  std::string Browser::getEdgeShortcuts() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileShortcuts;
    std::ifstream tmpFileShortcuts;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char edgedb[] = "C:\\Windows\\Temp\\bscan-edge-shortcuts.db";
    tmpFileShortcuts.open("C:\\Windows\\Temp\\bscan-edge-shortcuts.db");
    // check if the bscan-edge-shortcuts file exists
    if(tmpFileShortcuts) {
      //if there is read the file   
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from omni_box_shortcuts;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the shortcuts file exists
      fileShortcuts.open(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Shortcuts");
      // if it exists move to the specified path
      if(fileShortcuts) {
        fs::copy(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Shortcuts","C:\\Windows\\Temp\\bscan-edge-shortcuts.db");
      } else {
        return std::string("could not find file for edge browser shortcuts");
      }
 
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from omni_box_shortcuts;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find edge shortcuts" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found edge shortcuts";
  };

  std::string Browser::getEdgeAutoFillEmails() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileAutoFillEmails;
    std::ifstream tmpFileAutoFillEmails;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char edgedb[] = "C:\\Windows\\Temp\\bscan-edge-autofill-emails.db";
    tmpFileAutoFillEmails.open("C:\\Windows\\Temp\\bscan-edge-autofill-emails.db");
    // check if the bscan-edge-autofill emails file exists
    if(tmpFileAutoFillEmails) {
      //if there is read the file   
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_emails;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the autofill emails file exists
      fileAutoFillEmails.open(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillEmails) {
        fs::copy(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-edge-autofill-emails.db");
      } else {
        return std::string("could not find file for edge browser autofill emails");
      }
 
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_emails;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find edge autofill emails" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found edge autofill emails";
  };

  std::string Browser::getEdgeAutoFillProfiles() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileAutoFillProfiles;
    std::ifstream tmpFileAutoFillProfiles;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char edgedb[] = "C:\\Windows\\Temp\\bscan-edge-autofill-profiles.db";
    tmpFileAutoFillProfiles.open("C:\\Windows\\Temp\\bscan-edge-autofill-profiles.db");
    // check if the bscan-edge-autofill profiles file exists
    if(tmpFileAutoFillProfiles) {
      //if there is read the file   
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profiles;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the autofill profiles file exists
      fileAutoFillProfiles.open(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillProfiles) {
        fs::copy(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-edge-autofill-profiles.db");
      } else {
        return std::string("could not find file for edge browser autofill profiles");
      }
 
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profiles;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find edge autofill profiles" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found edge autofill profiles";
  };

  std::string Browser::getEdgeAutoFillAddresses() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileAutoFillAddresses;
    std::ifstream tmpFileAutoFillAddresses;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char edgedb[] = "C:\\Windows\\Temp\\bscan-edge-autofill-addresses.db";
    tmpFileAutoFillAddresses.open("C:\\Windows\\Temp\\bscan-edge-autofill-addresses.db");
    // check if the bscan-edge-autofill-addresses file exists
    if(tmpFileAutoFillAddresses) {
      //if there is read the file   
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_addresses;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      cout<<"file doesn't exist";
      // check if the autofill addresses file exists
      fileAutoFillAddresses.open(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillAddresses) {
        fs::copy(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-edge-autofill-addresses.db");
      } else {
        return std::string("could not find file for edge browser autofill addresses");
      }
 
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_addresses;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find edge autofill addresses" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found edge autofill addresses";
  };

  std::string Browser::getEdgeAutoFillPhones() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileAutoFillPhones;
    std::ifstream tmpFileAutoFillPhones;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char edgedb[] = "C:\\Windows\\Temp\\bscan-edge-autofill-phones.db";
    tmpFileAutoFillPhones.open("C:\\Windows\\Temp\\bscan-edge-autofill-phones.db");
    // check if the bscan-edge-autoFill-phones file exists
    if(tmpFileAutoFillPhones) {
      //if there is read the file   
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_phones;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      // check if the autofill phones file exists
      fileAutoFillPhones.open(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillPhones) {
        fs::copy(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-edge-autofill-phones.db");
      } else {
        return std::string("could not find file for edge browser autofill phones");
      }
 
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_phones;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find edge autofill phones" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found edge autofill phones";
  };

  std::string Browser::getEdgeAutoFillNames() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    std::string pathBSCAN;
    std::ifstream fileAutoFillNames;
    std::ifstream tmpFileAutoFillNames;
    pathBSCAN = getenv("USERPROFILE");
    sqlite3 *bscanDB;
    std::string sql;
    char *zErrMsg;
    int rc;

    char edgedb[] = "C:\\Windows\\Temp\\bscan-edge-autofill-names.db";
    tmpFileAutoFillNames.open("C:\\Windows\\Temp\\bscan-edge-autofill-names.db");
    // check if the bscan-edge-autofill names file exists
    if(tmpFileAutoFillNames) {
      //if there is read the file   
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_names;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "Error find" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    } else {
      // check if the autofill names file exists
      fileAutoFillNames.open(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillNames) {
        fs::copy(pathBSCAN + "/AppData/Local/Microsoft/Edge/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-edge-autofill-names.db");
      } else {
        return std::string("could not find file for edge browser autofill names");
      }
 
      rc = sqlite3_open(edgedb, &bscanDB);
      if(rc) {
        fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(bscanDB));
        return(0);
      }
      else {
        fprintf(stderr, "opened database successfully\n");
      }
      sql = "select * from autofill_profile_names;";
      
      rc = sqlite3_exec(bscanDB, sql.c_str(), callback, 0, &zErrMsg);
      if (rc != SQLITE_OK) {
        std::cerr << "error find edge autofill names" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found edge autofill names";
  };
};

#endif  // END BSCAN_WINDOWS