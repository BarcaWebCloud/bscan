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

#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <stdlib.h>

//inline std::string exec(std::string& command) {
//  std::string output;
//  std::vector<char> buffer(0x80);
//  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
//  if (!pipe) {
//    return "";
//  }
//  while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr) {
//    output.append(buffer.data());
//  }
//  return output;
//}


static int callback(void* data, int argc, char** argv, char** col_name) {
  int i;
  fprintf(stderr, "%s: ", (const char*)data);

  for (i = 0; i < argc; i++) {
    printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
  }

  printf("\n");
  return 0;
}