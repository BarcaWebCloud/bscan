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
    // output.close();
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