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

  class BIOS {
   public:
    BIOS() = default;
    BIOS(const std::string& description,
        const std::string& name,
        const std::string& status,
        const std::string& manufacturer,
        const std::string& otherIdentifyingInfo,
        const std::string& partNumber,
        const std::string& serialNumber,
        const std::string& sku,
        const std::string& breachDescription,
        const std::string& version,
        bool poweredOn,
        bool hotSwappable,
        bool removable,
        bool replaceable,
        bool audibleAlarm,
        bool lockPresent,
        bool visibleAlarm,
        int64_t securityBreach,
        int64_t heatGeneration,
        int64_t numberOfPowerCords);
    ~BIOS() = default;
    
    std::string& description();
    std::string& name();
    std::string& status();
    std::string& manufacturer();
    std::string& otherIdentifyingInfo();
    std::string& partNumber();
    std::string& serialNumber();
    std::string& sku();
    std::string& breachDescription();
    std::string& version();
    bool poweredOn();
    bool hotSwappable();
    bool removable();
    bool replaceable();
    bool audibleAlarm();
    bool lockPresent();
    bool visibleAlarm();
    int64_t securityBreach();
    int64_t heatGeneration();
    int64_t numberOfPowerCords();

    static std::string getDescription();
    static std::string getName();
    static std::string getStatus();
    static std::string getManufacturer();
    static std::string getOtherIdentifyingInfo();
    static std::string getPartNumber();
    static std::string getSerialNumber();
    static std::string getSku();
    static std::string getBreachDescription();
    static std::string getVersion();
    static bool getPoweredOn();
    static bool getHotSwappable();
    static bool getRemovable();
    static bool getReplaceable();
    static bool getAudibleAlarm();
    static bool getLockPresent();
    static bool getVisibleAlarm();
    static int64_t getSecurityBreach();
    static int64_t getHeatGeneration();
    static int64_t getNumberOfPowerCords();

   private:
    std::string& _description;
    std::string& _name;
    std::string& _status;
    std::string& _manufacturer;
    std::string& _otherIdentifyingInfo;
    std::string& _partNumber;
    std::string& _serialNumber;
    std::string& _sku;
    std::string& _breachDescription;
    std::string& _version;
    bool _poweredOn;
    bool _hotSwappable;
    bool _removable;
    bool _replaceable;
    bool _audibleAlarm;
    bool _lockPresent;
    bool _visibleAlarm;
    int64_t _securityBreach = -1;
    int64_t _heatGeneration = -1;
    int64_t _numberOfPowerCords = -1;

  };

};
