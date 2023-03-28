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
    std::string pkgs();
    std::string user();
    std::string log();
    std::string envvariables();
    std::string kernel();
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
    static std::string getPkgs();
    static std::string getUser();
    static std::string getLog();
    static std::string getEnvVariables();
    static std::string getKernel();
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
    std::string _pkgs;
    std::string _user;
    std::string _log;
    std::string _envvariables;
    std::string _kernel;
    bool _32bit = false;
    bool _64bit = false;
    bool _bigEndian = false;
    bool _littleEndian = false;
  };

};
