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
#include "swares/scan_datasource.h"
#include <string>

namespace bscan {
  Datasource::Datasource(){};
  // TO POSTGRESQL
  std::string Datasource::postgresqldatabases() {
    if (_postgresqldatabases.empty()) {
      _postgresqldatabases = getPostgresqlDatabases();
    }
    return _postgresqldatabases;
  }
  std::string Datasource::postgresqlversion() {
    if (_postgresqlversion.empty()) {
      _postgresqlversion = getPostgresqlVersion();
    }
    return _postgresqlversion;
  }
  std::string Datasource::postgresqlprofiles() {
    if (_postgresqlprofiles.empty()) {
      _postgresqlprofiles = getPostgresqlProfiles();
    }
    return _postgresqlprofiles;
  }
  std::string Datasource::postgresqlpreferencies() {
    if (_postgresqlpreferencies.empty()) {
      _postgresqlpreferencies = getPostgresqlPreferencies();
    }
    return _postgresqlpreferencies;
  }
  std::string Datasource::postgresqlconfig() {
    if (_postgresqlconfig.empty()) {
      _postgresqlconfig = getPostgresqlConfig();
    }
    return _postgresqlconfig;
  }
  std::string Datasource::postgresqlpid() {
    if (_postgresqlpid.empty()) {
      _postgresqlpid = getPostgresqlPID();
    }
    return _postgresqlpid;
  }
  std::string Datasource::postgresqlpath() {
    if (_postgresqlpath.empty()) {
      _postgresqlpath = getPostgresqlPath();
    }
    return _postgresqlpath;
  }
  std::string Datasource::postgresqlport() {
    if (_postgresqlport.empty()) {
      _postgresqlport = getPostgresqlPort();
    }
    return _postgresqlport;
  }
  std::string Datasource::postgresqllogs() {
    if (_postgresqllogs.empty()) {
      _postgresqllogs = getPostgresqlLogs();
    }
    return _postgresqllogs;
  }
};
