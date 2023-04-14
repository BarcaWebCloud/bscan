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

  class Temperature {
   public:
    Temperature() = default;
    Temperature(const std::string& description,
        const std::string& name,
        const std::string& pnpdeviceID,
        const std::string& deviceID,
        const std::string& status,
        const std::string& errorDescription,
        bool isLinear,
        bool errorCleared,
        int64_t tolerance,
        int64_t currentReading,
        int64_t lowerThresholdCritical,
        int64_t lowerThresholdFatal,
        int64_t lowerThresholdNonCritical,
        int64_t maxReadable,
        int64_t minReadable,
        int64_t nominalReading,
        int64_t normalMax,
        int64_t normalMin,
        int64_t accuracy,
        int64_t desiredSpeed,
        int64_t lastErrorCode,
        int64_t availability,
        int64_t statusInfo);
    ~Temperature() = default;
    
    std::string& description();
    std::string& name();
    std::string& pnpdeviceID();
    std::string& deviceID();
    std::string& status();
    std::string& errorDescription();
    bool isLinear();
    bool errorCleared();
    int64_t tolerance();
    int64_t currentReading();
    int64_t statusInfo();
    int64_t lastErrorCode();
    int64_t lowerThresholdCritical();
    int64_t lowerThresholdFatal();
    int64_t lowerThresholdNonCritical();
    int64_t maxReadable();
    int64_t minReadable();
    int64_t nominalReading();
    int64_t normalMax();
    int64_t normalMin();
    int64_t availability();
    int64_t accuracy();

    static std::string getDescription();
    static std::string getName();
    static std::string getPNPDeviceID();
    static std::string getDeviceID();
    static std::string getStatus();
    static std::string getErrorDescription();
    static bool getIsLinear();
    static bool getErrorCleared();
    static int64_t getTolerance();
    static int64_t getCurrentReading();
    static int64_t getStatusInfo();
    static int64_t getLastErrorCode();
    static int64_t getLowerThresholdCritical();
    static int64_t getLowerThresholdFatal();
    static int64_t getLowerThresholdNonCritical();
    static int64_t getMaxReadable();
    static int64_t getMinReadable();
    static int64_t getNominalReading();
    static int64_t getNormalMax();
    static int64_t getNormalMin();
    static int64_t getAvailability();
    static int64_t getAccuracy();

   private:
    std::string _description;
    std::string _name;
    std::string _pnpdeviceID;
    std::string _deviceID;
    std::string _status;
    std::string _errorDescription;
    bool _isLinear;
    bool _errorCleared;
    int64_t _tolerance = -1;
    int64_t _currentReading = -1;
    int64_t _statusInfo = -1;
    int64_t _lowerThresholdCritical = -1;
    int64_t _lowerThresholdFatal = -1;
    int64_t _lowerThresholdNonCritical = -1;
    int64_t _maxReadable = -1;
    int64_t _minReadable = -1;
    int64_t _nominalReading = -1;
    int64_t _normalMax = -1;
    int64_t _normalMin = -1;
    int64_t _lastErrorCode = -1;
    int64_t _availability = -1;
    int64_t _accuracy = -1;

  };

};
