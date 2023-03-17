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

#include "platform.h"

namespace bscan {

  class Battery {
    friend std::vector<Battery> getAllBatteries();

   public:
    explicit Battery(int8_t id = 0);
    ~Battery() = default;

    std::string& vendor();
    std::string& model();
    std::string& serialNumber();
    std::string& technology();
    uint32_t energyFull();

    double capacity();

    [[nodiscard]] std::string getVendor() const;
    [[nodiscard]] std::string getModel() const;
    [[nodiscard]] std::string getSerialNumber() const;
    [[nodiscard]] std::string getTechnology() const;
    [[nodiscard]] uint32_t getEnergyFull() const;

    [[nodiscard]] uint32_t energyNow() const;
    [[nodiscard]] bool charging() const;
    [[nodiscard]] bool discharging() const;

   private:
    int8_t _id = -1;
    std::string _vendor;
    std::string _model;
    std::string _serialNumber;
    std::string _technology;
    uint32_t _energyFull = 0;
  };

std::vector<Battery> getAllBatteries();

};
