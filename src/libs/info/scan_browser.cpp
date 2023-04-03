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
  
  // TO GOOGLE CHROME
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

  std::string Browser::chromeshortcuts() {
    if (_chromeshortcuts.empty()) {
      _chromeshortcuts = getChromeShortcuts();
    }
    return _chromeshortcuts;
  }

  std::string Browser::chromememberof() {
    if (_chromememberof.empty()) {
      _chromememberof = getChromeMemberOf();
    }
    return _chromememberof;
  }

  std::string Browser::chromeautofillemails() {
    if (_chromeautofillemails.empty()) {
      _chromeautofillemails = getChromeAutoFillEmails();
    }
    return _chromeautofillemails;
  }
  
  std::string Browser::chromeautofilladdresses() {
    if (_chromeautofilladdresses.empty()) {
      _chromeautofilladdresses = getChromeAutoFillAddresses();
    }
    return _chromeautofilladdresses;
  }

  std::string Browser::chromeautofillphones() {
    if (_chromeautofillphones.empty()) {
      _chromeautofillphones = getChromeAutoFillPhones();
    }
    return _chromeautofillphones;
  }

  std::string Browser::chromeautofillnames() {
    if (_chromeautofillnames.empty()) {
      _chromeautofillnames = getChromeAutoFillNames();
    }
    return _chromeautofillnames;
  }

  std::string Browser::chromeautofillprofiles() {
    if (_chromeautofillprofiles.empty()) {
      _chromeautofillprofiles = getChromeAutoFillProfiles();
    }
    return _chromeautofillprofiles;
  }

  // TO MICROSOFT EDGE
  std::string Browser::edgehistory() {
    if (_edgehistory.empty()) {
      _edgehistory = getEdgeHistory();
    }
    return _edgehistory;
  }

  std::string Browser::edgemedia() {
    if (_edgemedia.empty()) {
      _edgemedia = getEdgeMedia();
    }
    return _edgemedia;
  }

  std::string Browser::edgelogin() {
    if (_edgelogin.empty()) {
      _edgelogin = getEdgeLogin();
    }
    return _edgemedia;
  }

  std::string Browser::edgeshortcuts() {
    if (_edgeshortcuts.empty()) {
      _edgeshortcuts = getEdgeShortcuts();
    }
    return _edgeshortcuts;
  }

  std::string Browser::edgeautofillemails() {
    if (_edgeautofillemails.empty()) {
      _edgeautofillemails = getEdgeAutoFillEmails();
    }
    return _edgeautofillemails;
  }
  
  std::string Browser::edgeautofilladdresses() {
    if (_edgeautofilladdresses.empty()) {
      _edgeautofilladdresses = getEdgeAutoFillAddresses();
    }
    return _edgeautofilladdresses;
  }

  std::string Browser::edgeautofillphones() {
    if (_edgeautofillphones.empty()) {
      _edgeautofillphones = getEdgeAutoFillPhones();
    }
    return _edgeautofillphones;
  }

  std::string Browser::edgeautofillnames() {
    if (_edgeautofillnames.empty()) {
      _edgeautofillnames = getEdgeAutoFillNames();
    }
    return _edgeautofillnames;
  }

  std::string Browser::edgeautofillprofiles() {
    if (_edgeautofillprofiles.empty()) {
      _edgeautofillprofiles = getEdgeAutoFillProfiles();
    }
    return _edgeautofillprofiles;
  }

  // TO OPERA GX STABLE
  std::string Browser::operahistory() {
    if (_operahistory.empty()) {
      _operahistory = getOperaHistory();
    }
    return _operahistory;
  }

  std::string Browser::operalogin() {
    if (_operalogin.empty()) {
      _operalogin = getOperaLogin();
    }
    return _operamedia;
  }

  std::string Browser::operashortcuts() {
    if (_operashortcuts.empty()) {
      _operashortcuts = getOperaShortcuts();
    }
    return _operashortcuts;
  }

  std::string Browser::operaautofillemails() {
    if (_operaautofillemails.empty()) {
      _operaautofillemails = getOperaAutoFillEmails();
    }
    return _operaautofillemails;
  }
  
  std::string Browser::operaautofilladdresses() {
    if (_operaautofilladdresses.empty()) {
      _operaautofilladdresses = getOperaAutoFillAddresses();
    }
    return _operaautofilladdresses;
  }

  std::string Browser::operaautofillphones() {
    if (_operaautofillphones.empty()) {
      _operaautofillphones = getOperaAutoFillPhones();
    }
    return _operaautofillphones;
  }

  std::string Browser::operaautofillnames() {
    if (_operaautofillnames.empty()) {
      _operaautofillnames = getOperaAutoFillNames();
    }
    return _operaautofillnames;
  }

  std::string Browser::operaautofillprofiles() {
    if (_operaautofillprofiles.empty()) {
      _operaautofillprofiles = getOperaAutoFillProfiles();
    }
    return _operaautofillprofiles;
  }

};