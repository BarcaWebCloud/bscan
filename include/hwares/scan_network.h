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

class NET {
  friend std::vector<NET> getAllAdapters();

 public:
  NET(std::string& name, std::string& model, std::string& mask, std::string& ipAddressPrivate, std::string& ipAddressPublic, std::string& gateway);
  ~NET() = default;

  [[nodiscard]] const std::string& name() const;
  [[nodiscard]] const std::string& model() const;
  [[nodiscard]] const std::string& mask() const;
  [[nodiscard]] const std::string& ipAddressPrivate() const;
  [[nodiscard]] const std::string& ipAddressPublic() const;
  [[nodiscard]] const std::string& gateway() const;
  std::string& privateIP();

  static std::string getPrivateIP();

 private:
  std::string _name;
  std::string _model;
  std::string _mask;
  std::string _ipAddressPrivate;
  std::string _ipAddressPublic;
  std::string _gateway;
  std::string _privateIP;
};

std::vector<NET> getAllAdapters();

};