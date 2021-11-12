#ifndef BASICPRFS_H
#define BASICPRFS_H
#include <iostream>
#include "PRF.h"
#pragma once

class BasicPRFs : public PRF {

  public:
    BasicPRFs() {}
    ~BasicPRFs() {}
    static std::vector<int> zero(std::vector<int>);
    static std::vector<int> successor(std::vector<int>);
    template <int I>
    static std::vector<int> projection(std::vector<int>);

};
#endif //BASICPRFS_H


template <int I>
std::vector<int> BasicPRFs::projection(std::vector<int> v) {
  return std::vector<int>(1, v[I]);
}
