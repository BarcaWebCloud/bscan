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

class Disk {
  friend std::vector<Disk> getAllDisks();

 public:
  Disk(std::string& vendor, std::string& model, std::string& serialNumber, int64_t size_Bytes);
  ~Disk() = default;

  [[nodiscard]] const std::string& vendor() const;
  [[nodiscard]] const std::string& model() const;
  [[nodiscard]] const std::string& serialNumber() const;
  [[nodiscard]] int64_t size_Bytes() const;

 private:
  Disk() = default;
  std::string _vendor;
  std::string _model;
  std::string _serialNumber;
  int64_t _size_Bytes = -1;
};

std::vector<Disk> getAllDisks();

};