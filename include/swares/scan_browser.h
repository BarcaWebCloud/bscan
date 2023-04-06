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
    // comodo ice dragon browser
    std::string comodoicedragonhistory();
    std::string comodoicedragonlogin();
    std::string comodoicedragonpreferences();
    std::string comodoicedragonsecurepreferences();
    std::string comodoicedragonshortcuts();
    std::string comodoicedragonmemberof();
    std::string comodoicedragonautofillemails();
    std::string comodoicedragonautofilladdresses();
    std::string comodoicedragonautofillphones();
    std::string comodoicedragonautofillnames();
    std::string comodoicedragonautofillprofiles();
    // 360 chrome x browser
    std::string chromexhistory();
    std::string chromexlogin();
    std::string chromexpreferences();
    std::string chromexsecurepreferences();
    std::string chromexshortcuts();
    std::string chromexmemberof();
    std::string chromexautofillemails();
    std::string chromexautofilladdresses();
    std::string chromexautofillphones();
    std::string chromexautofillnames();
    std::string chromexautofillprofiles();
    // waterfox browser
    std::string waterfoxhistory();
    std::string waterfoxlogin();
    std::string waterfoxpreferences();
    std::string waterfoxsecurepreferences();
    std::string waterfoxshortcuts();
    std::string waterfoxmemberof();
    std::string waterfoxautofillemails();
    std::string waterfoxautofilladdresses();
    std::string waterfoxautofillphones();
    std::string waterfoxautofillnames();
    std::string waterfoxautofillprofiles();
    // briskbard browser
    std::string briskbardhistory();
    std::string briskbardlogin();
    std::string briskbardpreferences();
    std::string briskbardsecurepreferences();
    std::string briskbardshortcuts();
    std::string briskbardmemberof();
    std::string briskbardautofillemails();
    std::string briskbardautofilladdresses();
    std::string briskbardautofillphones();
    std::string briskbardautofillnames();
    std::string briskbardautofillprofiles();
    // slim browser
    std::string slimhistory();
    std::string slimlogin();
    std::string slimpreferences();
    std::string slimsecurepreferences();
    std::string slimshortcuts();
    std::string slimmemberof();
    std::string slimautofillemails();
    std::string slimautofilladdresses();
    std::string slimautofillphones();
    std::string slimautofillnames();
    std::string slimautofillprofiles();
    // srwareiron browser
    std::string srwareironhistory();
    std::string srwareironlogin();
    std::string srwareironpreferences();
    std::string srwareironsecurepreferences();
    std::string srwareironshortcuts();
    std::string srwareironmemberof();
    std::string srwareironautofillemails();
    std::string srwareironautofilladdresses();
    std::string srwareironautofillphones();
    std::string srwareironautofillnames();
    std::string srwareironautofillprofiles();
    // tungsten browser
    std::string tungstenhistory();
    std::string tungstenlogin();
    std::string tungstenpreferences();
    std::string tungstensecurepreferences();
    std::string tungstenshortcuts();
    std::string tungstenmemberof();
    std::string tungstenautofillemails();
    std::string tungstenautofilladdresses();
    std::string tungstenautofillphones();
    std::string tungstenautofillnames();
    std::string tungstenautofillprofiles();
    // yandex browser
    std::string yandexhistory();
    std::string yandexlogin();
    std::string yandexpreferences();
    std::string yandexsecurepreferences();
    std::string yandexshortcuts();
    std::string yandexmemberof();
    std::string yandexautofillemails();
    std::string yandexautofilladdresses();
    std::string yandexautofillphones();
    std::string yandexautofillnames();
    std::string yandexautofillprofiles();
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
    // comodo dragon browser
    static std::string getComodoDragonHistory();
    static std::string getComodoDragonLogin();
    static std::string getComodoDragonShortcuts();
    static std::string getComodoDragonMemberOf();
    static std::string getComodoDragonAutoFillEmails();
    static std::string getComodoDragonAutoFillAddresses();
    static std::string getComodoDragonAutoFillPhones();
    static std::string getComodoDragonAutoFillNames();
    static std::string getComodoDragonAutoFillProfiles();
    // comodo ice dragon browser
    static std::string getComodoIceDragonHistory();
    static std::string getComodoIceDragonLogin();
    static std::string getComodoIceDragonShortcuts();
    static std::string getComodoIceDragonMemberOf();
    static std::string getComodoIceDragonAutoFillEmails();
    static std::string getComodoIceDragonAutoFillAddresses();
    static std::string getComodoIceDragonAutoFillPhones();
    static std::string getComodoIceDragonAutoFillNames();
    static std::string getComodoIceDragonAutoFillProfiles();
    // 360 chrome x browser
    static std::string get360ChromeXHistory();
    static std::string get360ChromeXLogin();
    static std::string get360ChromeXShortcuts();
    static std::string get360ChromeXMemberOf();
    static std::string get360ChromeXAutoFillEmails();
    static std::string get360ChromeXAutoFillAddresses();
    static std::string get360ChromeXAutoFillPhones();
    static std::string get360ChromeXAutoFillNames();
    static std::string get360ChromeXAutoFillProfiles();
    // Waterfox browser
    static std::string getWaterfoxHistory();
    static std::string getWaterfoxLogin();
    static std::string getWaterfoxShortcuts();
    static std::string getWaterfoxMemberOf();
    static std::string getWaterfoxAutoFillEmails();
    static std::string getWaterfoxAutoFillAddresses();
    static std::string getWaterfoxAutoFillPhones();
    static std::string getWaterfoxAutoFillNames();
    static std::string getWaterfoxAutoFillProfiles();
    // briskbird browser
    static std::string getBriskBardHistory();
    static std::string getBriskBardLogin();
    static std::string getBriskBardShortcuts();
    static std::string getBriskBardMemberOf();
    static std::string getBriskBardAutoFillEmails();
    static std::string getBriskBardAutoFillAddresses();
    static std::string getBriskBardAutoFillPhones();
    static std::string getBriskBardAutoFillNames();
    static std::string getBriskBardAutoFillProfiles();
    // otter browser
    static std::string getOtterHistory();
    static std::string getOtterLogin();
    static std::string getOtterShortcuts();
    static std::string getOtterMemberOf();
    static std::string getOtterAutoFillEmails();
    static std::string getOtterAutoFillAddresses();
    static std::string getOtterAutoFillPhones();
    static std::string getOtterAutoFillNames();
    static std::string getOtterAutoFillProfiles();
    // slim browser
    static std::string getSlimHistory();
    static std::string getSlimLogin();
    static std::string getSlimShortcuts();
    static std::string getSlimMemberOf();
    static std::string getSlimAutoFillEmails();
    static std::string getSlimAutoFillAddresses();
    static std::string getSlimAutoFillPhones();
    static std::string getSlimAutoFillNames();
    static std::string getSlimAutoFillProfiles();
    // srwareiron browser
    static std::string getSRWareIronHistory();
    static std::string getSRWareIronLogin();
    static std::string getSRWareIronShortcuts();
    static std::string getSRWareIronMemberOf();
    static std::string getSRWareIronAutoFillEmails();
    static std::string getSRWareIronAutoFillAddresses();
    static std::string getSRWareIronAutoFillPhones();
    static std::string getSRWareIronAutoFillNames();
    static std::string getSRWareIronAutoFillProfiles();
    // tungsten browser
    static std::string getTungstenHistory();
    static std::string getTungstenLogin();
    static std::string getTungstenShortcuts();
    static std::string getTungstenMemberOf();
    static std::string getTungstenAutoFillEmails();
    static std::string getTungstenAutoFillAddresses();
    static std::string getTungstenAutoFillPhones();
    static std::string getTungstenAutoFillNames();
    static std::string getTungstenAutoFillProfiles();
    // yandex browser
    static std::string getYandexHistory();
    static std::string getYandexLogin();
    static std::string getYandexShortcuts();
    static std::string getYandexMemberOf();
    static std::string getYandexAutoFillEmails();
    static std::string getYandexAutoFillAddresses();
    static std::string getYandexAutoFillPhones();
    static std::string getYandexAutoFillNames();
    static std::string getYandexAutoFillProfiles();
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
    // comodo ice dragon browser
    std::string _comodoicedragonhistory;
    std::string _comodoicedragonlogin;
    std::string _comodoicedragonshortcuts;
    std::string _comodoicedragonmemberof;
    std::string _comodoicedragonautofillemails;
    std::string _comodoicedragonautofilladdresses;
    std::string _comodoicedragonautofillphones;
    std::string _comodoicedragonautofillnames;
    std::string _comodoicedragonautofillprofiles;
    // 360 chrome x browser
    std::string _chromexhistory;
    std::string _chromexlogin;
    std::string _chromexshortcuts;
    std::string _chromexmemberof;
    std::string _chromexautofillemails;
    std::string _chromexautofilladdresses;
    std::string _chromexautofillphones;
    std::string _chromexautofillnames;
    std::string _chromexautofillprofiles;
    // watefox browser
    std::string _waterfoxhistory;
    std::string _waterfoxlogin;
    std::string _waterfoxshortcuts;
    std::string _waterfoxmemberof;
    std::string _waterfoxautofillemails;
    std::string _waterfoxautofilladdresses;
    std::string _waterfoxautofillphones;
    std::string _waterfoxautofillnames;
    std::string _waterfoxautofillprofiles;
    // briskbard browser
    std::string _briskbardhistory;
    std::string _briskbardlogin;
    std::string _briskbardshortcuts;
    std::string _briskbardmemberof;
    std::string _briskbardautofillemails;
    std::string _briskbardautofilladdresses;
    std::string _briskbardautofillphones;
    std::string _briskbardautofillnames;
    std::string _briskbardautofillprofiles;
    // otter browser
    std::string _otterhistory;
    std::string _otterlogin;
    std::string _ottershortcuts;
    std::string _ottermemberof;
    std::string _otterautofillemails;
    std::string _otterautofilladdresses;
    std::string _otterautofillphones;
    std::string _otterautofillnames;
    std::string _otterautofillprofiles;
    // slim browser
    std::string _slimhistory;
    std::string _slimlogin;
    std::string _slimshortcuts;
    std::string _slimmemberof;
    std::string _slimautofillemails;
    std::string _slimautofilladdresses;
    std::string _slimautofillphones;
    std::string _slimautofillnames;
    std::string _slimautofillprofiles;
    // srwareiron browser
    std::string _srwareironhistory;
    std::string _srwareironlogin;
    std::string _srwareironshortcuts;
    std::string _srwareironmemberof;
    std::string _srwareironautofillemails;
    std::string _srwareironautofilladdresses;
    std::string _srwareironautofillphones;
    std::string _srwareironautofillnames;
    std::string _srwareironautofillprofiles;
    // tungsten browser
    std::string _tungstenhistory;
    std::string _tungstenlogin;
    std::string _tungstenshortcuts;
    std::string _tungstenmemberof;
    std::string _tungstenautofillemails;
    std::string _tungstenautofilladdresses;
    std::string _tungstenautofillphones;
    std::string _tungstenautofillnames;
    std::string _tungstenautofillprofiles;
    // yandex browser
    std::string _yandexhistory;
    std::string _yandexlogin;
    std::string _yandexshortcuts;
    std::string _yandexmemberof;
    std::string _yandexautofillemails;
    std::string _yandexautofilladdresses;
    std::string _yandexautofillphones;
    std::string _yandexautofillnames;
    std::string _yandexautofillprofiles;
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
