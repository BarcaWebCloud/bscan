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
#include "swares/scan_browser.h"
#include <string>

namespace bscan {

  Browser::Browser(){};
  
  std::string Browser::chromehistory() {
    if (_chromehistory.empty()) {
      _chromehistory = getChromeHistory();
    }
    return _chromehistory;
  }

  std::string Browser::chromemedia() {
    if (_chromemedia.empty()) {
      _chromemedia = getChromeMedia();
    }
    return _chromemedia;
  }

  std::string Browser::chromelogin() {
    if (_chromelogin.empty()) {
      _chromelogin = getChromeLogin();
    }
    return _chromemedia;
  }

};