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
