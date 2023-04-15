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
#pragma once

#include <string>
#include <vector>

namespace bscan {

  class OS {
   public:
    OS();
    ~OS() = default;

    std::string fullName();
    std::string name();
    std::string version();
    std::string hostname();
    std::string domainname();
    std::string uptime();
    std::string homedir();
    std::string recentitems();
    std::string programfiles();
    std::string documents();
    std::string personaldocuments();
    std::string publicdocuments();
    std::string searcheseverywhere();
    std::string desktop();
    std::string downloads();
    std::string musics();
    std::string videos();
    std::string startmenu();
    std::string imagescam();
    std::string imagessaved();
    std::string images();
    std::string historypowershell();
    std::vector<std::string> programsandresources();
    std::string pkgs();
    std::string user();
    std::string log();
    std::string envvariables();
    std::string accountname();
    std::string accountloginid();
    std::string type();
    std::string fulltype();
    std::string servicepath();
    std::string bootdir();
    std::string boottempdir();
    std::string bootlastdrive();
    std::string productidentificationcode();
    std::string productidentificationname();
    std::string productidentificationversion();
    std::string pathsystemdriver();
    std::string productidentificationuuid();
    std::string timez();
    std::string status();
    std::string kernel();
    int64_t users();
    int64_t processes();
    int64_t maxProcessMemory();
    [[nodiscard]] bool is32bit() const;
    [[nodiscard]] bool is64bit() const;
    [[nodiscard]] bool isBigEndian() const;
    [[nodiscard]] bool isLittleEndian() const;

    static std::string getFullName();
    static std::string getName();
    static std::string getVersion();
    static std::string getHostname();
    static std::string getDomainName();
    static std::string getUptime();
    static std::string listHomeDir();
    static std::string listRecentItems();
    static std::string listProgramFiles();
    static std::string listDocuments();
    static std::string listPersonalDocuments();
    static std::string listPublicDocuments();
    static std::string listSearchesEverywhere();
    static std::string listDesktop();
    static std::string listDownloads();
    static std::string listMusics();
    static std::string listVideos();
    static std::string listStartMenu();
    static std::string getImagesCAM();
    static std::string getImagesSaved();
    static std::string getImages();
    static std::string getHistoryPowerShell();
    static std::vector<std::string> getProgramsAndResources();
    static std::string getPkgs();
    static std::string getUser();
    static std::string getLog();
    static std::string getEnvVariables();
    static std::string getAccountName();
    static std::string getAccountLoginID();
    static std::string getType();
    static std::string getFullType();
    static std::string getServicePath();
    static std::string getBootDir();
    static std::string getBootTempDir();
    static std::string getBootLastDrive();
    static std::string getProductIdentificationCode();
    static std::string getProductIdentificationName();
    static std::string getProductIdentificationVersion();
    static std::string getPathSystemDriver();
    static std::string getProductIdentificationUUID();
    static std::string getTimeZone();
    static std::string getStatus();
    static std::string getKernel();
    static int64_t getUsers();
    static int64_t getProcesses();
    static int64_t getMaxProcessMemory();
    static bool getIs32bit();
    static bool getIs64bit();
    static bool getIsBigEndian();
    static bool getIsLittleEndian();

   private:
    std::string _fullName;
    std::string _name;
    std::string _version;
    std::string _hostname;
    std::string _domainname;
    std::string _uptime;
    std::string _homedir;
    std::string _recentitems;
    std::string _programfiles;
    std::string _documents;
    std::string _personaldocuments;
    std::string _publicdocuments;
    std::string _searcheseverywhere;
    std::string _desktop;
    std::string _downloads;
    std::string _musics;
    std::string _videos;
    std::string _startmenu;
    std::string _imagescam;
    std::string _imagessaved;
    std::string _images;
    std::string _historypowershell;
    std::vector<std::string> _programsandresources;
    std::string _pkgs;
    std::string _user;
    std::string _log;
    std::string _envvariables;
    std::string _accountname;
    std::string _accountloginid;
    std::string _type;
    std::string _fulltype;
    std::string _servicepath;
    std::string _bootdir;
    std::string _boottempdir;
    std::string _bootlastdrive;
    std::string _productidentificationcode;
    std::string _productidentificationname;
    std::string _productidentificationversion;
    std::string _pathsystemdriver;
    std::string _productidentificationuuid;
    std::string _timez;
    std::string _status;
    std::string _kernel;
    int64_t _users;
    int64_t _processes;
    int64_t _maxProcessMemory;
    bool _32bit = false;
    bool _64bit = false;
    bool _bigEndian = false;
    bool _littleEndian = false;
  };

};
