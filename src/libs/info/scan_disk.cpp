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
#include "hwares/scan_disk.h"
#include "utils/stringutils.h"

namespace bscan {

	Disk::Disk(std::string& vendor, std::string& model, std::string& serialNumber, int64_t size_Bytes)
	    : _vendor(vendor), _model(model), _serialNumber(serialNumber) {
	  _size_Bytes = size_Bytes;
	}

	const std::string& Disk::vendor() const { return _vendor; }

	const std::string& Disk::model() const { return _model; }

	const std::string& Disk::serialNumber() const { return _serialNumber; }

	int64_t Disk::size_Bytes() const { return _size_Bytes; }

};
