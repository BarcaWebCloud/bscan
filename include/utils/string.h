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

#ifdef BSCAN_WINDOWS
  #include<iostream>

	using namespace std;

	static std::string upper(std::string str) {
	  for(int j=0;j<str.length();j++)
	    str[j]=toupper(str[j]);

	  return std::string(str);
	};

	static std::string lower(std::string str) {
	  for(int j=0;j<str.length();j++)
	    str[j]=tolower(str[j]);
	  return std::string(str);
	};
	// for string delimiter
	static std::vector<std::string> split(std::string s, std::string delimiter) {
	    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	    std::string token;
	    std::vector<std::string> res;

	    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
	        token = s.substr (pos_start, pos_end - pos_start);
	        pos_start = pos_end + delim_len;
	        res.push_back (token);
	    }

	    res.push_back (s.substr (pos_start));
	    return res;
	}
#endif