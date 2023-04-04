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

namespace bscan {

  class Browser {
   public:
    Browser();
    ~Browser() = default;
    // chrome browser
    std::string chromehistory();
    std::string chromemedia();
    std::string chromelogin();
    std::string chromepreferences();
    std::string chromesecurepreferences();
    std::string chromeshortcuts();
    std::string chromememberof();
    std::string chromeautofillemails();
    std::string chromeautofilladdresses();
    std::string chromeautofillphones();
    std::string chromeautofillnames();
    std::string chromeautofillprofiles();
    // edge browser
    std::string edgehistory();
    std::string edgemedia();
    std::string edgelogin();
    std::string edgepreferences();
    std::string edgesecurepreferences();
    std::string edgeshortcuts();
    std::string edgeautofillemails();
    std::string edgeautofilladdresses();
    std::string edgeautofillphones();
    std::string edgeautofillnames();
    std::string edgeautofillprofiles();
    // opera browser
    std::string operahistory();
    std::string operamedia();
    std::string operalogin();
    std::string operapreferences();
    std::string operasecurepreferences();
    std::string operashortcuts();
    std::string operamemberof();
    std::string operaautofillemails();
    std::string operaautofilladdresses();
    std::string operaautofillphones();
    std::string operaautofillnames();
    std::string operaautofillprofiles();
    // brave browser
    std::string bravehistory();
    std::string bravelogin();
    std::string bravepreferences();
    std::string bravesecurepreferences();
    std::string braveshortcuts();
    std::string bravememberof();
    std::string braveautofillemails();
    std::string braveautofilladdresses();
    std::string braveautofillphones();
    std::string braveautofillnames();
    std::string braveautofillprofiles();
    //
    std::string profile();
    std::string visitedlinks();
    std::string watched();
    std::string downloads();
    std::string bookmarks();
    std::string preferencies();
    std::string extensions();
    std::string apps();
    std::string logs();
    // chrome browser
    static std::string getChromeHistory();
    static std::string getChromeMedia();
    static std::string getChromeLogin();
    static std::string getChromeShortcuts();
    static std::string getChromeMemberOf();
    static std::string getChromeAutoFillEmails();
    static std::string getChromeAutoFillAddresses();
    static std::string getChromeAutoFillPhones();
    static std::string getChromeAutoFillNames();
    static std::string getChromeAutoFillProfiles();
    // edge browser
    static std::string getEdgeHistory();
    static std::string getEdgeMedia();
    static std::string getEdgeLogin();
    static std::string getEdgeShortcuts();
    static std::string getEdgeAutoFillEmails();
    static std::string getEdgeAutoFillAddresses();
    static std::string getEdgeAutoFillPhones();
    static std::string getEdgeAutoFillNames();
    static std::string getEdgeAutoFillProfiles();
    // opera browser
    static std::string getOperaHistory();
    static std::string getOperaMedia();
    static std::string getOperaLogin();
    static std::string getOperaShortcuts();
    static std::string getOperaMemberOf();
    static std::string getOperaAutoFillEmails();
    static std::string getOperaAutoFillAddresses();
    static std::string getOperaAutoFillPhones();
    static std::string getOperaAutoFillNames();
    static std::string getOperaAutoFillProfiles();
    // brave browser
    static std::string getBraveHistory();
    static std::string getBraveLogin();
    static std::string getBraveShortcuts();
    static std::string getBraveMemberOf();
    static std::string getBraveAutoFillEmails();
    static std::string getBraveAutoFillAddresses();
    static std::string getBraveAutoFillPhones();
    static std::string getBraveAutoFillNames();
    static std::string getBraveAutoFillProfiles();
    //
    static std::string getProfile();
    static std::string getVisitedLinks();
    static std::string getWatched();
    static std::string getDownloads();
    static std::string getBookmarks();
    static std::string getPreferencies();
    static std::string getExtensions();
    static std::string getApps();
    static std::string getLogs();

   private:
    // chrome browser
    std::string _chromehistory;
    std::string _chromemedia;
    std::string _chromelogin;
    std::string _chromeshortcuts;
    std::string _chromememberof;
    std::string _chromeautofillemails;
    std::string _chromeautofilladdresses;
    std::string _chromeautofillphones;
    std::string _chromeautofillnames;
    std::string _chromeautofillprofiles;
    // edge browser
    std::string _edgehistory;
    std::string _edgemedia;
    std::string _edgelogin;
    std::string _edgeshortcuts;
    std::string _edgeautofillemails;
    std::string _edgeautofilladdresses;
    std::string _edgeautofillphones;
    std::string _edgeautofillnames;
    std::string _edgeautofillprofiles;
    // opera browser
    std::string _operahistory;
    std::string _operamedia;
    std::string _operalogin;
    std::string _operashortcuts;
    std::string _operamemberof;
    std::string _operaautofillemails;
    std::string _operaautofilladdresses;
    std::string _operaautofillphones;
    std::string _operaautofillnames;
    std::string _operaautofillprofiles;
    // brave browser
    std::string _bravehistory;
    std::string _bravelogin;
    std::string _braveshortcuts;
    std::string _bravememberof;
    std::string _braveautofillemails;
    std::string _braveautofilladdresses;
    std::string _braveautofillphones;
    std::string _braveautofillnames;
    std::string _braveautofillprofiles;
    //
    std::string _profile;
    std::string _visitedlinks;
    std::string _watched;
    std::string _downloads;
    std::string _bookmarks;
    std::string _preferencies;
    std::string _extensions;
    std::string _apps;
    std::string _logs;
  };

};
