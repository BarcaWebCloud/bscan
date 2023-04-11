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
#include <random>

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

  static std::string randstr(std::size_t length) {
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i){
      random_string += CHARACTERS[distribution(generator)];
    }
    return random_string;
	};
#endif