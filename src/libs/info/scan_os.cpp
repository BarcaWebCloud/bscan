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
#include "swares/scan_os.h"
#include <string>

namespace bscan {

  OS::OS() {
    _32bit = getIs32bit();
    _64bit = getIs64bit();
    _bigEndian = getIsBigEndian();
    _littleEndian = !_bigEndian;
  }

  std::string OS::fullName() {
    if (_fullName.empty()) {
      _fullName = getFullName();
    }
    return _fullName;
  }

  std::string OS::name() {
    if (_name.empty()) {
      _name = getName();
    }
    return _name;
  }

  std::string OS::version() {
    if (_version.empty()) {
      _version = getVersion();
    }
    return _version;
  }

  std::string OS::hostname() {
    if (_hostname.empty()) {
      _hostname = getHostname();
    }
    return _hostname;
  }

  // std::string OS::domainname() {
  //   if (_domainname.empty()) {
  //     _domainname = getDomainName();
  //   }
  //   return _domainname;
  // }

  // std::string OS::uptime() {
  //   if (_uptime.empty()) {
  //     _uptime = getUptime();
  //   }
  //   return _uptime;
  // }

  std::string OS::homedir() {
    if (_homedir.empty()) {
      _homedir = listHomeDir();
    }
    return _homedir;
  }

  std::string OS::recentitems() {
    if (_recentitems.empty()) {
      _recentitems = listRecentItems();
    }
    return _recentitems;
  }

  std::string OS::deleteddata() {
    if (_deleteddata.empty()) {
      _deleteddata = listDeletedData();
    }
    return _deleteddata;
  }

  std::string OS::programfiles() {
    if (_programfiles.empty()) {
      _programfiles = listProgramFiles();
    }
    return _programfiles;
  }

  std::string OS::documents() {
    if (_documents.empty()) {
      _documents = listDocuments();
    }
    return _documents;
  }

  std::string OS::personaldocuments() {
    if (_personaldocuments.empty()) {
      _personaldocuments = listPersonalDocuments();
    }
    return _personaldocuments;
  }

  std::string OS::publicdocuments() {
    if (_publicdocuments.empty()) {
      _publicdocuments = listPublicDocuments();
    }
    return _publicdocuments;
  }

  std::string OS::searcheseverywhere() {
    if (_searcheseverywhere.empty()) {
      _searcheseverywhere = listSearchesEverywhere();
    }
    return _searcheseverywhere;
  }

  std::string OS::desktop() {
    if (_desktop.empty()) {
      _desktop = listDesktop();
    }
    return _desktop;
  }

  std::string OS::downloads() {
    if (_downloads.empty()) {
      _downloads = listDownloads();
    }
    return _downloads;
  }

  std::string OS::musics() {
    if (_musics.empty()) {
      _musics = listMusics();
    }
    return _musics;
  }

  std::string OS::videos() {
    if (_videos.empty()) {
      _videos = listVideos();
    }
    return _videos;
  }

  std::string OS::startmenu() {
    if (_startmenu.empty()) {
      _startmenu = listStartMenu();
    }
    return _startmenu;
  }

  std::string OS::imagescam() {
    if (_imagescam.empty()) {
      _imagescam = getImagesCAM();
    }
    return _imagescam;
  }

  std::string OS::imagessaved() {
    if (_imagessaved.empty()) {
      _imagessaved = getImagesSaved();
    }
    return _imagessaved;
  }

  std::string OS::images() {
    if (_images.empty()) {
      _images = getImages();
    }
    return _images;
  }

  std::string OS::historypowershell() {
    if (_historypowershell.empty()) {
      _historypowershell = getHistoryPowerShell();
    }
    return _historypowershell;
  }

  std::vector<std::string> OS::programsandresources() {
    if (_programsandresources.empty()) {
      _programsandresources = getProgramsAndResources();
    }
    return _programsandresources;
  }

  std::string OS::envvariables() {
    if (_envvariables.empty()) {
      _envvariables = getEnvVariables();
    }
    return _envvariables;
  }

  std::string OS::accountname() {
    if (_accountname.empty()) {
      _accountname = getAccountName();
    }
    return _accountname;
  }

  std::string OS::accountloginid() {
    if (_accountloginid.empty()) {
      _accountloginid = getAccountLoginID();
    }
    return _accountloginid;
  }

  std::string OS::type() {
    if (_type.empty()) {
      _type = getType();
    }
    return _type;
  }

  std::string OS::fulltype() {
    if (_fulltype.empty()) {
      _fulltype = getFullType();
    }
    return _fulltype;
  }

  std::string OS::servicepath() {
    if (_servicepath.empty()) {
      _servicepath = getServicePath();
    }
    return _servicepath;
  }

  std::string OS::bootdir() {
    if (_bootdir.empty()) {
      _bootdir = getBootDir();
    }
    return _bootdir;
  }

  std::string OS::boottempdir() {
    if (_boottempdir.empty()) {
      _boottempdir = getBootTempDir();
    }
    return _boottempdir;
  }

  std::string OS::bootlastdrive() {
    if (_bootlastdrive.empty()) {
      _bootlastdrive = getBootLastDrive();
    }
    return _bootlastdrive;
  }

  std::string OS::productidentificationcode() {
    if (_productidentificationcode.empty()) {
      _productidentificationcode = getProductIdentificationCode();
    }
    return _productidentificationcode;
  }

  std::string OS::productidentificationname() {
    if (_productidentificationname.empty()) {
      _productidentificationname = getProductIdentificationName();
    }
    return _productidentificationname;
  }

  std::string OS::productidentificationversion() {
    if (_productidentificationversion.empty()) {
      _productidentificationversion = getProductIdentificationVersion();
    }
    return _productidentificationversion;
  }

  std::string OS::pathsystemdriver() {
    if (_pathsystemdriver.empty()) {
      _pathsystemdriver = getPathSystemDriver();
    }
    return _pathsystemdriver;
  }

  std::string OS::productidentificationuuid() {
    if (_productidentificationuuid.empty()) {
      _productidentificationuuid = getProductIdentificationUUID();
    }
    return _productidentificationuuid;
  }

  std::string OS::timez() {
    if (_timez.empty()) {
      _timez = getTimeZone();
    }
    return _timez;
  }

  std::string OS::status() {
    if (_status.empty()) {
      _status = getStatus();
    }
    return _status;
  }

  std::string OS::kernel() {
    if (_kernel.empty()) {
      _kernel = getKernel();
    }
    return _kernel;
  }

  int64_t OS::maxProcessMemory() {
    if (_maxProcessMemory == -1) {
      _maxProcessMemory = getMaxProcessMemory();
    }
    return _maxProcessMemory;
  }

  int64_t OS::users() {
    if (_users == -1) {
      _users = getUsers();
    }
    return _users;
  }

  int64_t OS::processes() {
    if (_processes == -1) {
      _processes = getProcesses();
    }
    return _processes;
  }

  bool OS::is32bit() const { return _32bit; }
  bool OS::is64bit() const { return _64bit; }
  bool OS::isBigEndian() const { return _bigEndian; }
  bool OS::isLittleEndian() const { return _littleEndian; }
  bool OS::getIs32bit() { return !getIs64bit(); }
  bool OS::getIsBigEndian() {
    char16_t dummy = 0x0102;
    return ((char*)&dummy)[0] == 0x01;
  }
  bool OS::getIsLittleEndian() {
    char16_t dummy = 0x0102;
    return ((char*)&dummy)[0] == 0x02;
  }

};