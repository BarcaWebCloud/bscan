/************************************************************************************
      
 *      Copyright (C) 2021 - 2023, Barca Web Cloud, Inc. 
 *    Email: <opensource@barca.com>  GitHub: @BarcaWebCloud. 
 
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