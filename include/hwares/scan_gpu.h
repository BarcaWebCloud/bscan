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

namespace bscan {

  class GPU {
   public:
    GPU() = default;
    GPU(const std::string& vendor, const std::string& name, const std::string& driverVersion, int64_t memory_Bytes);
    ~GPU() = default;

    std::string& vendor();
    std::string& name();
    std::string& driverVersion();
    int64_t memory_Bytes();

    static std::string getVendor();
    static std::string getName();
    static std::string getDriverVersion();
    static int64_t getMemory_Bytes();

   private:
    std::string _vendor;
    std::string _name;
    std::string _driverVersion;
    int64_t _memory_Bytes = -1;
  };

};
