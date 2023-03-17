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

class Monitor {
  friend std::vector<Monitor> getAllMonitors();

  public:
    Monitor(std::string& model, std::string& key, std::string& name);
    ~Monitor() = default;

    [[nodiscard]] const std::string& model() const;
    [[nodiscard]] const std::string& key() const;
    [[nodiscard]] const std::string& name() const;

  private:
    Monitor() = default;
    std::string _model;
    std::string _key;
    std::string _name;
  };

  std::vector<Monitor> getAllMonitors();

};