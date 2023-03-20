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
#include "platform.h"
#include <stdio.h>
#ifdef BSCAN_WINDOWS
#include <direct.h>
#define getDir _getcwd
#else
#include <unistd.h>
#define getDir getcwd
#endif
#include<iostream>
#include<dirent.h>

std::string getCurrentDir(void) {
  char buff[FILENAME_MAX];
  getDir( buff, FILENAME_MAX );
  std::string currentDir(buff);

  return currentDir;
}

std::string getFoldersAndFilesInCurrentDir(void) {
  struct dirent *d;
  DIR *dr;
  dr = opendir(".");
  std::string res;
  if(dr!=NULL) {
    for(d=readdir(dr); d!=NULL; d=readdir(dr)) {
      res+= std::string(d->d_name) + std::string("\n");
    }
    closedir(dr);
  }
  else
    return "<null>";
  return res;
}