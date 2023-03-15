/************************************************************************************
      
 *      Copyright (C) 2021 - 2023, Barca Web Cloud, Inc. 
 *    Email: <opensource@barca.com>  GitHub: @BarcaWebCloud. 
 
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
#include <napi.h>
#include <string>
#include "hwares/hwares.h"
#include "swares/swares.h"

Napi::String cpu(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
  bscan::CPU cpu;

	std::string result = "Fabricante: " + cpu.vendor() +"\nModelo: "+cpu.getModelName();

	return Napi::String::New(env, result);
}

Napi::String ram(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
  bscan::RAM ram;

	std::string result = ram.getModel();

	return Napi::String::New(env, result);
}

Napi::String gpu(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
  bscan::GPU gpu;

	std::string result = "Fabricante: " + gpu.getVendor()+"\nModelo: "+gpu.getName();

	return Napi::String::New(env, result);
}

Napi::String mainboard(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
  bscan::MainBoard mo;

	std::string result = "Fabricante: " + mo.getVendor() +"\nModelo: " + mo.getName() + "\nVersão: " + mo.getVersion();

	return Napi::String::New(env, result);
}


Napi::String os(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
  bscan::OS os;

	std::string result = "SO: " + os.getFullName()+"\nDistribuição: "+ os.getName() + "\nVersão: " + os.getVersion() + "\nKernel: " + os.getKernel() + "\nHostname: " + os.getHostname() + "\nDomain Name: " + os.getDomainName();

	return Napi::String::New(env, result);
}

// callback of function when module is registered with Node.js
Napi::Object Init(Napi::Env env, Napi::Object exports) {
	// set a key on `exports`object
	exports.Set(
		Napi::String::New(env, "cpu"),
		Napi::Function::New(env, cpu)
	);

  exports.Set(
		Napi::String::New(env, "mainboard"),
		Napi::Function::New(env, mainboard)
	);

  exports.Set(
		Napi::String::New(env, "ram"),
		Napi::Function::New(env, ram)
	);
  
  exports.Set(
		Napi::String::New(env, "os"),
		Napi::Function::New(env, os)
	);
  
  exports.Set(
		Napi::String::New(env, "gpu"),
		Napi::Function::New(env, gpu)
	);

	return exports;
}

NODE_API_MODULE(bscan, Init)