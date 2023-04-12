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

  class Keyboard {
   public:
    Keyboard() = default;
    Keyboard(const std::string& deviceid, const std::string& pnpdeviceid, const std::string& name, const std::string& layout, uint16_t numberfunction);
    ~Keyboard() = default;

    std::string& deviceid();
    std::string& pnpdeviceid();
    std::string& name();
    std::string& layout();
    uint16_t numberfunction();

    static std::string getDeviceID();
    static std::string getPNPDeviceID();
    static std::string getName();
    static std::string getLayout();
    static uint16_t getNumberFunction();

   private:
    std::string _deviceid;
    std::string _pnpdeviceid;
    std::string _name;
    std::string _layout;
    uint16_t _numberfunction = -1;
  };

};
