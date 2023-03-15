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
#pragma once

#include <string>
#include <vector>

#include "hwares/scan_cpu.h"
#include "hwares/scan_disk.h"
#include "hwares/scan_gpu.h"
#include "hwares/scan_ram.h"

namespace bscan {

class System {
 public:
  System() = default;

  std::vector<CPU>& CPUs() const;
  std::vector<GPU>& GPUs() const;
  std::vector<RAM>& RAMs() const;
  std::vector<Disk>& Disks() const;

 private:
  std::vector<CPU> _cpuSockets;
  std::vector<GPU> _gpus;
  std::vector<RAM> _ramBars;
  std::vector<Disk> _disks;
};

};
