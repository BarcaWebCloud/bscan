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

  class Datasource {
   public:
    Datasource();
    ~Datasource() = default;
    // postgresql
    std::string postgresqldatabases();
    std::string postgresqlversion();
    std::string postgresqlprofiles();
    std::string postgresqlpreferencies();
    std::string postgresqlconfig();
    std::string postgresqlpid();
    std::string postgresqlpath();
    std::string postgresqlport();
    std::string postgresqllogs();
    // postgresql
    static std::string getPostgresqlDatabases();
    static std::string getPostgresqlVersion();
    static std::string getPostgresqlProfiles();
    static std::string getPostgresqlPreferencies();
    static std::string getPostgresqlConfig();
    static std::string getPostgresqlPID();
    static std::string getPostgresqlPath();
    static std::string getPostgresqlPort();
    static std::string getPostgresqlLogs();

   private:
    // postgresql
    std::string _postgresqldatabases;
    std::string _postgresqlversion;
    std::string _postgresqlprofiles;
    std::string _postgresqlpreferencies;
    std::string _postgresqlconfig;
    std::string _postgresqlpid;
    std::string _postgresqlpath;
    std::string _postgresqlport;
    std::string _postgresqllogs;
  };

};
