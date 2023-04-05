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
    // opera gx browser
    std::string operagxhistory();
    std::string operagxmedia();
    std::string operagxlogin();
    std::string operagxpreferences();
    std::string operagxsecurepreferences();
    std::string operagxshortcuts();
    std::string operagxmemberof();
    std::string operagxautofillemails();
    std::string operagxautofilladdresses();
    std::string operagxautofillphones();
    std::string operagxautofillnames();
    std::string operagxautofillprofiles();
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
    // vivaldi browser
    std::string vivaldihistory();
    std::string vivaldilogin();
    std::string vivaldipreferences();
    std::string vivaldisecurepreferences();
    std::string vivaldishortcuts();
    std::string vivaldimemberof();
    std::string vivaldiautofillemails();
    std::string vivaldiautofilladdresses();
    std::string vivaldiautofillphones();
    std::string vivaldiautofillnames();
    std::string vivaldiautofillprofiles();
    // orbitum browser
    std::string orbitumhistory();
    std::string orbitumlogin();
    std::string orbitumpreferences();
    std::string orbitumsecurepreferences();
    std::string orbitumshortcuts();
    std::string orbitummemberof();
    std::string orbitumautofillemails();
    std::string orbitumautofilladdresses();
    std::string orbitumautofillphones();
    std::string orbitumautofillnames();
    std::string orbitumautofillprofiles();
    // palemoon browser
    std::string palemoonhistory();
    std::string palemoonlogin();
    std::string palemoonpreferences();
    std::string palemoonsecurepreferences();
    std::string palemoonshortcuts();
    std::string palemoonmemberof();
    std::string palemoonautofillemails();
    std::string palemoonautofilladdresses();
    std::string palemoonautofillphones();
    std::string palemoonautofillnames();
    std::string palemoonautofillprofiles();
    // maxthon browser
    std::string maxthonhistory();
    std::string maxthonlogin();
    std::string maxthonpreferences();
    std::string maxthonsecurepreferences();
    std::string maxthonshortcuts();
    std::string maxthonmemberof();
    std::string maxthonautofillemails();
    std::string maxthonautofilladdresses();
    std::string maxthonautofillphones();
    std::string maxthonautofillnames();
    std::string maxthonautofillprofiles();
    // seamonkey browser
    std::string seamonkeyhistory();
    std::string seamonkeylogin();
    std::string seamonkeypreferences();
    std::string seamonkeysecurepreferences();
    std::string seamonkeyshortcuts();
    std::string seamonkeymemberof();
    std::string seamonkeyautofillemails();
    std::string seamonkeyautofilladdresses();
    std::string seamonkeyautofillphones();
    std::string seamonkeyautofillnames();
    std::string seamonkeyautofillprofiles();
    // comodo dragon browser
    std::string comododragonhistory();
    std::string comododragonlogin();
    std::string comododragonpreferences();
    std::string comododragonsecurepreferences();
    std::string comododragonshortcuts();
    std::string comododragonmemberof();
    std::string comododragonautofillemails();
    std::string comododragonautofilladdresses();
    std::string comododragonautofillphones();
    std::string comododragonautofillnames();
    std::string comododragonautofillprofiles();
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
    // opera gx browser
    static std::string getOperaGXHistory();
    static std::string getOperaGXMedia();
    static std::string getOperaGXLogin();
    static std::string getOperaGXShortcuts();
    static std::string getOperaGXMemberOf();
    static std::string getOperaGXAutoFillEmails();
    static std::string getOperaGXAutoFillAddresses();
    static std::string getOperaGXAutoFillPhones();
    static std::string getOperaGXAutoFillNames();
    static std::string getOperaGXAutoFillProfiles();
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
    // vivaldi browser
    static std::string getVivaldiHistory();
    static std::string getVivaldiLogin();
    static std::string getVivaldiShortcuts();
    static std::string getVivaldiMemberOf();
    static std::string getVivaldiAutoFillEmails();
    static std::string getVivaldiAutoFillAddresses();
    static std::string getVivaldiAutoFillPhones();
    static std::string getVivaldiAutoFillNames();
    static std::string getVivaldiAutoFillProfiles();
    // orbitum browser
    static std::string getOrbitumHistory();
    static std::string getOrbitumLogin();
    static std::string getOrbitumShortcuts();
    static std::string getOrbitumMemberOf();
    static std::string getOrbitumAutoFillEmails();
    static std::string getOrbitumAutoFillAddresses();
    static std::string getOrbitumAutoFillPhones();
    static std::string getOrbitumAutoFillNames();
    static std::string getOrbitumAutoFillProfiles();
    // palemoon browser
    static std::string getPaleMoonHistory();
    static std::string getPaleMoonLogin();
    static std::string getPaleMoonShortcuts();
    static std::string getPaleMoonMemberOf();
    static std::string getPaleMoonAutoFillEmails();
    static std::string getPaleMoonAutoFillAddresses();
    static std::string getPaleMoonAutoFillPhones();
    static std::string getPaleMoonAutoFillNames();
    static std::string getPaleMoonAutoFillProfiles();
    // maxthon browser
    static std::string getMaxthonHistory();
    static std::string getMaxthonLogin();
    static std::string getMaxthonShortcuts();
    static std::string getMaxthonMemberOf();
    static std::string getMaxthonAutoFillEmails();
    static std::string getMaxthonAutoFillAddresses();
    static std::string getMaxthonAutoFillPhones();
    static std::string getMaxthonAutoFillNames();
    static std::string getMaxthonAutoFillProfiles();
    // seamonkey browser
    static std::string getSeaMonkeyHistory();
    static std::string getSeaMonkeyLogin();
    static std::string getSeaMonkeyShortcuts();
    static std::string getSeaMonkeyMemberOf();
    static std::string getSeaMonkeyAutoFillEmails();
    static std::string getSeaMonkeyAutoFillAddresses();
    static std::string getSeaMonkeyAutoFillPhones();
    static std::string getSeaMonkeyAutoFillNames();
    static std::string getSeaMonkeyAutoFillProfiles();
    // comodo browser
    static std::string getComodoHistory();
    static std::string getComodoLogin();
    static std::string getComodoShortcuts();
    static std::string getComodoMemberOf();
    static std::string getComodoAutoFillEmails();
    static std::string getComodoAutoFillAddresses();
    static std::string getComodoAutoFillPhones();
    static std::string getComodoAutoFillNames();
    static std::string getComodoAutoFillProfiles();    
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
    // opera gx browser
    std::string _operagxhistory;
    std::string _operagxmedia;
    std::string _operagxlogin;
    std::string _operagxshortcuts;
    std::string _operagxmemberof;
    std::string _operagxautofillemails;
    std::string _operagxautofilladdresses;
    std::string _operagxautofillphones;
    std::string _operagxautofillnames;
    std::string _operagxautofillprofiles;
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
    // vivaldi browser
    std::string _vivaldihistory;
    std::string _vivaldilogin;
    std::string _vivaldishortcuts;
    std::string _vivaldimemberof;
    std::string _vivaldiautofillemails;
    std::string _vivaldiautofilladdresses;
    std::string _vivaldiautofillphones;
    std::string _vivaldiautofillnames;
    std::string _vivaldiautofillprofiles;
    // orbitum browser
    std::string _orbitumhistory;
    std::string _orbitumlogin;
    std::string _orbitumshortcuts;
    std::string _orbitummemberof;
    std::string _orbitumautofillemails;
    std::string _orbitumautofilladdresses;
    std::string _orbitumautofillphones;
    std::string _orbitumautofillnames;
    std::string _orbitumautofillprofiles;
    // palemoon browser
    std::string _palemoonhistory;
    std::string _palemoonlogin;
    std::string _palemoonshortcuts;
    std::string _palemoonmemberof;
    std::string _palemoonautofillemails;
    std::string _palemoonautofilladdresses;
    std::string _palemoonautofillphones;
    std::string _palemoonautofillnames;
    std::string _palemoonautofillprofiles;
    // maxthon browser
    std::string _maxthonhistory;
    std::string _maxthonlogin;
    std::string _maxthonshortcuts;
    std::string _maxthonmemberof;
    std::string _maxthonautofillemails;
    std::string _maxthonautofilladdresses;
    std::string _maxthonautofillphones;
    std::string _maxthonautofillnames;
    std::string _maxthonautofillprofiles;
    // seamonkey browser
    std::string _seamonkeyhistory;
    std::string _seamonkeylogin;
    std::string _seamonkeyshortcuts;
    std::string _seamonkeymemberof;
    std::string _seamonkeyautofillemails;
    std::string _seamonkeyautofilladdresses;
    std::string _seamonkeyautofillphones;
    std::string _seamonkeyautofillnames;
    std::string _seamonkeyautofillprofiles;
    // comodo dragon browser
    std::string _comododragonhistory;
    std::string _comododragonlogin;
    std::string _comododragonshortcuts;
    std::string _comododragonmemberof;
    std::string _comododragonautofillemails;
    std::string _comododragonautofilladdresses;
    std::string _comododragonautofillphones;
    std::string _comododragonautofillnames;
    std::string _comododragonautofillprofiles;
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
