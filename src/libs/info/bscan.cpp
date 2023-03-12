#include <napi.h>
#include <string>
#include "hwares/hwares.h"
#include "swares/swares.h"

Napi::String cpu(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
  bscan::CPU cpu;

	std::string result = "Modelo: \n"+cpu.getModelName();

	return Napi::String::New(env, result);
}

Napi::String ram(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
  bscan::RAM ram;

	std::string result = ram.totalSize_Bytes();

	return Napi::String::New(env, result);
}

Napi::String mainboard(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
  bscan::MainBoard mo;

	std::string result = mo.name();

	return Napi::String::New(env, result);
}

// callback of function when module is registered with Node.js
Napi::Object Init(Napi::Env env, Napi::Object exports) {
	// set a key on `exports`object
	exports.Set(
		Napi::String::New(env, "cpu"),
		Napi::Function::New(env, cpu),
    Napi::String::New(env, "mainboard"),
		Napi::Function::New(env, mainboard),
    Napi::String::New(env, "ram"),
		Napi::Function::New(env, ram)
	);

	return exports;
}

NODE_API_MODULE(bscan, Init)