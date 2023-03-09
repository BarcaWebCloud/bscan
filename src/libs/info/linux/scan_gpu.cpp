#include "platform.h"

#ifdef BSCAN_UNIX

#include <regex>
#include <string>
#include <vector>

#include "hware/scan_gpu.h"
#include "utils/subprocess.h"

namespace bscan {

  std::string GPU::getVendor() {
    // TODO: piping stderr to /dev/null seems super ugly.
    //  Why am I doing this? -> lshw prints that one should run it as sudo user to stderr...
    std::string command("lshw -c display 2> /dev/null");
    std::regex matcher("vendor:.*");
    std::string output = exec(command);
    std::smatch match;
    std::string vendor;
    if (std::regex_search(output.cbegin(), output.cend(), match, matcher)) {
      char prev = '\0';
      bool add = false;
      std::string tmp = match[0];
      for (auto& c : tmp) {
        if (c == '\n') {
          break;
        }
        if (add) {
          vendor += c;
        }
        if (prev == ':') {
          add = true;
        }
        prev = c;
      }
    }
    return vendor.empty() ? "<unknown>" : vendor;
  }

  std::string GPU::getName() {
    std::string command("lshw -c display 2> /dev/null");
    std::regex matcher("product:.*\\[.*\\]");
    std::string output = exec(command);
    std::smatch match;
    std::string name;
    if (std::regex_search(output.cbegin(), output.cend(), match, matcher)) {
      bool add = false;
      std::string tmp = match[0];
      for (auto& c : tmp) {
        if (c == ']') {
          break;
        }
        if (add) {
          name += c;
        }
        if (c == '[') {
          add = true;
        }
      }
    }
    return name;
  }

  std::string GPU::getDriverVersion() {
    // TODO: implement
    return "<unknown>";
  }

  int64_t GPU::getMemory_Bytes() {
    // TODO: implement
    return -1;
  }

};

#endif  // END BSCAN_UNIX