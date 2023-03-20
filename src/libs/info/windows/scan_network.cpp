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
#include "platform.h"

#ifdef BSCAN_WINDOWS

#include <sys/stat.h>
#include <sys/utsname.h>
#include <fstream>
#include <sstream>
#include <string>
#include "swares/scan_os.h"
#include "utils/stringutils.h"
#include <iostream>
#include <winsock.h>
#include <vector>
#include <array>
#include <numeric>

namespace bscan {

  std::string NET::enabledIPForward() {
    return "<unkenow>";
  }

  std::string NET::getAllAdapters() {
    int count = 0;
	  string ips;
    char hostname[80];
    if (gethostname(hostname, sizeof(hostname)) == SOCKET_ERROR) {
      return 'error ao tentar obter <hostname>';
    }

    struct hostent *phe = gethostbyname(hostname);
    if (phe == 0) {
      return 'error ao tentar obter <hostname>';
    }

    for (int i = 0; phe->h_addr_list[i] != 0; ++i) {
      struct in_addr addr;
      memcpy(&addr, phe->h_addr_list[i], sizeof(struct in_addr));

    	ips+=std::string(inet_ntoa(addr)) + std::string("\n");
    	count+= 1;
    }
    if (count >= 2) {
      return ips;
    } else {
      return "<unknow>"
    }
  }

  std::string NET::getPrivateIP() {
    return "<unkenow>";
  }

  std::string NET::getPublicIP() {
    return "<unkenow>";
  }

  std::string NET::getDomainName() {
    return "<unkenow>";
  }

  std::string OS::getKernel() {
    return "<unkenow>";
  }

  bool OS::getIs64bit() {
    return "<unkenow>";
  }

};

#endif  // END BSCAN_WINDOWS