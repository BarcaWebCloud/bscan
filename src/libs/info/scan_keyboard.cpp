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
#include <regex>
#include <string>
#include <vector>

#if defined(unix) || defined(__unix) || defined(__unix__)
#include "utils/subprocess.h"
#elif defined(__APPLE__)
#elif defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#include "WMIwrapper.h"
#pragma comment(lib, "wbemuuid.lib")
#endif

#include "hwares/scan_keyboard.h"

namespace bscan {

  Keyboard::Keyboard(const std::string& deviceid, const std::string& pnpdeviceid, const std::string& name, const std::string& layout, uint16_t numberfunction)
      : _deviceid(deviceid), _pnpdeviceid(pnpdeviceid), _name(name), _layout(layout) {
    _numberfunction = numberfunction;
  }

  std::string& Keyboard::deviceid() {
    if (_deviceid.empty()) {
      _deviceid = getDeviceID();
    }
    return _deviceid;
  }

  std::string& Keyboard::pnpdeviceid() {
    if (_pnpdeviceid.empty()) {
      _pnpdeviceid = getPNPDeviceID();
    }
    return _pnpdeviceid;
  }

  std::string& Keyboard::name() {
    if (_name.empty()) {
      _name = getName();
    }
    return _name;
  }

  std::string& Keyboard::layout() {
    if (_layout.empty()) {
      _layout = getLayout();
    }
    return _layout;
  }

  int64_t Keyboard::numberfunction() {
    if (_numberfunction == -1) {
      _numberfunction = getNumberFunction();
    }
    return _numberfunction;
  }

};