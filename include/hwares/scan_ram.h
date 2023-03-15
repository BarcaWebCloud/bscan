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

namespace bscan {

  class RAM {
   public:
    RAM() = default;
    RAM(std::string& vendor, std::string& name, std::string& model, std::string& serialNumber, int64_t size_Bytes);
    ~RAM() = default;

    std::string& vendor();
    std::string& name();
    std::string& model();
    std::string& serialNumber();
    int64_t totalSize_Bytes();
    int64_t availableMemory();

    static std::string getVendor();
    static std::string getName();
    static std::string getModel();
    static std::string getSerialNumber();
    static int64_t getTotalSize_Bytes();
    static int64_t getAvailableMemory();

   private:
    std::string _vendor;
    std::string _name;
    std::string _model;
    std::string _serialNumber;
    int64_t _totalSize_Bytes = -1;
    int64_t _totalFreeSize_Bytes = -1;
    int _clockSpeed = -1;
  };

};
