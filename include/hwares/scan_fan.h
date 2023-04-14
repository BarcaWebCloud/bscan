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

  class FAN {
   public:
    FAN() = default;
    FAN(const std::string& description,
        const std::string& name,
        const std::string& pnpdeviceID,
        const std::string& deviceID,
        const std::string& status,
        const std::string& errorDescription,
        int64_t desiredSpeed,
        int64_t lastErrorCode,
        int64_t availability,
        int64_t statusInfo);
    ~FAN() = default;

    std::string& description();
    std::string& name();
    std::string& pnpdeviceID();
    std::string& deviceID();
    std::string& status();
    std::string& errorDescription();
    int64_t desiredSpeed();
    int64_t lastErrorCode();
    int64_t availability();
    int64_t statusInfo();

    static std::string getDescription();
    static std::string getName();
    static std::string getPNPDeviceID();
    static std::string getDeviceID();
    static std::string getStatus();
    static std::string getErrorDescription();
    static int64_t getDesiredSpeed();
    static int64_t getLastErrorCode();
    static int64_t getAvailability();
    static int64_t getStatusInfo();

   private:
    std::string _description;
    std::string _name;
    std::string _pnpdeviceID;
    std::string _deviceID;
    std::string _status;
    std::string _errorDescription;
    int64_t _desiredSpeed = -1;
    int64_t _lastErrorCode = -1;
    int64_t _availability = -1;
    int64_t _statusInfo = -1;
  };

};
