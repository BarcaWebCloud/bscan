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
  // TO OPERA GX STABLE
  std::string Browser::getOperaGXHistory() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-history.db";
    tmpFileHistory.open("C:\\Windows\\Temp\\bscan-opera-history.db");
    // check if the bscan-opera-media file exists
    if(tmpFileHistory) {
      //if there is read the file
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileHistory.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/History");
      // if it exists move to the specified path
      if(fileHistory) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/History","C:\\Windows\\Temp\\bscan-opera-history.db");
      } else {
        return std::string("could not find file for opera browser history");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found opera history";
  };

  std::string Browser::getOperaGXLogin() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-logins.db";
    tmpFileLogins.open("C:\\Windows\\Temp\\bscan-opera-logins.db");
    // check if the bscan-opera-logins file exists
    if(tmpFileLogins) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileLogins.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Login Data");
      // if it exists move to the specified path
      if(fileLogins) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Login Data","C:\\Windows\\Temp\\bscan-opera-logins.db");
      } else {
        return std::string("could not find file for opera browser logins");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera logins" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found opera logins";
  };

  std::string Browser::getOperaGXShortcuts() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-shortcuts.db";
    tmpFileShortcuts.open("C:\\Windows\\Temp\\bscan-opera-shortcuts.db");
    // check if the bscan-opera-shortcuts file exists
    if(tmpFileShortcuts) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileShortcuts.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Shortcuts");
      // if it exists move to the specified path
      if(fileShortcuts) {
        fs::copy(pathBSCAN + "/AppData/Local/Roaming/Opera Software/Opera GX Stable/Shortcuts","C:\\Windows\\Temp\\bscan-opera-shortcuts.db");
      } else {
        return std::string("could not find file for opera browser shortcuts");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera shortcuts" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found opera shortcuts";
  };

  std::string Browser::getOperaGXMemberOf() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-member-of.db";
    tmpFileMemberOf.open("C:\\Windows\\Temp\\bscan-opera-member-of.db");
    // check if the bscan-opera-member of file exists
    if(tmpFileMemberOf) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileMemberOf.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Affiliation Database");
      // if it exists move to the specified path
      if(fileMemberOf) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Affiliation Database","C:\\Windows\\Temp\\bscan-opera-member-of.db");
      } else {
        return std::string("could not find file for opera browser affiliation");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera affiliation" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found opera affiliation";
  };

  std::string Browser::getOperaGXAutoFillEmails() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-autofill-emails.db";
    tmpFileAutoFillEmails.open("C:\\Windows\\Temp\\bscan-opera-autofill-emails.db");
    // check if the bscan-opera-autofill emails file exists
    if(tmpFileAutoFillEmails) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileAutoFillEmails.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillEmails) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data","C:\\Windows\\Temp\\bscan-opera-autofill-emails.db");
      } else {
        return std::string("could not find file for opera browser autofill emails");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera autofill emails" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found opera autofill emails";
  };

  std::string Browser::getOperaGXAutoFillProfiles() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-autofill-profiles.db";
    tmpFileAutoFillProfiles.open("C:\\Windows\\Temp\\bscan-opera-autofill-profiles.db");
    // check if the bscan-opera-autofill profiles file exists
    if(tmpFileAutoFillProfiles) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileAutoFillProfiles.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillProfiles) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data","C:\\Windows\\Temp\\bscan-opera-autofill-profiles.db");
      } else {
        return std::string("could not find file for opera browser autofill profiles");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera autofill profiles" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found opera autofill profiles";
  };

  std::string Browser::getOperaGXAutoFillAddresses() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-autofill-addresses.db";
    tmpFileAutoFillAddresses.open("C:\\Windows\\Temp\\bscan-opera-autofill-addresses.db");
    // check if the bscan-opera-autofill-addresses file exists
    if(tmpFileAutoFillAddresses) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileAutoFillAddresses.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillAddresses) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data","C:\\Windows\\Temp\\bscan-opera-autofill-addresses.db");
      } else {
        return std::string("could not find file for opera browser autofill addresses");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera autofill addresses" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found opera autofill addresses";
  };

  std::string Browser::getOperaGXAutoFillPhones() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-autofill-phones.db";
    tmpFileAutoFillPhones.open("C:\\Windows\\Temp\\bscan-opera-autofill-phones.db");
    // check if the bscan-opera-autoFill-phones file exists
    if(tmpFileAutoFillPhones) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileAutoFillPhones.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillPhones) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data","C:\\Windows\\Temp\\bscan-opera-autofill-phones.db");
      } else {
        return std::string("could not find file for opera browser autofill phones");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera autofill phones" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found opera autofill phones";
  };

  std::string Browser::getOperaGXAutoFillNames() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-autofill-names.db";
    tmpFileAutoFillNames.open("C:\\Windows\\Temp\\bscan-opera-autofill-names.db");
    // check if the bscan-opera-autofill names file exists
    if(tmpFileAutoFillNames) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileAutoFillNames.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillNames) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data","C:\\Windows\\Temp\\bscan-opera-autofill-names.db");
      } else {
        return std::string("could not find file for opera browser autofill names");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera autofill names" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found opera autofill names";
  };
  // TO OPERA STABLE
  std::string Browser::getOperaHistory() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-history.db";
    tmpFileHistory.open("C:\\Windows\\Temp\\bscan-opera-history.db");
    // check if the bscan-opera-media file exists
    if(tmpFileHistory) {
      //if there is read the file
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileHistory.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/History");
      // if it exists move to the specified path
      if(fileHistory) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/History","C:\\Windows\\Temp\\bscan-opera-history.db");
      } else {
        return std::string("could not find file for opera browser history");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found opera history";
  };

  std::string Browser::getOperaLogin() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-logins.db";
    tmpFileLogins.open("C:\\Windows\\Temp\\bscan-opera-logins.db");
    // check if the bscan-opera-logins file exists
    if(tmpFileLogins) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileLogins.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Login Data");
      // if it exists move to the specified path
      if(fileLogins) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Login Data","C:\\Windows\\Temp\\bscan-opera-logins.db");
      } else {
        return std::string("could not find file for opera browser logins");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera logins" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found opera logins";
  };

  std::string Browser::getOperaShortcuts() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-shortcuts.db";
    tmpFileShortcuts.open("C:\\Windows\\Temp\\bscan-opera-shortcuts.db");
    // check if the bscan-opera-shortcuts file exists
    if(tmpFileShortcuts) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileShortcuts.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Shortcuts");
      // if it exists move to the specified path
      if(fileShortcuts) {
        fs::copy(pathBSCAN + "/AppData/Local/Roaming/Opera Software/Opera GX Stable/Shortcuts","C:\\Windows\\Temp\\bscan-opera-shortcuts.db");
      } else {
        return std::string("could not find file for opera browser shortcuts");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera shortcuts" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found opera shortcuts";
  };

  std::string Browser::getOperaMemberOf() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-member-of.db";
    tmpFileMemberOf.open("C:\\Windows\\Temp\\bscan-opera-member-of.db");
    // check if the bscan-opera-member of file exists
    if(tmpFileMemberOf) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileMemberOf.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Affiliation Database");
      // if it exists move to the specified path
      if(fileMemberOf) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Affiliation Database","C:\\Windows\\Temp\\bscan-opera-member-of.db");
      } else {
        return std::string("could not find file for opera browser affiliation");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera affiliation" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found opera affiliation";
  };

  std::string Browser::getOperaAutoFillEmails() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-autofill-emails.db";
    tmpFileAutoFillEmails.open("C:\\Windows\\Temp\\bscan-opera-autofill-emails.db");
    // check if the bscan-opera-autofill emails file exists
    if(tmpFileAutoFillEmails) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileAutoFillEmails.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillEmails) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data","C:\\Windows\\Temp\\bscan-opera-autofill-emails.db");
      } else {
        return std::string("could not find file for opera browser autofill emails");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera autofill emails" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found opera autofill emails";
  };

  std::string Browser::getOperaAutoFillProfiles() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-autofill-profiles.db";
    tmpFileAutoFillProfiles.open("C:\\Windows\\Temp\\bscan-opera-autofill-profiles.db");
    // check if the bscan-opera-autofill profiles file exists
    if(tmpFileAutoFillProfiles) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileAutoFillProfiles.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillProfiles) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data","C:\\Windows\\Temp\\bscan-opera-autofill-profiles.db");
      } else {
        return std::string("could not find file for opera browser autofill profiles");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera autofill profiles" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found opera autofill profiles";
  };

  std::string Browser::getOperaAutoFillAddresses() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-autofill-addresses.db";
    tmpFileAutoFillAddresses.open("C:\\Windows\\Temp\\bscan-opera-autofill-addresses.db");
    // check if the bscan-opera-autofill-addresses file exists
    if(tmpFileAutoFillAddresses) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileAutoFillAddresses.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillAddresses) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data","C:\\Windows\\Temp\\bscan-opera-autofill-addresses.db");
      } else {
        return std::string("could not find file for opera browser autofill addresses");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera autofill addresses" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found opera autofill addresses";
  };

  std::string Browser::getOperaAutoFillPhones() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-autofill-phones.db";
    tmpFileAutoFillPhones.open("C:\\Windows\\Temp\\bscan-opera-autofill-phones.db");
    // check if the bscan-opera-autoFill-phones file exists
    if(tmpFileAutoFillPhones) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileAutoFillPhones.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillPhones) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data","C:\\Windows\\Temp\\bscan-opera-autofill-phones.db");
      } else {
        return std::string("could not find file for opera browser autofill phones");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera autofill phones" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found opera autofill phones";
  };

  std::string Browser::getOperaAutoFillNames() {
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

    char operadb[] = "C:\\Windows\\Temp\\bscan-opera-autofill-names.db";
    tmpFileAutoFillNames.open("C:\\Windows\\Temp\\bscan-opera-autofill-names.db");
    // check if the bscan-opera-autofill names file exists
    if(tmpFileAutoFillNames) {
      //if there is read the file   
      rc = sqlite3_open(operadb, &bscanDB);
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
      fileAutoFillNames.open(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillNames) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Opera Software/Opera GX Stable/Web Data","C:\\Windows\\Temp\\bscan-opera-autofill-names.db");
      } else {
        return std::string("could not find file for opera browser autofill names");
      }
 
      rc = sqlite3_open(operadb, &bscanDB);
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
        std::cerr << "error find opera autofill names" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found opera autofill names";
  };
  // TO BRAVE
  std::string Browser::getBraveHistory() {
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

    char bravedb[] = "C:\\Windows\\Temp\\bscan-brave-history.db";
    tmpFileHistory.open("C:\\Windows\\Temp\\bscan-brave-history.db");
    // check if the bscan-brave-media file exists
    if(tmpFileHistory) {
      //if there is read the file
      rc = sqlite3_open(bravedb, &bscanDB);
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
      fileHistory.open(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/History");
      // if it exists move to the specified path
      if(fileHistory) {
        fs::copy(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/History","C:\\Windows\\Temp\\bscan-brave-history.db");
      } else {
        return std::string("could not find file for brave browser history");
      }
 
      rc = sqlite3_open(bravedb, &bscanDB);
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
        std::cerr << "error find brave history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found brave history";
  };

  std::string Browser::getBraveLogin() {
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

    char bravedb[] = "C:\\Windows\\Temp\\bscan-brave-logins.db";
    tmpFileLogins.open("C:\\Windows\\Temp\\bscan-brave-logins.db");
    // check if the bscan-brave-logins file exists
    if(tmpFileLogins) {
      //if there is read the file   
      rc = sqlite3_open(bravedb, &bscanDB);
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
      // check if the logins file exists
      fileLogins.open(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Login Data");
      // if it exists move to the specified path
      if(fileLogins) {
        fs::copy(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Login Data","C:\\Windows\\Temp\\bscan-brave-logins.db");
      } else {
        return std::string("could not find file for brave browser logins");
      }
 
      rc = sqlite3_open(bravedb, &bscanDB);
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
        std::cerr << "error find brave logins" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found brave logins";
  };

  std::string Browser::getBraveShortcuts() {
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

    char bravedb[] = "C:\\Windows\\Temp\\bscan-brave-shortcuts.db";
    tmpFileShortcuts.open("C:\\Windows\\Temp\\bscan-brave-shortcuts.db");
    // check if the bscan-brave-shortcuts file exists
    if(tmpFileShortcuts) {
      //if there is read the file   
      rc = sqlite3_open(bravedb, &bscanDB);
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
      fileShortcuts.open(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Shortcuts");
      // if it exists move to the specified path
      if(fileShortcuts) {
        fs::copy(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Shortcuts","C:\\Windows\\Temp\\bscan-brave-shortcuts.db");
      } else {
        return std::string("could not find file for brave browser shortcuts");
      }
 
      rc = sqlite3_open(bravedb, &bscanDB);
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
        std::cerr << "error find brave shortcuts" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found brave shortcuts";
  };

  std::string Browser::getBraveMemberOf() {
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

    char bravedb[] = "C:\\Windows\\Temp\\bscan-brave-member-of.db";
    tmpFileMemberOf.open("C:\\Windows\\Temp\\bscan-brave-member-of.db");
    // check if the bscan-brave-member of file exists
    if(tmpFileMemberOf) {
      //if there is read the file   
      rc = sqlite3_open(bravedb, &bscanDB);
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
      // check if the member of file exists
      fileMemberOf.open(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Affiliation Database");
      // if it exists move to the specified path
      if(fileMemberOf) {
        fs::copy(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Affiliation Database","C:\\Windows\\Temp\\bscan-brave-member-of.db");
      } else {
        return std::string("could not find file for brave browser affiliation");
      }
 
      rc = sqlite3_open(bravedb, &bscanDB);
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
        std::cerr << "error find brave affiliation" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found brave affiliation";
  };

  std::string Browser::getBraveAutoFillEmails() {
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

    char bravedb[] = "C:\\Windows\\Temp\\bscan-brave-autofill-emails.db";
    tmpFileAutoFillEmails.open("C:\\Windows\\Temp\\bscan-brave-autofill-emails.db");
    // check if the bscan-brave-autofill emails file exists
    if(tmpFileAutoFillEmails) {
      //if there is read the file   
      rc = sqlite3_open(bravedb, &bscanDB);
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
      // check if the autofill emails file exists
      fileAutoFillEmails.open(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillEmails) {
        fs::copy(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-brave-autofill-emails.db");
      } else {
        return std::string("could not find file for brave browser autofill emails");
      }
 
      rc = sqlite3_open(bravedb, &bscanDB);
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
        std::cerr << "error find brave autofill emails" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found brave autofill emails";
  };

  std::string Browser::getBraveAutoFillProfiles() {
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

    char bravedb[] = "C:\\Windows\\Temp\\bscan-brave-autofill-profiles.db";
    tmpFileAutoFillProfiles.open("C:\\Windows\\Temp\\bscan-brave-autofill-profiles.db");
    // check if the bscan-brave-autofill profiles file exists
    if(tmpFileAutoFillProfiles) {
      //if there is read the file   
      rc = sqlite3_open(bravedb, &bscanDB);
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
      fileAutoFillProfiles.open(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillProfiles) {
        fs::copy(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-brave-autofill-profiles.db");
      } else {
        return std::string("could not find file for brave browser autofill profiles");
      }
 
      rc = sqlite3_open(bravedb, &bscanDB);
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
        std::cerr << "error find brave autofill profiles" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found brave autofill profiles";
  };

  std::string Browser::getBraveAutoFillAddresses() {
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

    char bravedb[] = "C:\\Windows\\Temp\\bscan-brave-autofill-addresses.db";
    tmpFileAutoFillAddresses.open("C:\\Windows\\Temp\\bscan-brave-autofill-addresses.db");
    // check if the bscan-brave-autofill-addresses file exists
    if(tmpFileAutoFillAddresses) {
      //if there is read the file   
      rc = sqlite3_open(bravedb, &bscanDB);
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
      fileAutoFillAddresses.open(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillAddresses) {
        fs::copy(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-brave-autofill-addresses.db");
      } else {
        return std::string("could not find file for brave browser autofill addresses");
      }
 
      rc = sqlite3_open(bravedb, &bscanDB);
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
        std::cerr << "error find brave autofill addresses" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found brave autofill addresses";
  };

  std::string Browser::getBraveAutoFillPhones() {
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

    char bravedb[] = "C:\\Windows\\Temp\\bscan-brave-autofill-phones.db";
    tmpFileAutoFillPhones.open("C:\\Windows\\Temp\\bscan-brave-autofill-phones.db");
    // check if the bscan-brave-autoFill-phones file exists
    if(tmpFileAutoFillPhones) {
      //if there is read the file   
      rc = sqlite3_open(bravedb, &bscanDB);
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
      fileAutoFillPhones.open(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillPhones) {
        fs::copy(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-brave-autofill-phones.db");
      } else {
        return std::string("could not find file for brave browser autofill phones");
      }
 
      rc = sqlite3_open(bravedb, &bscanDB);
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
        std::cerr << "error find brave autofill phones" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found brave autofill phones";
  };

  std::string Browser::getBraveAutoFillNames() {
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

    char bravedb[] = "C:\\Windows\\Temp\\bscan-brave-autofill-names.db";
    tmpFileAutoFillNames.open("C:\\Windows\\Temp\\bscan-brave-autofill-names.db");
    // check if the bscan-brave-autofill names file exists
    if(tmpFileAutoFillNames) {
      //if there is read the file   
      rc = sqlite3_open(bravedb, &bscanDB);
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
      fileAutoFillNames.open(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillNames) {
        fs::copy(pathBSCAN + "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-brave-autofill-names.db");
      } else {
        return std::string("could not find file for brave browser autofill names");
      }
 
      rc = sqlite3_open(bravedb, &bscanDB);
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
        std::cerr << "error find brave autofill names" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found brave autofill names";
  };
  // TO VIVALDI
  std::string Browser::getVivaldiHistory() {
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

    char vivaldidb[] = "C:\\Windows\\Temp\\bscan-vivaldi-history.db";
    tmpFileHistory.open("C:\\Windows\\Temp\\bscan-vivaldi-history.db");
    // check if the bscan-vivaldi-media file exists
    if(tmpFileHistory) {
      //if there is read the file
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
      fileHistory.open(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/History");
      // if it exists move to the specified path
      if(fileHistory) {
        fs::copy(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/History","C:\\Windows\\Temp\\bscan-vivaldi-history.db");
      } else {
        return std::string("could not find file for vivaldi browser history");
      }
 
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
        std::cerr << "error find vivaldi history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found vivaldi history";
  };

  std::string Browser::getVivaldiLogin() {
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

    char vivaldidb[] = "C:\\Windows\\Temp\\bscan-vivaldi-logins.db";
    tmpFileLogins.open("C:\\Windows\\Temp\\bscan-vivaldi-logins.db");
    // check if the bscan-vivaldi-logins file exists
    if(tmpFileLogins) {
      //if there is read the file   
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
      // check if the logins file exists
      fileLogins.open(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Login Data");
      // if it exists move to the specified path
      if(fileLogins) {
        fs::copy(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Login Data","C:\\Windows\\Temp\\bscan-vivaldi-logins.db");
      } else {
        return std::string("could not find file for vivaldi browser logins");
      }
 
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
        std::cerr << "error find vivaldi logins" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found vivaldi logins";
  };

  std::string Browser::getVivaldiShortcuts() {
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

    char vivaldidb[] = "C:\\Windows\\Temp\\bscan-vivaldi-shortcuts.db";
    tmpFileShortcuts.open("C:\\Windows\\Temp\\bscan-vivaldi-shortcuts.db");
    // check if the bscan-vivaldi-shortcuts file exists
    if(tmpFileShortcuts) {
      //if there is read the file   
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
      // check if the shortcuts file exists
      fileShortcuts.open(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Shortcuts");
      // if it exists move to the specified path
      if(fileShortcuts) {
        fs::copy(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Shortcuts","C:\\Windows\\Temp\\bscan-vivaldi-shortcuts.db");
      } else {
        return std::string("could not find file for vivaldi browser shortcuts");
      }
 
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
        std::cerr << "error find vivaldi shortcuts" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found vivaldi shortcuts";
  };

  std::string Browser::getVivaldiMemberOf() {
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

    char vivaldidb[] = "C:\\Windows\\Temp\\bscan-vivaldi-member-of.db";
    tmpFileMemberOf.open("C:\\Windows\\Temp\\bscan-vivaldi-member-of.db");
    // check if the bscan-vivaldi-member of file exists
    if(tmpFileMemberOf) {
      //if there is read the file   
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
      // check if the member of file exists
      fileMemberOf.open(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Affiliation Database");
      // if it exists move to the specified path
      if(fileMemberOf) {
        fs::copy(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Affiliation Database","C:\\Windows\\Temp\\bscan-vivaldi-member-of.db");
      } else {
        return std::string("could not find file for vivaldi browser affiliation");
      }
 
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
        std::cerr << "error find vivaldi affiliation" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found vivaldi affiliation";
  };

  std::string Browser::getVivaldiAutoFillEmails() {
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

    char vivaldidb[] = "C:\\Windows\\Temp\\bscan-vivaldi-autofill-emails.db";
    tmpFileAutoFillEmails.open("C:\\Windows\\Temp\\bscan-vivaldi-autofill-emails.db");
    // check if the bscan-vivaldi-autofill emails file exists
    if(tmpFileAutoFillEmails) {
      //if there is read the file   
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
      // check if the autofill emails file exists
      fileAutoFillEmails.open(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillEmails) {
        fs::copy(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-vivaldi-autofill-emails.db");
      } else {
        return std::string("could not find file for vivaldi browser autofill emails");
      }
 
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
        std::cerr << "error find vivaldi autofill emails" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found vivaldi autofill emails";
  };

  std::string Browser::getVivaldiAutoFillProfiles() {
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

    char vivaldidb[] = "C:\\Windows\\Temp\\bscan-vivaldi-autofill-profiles.db";
    tmpFileAutoFillProfiles.open("C:\\Windows\\Temp\\bscan-vivaldi-autofill-profiles.db");
    // check if the bscan-vivaldi-autofill profiles file exists
    if(tmpFileAutoFillProfiles) {
      //if there is read the file   
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
      // check if the autofill profiles file exists
      fileAutoFillProfiles.open(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillProfiles) {
        fs::copy(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-vivaldi-autofill-profiles.db");
      } else {
        return std::string("could not find file for vivaldi browser autofill profiles");
      }
 
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
        std::cerr << "error find vivaldi autofill profiles" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found vivaldi autofill profiles";
  };

  std::string Browser::getVivaldiAutoFillAddresses() {
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

    char vivaldidb[] = "C:\\Windows\\Temp\\bscan-vivaldi-autofill-addresses.db";
    tmpFileAutoFillAddresses.open("C:\\Windows\\Temp\\bscan-vivaldi-autofill-addresses.db");
    // check if the bscan-vivaldi-autofill-addresses file exists
    if(tmpFileAutoFillAddresses) {
      //if there is read the file   
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
      // check if the autofill addresses file exists
      fileAutoFillAddresses.open(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillAddresses) {
        fs::copy(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-vivaldi-autofill-addresses.db");
      } else {
        return std::string("could not find file for vivaldi browser autofill addresses");
      }
 
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
        std::cerr << "error find vivaldi autofill addresses" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found vivaldi autofill addresses";
  };

  std::string Browser::getVivaldiAutoFillPhones() {
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

    char vivaldidb[] = "C:\\Windows\\Temp\\bscan-vivaldi-autofill-phones.db";
    tmpFileAutoFillPhones.open("C:\\Windows\\Temp\\bscan-vivaldi-autofill-phones.db");
    // check if the bscan-vivaldi-autoFill-phones file exists
    if(tmpFileAutoFillPhones) {
      //if there is read the file   
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
      fileAutoFillPhones.open(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillPhones) {
        fs::copy(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-vivaldi-autofill-phones.db");
      } else {
        return std::string("could not find file for vivaldi browser autofill phones");
      }
 
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
        std::cerr << "error find vivaldi autofill phones" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found vivaldi autofill phones";
  };

  std::string Browser::getVivaldiAutoFillNames() {
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

    char vivaldidb[] = "C:\\Windows\\Temp\\bscan-vivaldi-autofill-names.db";
    tmpFileAutoFillNames.open("C:\\Windows\\Temp\\bscan-vivaldi-autofill-names.db");
    // check if the bscan-vivaldi-autofill names file exists
    if(tmpFileAutoFillNames) {
      //if there is read the file   
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
      fileAutoFillNames.open(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillNames) {
        fs::copy(pathBSCAN + "/AppData/Local/Vivaldi/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-vivaldi-autofill-names.db");
      } else {
        return std::string("could not find file for vivaldi browser autofill names");
      }
 
      rc = sqlite3_open(vivaldidb, &bscanDB);
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
        std::cerr << "error find vivaldi autofill names" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found vivaldi autofill names";
  };
  // TO ORBITUM
  std::string Browser::getOrbitumHistory() {
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

    char orbitumdb[] = "C:\\Windows\\Temp\\bscan-orbitum-history.db";
    tmpFileHistory.open("C:\\Windows\\Temp\\bscan-orbitum-history.db");
    // check if the bscan-orbitum-media file exists
    if(tmpFileHistory) {
      //if there is read the file
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
      fileHistory.open(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/History");
      // if it exists move to the specified path
      if(fileHistory) {
        fs::copy(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/History","C:\\Windows\\Temp\\bscan-orbitum-history.db");
      } else {
        return std::string("could not find file for orbitum browser history");
      }
 
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
        std::cerr << "error find orbitum history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found orbitum history";
  };

  std::string Browser::getOrbitumLogin() {
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

    char orbitumdb[] = "C:\\Windows\\Temp\\bscan-orbitum-logins.db";
    tmpFileLogins.open("C:\\Windows\\Temp\\bscan-orbitum-logins.db");
    // check if the bscan-orbitum-logins file exists
    if(tmpFileLogins) {
      //if there is read the file   
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
      // check if the logins file exists
      fileLogins.open(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Login Data");
      // if it exists move to the specified path
      if(fileLogins) {
        fs::copy(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Login Data","C:\\Windows\\Temp\\bscan-orbitum-logins.db");
      } else {
        return std::string("could not find file for orbitum browser logins");
      }
 
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
        std::cerr << "error find orbitum logins" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found orbitum logins";
  };

  std::string Browser::getOrbitumShortcuts() {
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

    char orbitumdb[] = "C:\\Windows\\Temp\\bscan-orbitum-shortcuts.db";
    tmpFileShortcuts.open("C:\\Windows\\Temp\\bscan-orbitum-shortcuts.db");
    // check if the bscan-orbitum-shortcuts file exists
    if(tmpFileShortcuts) {
      //if there is read the file   
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
      // check if the shortcuts file exists
      fileShortcuts.open(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Shortcuts");
      // if it exists move to the specified path
      if(fileShortcuts) {
        fs::copy(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Shortcuts","C:\\Windows\\Temp\\bscan-orbitum-shortcuts.db");
      } else {
        return std::string("could not find file for orbitum browser shortcuts");
      }
 
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
        std::cerr << "error find orbitum shortcuts" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found orbitum shortcuts";
  };

  std::string Browser::getOrbitumMemberOf() {
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

    char orbitumdb[] = "C:\\Windows\\Temp\\bscan-orbitum-member-of.db";
    tmpFileMemberOf.open("C:\\Windows\\Temp\\bscan-orbitum-member-of.db");
    // check if the bscan-orbitum-member of file exists
    if(tmpFileMemberOf) {
      //if there is read the file   
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
      // check if the member of file exists
      fileMemberOf.open(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Affiliation Database");
      // if it exists move to the specified path
      if(fileMemberOf) {
        fs::copy(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Affiliation Database","C:\\Windows\\Temp\\bscan-orbitum-member-of.db");
      } else {
        return std::string("could not find file for orbitum browser affiliation");
      }
 
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
        std::cerr << "error find orbitum affiliation" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found orbitum affiliation";
  };

  std::string Browser::getOrbitumAutoFillEmails() {
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

    char orbitumdb[] = "C:\\Windows\\Temp\\bscan-orbitum-autofill-emails.db";
    tmpFileAutoFillEmails.open("C:\\Windows\\Temp\\bscan-orbitum-autofill-emails.db");
    // check if the bscan-orbitum-autofill emails file exists
    if(tmpFileAutoFillEmails) {
      //if there is read the file   
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
      // check if the autofill emails file exists
      fileAutoFillEmails.open(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillEmails) {
        fs::copy(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-orbitum-autofill-emails.db");
      } else {
        return std::string("could not find file for orbitum browser autofill emails");
      }
 
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
        std::cerr << "error find orbitum autofill emails" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found orbitum autofill emails";
  };

  std::string Browser::getOrbitumAutoFillProfiles() {
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

    char orbitumdb[] = "C:\\Windows\\Temp\\bscan-orbitum-autofill-profiles.db";
    tmpFileAutoFillProfiles.open("C:\\Windows\\Temp\\bscan-orbitum-autofill-profiles.db");
    // check if the bscan-orbitum-autofill profiles file exists
    if(tmpFileAutoFillProfiles) {
      //if there is read the file   
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
      // check if the autofill profiles file exists
      fileAutoFillProfiles.open(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillProfiles) {
        fs::copy(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-orbitum-autofill-profiles.db");
      } else {
        return std::string("could not find file for orbitum browser autofill profiles");
      }
 
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
        std::cerr << "error find orbitum autofill profiles" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found orbitum autofill profiles";
  };

  std::string Browser::getOrbitumAutoFillAddresses() {
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

    char orbitumdb[] = "C:\\Windows\\Temp\\bscan-orbitum-autofill-addresses.db";
    tmpFileAutoFillAddresses.open("C:\\Windows\\Temp\\bscan-orbitum-autofill-addresses.db");
    // check if the bscan-orbitum-autofill-addresses file exists
    if(tmpFileAutoFillAddresses) {
      //if there is read the file   
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
      // check if the autofill addresses file exists
      fileAutoFillAddresses.open(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillAddresses) {
        fs::copy(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-orbitum-autofill-addresses.db");
      } else {
        return std::string("could not find file for orbitum browser autofill addresses");
      }
 
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
        std::cerr << "error find orbitum autofill addresses" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found orbitum autofill addresses";
  };

  std::string Browser::getOrbitumAutoFillPhones() {
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

    char orbitumdb[] = "C:\\Windows\\Temp\\bscan-orbitum-autofill-phones.db";
    tmpFileAutoFillPhones.open("C:\\Windows\\Temp\\bscan-orbitum-autofill-phones.db");
    // check if the bscan-orbitum-autoFill-phones file exists
    if(tmpFileAutoFillPhones) {
      //if there is read the file   
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
      fileAutoFillPhones.open(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillPhones) {
        fs::copy(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-orbitum-autofill-phones.db");
      } else {
        return std::string("could not find file for orbitum browser autofill phones");
      }
 
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
        std::cerr << "error find orbitum autofill phones" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found orbitum autofill phones";
  };

  std::string Browser::getOrbitumAutoFillNames() {
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

    char orbitumdb[] = "C:\\Windows\\Temp\\bscan-orbitum-autofill-names.db";
    tmpFileAutoFillNames.open("C:\\Windows\\Temp\\bscan-orbitum-autofill-names.db");
    // check if the bscan-orbitum-autofill names file exists
    if(tmpFileAutoFillNames) {
      //if there is read the file   
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
      fileAutoFillNames.open(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillNames) {
        fs::copy(pathBSCAN + "/AppData/Local/Orbitum/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-orbitum-autofill-names.db");
      } else {
        return std::string("could not find file for orbitum browser autofill names");
      }
 
      rc = sqlite3_open(orbitumdb, &bscanDB);
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
        std::cerr << "error find orbitum autofill names" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found orbitum autofill names";
  };
  // TO MAXTHON
  std::string Browser::getMaxthonHistory() {
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

    char maxthondb[] = "C:\\Windows\\Temp\\bscan-maxthon-history.db";
    tmpFileHistory.open("C:\\Windows\\Temp\\bscan-maxthon-history.db");
    // check if the bscan-maxthon-media file exists
    if(tmpFileHistory) {
      //if there is read the file
      rc = sqlite3_open(maxthondb, &bscanDB);
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
      fileHistory.open(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/History");
      // if it exists move to the specified path
      if(fileHistory) {
        fs::copy(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/History","C:\\Windows\\Temp\\bscan-maxthon-history.db");
      } else {
        return std::string("could not find file for maxthon browser history");
      }
 
      rc = sqlite3_open(maxthondb, &bscanDB);
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
        std::cerr << "error find maxthon history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found maxthon history";
  };

  std::string Browser::getMaxthonLogin() {
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

    char maxthondb[] = "C:\\Windows\\Temp\\bscan-maxthon-logins.db";
    tmpFileLogins.open("C:\\Windows\\Temp\\bscan-maxthon-logins.db");
    // check if the bscan-maxthon-logins file exists
    if(tmpFileLogins) {
      //if there is read the file   
      rc = sqlite3_open(maxthondb, &bscanDB);
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
      // check if the logins file exists
      fileLogins.open(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Login Data");
      // if it exists move to the specified path
      if(fileLogins) {
        fs::copy(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Login Data","C:\\Windows\\Temp\\bscan-maxthon-logins.db");
      } else {
        return std::string("could not find file for maxthon browser logins");
      }
 
      rc = sqlite3_open(maxthondb, &bscanDB);
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
        std::cerr << "error find maxthon logins" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found maxthon logins";
  };

  std::string Browser::getMaxthonShortcuts() {
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

    char maxthondb[] = "C:\\Windows\\Temp\\bscan-maxthon-shortcuts.db";
    tmpFileShortcuts.open("C:\\Windows\\Temp\\bscan-maxthon-shortcuts.db");
    // check if the bscan-maxthon-shortcuts file exists
    if(tmpFileShortcuts) {
      //if there is read the file   
      rc = sqlite3_open(maxthondb, &bscanDB);
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
      // check if the shortcuts file exists
      fileShortcuts.open(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Shortcuts");
      // if it exists move to the specified path
      if(fileShortcuts) {
        fs::copy(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Shortcuts","C:\\Windows\\Temp\\bscan-maxthon-shortcuts.db");
      } else {
        return std::string("could not find file for maxthon browser shortcuts");
      }
 
      rc = sqlite3_open(maxthondb, &bscanDB);
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
        std::cerr << "error find maxthon shortcuts" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found maxthon shortcuts";
  };

  std::string Browser::getMaxthonMemberOf() {
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

    char maxthondb[] = "C:\\Windows\\Temp\\bscan-maxthon-member-of.db";
    tmpFileMemberOf.open("C:\\Windows\\Temp\\bscan-maxthon-member-of.db");
    // check if the bscan-maxthon-member of file exists
    if(tmpFileMemberOf) {
      //if there is read the file   
      rc = sqlite3_open(maxthondb, &bscanDB);
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
      // check if the member of file exists
      fileMemberOf.open(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Affiliation Database");
      // if it exists move to the specified path
      if(fileMemberOf) {
        fs::copy(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Affiliation Database","C:\\Windows\\Temp\\bscan-maxthon-member-of.db");
      } else {
        return std::string("could not find file for maxthon browser affiliation");
      }
 
      rc = sqlite3_open(maxthondb, &bscanDB);
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
        std::cerr << "error find maxthon affiliation" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found maxthon affiliation";
  };

  std::string Browser::getMaxthonAutoFillEmails() {
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

    char maxthondb[] = "C:\\Windows\\Temp\\bscan-maxthon-autofill-emails.db";
    tmpFileAutoFillEmails.open("C:\\Windows\\Temp\\bscan-maxthon-autofill-emails.db");
    // check if the bscan-maxthon-autofill emails file exists
    if(tmpFileAutoFillEmails) {
      //if there is read the file   
      rc = sqlite3_open(maxthondb, &bscanDB);
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
      // check if the autofill emails file exists
      fileAutoFillEmails.open(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillEmails) {
        fs::copy(pathBSCAN + "/AppData/Local/maxthon/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-maxthon-autofill-emails.db");
      } else {
        return std::string("could not find file for maxthon browser autofill emails");
      }
 
      rc = sqlite3_open(maxthondb, &bscanDB);
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
        std::cerr << "error find maxthon autofill emails" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found maxthon autofill emails";
  };

  std::string Browser::getMaxthonAutoFillProfiles() {
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

    char maxthondb[] = "C:\\Windows\\Temp\\bscan-maxthon-autofill-profiles.db";
    tmpFileAutoFillProfiles.open("C:\\Windows\\Temp\\bscan-maxthon-autofill-profiles.db");
    // check if the bscan-maxthon-autofill profiles file exists
    if(tmpFileAutoFillProfiles) {
      //if there is read the file   
      rc = sqlite3_open(maxthondb, &bscanDB);
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
      // check if the autofill profiles file exists
      fileAutoFillProfiles.open(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillProfiles) {
        fs::copy(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-maxthon-autofill-profiles.db");
      } else {
        return std::string("could not find file for maxthon browser autofill profiles");
      }
 
      rc = sqlite3_open(maxthondb, &bscanDB);
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
        std::cerr << "error find maxthon autofill profiles" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found maxthon autofill profiles";
  };

  std::string Browser::getMaxthonAutoFillAddresses() {
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

    char maxthondb[] = "C:\\Windows\\Temp\\bscan-maxthon-autofill-addresses.db";
    tmpFileAutoFillAddresses.open("C:\\Windows\\Temp\\bscan-maxthon-autofill-addresses.db");
    // check if the bscan-maxthon-autofill-addresses file exists
    if(tmpFileAutoFillAddresses) {
      //if there is read the file
      rc = sqlite3_open(maxthondb, &bscanDB);
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
      // check if the autofill addresses file exists
      fileAutoFillAddresses.open(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillAddresses) {
        fs::copy(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-maxthon-autofill-addresses.db");
      } else {
        return std::string("could not find file for maxthon browser autofill addresses");
      }
 
      rc = sqlite3_open(maxthondb, &bscanDB);
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
        std::cerr << "error find maxthon autofill addresses" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found maxthon autofill addresses";
  };

  std::string Browser::getMaxthonAutoFillPhones() {
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

    char maxthondb[] = "C:\\Windows\\Temp\\bscan-maxthon-autofill-phones.db";
    tmpFileAutoFillPhones.open("C:\\Windows\\Temp\\bscan-maxthon-autofill-phones.db");
    // check if the bscan-maxthon-autoFill-phones file exists
    if(tmpFileAutoFillPhones) {
      //if there is read the file   
      rc = sqlite3_open(maxthondb, &bscanDB);
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
      fileAutoFillPhones.open(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillPhones) {
        fs::copy(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-maxthon-autofill-phones.db");
      } else {
        return std::string("could not find file for maxthon browser autofill phones");
      }
 
      rc = sqlite3_open(maxthondb, &bscanDB);
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
        std::cerr << "error find maxthon autofill phones" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found maxthon autofill phones";
  };

  std::string Browser::getMaxthonAutoFillNames() {
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

    char maxthondb[] = "C:\\Windows\\Temp\\bscan-maxthon-autofill-names.db";
    tmpFileAutoFillNames.open("C:\\Windows\\Temp\\bscan-maxthon-autofill-names.db");
    // check if the bscan-maxthon-autofill names file exists
    if(tmpFileAutoFillNames) {
      //if there is read the file   
      rc = sqlite3_open(maxthondb, &bscanDB);
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
      fileAutoFillNames.open(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillNames) {
        fs::copy(pathBSCAN + "/AppData/Local/Maxthon/Application/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-maxthon-autofill-names.db");
      } else {
        return std::string("could not find file for maxthon browser autofill names");
      }
 
      rc = sqlite3_open(maxthondb, &bscanDB);
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
        std::cerr << "error find maxthon autofill names" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found maxthon autofill names";
  };
  // TO SEAMONKEY
  // TODO: find path files
  std::string Browser::getSeaMonkeyHistory() {
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

    char seamonkeydb[] = "C:\\Windows\\Temp\\bscan-seamonkey-history.db";
    tmpFileHistory.open("C:\\Windows\\Temp\\bscan-seamonkey-history.db");
    // check if the bscan-seamonkey-media file exists
    if(tmpFileHistory) {
      //if there is read the file
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
      fileHistory.open(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/History");
      // if it exists move to the specified path
      if(fileHistory) {
        fs::copy(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/History","C:\\Windows\\Temp\\bscan-seamonkey-history.db");
      } else {
        return std::string("could not find file for seamonkey browser history");
      }
 
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
        std::cerr << "error find seamonkey history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found seamonkey history";
  };

  std::string Browser::getSeaMonkeyLogin() {
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

    char seamonkeydb[] = "C:\\Windows\\Temp\\bscan-seamonkey-logins.db";
    tmpFileLogins.open("C:\\Windows\\Temp\\bscan-seamonkey-logins.db");
    // check if the bscan-seamonkey-logins file exists
    if(tmpFileLogins) {
      //if there is read the file   
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
      // check if the logins file exists
      fileLogins.open(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Login Data");
      // if it exists move to the specified path
      if(fileLogins) {
        fs::copy(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Login Data","C:\\Windows\\Temp\\bscan-seamonkey-logins.db");
      } else {
        return std::string("could not find file for seamonkey browser logins");
      }
 
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
        std::cerr << "error find seamonkey logins" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found seamonkey logins";
  };

  std::string Browser::getSeaMonkeyShortcuts() {
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

    char seamonkeydb[] = "C:\\Windows\\Temp\\bscan-seamonkey-shortcuts.db";
    tmpFileShortcuts.open("C:\\Windows\\Temp\\bscan-seamonkey-shortcuts.db");
    // check if the bscan-seamonkey-shortcuts file exists
    if(tmpFileShortcuts) {
      //if there is read the file   
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
      // check if the shortcuts file exists
      fileShortcuts.open(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Shortcuts");
      // if it exists move to the specified path
      if(fileShortcuts) {
        fs::copy(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Shortcuts","C:\\Windows\\Temp\\bscan-seamonkey-shortcuts.db");
      } else {
        return std::string("could not find file for seamonkey browser shortcuts");
      }
 
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
        std::cerr << "error find seamonkey shortcuts" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found seamonkey shortcuts";
  };

  std::string Browser::getSeaMonkeyMemberOf() {
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

    char seamonkeydb[] = "C:\\Windows\\Temp\\bscan-seamonkey-member-of.db";
    tmpFileMemberOf.open("C:\\Windows\\Temp\\bscan-seamonkey-member-of.db");
    // check if the bscan-seamonkey-member of file exists
    if(tmpFileMemberOf) {
      //if there is read the file   
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
      // check if the member of file exists
      fileMemberOf.open(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Affiliation Database");
      // if it exists move to the specified path
      if(fileMemberOf) {
        fs::copy(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Affiliation Database","C:\\Windows\\Temp\\bscan-seamonkey-member-of.db");
      } else {
        return std::string("could not find file for seamonkey browser affiliation");
      }
 
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
        std::cerr << "error find seamonkey affiliation" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found seamonkey affiliation";
  };

  std::string Browser::getSeaMonkeyAutoFillEmails() {
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

    char seamonkeydb[] = "C:\\Windows\\Temp\\bscan-seamonkey-autofill-emails.db";
    tmpFileAutoFillEmails.open("C:\\Windows\\Temp\\bscan-seamonkey-autofill-emails.db");
    // check if the bscan-seamonkey-autofill emails file exists
    if(tmpFileAutoFillEmails) {
      //if there is read the file   
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
      // check if the autofill emails file exists
      fileAutoFillEmails.open(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillEmails) {
        fs::copy(pathBSCAN + "/AppData/Local/seamonkey/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-seamonkey-autofill-emails.db");
      } else {
        return std::string("could not find file for seamonkey browser autofill emails");
      }
 
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
        std::cerr << "error find seamonkey autofill emails" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found seamonkey autofill emails";
  };

  std::string Browser::getSeaMonkeyAutoFillProfiles() {
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

    char seamonkeydb[] = "C:\\Windows\\Temp\\bscan-seamonkey-autofill-profiles.db";
    tmpFileAutoFillProfiles.open("C:\\Windows\\Temp\\bscan-seamonkey-autofill-profiles.db");
    // check if the bscan-seamonkey-autofill profiles file exists
    if(tmpFileAutoFillProfiles) {
      //if there is read the file   
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
      // check if the autofill profiles file exists
      fileAutoFillProfiles.open(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillProfiles) {
        fs::copy(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-seamonkey-autofill-profiles.db");
      } else {
        return std::string("could not find file for seamonkey browser autofill profiles");
      }
 
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
        std::cerr << "error find seamonkey autofill profiles" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found seamonkey autofill profiles";
  };

  std::string Browser::getSeaMonkeyAutoFillAddresses() {
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

    char seamonkeydb[] = "C:\\Windows\\Temp\\bscan-seamonkey-autofill-addresses.db";
    tmpFileAutoFillAddresses.open("C:\\Windows\\Temp\\bscan-seamonkey-autofill-addresses.db");
    // check if the bscan-seamonkey-autofill-addresses file exists
    if(tmpFileAutoFillAddresses) {
      //if there is read the file
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
      // check if the autofill addresses file exists
      fileAutoFillAddresses.open(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillAddresses) {
        fs::copy(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-seamonkey-autofill-addresses.db");
      } else {
        return std::string("could not find file for seamonkey browser autofill addresses");
      }
 
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
        std::cerr << "error find seamonkey autofill addresses" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found seamonkey autofill addresses";
  };

  std::string Browser::getSeaMonkeyAutoFillPhones() {
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

    char seamonkeydb[] = "C:\\Windows\\Temp\\bscan-seamonkey-autofill-phones.db";
    tmpFileAutoFillPhones.open("C:\\Windows\\Temp\\bscan-seamonkey-autofill-phones.db");
    // check if the bscan-seamonkey-autoFill-phones file exists
    if(tmpFileAutoFillPhones) {
      //if there is read the file   
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
      fileAutoFillPhones.open(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillPhones) {
        fs::copy(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-seamonkey-autofill-phones.db");
      } else {
        return std::string("could not find file for seamonkey browser autofill phones");
      }
 
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
        std::cerr << "error find seamonkey autofill phones" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found seamonkey autofill phones";
  };

  std::string Browser::getSeaMonkeyAutoFillNames() {
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

    char seamonkeydb[] = "C:\\Windows\\Temp\\bscan-seamonkey-autofill-names.db";
    tmpFileAutoFillNames.open("C:\\Windows\\Temp\\bscan-seamonkey-autofill-names.db");
    // check if the bscan-seamonkey-autofill names file exists
    if(tmpFileAutoFillNames) {
      //if there is read the file   
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
      fileAutoFillNames.open(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillNames) {
        fs::copy(pathBSCAN + "/AppData/Local/seamonkey/Application/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-seamonkey-autofill-names.db");
      } else {
        return std::string("could not find file for seamonkey browser autofill names");
      }
 
      rc = sqlite3_open(seamonkeydb, &bscanDB);
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
        std::cerr << "error find seamonkey autofill names" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found seamonkey autofill names";
  };
  // TO COMODO DRAGON
  std::string Browser::getComodoDragonHistory() {
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

    char comododragondb[] = "C:\\Windows\\Temp\\bscan-comododragon-history.db";
    tmpFileHistory.open("C:\\Windows\\Temp\\bscan-comododragon-history.db");
    // check if the bscan-comododragon-media file exists
    if(tmpFileHistory) {
      //if there is read the file
      rc = sqlite3_open(comododragondb, &bscanDB);
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
      fileHistory.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/History");
      // if it exists move to the specified path
      if(fileHistory) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/History","C:\\Windows\\Temp\\bscan-comododragon-history.db");
      } else {
        return std::string("could not find file for comododragon browser history");
      }
 
      rc = sqlite3_open(comododragondb, &bscanDB);
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
        std::cerr << "error find comododragon history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found comododragon history";
  };

  std::string Browser::getComodoDragonLogin() {
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

    char comododragondb[] = "C:\\Windows\\Temp\\bscan-comododragon-logins.db";
    tmpFileLogins.open("C:\\Windows\\Temp\\bscan-comododragon-logins.db");
    // check if the bscan-comododragon-logins file exists
    if(tmpFileLogins) {
      //if there is read the file   
      rc = sqlite3_open(comododragondb, &bscanDB);
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
      // check if the logins file exists
      fileLogins.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Login Data");
      // if it exists move to the specified path
      if(fileLogins) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Login Data","C:\\Windows\\Temp\\bscan-comododragon-logins.db");
      } else {
        return std::string("could not find file for comododragon browser logins");
      }
 
      rc = sqlite3_open(comododragondb, &bscanDB);
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
        std::cerr << "error find comododragon logins" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found comododragon logins";
  };

  std::string Browser::getComodoDragonShortcuts() {
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

    char comododragondb[] = "C:\\Windows\\Temp\\bscan-comododragon-shortcuts.db";
    tmpFileShortcuts.open("C:\\Windows\\Temp\\bscan-comododragon-shortcuts.db");
    // check if the bscan-comododragon-shortcuts file exists
    if(tmpFileShortcuts) {
      //if there is read the file   
      rc = sqlite3_open(comododragondb, &bscanDB);
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
      // check if the shortcuts file exists
      fileShortcuts.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Shortcuts");
      // if it exists move to the specified path
      if(fileShortcuts) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Shortcuts","C:\\Windows\\Temp\\bscan-comododragon-shortcuts.db");
      } else {
        return std::string("could not find file for comododragon browser shortcuts");
      }
 
      rc = sqlite3_open(comododragondb, &bscanDB);
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
        std::cerr << "error find comododragon shortcuts" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found comododragon shortcuts";
  };

  std::string Browser::getComodoDragonMemberOf() {
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

    char comododragondb[] = "C:\\Windows\\Temp\\bscan-comododragon-member-of.db";
    tmpFileMemberOf.open("C:\\Windows\\Temp\\bscan-comododragon-member-of.db");
    // check if the bscan-comododragon-member of file exists
    if(tmpFileMemberOf) {
      //if there is read the file   
      rc = sqlite3_open(comododragondb, &bscanDB);
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
      // check if the member of file exists
      fileMemberOf.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Affiliation Database");
      // if it exists move to the specified path
      if(fileMemberOf) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Affiliation Database","C:\\Windows\\Temp\\bscan-comododragon-member-of.db");
      } else {
        return std::string("could not find file for comododragon browser affiliation");
      }
 
      rc = sqlite3_open(comododragondb, &bscanDB);
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
        std::cerr << "error find comododragon affiliation" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found comododragon affiliation";
  };

  std::string Browser::getComodoDragonAutoFillEmails() {
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

    char comododragondb[] = "C:\\Windows\\Temp\\bscan-comododragon-autofill-emails.db";
    tmpFileAutoFillEmails.open("C:\\Windows\\Temp\\bscan-comododragon-autofill-emails.db");
    // check if the bscan-comododragon-autofill emails file exists
    if(tmpFileAutoFillEmails) {
      //if there is read the file   
      rc = sqlite3_open(comododragondb, &bscanDB);
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
      // check if the autofill emails file exists
      fileAutoFillEmails.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillEmails) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-comododragon-autofill-emails.db");
      } else {
        return std::string("could not find file for comododragon browser autofill emails");
      }
 
      rc = sqlite3_open(comododragondb, &bscanDB);
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
        std::cerr << "error find comododragon autofill emails" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found comododragon autofill emails";
  };

  std::string Browser::getComodoDragonAutoFillProfiles() {
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

    char comododragondb[] = "C:\\Windows\\Temp\\bscan-comododragon-autofill-profiles.db";
    tmpFileAutoFillProfiles.open("C:\\Windows\\Temp\\bscan-comododragon-autofill-profiles.db");
    // check if the bscan-comododragon-autofill profiles file exists
    if(tmpFileAutoFillProfiles) {
      //if there is read the file   
      rc = sqlite3_open(comododragondb, &bscanDB);
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
      // check if the autofill profiles file exists
      fileAutoFillProfiles.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillProfiles) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-comododragon-autofill-profiles.db");
      } else {
        return std::string("could not find file for comododragon browser autofill profiles");
      }
 
      rc = sqlite3_open(comododragondb, &bscanDB);
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
        std::cerr << "error find comododragon autofill profiles" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found comododragon autofill profiles";
  };

  std::string Browser::getComodoDragonAutoFillAddresses() {
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

    char comododragondb[] = "C:\\Windows\\Temp\\bscan-comododragon-autofill-addresses.db";
    tmpFileAutoFillAddresses.open("C:\\Windows\\Temp\\bscan-comododragon-autofill-addresses.db");
    // check if the bscan-comododragon-autofill-addresses file exists
    if(tmpFileAutoFillAddresses) {
      //if there is read the file
      rc = sqlite3_open(comododragondb, &bscanDB);
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
      // check if the autofill addresses file exists
      fileAutoFillAddresses.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillAddresses) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-comododragon-autofill-addresses.db");
      } else {
        return std::string("could not find file for comododragon browser autofill addresses");
      }
 
      rc = sqlite3_open(comododragondb, &bscanDB);
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
        std::cerr << "error find comododragon autofill addresses" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found comododragon autofill addresses";
  };

  std::string Browser::getComodoDragonAutoFillPhones() {
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

    char comododragondb[] = "C:\\Windows\\Temp\\bscan-comododragon-autofill-phones.db";
    tmpFileAutoFillPhones.open("C:\\Windows\\Temp\\bscan-comododragon-autofill-phones.db");
    // check if the bscan-comododragon-autoFill-phones file exists
    if(tmpFileAutoFillPhones) {
      //if there is read the file   
      rc = sqlite3_open(comododragondb, &bscanDB);
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
      fileAutoFillPhones.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillPhones) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-comododragon-autofill-phones.db");
      } else {
        return std::string("could not find file for comododragon browser autofill phones");
      }
 
      rc = sqlite3_open(comododragondb, &bscanDB);
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
        std::cerr << "error find comododragon autofill phones" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found comododragon autofill phones";
  };

  std::string Browser::getComodoDragonAutoFillNames() {
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

    char comododragondb[] = "C:\\Windows\\Temp\\bscan-comododragon-autofill-names.db";
    tmpFileAutoFillNames.open("C:\\Windows\\Temp\\bscan-comododragon-autofill-names.db");
    // check if the bscan-comododragon-autofill names file exists
    if(tmpFileAutoFillNames) {
      //if there is read the file   
      rc = sqlite3_open(comododragondb, &bscanDB);
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
      fileAutoFillNames.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillNames) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-comododragon-autofill-names.db");
      } else {
        return std::string("could not find file for comododragon browser autofill names");
      }
 
      rc = sqlite3_open(comododragondb, &bscanDB);
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
        std::cerr << "error find comododragon autofill names" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found comododragon autofill names";
  };
  // TO COMODO ICE DRAGON
  // TODO: path 
  std::string Browser::getComodoIceDragonHistory() {
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

    char comododragondb[] = "C:\\Windows\\Temp\\bscan-comododragon-history.db";
    tmpFileHistory.open("C:\\Windows\\Temp\\bscan-comododragon-history.db");
    // check if the bscan-comododragon-media file exists
    if(tmpFileHistory) {
      //if there is read the file
      rc = sqlite3_open(comododragondb, &bscanDB);
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
      fileHistory.open(pathBSCAN + "/AppData/Roaming/Comodo/IceDragon/Profiles/bgfvsqmc.default/places.sqlite");
      // if it exists move to the specified path
      if(fileHistory) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Comodo/IceDragon/Profiles/bgfvsqmc.default/places.sqlite","C:\\Windows\\Temp\\bscan-comododragon-history.db");
      } else {
        return std::string("could not find file for comododragon browser history");
      }
 
      rc = sqlite3_open(comododragondb, &bscanDB);
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
        std::cerr << "error find comododragon history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found comododragon history";
  };

  std::string Browser::getComodoIceDragonLogin() {
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

    char comodoicedragondb[] = "C:\\Windows\\Temp\\bscan-comodoicedragon-logins.db";
    tmpFileLogins.open("C:\\Windows\\Temp\\bscan-comodoicedragon-logins.db");
    // check if the bscan-comodoicedragon-logins file exists
    if(tmpFileLogins) {
      //if there is read the file   
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
      // check if the logins file exists
      fileLogins.open(pathBSCAN + "/AppData/Roaming/Comodo/IceDragon/Profiles/bgfvsqmc.default");
      // if it exists move to the specified path
      if(fileLogins) {
        fs::copy(pathBSCAN + "/AppData/Roaming/Comodo/IceDragon/Profiles/bgfvsqmc.default/places.sqlite","C:\\Windows\\Temp\\bscan-comodoicedragon-logins.db");
      } else {
        return std::string("could not find file for comodoicedragon browser logins");
      }
 
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
        std::cerr << "error find comodoicedragon logins" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found comodoicedragon logins";
  };

  std::string Browser::getComodoIceDragonShortcuts() {
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

    char comodoicedragondb[] = "C:\\Windows\\Temp\\bscan-comodoicedragon-shortcuts.db";
    tmpFileShortcuts.open("C:\\Windows\\Temp\\bscan-comodoicedragon-shortcuts.db");
    // check if the bscan-comodoicedragon-shortcuts file exists
    if(tmpFileShortcuts) {
      //if there is read the file   
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
      // check if the shortcuts file exists
      fileShortcuts.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Shortcuts");
      // if it exists move to the specified path
      if(fileShortcuts) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Shortcuts","C:\\Windows\\Temp\\bscan-comodoicedragon-shortcuts.db");
      } else {
        return std::string("could not find file for comodoicedragon browser shortcuts");
      }
 
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
        std::cerr << "error find comodoicedragon shortcuts" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found comodoicedragon shortcuts";
  };

  std::string Browser::getComodoIceDragonMemberOf() {
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

    char comodoicedragondb[] = "C:\\Windows\\Temp\\bscan-comodoicedragon-member-of.db";
    tmpFileMemberOf.open("C:\\Windows\\Temp\\bscan-comodoicedragon-member-of.db");
    // check if the bscan-comodoicedragon-member of file exists
    if(tmpFileMemberOf) {
      //if there is read the file   
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
      // check if the member of file exists
      fileMemberOf.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Affiliation Database");
      // if it exists move to the specified path
      if(fileMemberOf) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Affiliation Database","C:\\Windows\\Temp\\bscan-comodoicedragon-member-of.db");
      } else {
        return std::string("could not find file for comodoicedragon browser affiliation");
      }
 
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
        std::cerr << "error find comodoicedragon affiliation" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found comodoicedragon affiliation";
  };

  std::string Browser::getComodoIceDragonAutoFillEmails() {
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

    char comodoicedragondb[] = "C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-emails.db";
    tmpFileAutoFillEmails.open("C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-emails.db");
    // check if the bscan-comodoicedragon-autofill emails file exists
    if(tmpFileAutoFillEmails) {
      //if there is read the file   
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
      // check if the autofill emails file exists
      fileAutoFillEmails.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillEmails) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-emails.db");
      } else {
        return std::string("could not find file for comodoicedragon browser autofill emails");
      }
 
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
        std::cerr << "error find comodoicedragon autofill emails" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found comodoicedragon autofill emails";
  };

  std::string Browser::getComodoIceDragonAutoFillProfiles() {
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

    char comodoicedragondb[] = "C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-profiles.db";
    tmpFileAutoFillProfiles.open("C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-profiles.db");
    // check if the bscan-comodoicedragon-autofill profiles file exists
    if(tmpFileAutoFillProfiles) {
      //if there is read the file   
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
      // check if the autofill profiles file exists
      fileAutoFillProfiles.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillProfiles) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-profiles.db");
      } else {
        return std::string("could not find file for comodoicedragon browser autofill profiles");
      }
 
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
        std::cerr << "error find comodoicedragon autofill profiles" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found comodoicedragon autofill profiles";
  };

  std::string Browser::getComodoIceDragonAutoFillAddresses() {
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

    char comodoicedragondb[] = "C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-addresses.db";
    tmpFileAutoFillAddresses.open("C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-addresses.db");
    // check if the bscan-comodoicedragon-autofill-addresses file exists
    if(tmpFileAutoFillAddresses) {
      //if there is read the file
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
      // check if the autofill addresses file exists
      fileAutoFillAddresses.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillAddresses) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-addresses.db");
      } else {
        return std::string("could not find file for comodoicedragon browser autofill addresses");
      }
 
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
        std::cerr << "error find comodoicedragon autofill addresses" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found comodoicedragon autofill addresses";
  };

  std::string Browser::getComodoIceDragonAutoFillPhones() {
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

    char comodoicedragondb[] = "C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-phones.db";
    tmpFileAutoFillPhones.open("C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-phones.db");
    // check if the bscan-comodoicedragon-autoFill-phones file exists
    if(tmpFileAutoFillPhones) {
      //if there is read the file   
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
      fileAutoFillPhones.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillPhones) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-phones.db");
      } else {
        return std::string("could not find file for comodoicedragon browser autofill phones");
      }
 
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
        std::cerr << "error find comodoicedragon autofill phones" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found comodoicedragon autofill phones";
  };

  std::string Browser::getComodoIceDragonAutoFillNames() {
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

    char comodoicedragondb[] = "C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-names.db";
    tmpFileAutoFillNames.open("C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-names.db");
    // check if the bscan-comodoicedragon-autofill names file exists
    if(tmpFileAutoFillNames) {
      //if there is read the file   
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
      fileAutoFillNames.open(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillNames) {
        fs::copy(pathBSCAN + "/AppData/Local/Comodo/Dragon/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-comodoicedragon-autofill-names.db");
      } else {
        return std::string("could not find file for comodoicedragon browser autofill names");
      }
 
      rc = sqlite3_open(comodoicedragondb, &bscanDB);
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
        std::cerr << "error find comodoicedragon autofill names" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found comodoicedragon autofill names";
  };
  // TO 360 CHROME X
  std::string Browser::get360ChromeXHistory() {
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

    char chromexdb[] = "C:\\Windows\\Temp\\bscan-chromex-history.db";
    tmpFileHistory.open("C:\\Windows\\Temp\\bscan-chromex-history.db");
    // check if the bscan-chromex-media file exists
    if(tmpFileHistory) {
      //if there is read the file
      rc = sqlite3_open(chromexdb, &bscanDB);
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
      fileHistory.open(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/360History");
      // if it exists move to the specified path
      if(fileHistory) {
        fs::copy(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/360History","C:\\Windows\\Temp\\bscan-chromex-history.db");
      } else {
        return std::string("could not find file for chromex browser history");
      }
 
      rc = sqlite3_open(chromexdb, &bscanDB);
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
        std::cerr << "error find chromex history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found chromex history";
  };

  std::string Browser::get360ChromeXLogin() {
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

    char chromexdb[] = "C:\\Windows\\Temp\\bscan-chromex-logins.db";
    tmpFileLogins.open("C:\\Windows\\Temp\\bscan-chromex-logins.db");
    // check if the bscan-chromex-logins file exists
    if(tmpFileLogins) {
      //if there is read the file   
      rc = sqlite3_open(chromexdb, &bscanDB);
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
      // check if the logins file exists
      fileLogins.open(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Login Data");
      // if it exists move to the specified path
      if(fileLogins) {
        fs::copy(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Login Data","C:\\Windows\\Temp\\bscan-chromex-logins.db");
      } else {
        return std::string("could not find file for chromex browser logins");
      }
 
      rc = sqlite3_open(chromexdb, &bscanDB);
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
        std::cerr << "error find chromex logins" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found chromex logins";
  };

  std::string Browser::get360ChromeXShortcuts() {
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

    char chromexdb[] = "C:\\Windows\\Temp\\bscan-chromex-shortcuts.db";
    tmpFileShortcuts.open("C:\\Windows\\Temp\\bscan-chromex-shortcuts.db");
    // check if the bscan-chromex-shortcuts file exists
    if(tmpFileShortcuts) {
      //if there is read the file   
      rc = sqlite3_open(chromexdb, &bscanDB);
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
      // check if the shortcuts file exists
      fileShortcuts.open(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Shortcuts");
      // if it exists move to the specified path
      if(fileShortcuts) {
        fs::copy(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Shortcuts","C:\\Windows\\Temp\\bscan-chromex-shortcuts.db");
      } else {
        return std::string("could not find file for chromex browser shortcuts");
      }
 
      rc = sqlite3_open(chromexdb, &bscanDB);
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
        std::cerr << "error find chromex shortcuts" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found chromex shortcuts";
  };

  std::string Browser::get360ChromeXMemberOf() {
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

    char chromexdb[] = "C:\\Windows\\Temp\\bscan-chromex-member-of.db";
    tmpFileMemberOf.open("C:\\Windows\\Temp\\bscan-chromex-member-of.db");
    // check if the bscan-chromex-member of file exists
    if(tmpFileMemberOf) {
      //if there is read the file   
      rc = sqlite3_open(chromexdb, &bscanDB);
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
      // check if the member of file exists
      fileMemberOf.open(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Affiliation Database");
      // if it exists move to the specified path
      if(fileMemberOf) {
        fs::copy(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Affiliation Database","C:\\Windows\\Temp\\bscan-chromex-member-of.db");
      } else {
        return std::string("could not find file for chromex browser affiliation");
      }
 
      rc = sqlite3_open(chromexdb, &bscanDB);
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
        std::cerr << "error find chromex affiliation" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found chromex affiliation";
  };

  std::string Browser::get360ChromeXAutoFillEmails() {
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

    char chromexdb[] = "C:\\Windows\\Temp\\bscan-chromex-autofill-emails.db";
    tmpFileAutoFillEmails.open("C:\\Windows\\Temp\\bscan-chromex-autofill-emails.db");
    // check if the bscan-chromex-autofill emails file exists
    if(tmpFileAutoFillEmails) {
      //if there is read the file   
      rc = sqlite3_open(chromexdb, &bscanDB);
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
      // check if the autofill emails file exists
      fileAutoFillEmails.open(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillEmails) {
        fs::copy(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-chromex-autofill-emails.db");
      } else {
        return std::string("could not find file for chromex browser autofill emails");
      }
 
      rc = sqlite3_open(chromexdb, &bscanDB);
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
        std::cerr << "error find chromex autofill emails" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found chromex autofill emails";
  };

  std::string Browser::get360ChromeXAutoFillProfiles() {
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

    char chromexdb[] = "C:\\Windows\\Temp\\bscan-chromex-autofill-profiles.db";
    tmpFileAutoFillProfiles.open("C:\\Windows\\Temp\\bscan-chromex-autofill-profiles.db");
    // check if the bscan-chromex-autofill profiles file exists
    if(tmpFileAutoFillProfiles) {
      //if there is read the file   
      rc = sqlite3_open(chromexdb, &bscanDB);
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
      // check if the autofill profiles file exists
      fileAutoFillProfiles.open(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillProfiles) {
        fs::copy(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-chromex-autofill-profiles.db");
      } else {
        return std::string("could not find file for chromex browser autofill profiles");
      }
 
      rc = sqlite3_open(chromexdb, &bscanDB);
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
        std::cerr << "error find chromex autofill profiles" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found chromex autofill profiles";
  };

  std::string Browser::get360ChromeXAutoFillAddresses() {
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

    char chromexdb[] = "C:\\Windows\\Temp\\bscan-chromex-autofill-addresses.db";
    tmpFileAutoFillAddresses.open("C:\\Windows\\Temp\\bscan-chromex-autofill-addresses.db");
    // check if the bscan-chromex-autofill-addresses file exists
    if(tmpFileAutoFillAddresses) {
      //if there is read the file
      rc = sqlite3_open(chromexdb, &bscanDB);
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
      // check if the autofill addresses file exists
      fileAutoFillAddresses.open(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillAddresses) {
        fs::copy(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-chromex-autofill-addresses.db");
      } else {
        return std::string("could not find file for chromex browser autofill addresses");
      }
 
      rc = sqlite3_open(chromexdb, &bscanDB);
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
        std::cerr << "error find chromex autofill addresses" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found chromex autofill addresses";
  };

  std::string Browser::get360ChromeXAutoFillPhones() {
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

    char chromexdb[] = "C:\\Windows\\Temp\\bscan-chromex-autofill-phones.db";
    tmpFileAutoFillPhones.open("C:\\Windows\\Temp\\bscan-chromex-autofill-phones.db");
    // check if the bscan-chromex-autoFill-phones file exists
    if(tmpFileAutoFillPhones) {
      //if there is read the file   
      rc = sqlite3_open(chromexdb, &bscanDB);
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
      fileAutoFillPhones.open(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillPhones) {
        fs::copy(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-chromex-autofill-phones.db");
      } else {
        return std::string("could not find file for chromex browser autofill phones");
      }
 
      rc = sqlite3_open(chromexdb, &bscanDB);
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
        std::cerr << "error find chromex autofill phones" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found chromex autofill phones";
  };

  std::string Browser::get360ChromeXAutoFillNames() {
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

    char chromexdb[] = "C:\\Windows\\Temp\\bscan-chromex-autofill-names.db";
    tmpFileAutoFillNames.open("C:\\Windows\\Temp\\bscan-chromex-autofill-names.db");
    // check if the bscan-chromex-autofill names file exists
    if(tmpFileAutoFillNames) {
      //if there is read the file   
      rc = sqlite3_open(chromexdb, &bscanDB);
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
      fileAutoFillNames.open(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillNames) {
        fs::copy(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-chromex-autofill-names.db");
      } else {
        return std::string("could not find file for chromex browser autofill names");
      }
 
      rc = sqlite3_open(chromexdb, &bscanDB);
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
        std::cerr << "error find chromex autofill names" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found chromex autofill names";
  };
  // TO WATERFOX
  // TODO: path 
  std::string Browser::getWaterfoxHistory() {
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

    char waterfoxdb[] = "C:\\Windows\\Temp\\bscan-waterfox-history.db";
    tmpFileHistory.open("C:\\Windows\\Temp\\bscan-waterfox-history.db");
    // check if the bscan-waterfox-media file exists
    if(tmpFileHistory) {
      //if there is read the file
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
      fileHistory.open(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/360History");
      // if it exists move to the specified path
      if(fileHistory) {
        fs::copy(pathBSCAN + "/AppData/Local/360ChromeX/Chrome/User Data/Default/360History","C:\\Windows\\Temp\\bscan-waterfox-history.db");
      } else {
        return std::string("could not find file for waterfox browser history");
      }
 
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
        std::cerr << "error find waterfox history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found waterfox history";
  };

  std::string Browser::getWaterfoxLogin() {
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

    char waterfoxdb[] = "C:\\Windows\\Temp\\bscan-waterfox-logins.db";
    tmpFileLogins.open("C:\\Windows\\Temp\\bscan-waterfox-logins.db");
    // check if the bscan-waterfox-logins file exists
    if(tmpFileLogins) {
      //if there is read the file   
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
      // check if the logins file exists
      fileLogins.open(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Login Data");
      // if it exists move to the specified path
      if(fileLogins) {
        fs::copy(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Login Data","C:\\Windows\\Temp\\bscan-waterfox-logins.db");
      } else {
        return std::string("could not find file for waterfox browser logins");
      }
 
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
        std::cerr << "error find waterfox logins" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found waterfox logins";
  };

  std::string Browser::getWaterfoxShortcuts() {
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

    char waterfoxdb[] = "C:\\Windows\\Temp\\bscan-waterfox-shortcuts.db";
    tmpFileShortcuts.open("C:\\Windows\\Temp\\bscan-waterfox-shortcuts.db");
    // check if the bscan-waterfox-shortcuts file exists
    if(tmpFileShortcuts) {
      //if there is read the file   
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
      // check if the shortcuts file exists
      fileShortcuts.open(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Shortcuts");
      // if it exists move to the specified path
      if(fileShortcuts) {
        fs::copy(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Shortcuts","C:\\Windows\\Temp\\bscan-waterfox-shortcuts.db");
      } else {
        return std::string("could not find file for waterfox browser shortcuts");
      }
 
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
        std::cerr << "error find waterfox shortcuts" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found waterfox shortcuts";
  };

  std::string Browser::getWaterfoxMemberOf() {
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

    char waterfoxdb[] = "C:\\Windows\\Temp\\bscan-waterfox-member-of.db";
    tmpFileMemberOf.open("C:\\Windows\\Temp\\bscan-waterfox-member-of.db");
    // check if the bscan-waterfox-member of file exists
    if(tmpFileMemberOf) {
      //if there is read the file   
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
      // check if the member of file exists
      fileMemberOf.open(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Affiliation Database");
      // if it exists move to the specified path
      if(fileMemberOf) {
        fs::copy(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Affiliation Database","C:\\Windows\\Temp\\bscan-waterfox-member-of.db");
      } else {
        return std::string("could not find file for waterfox browser affiliation");
      }
 
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
        std::cerr << "error find waterfox affiliation" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found waterfox affiliation";
  };

  std::string Browser::getWaterfoxAutoFillEmails() {
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

    char waterfoxdb[] = "C:\\Windows\\Temp\\bscan-waterfox-autofill-emails.db";
    tmpFileAutoFillEmails.open("C:\\Windows\\Temp\\bscan-waterfox-autofill-emails.db");
    // check if the bscan-waterfox-autofill emails file exists
    if(tmpFileAutoFillEmails) {
      //if there is read the file   
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
      // check if the autofill emails file exists
      fileAutoFillEmails.open(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillEmails) {
        fs::copy(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-waterfox-autofill-emails.db");
      } else {
        return std::string("could not find file for waterfox browser autofill emails");
      }
 
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
        std::cerr << "error find waterfox autofill emails" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found waterfox autofill emails";
  };

  std::string Browser::getWaterfoxAutoFillProfiles() {
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

    char waterfoxdb[] = "C:\\Windows\\Temp\\bscan-waterfox-autofill-profiles.db";
    tmpFileAutoFillProfiles.open("C:\\Windows\\Temp\\bscan-waterfox-autofill-profiles.db");
    // check if the bscan-waterfox-autofill profiles file exists
    if(tmpFileAutoFillProfiles) {
      //if there is read the file   
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
      // check if the autofill profiles file exists
      fileAutoFillProfiles.open(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillProfiles) {
        fs::copy(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-waterfox-autofill-profiles.db");
      } else {
        return std::string("could not find file for waterfox browser autofill profiles");
      }
 
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
        std::cerr << "error find waterfox autofill profiles" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found waterfox autofill profiles";
  };

  std::string Browser::getWaterfoxAutoFillAddresses() {
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

    char waterfoxdb[] = "C:\\Windows\\Temp\\bscan-waterfox-autofill-addresses.db";
    tmpFileAutoFillAddresses.open("C:\\Windows\\Temp\\bscan-waterfox-autofill-addresses.db");
    // check if the bscan-waterfox-autofill-addresses file exists
    if(tmpFileAutoFillAddresses) {
      //if there is read the file
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
      // check if the autofill addresses file exists
      fileAutoFillAddresses.open(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillAddresses) {
        fs::copy(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-waterfox-autofill-addresses.db");
      } else {
        return std::string("could not find file for waterfox browser autofill addresses");
      }
 
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
        std::cerr << "error find waterfox autofill addresses" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found waterfox autofill addresses";
  };

  std::string Browser::getWaterfoxAutoFillPhones() {
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

    char waterfoxdb[] = "C:\\Windows\\Temp\\bscan-waterfox-autofill-phones.db";
    tmpFileAutoFillPhones.open("C:\\Windows\\Temp\\bscan-waterfox-autofill-phones.db");
    // check if the bscan-waterfox-autoFill-phones file exists
    if(tmpFileAutoFillPhones) {
      //if there is read the file   
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
      fileAutoFillPhones.open(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillPhones) {
        fs::copy(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-waterfox-autofill-phones.db");
      } else {
        return std::string("could not find file for waterfox browser autofill phones");
      }
 
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
        std::cerr << "error find waterfox autofill phones" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found waterfox autofill phones";
  };

  std::string Browser::getWaterfoxAutoFillNames() {
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

    char waterfoxdb[] = "C:\\Windows\\Temp\\bscan-waterfox-autofill-names.db";
    tmpFileAutoFillNames.open("C:\\Windows\\Temp\\bscan-waterfox-autofill-names.db");
    // check if the bscan-waterfox-autofill names file exists
    if(tmpFileAutoFillNames) {
      //if there is read the file   
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
      fileAutoFillNames.open(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillNames) {
        fs::copy(pathBSCAN + "/AppData/Local/360waterfox/Chrome/User Data/Default/Web Data","C:\\Windows\\Temp\\bscan-waterfox-autofill-names.db");
      } else {
        return std::string("could not find file for waterfox browser autofill names");
      }
 
      rc = sqlite3_open(waterfoxdb, &bscanDB);
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
        std::cerr << "error find waterfox autofill names" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found waterfox autofill names";
  };
  // TO BLISK BARD
  // TODO: fixed bug in path files
  std::string Browser::getBriskBardHistory() {
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

    char briskbarddb[] = "C:\\Windows\\Temp\\bscan-briskbard-history.db";
    tmpFileHistory.open("C:\\Windows\\Temp\\bscan-briskbard-history.db");
    // check if the bscan-briskbard-media file exists
    if(tmpFileHistory) {
      //if there is read the file
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
      fileHistory.open(pathBSCAN + "/AppData/Local/BriskBard/cache");
      // if it exists move to the specified path
      if(fileHistory) {
        fs::copy(pathBSCAN + "/AppData/Local/BriskBard/cache/History","C:\\Windows\\Temp\\bscan-briskbard-history.db");
      } else {
        return std::string("could not find file for briskbard browser history");
      }
 
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
        std::cerr << "error find briskbard history" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found briskbard history";
  };

  std::string Browser::getBriskBardLogin() {
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

    char briskbarddb[] = "C:\\Windows\\Temp\\bscan-briskbard-logins.db";
    tmpFileLogins.open("C:\\Windows\\Temp\\bscan-briskbard-logins.db");
    // check if the bscan-briskbard-logins file exists
    if(tmpFileLogins) {
      //if there is read the file   
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
      // check if the logins file exists
      fileLogins.open(pathBSCAN + "/AppData/Local/BriskBard/cache/Login Data");
      // if it exists move to the specified path
      if(fileLogins) {
        fs::copy(pathBSCAN + "/AppData/Local/BriskBard/cache/Login Data","C:\\Windows\\Temp\\bscan-briskbard-logins.db");
      } else {
        return std::string("could not find file for briskbard browser logins");
      }
 
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
        std::cerr << "error find briskbard logins" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found briskbard logins";
  };

  std::string Browser::getBriskBardShortcuts() {
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

    char briskbarddb[] = "C:\\Windows\\Temp\\bscan-briskbard-shortcuts.db";
    tmpFileShortcuts.open("C:\\Windows\\Temp\\bscan-briskbard-shortcuts.db");
    // check if the bscan-briskbard-shortcuts file exists
    if(tmpFileShortcuts) {
      //if there is read the file   
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
      // check if the shortcuts file exists
      fileShortcuts.open(pathBSCAN + "/AppData/Local/BriskBard/cache/Shortcuts");
      // if it exists move to the specified path
      if(fileShortcuts) {
        fs::copy(pathBSCAN + "/AppData/Local/BriskBard/cache/Shortcuts","C:\\Windows\\Temp\\bscan-briskbard-shortcuts.db");
      } else {
        return std::string("could not find file for briskbard browser shortcuts");
      }
 
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
        std::cerr << "error find briskbard shortcuts" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found briskbard shortcuts";
  };

  std::string Browser::getBriskBardMemberOf() {
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

    char briskbarddb[] = "C:\\Windows\\Temp\\bscan-briskbard-member-of.db";
    tmpFileMemberOf.open("C:\\Windows\\Temp\\bscan-briskbard-member-of.db");
    // check if the bscan-briskbard-member of file exists
    if(tmpFileMemberOf) {
      //if there is read the file   
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
      // check if the member of file exists
      fileMemberOf.open(pathBSCAN + "/AppData/Local/BriskBard/cache/Affiliation Database");
      // if it exists move to the specified path
      if(fileMemberOf) {
        fs::copy(pathBSCAN + "/AppData/Local/BriskBard/cache/Affiliation Database","C:\\Windows\\Temp\\bscan-briskbard-member-of.db");
      } else {
        return std::string("could not find file for briskbard browser affiliation");
      }
 
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
        std::cerr << "error find briskbard affiliation" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found briskbard affiliation";
  };

  std::string Browser::getBriskBardAutoFillEmails() {
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

    char briskbarddb[] = "C:\\Windows\\Temp\\bscan-briskbard-autofill-emails.db";
    tmpFileAutoFillEmails.open("C:\\Windows\\Temp\\bscan-briskbard-autofill-emails.db");
    // check if the bscan-briskbard-autofill emails file exists
    if(tmpFileAutoFillEmails) {
      //if there is read the file   
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
      // check if the autofill emails file exists
      fileAutoFillEmails.open(pathBSCAN + "/AppData/Local/BriskBard/cache/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillEmails) {
        fs::copy(pathBSCAN + "/AppData/Local/BriskBard/cache/Web Data","C:\\Windows\\Temp\\bscan-briskbard-autofill-emails.db");
      } else {
        return std::string("could not find file for briskbard browser autofill emails");
      }
 
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
        std::cerr << "error find briskbard autofill emails" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found briskbard autofill emails";
  };

  std::string Browser::getBriskBardAutoFillProfiles() {
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

    char briskbarddb[] = "C:\\Windows\\Temp\\bscan-briskbard-autofill-profiles.db";
    tmpFileAutoFillProfiles.open("C:\\Windows\\Temp\\bscan-briskbard-autofill-profiles.db");
    // check if the bscan-briskbard-autofill profiles file exists
    if(tmpFileAutoFillProfiles) {
      //if there is read the file   
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
      // check if the autofill profiles file exists
      fileAutoFillProfiles.open(pathBSCAN + "/AppData/Local/BriskBard/cache/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillProfiles) {
        fs::copy(pathBSCAN + "/AppData/Local/BriskBard/cache/Web Data","C:\\Windows\\Temp\\bscan-briskbard-autofill-profiles.db");
      } else {
        return std::string("could not find file for briskbard browser autofill profiles");
      }
 
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
        std::cerr << "error find briskbard autofill profiles" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };

    return "successfully found briskbard autofill profiles";
  };

  std::string Browser::getBriskBardAutoFillAddresses() {
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

    char briskbarddb[] = "C:\\Windows\\Temp\\bscan-briskbard-autofill-addresses.db";
    tmpFileAutoFillAddresses.open("C:\\Windows\\Temp\\bscan-briskbard-autofill-addresses.db");
    // check if the bscan-briskbard-autofill-addresses file exists
    if(tmpFileAutoFillAddresses) {
      //if there is read the file
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
      // check if the autofill addresses file exists
      fileAutoFillAddresses.open(pathBSCAN + "/AppData/Local/BriskBard/cache/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillAddresses) {
        fs::copy(pathBSCAN + "/AppData/Local/BriskBard/cache/Web Data","C:\\Windows\\Temp\\bscan-briskbard-autofill-addresses.db");
      } else {
        return std::string("could not find file for briskbard browser autofill addresses");
      }
 
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
        std::cerr << "error find briskbard autofill addresses" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found briskbard autofill addresses";
  };

  std::string Browser::getBriskBardAutoFillPhones() {
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

    char briskbarddb[] = "C:\\Windows\\Temp\\bscan-briskbard-autofill-phones.db";
    tmpFileAutoFillPhones.open("C:\\Windows\\Temp\\bscan-briskbard-autofill-phones.db");
    // check if the bscan-briskbard-autoFill-phones file exists
    if(tmpFileAutoFillPhones) {
      //if there is read the file   
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
      fileAutoFillPhones.open(pathBSCAN + "/AppData/Local/BriskBard/cache/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillPhones) {
        fs::copy(pathBSCAN + "/AppData/Local/BriskBard/cache/Web Data","C:\\Windows\\Temp\\bscan-briskbard-autofill-phones.db");
      } else {
        return std::string("could not find file for briskbard browser autofill phones");
      }
 
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
        std::cerr << "error find briskbard autofill phones" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found briskbard autofill phones";
  };

  std::string Browser::getBriskBardAutoFillNames() {
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

    char briskbarddb[] = "C:\\Windows\\Temp\\bscan-briskbard-autofill-names.db";
    tmpFileAutoFillNames.open("C:\\Windows\\Temp\\bscan-briskbard-autofill-names.db");
    // check if the bscan-briskbard-autofill names file exists
    if(tmpFileAutoFillNames) {
      //if there is read the file   
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
      fileAutoFillNames.open(pathBSCAN + "/AppData/Local/BriskBard/cache/Web Data");
      // if it exists move to the specified path
      if(fileAutoFillNames) {
        fs::copy(pathBSCAN + "/AppData/Local/BriskBard/cache/Web Data","C:\\Windows\\Temp\\bscan-briskbard-autofill-names.db");
      } else {
        return std::string("could not find file for briskbard browser autofill names");
      }
 
      rc = sqlite3_open(briskbarddb, &bscanDB);
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
        std::cerr << "error find briskbard autofill names" << std::endl;
        sqlite3_free(zErrMsg);
      }
      else
        std::cout << stdout << std::endl;
      sqlite3_close(bscanDB);
    };
    
    return "successfully found briskbard autofill names";
  };
  //todo: make media


};

#endif  // END BSCAN_WINDOWS