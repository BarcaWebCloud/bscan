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

  class GPU {
   public:
    GPU() = default;
    GPU(const std::string& vendor,
        const std::string& name,
        const std::string& processor,
        const std::string& driverVersion,
        const std::string& deviceID,
        const std::string& status,
        const std::string& installedDriversPath,
        int64_t architecture,
        int64_t type,
        int64_t mode,
        int64_t availability,
        int64_t maxMemory,
        int64_t memoryBytes);
    ~GPU() = default;

    std::string& vendor();
    std::string& name();
    std::string& processor();
    std::string& driverVersion();
    std::string& deviceID();
    std::string& status();
    std::string& installedDriversPath();
    int64_t architecture();
    int64_t type();
    int64_t mode();
    int64_t availability();
    int64_t memoryBytes();
    int64_t maxMemory();

    static std::string getVendor();
    static std::string getName();
    static std::string getProcessor();
    static std::string getDriverVersion();
    static std::string getDeviceID();
    static std::string getStatus();
    static std::string getInstalledDriversPath();
    static int64_t getType();
    static int64_t getMode();
    static int64_t getArchitecture();
    static int64_t getAvailability();
    static int64_t getMaxMemory();
    static int64_t getMemoryBytes();

   private:
    std::string _vendor;
    std::string _name;
    std::string _processor;
    std::string _driverVersion;
    std::string _deviceID;
    std::string _status;
    std::string _installedDriversPath;
    int64_t _architecture = -1;
    int64_t _type = -1;
    int64_t _mode = -1;
    int64_t _availability = -1;
    int64_t _memoryBytes = -1;
    int64_t _maxMemory = -1;
  };

};
