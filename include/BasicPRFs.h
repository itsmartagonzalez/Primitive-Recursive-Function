#ifndef BASICPRFS_H
#define BASICPRFS_H
#include <iostream>
#include "PRF.h"
#pragma once

template <typename T>
class BasicPRFs : public PRF {

  public:
    BasicPRFs() {}
    ~BasicPRFs() {}
    static std::vector<T> zero(std::vector<T>);
    static std::vector<T> successor(std::vector<T>);
    static std::vector<T> projection(std::vector<T>);

};
#endif //BASICPRFS_H

template <typename T>
std::vector<T> BasicPRFs<T>::zero(std::vector<T> v) {
  return std::vector<int>(1, 0);
}

template <typename T>
std::vector<T> BasicPRFs<T>::successor(std::vector<T> v) {
  return std::vector<int>(1, v[0] + 1);
}

template <typename T>
std::vector<T> BasicPRFs<T>::projection(std::vector<T> v) {
  return std::vector<int>(1, v[v.back()]);
}
