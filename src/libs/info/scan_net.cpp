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
#include "hwares/scan_net.h"
#include "utils/stringutils.h"

namespace bscan {

	Net::Net(
		std::string& name,
		std::string& manufacturer,
		std::string& permanentAddress,
		std::string& dnsHostname,
		std::string& serviceName,
		std::string& driverPath,
		std::string& status,
		std::string& macAddress,
		std::string& ipAddress,
		std::string& subnet,
		std::string& gateway
		
		)
	    : _name(name),
	     _manufacturer(manufacturer),
	     _permanentAddress(permanentAddress),
	     _dnsHostname(dnsHostname),
	     _serviceName(serviceName),
	     _driverPath(driverPath),
	     _status(status),
	     _macAddress(macAddress),
	     _ipAddress(ipAddress),
	     _subnet(subnet),
	     _gateway(gateway)
	     {}
	const std::string& Net::name() const { return _name; }
	const std::string& Net::manufacturer() const { return _manufacturer; }
	const std::string& Net::permanentAddress() const { return _permanentAddress; }
	const std::string& Net::dnsHostname() const { return _dnsHostname; }
	const std::string& Net::serviceName() const { return _serviceName; }
	const std::string& Net::driverPath() const { return _driverPath; }
	const std::string& Net::status() const { return _status; }
	const std::string& Net::macAddress() const { return _macAddress; }
	const std::string& Net::ipAddress() const { return _ipAddress; }
	const std::string& Net::subnet() const { return _subnet; }
	const std::string& Net::gateway() const { return _gateway; }

};
