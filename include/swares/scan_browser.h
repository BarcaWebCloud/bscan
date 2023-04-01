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

  class BROWSER {
   public:
    BROWSER();
    ~BROWSER() = default;

    std::string history();
    std::string media();
    std::string profile();
    std::string visitedlinks();
    std::string watched();
    std::string downloads();
    std::string bookmarks();
    std::string preferencies();
    std::string extensions();
    std::string apps();
    std::string logs();
    
    static std::string getHistory();
    static std::string getMedia();
    static std::string getProfile();
    static std::string getVisitedLinks();
    static std::string getWatched();
    static std::string getDownloads();
    static std::string getBookmarks();
    static std::string getPreferencies();

   private:
    std::string _history;
    std::string _media;
    std::string _profile;
    std::string _visitedlinks;
    std::string _watched;
    std::string _downloads;
    std::string _bookmarks;
    std::string _preferencies;
  };

};
