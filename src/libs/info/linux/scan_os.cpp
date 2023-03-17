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

#ifdef BSCAN_UNIX

#include <sys/stat.h>
#include <sys/utsname.h>
#include <fstream>
#include <sstream>
#include <string>
#include "swares/scan_os.h"
#include "utils/stringutils.h"
#include "utils/subprocess.h"

namespace bscan {

  std::string OS::getFullName() {
    std::string line;
    std::ifstream stream("/etc/lsb-release");
    if (!stream) {
      return "Linux <unknown version>";
    }
    while (getline(stream, line)) {
      if (starts_with(line, "DISTRIB_DESCRIPTION")) {
        line = line.substr(line.find('=') + 1, line.length());
        // remove \" at begin and end of the substring result
        return {line.begin() + 1, line.end() - 1};
      }
    }
    stream.close();
    return "Linux <unknown version>";
  }

  std::string OS::getName() {
    std::string line;
    std::ifstream stream("/etc/lsb-release");
    if (!stream) {
      return "Linux";
    }
    while (getline(stream, line)) {
      if (starts_with(line, "DISTRIB_ID")) {
        return line.substr(line.find('=') + 1, line.length());
      }
    }
    stream.close();
    return "Linux";
  }

  std::string OS::getVersion() {
    std::string line;
    std::ifstream stream("/etc/lsb-release");
    if (!stream) {
      return "<unknown version>";
    }
    while (getline(stream, line)) {
      if (starts_with(line, "DISTRIB_RELEASE")) {
        return line.substr(line.find('=') + 1, line.length());
      }
    }
    stream.close();
    return "<unknown version>";
  }

  std::string OS::getHostname() {
    std::string line;
    std::ifstream stream("/proc/sys/kernel/hostname");
    if (!stream) {
      return "Linux <unknown hostname>";
    }
    getline(stream, line);
    stream.close();

    return std::string(line);
  }

  std::string OS::getUsersWithHome() {
    std::string command("getent passwd | grep '/home' | cut -d: -f1 | awk 'FNR>=2'");
    std::string output = exec(command);
    if (!output) {
      return "Linux <unknown users with home directory>";
    }
    return std::string(output);
  }
  
  std::string OS::getUptime() {
    std::string command("uptime | sed -E 's/^[^,]*up *//; s/, *[[:digit:]]* users.*//; s/min/minutes/; s/([[:digit:]]+):0?([[:digit:]]+)/\1 hours, \2 minutes/' ");
    std::string output = exec(command);
    if (!output) {
      return "Linux <unknown uptime>";
    }
    return std::string(output);
  }

  std::string OS::getPkgs() {
    std::string command("apt-cache --all-names pkgnames");
    std::string output = exec(command);
    if (!output) {
      return "Linux <unknown pkgs installed>";
    }
    return std::string(output);
  }

  std::string OS::getUser() {
    std::string command("whoami");
    std::string output = exec(command);
    if (!output) {
      return "Linux <unknown user>";
    }
    return std::string(output);
  }

  std::string OS::getDomainName() {
    std::string line;
    std::ifstream stream("/proc/sys/kernel/domainname");
    if (!stream) {
      return "Linux <unknown domain name>";
    }
    getline(stream, line);
    stream.close();

    return std::string(line);
  }

  std::string OS::getLog() {
    std::string line;
    std::ifstream stream("/var/log/boot.log");
    if (!stream) {
      return "Linux <unknown hostname>";
    }
    getline(stream, line);
    stream.close();

    return std::string(line);
  }

  std::string OS::getKernel() {
    static utsname info;
    if (uname(&info) == 0) {
      return info.release;
    }
    return "<unknown kernel>";
  }

  bool OS::getIs64bit() {
    struct stat buffer {};
    return (stat("/lib64/ld-linux-x86-64.so.2", &buffer) == 0);
  }

};

#endif  // END BSCAN_UNIX