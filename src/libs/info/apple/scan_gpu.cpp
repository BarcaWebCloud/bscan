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
#ifdef BSCAN_APPLE
#include <regex>
#include <string>
#include <vector>

#include "hwares/scan_gpu.h"

namespace bscan {

	std::string GPU::getVendor() {
	  // TODO: implement
	  return "<unknown>";
	}

	std::string GPU::getName() {
	  // TODO: implement
	  return "<unknown>";
	}

	std::string GPU::getDriverVersion() {
	  // TODO: implement
	  return "<unknown>";
	}

	int64_t GPU::getMemory_Bytes() {
	  // TODO: implement
	  return -1;
	}

};

#endif  // END BSCAN_APPLE