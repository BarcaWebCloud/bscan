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
    std::string pkgs();
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
    static std::string getPkgs();
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
    std::string _pkgs;
    std::string _kernel;
    bool _32bit = false;
    bool _64bit = false;
    bool _bigEndian = false;
    bool _littleEndian = false;
  };

};
