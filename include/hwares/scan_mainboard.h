#pragma once

#include <string>
#include <vector>

#include "platform.h"

namespace bscan {

  class MainBoard {
   public:
    MainBoard() = default;
    MainBoard(std::string vendor, std::string product, std::string version, std::string serialNumber);
    ~MainBoard() = default;

    std::string& vendor();
    std::string& name();
    std::string& version();
    std::string& serialNumber();

    static std::string getVendor();
    static std::string getName();
    static std::string getVersion();
    static std::string getSerialNumber();

   private:
    std::string _vendor;
    std::string _name;
    std::string _version;
    std::string _serialNumber;

  #ifdef BSCAN_UNIX
    static std::vector<std::string> _candidates;
  #endif
  };

};