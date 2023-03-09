#include <iostream> 
#include "bscan.h"

int main() { 
  bscan::CPU cpu;
	std::cout << "BSCAN MODULE TETST" << std::endl;

  std::cout << cpu.vendor() << std::endl;
}