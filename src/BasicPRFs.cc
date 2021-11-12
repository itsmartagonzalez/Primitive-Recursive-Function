#include "BasicPRFs.h"

// Always returns 0
std::vector<int> BasicPRFs::zero(std::vector<int> v) {
  return std::vector<int>(1, 0);
}

// Returns x + 1
std::vector<int> BasicPRFs::successor(std::vector<int> v) {
  return std::vector<int>(1, v[0] + 1);
}