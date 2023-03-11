#include <napi.h>
#include <string>
#include "../../../include/hwares/hwares.h"
#include "../../../include/swares/swares.h"

Napi::String cpu(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
  bscan::CPU cpu;

	std::string result = cpu.vendor();

	return Napi::String::New(env, result);
}

// callback of function when module is registered with Node.js
Napi::Object Init(Napi::Env env, Napi::Object exports) {
	// set a key on `exports`object
	exports.Set(
		Napi::String::New(env, "cpu"),
		Napi::Function::New(env, cpu)
	);

	return exports;
}

NODE_API_MODULE(bscan, Init)