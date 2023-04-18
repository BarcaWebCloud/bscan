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

class Net {
  friend std::vector<Net> getAllNets();

 public:
  Net(
    std::string& name, 
    std::string& manufacturer,
    std::string& permanentAddress,
    std::string& dnsHostname,
    std::string& serviceName,
    std::string& driverPath,
    std::string& status,
    std::string& macAddress,
    std::string& ipAddress,
    std::string& subnet,
    std::string& gateway
  );
  ~Net() = default;

  [[nodiscard]] const std::string& name() const;
  [[nodiscard]] const std::string& manufacturer() const;
  [[nodiscard]] const std::string& permanentAddress() const;
  [[nodiscard]] const std::string& dnsHostname() const;
  [[nodiscard]] const std::string& serviceName() const;
  [[nodiscard]] const std::string& driverPath() const;
  [[nodiscard]] const std::string& status() const;
  [[nodiscard]] const std::string& macAddress() const;
  [[nodiscard]] const std::string& ipAddress() const;
  [[nodiscard]] const std::string& subnet() const;
  [[nodiscard]] const std::string& gateway() const;
  
 private:
  Net() = default;
  std::string _name;
  std::string _manufacturer;
  std::string _permanentAddress;
  std::string _dnsHostname;
  std::string _serviceName;
  std::string _driverPath;
  std::string _status;
  std::string _macAddress;
  std::string _ipAddress;
  std::string _subnet;
  std::string _gateway;
};

std::vector<Net> getAllNets();

};