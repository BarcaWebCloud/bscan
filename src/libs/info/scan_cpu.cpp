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
#include "hwares/scan_cpu.h"
#include "hwares/scan_cpuid.h"
#include <string>
#include <vector>
#include "platform.h"

namespace bscan {

  CPU::CPU(int id) { _id = id; }

  std::string& CPU::modelName() {
    if (_modelName.empty()) {
      _modelName = std::move(getModelName());
    }
    return _modelName;
  }

  std::string& CPU::vendor() {
    if (_vendor.empty()) {
      _vendor = std::move(getVendor());
    }
    return _vendor;
  }

  int CPU::cacheSize_Bytes() {
    if (_cacheSize_Bytes == -1) {
      _cacheSize_Bytes = getCacheSize_Bytes();
    }
    return _cacheSize_Bytes;
  }

  int CPU::numPhysicalCores() {
    if (_numPhysicalCores == -1) {
      _numPhysicalCores = getNumPhysicalCores();
    }
    return _numPhysicalCores;
  }

  int CPU::numLogicalCores() {
    if (_numLogicalCores == -1) {
      _numLogicalCores = getNumLogicalCores();
    }
    return _numLogicalCores;
  }

  int CPU::maxClockSpeed_kHz() {
    if (_maxClockSpeed_kHz == -1) {
      _maxClockSpeed_kHz = getMaxClockSpeed_kHz();
    }
    return _maxClockSpeed_kHz;
  }

  int CPU::regularClockSpeed_kHz() {
    if (_regularClockSpeed_kHz == -1) {
      _regularClockSpeed_kHz = getRegularClockSpeed_kHz();
    }
    return _regularClockSpeed_kHz;
  }

  InstructionSet& CPU::instructionSet() {
    if (!_instructionSet._init_) {
  #if defined(HWINFO_X86)
      uint32_t regs[4]{};
      cpuid::cpuid(1, 0, regs);
      _instructionSet = InstructionSet{static_cast<bool>(regs[3] & AVX_POS),
                                       static_cast<bool>(regs[3] & SSE_POS),
                                       static_cast<bool>(regs[3] & SSE2_POS),
                                       static_cast<bool>(regs[2] & SSE3_POS),
                                       static_cast<bool>(regs[2] & SSE41_POS),
                                       static_cast<bool>(regs[2] & SSE42_POS),
                                       static_cast<bool>(regs[2] & AVX_POS),
                                       false,
                                       true};
      cpuid::cpuid(7, 0, regs);
      _instructionSet._isAVX2 = static_cast<bool>(regs[1] & AVX2_POS);
  #else
      _instructionSet = InstructionSet();
  #endif
    }
    return _instructionSet;
  }

  CPU& Socket::CPU() { return _cpu; }

};