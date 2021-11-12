#ifndef COMPLEXPRFS_H
#define COMPLEXPRFS_H
#include <iostream>
#include "PRF.h"
#pragma once

template <typename T>
class ComplexPRFs : public PRF {

  public:
    ComplexPRFs() {}
    ~ComplexPRFs() {}
    static std::vector<T> solve(std::vector<T>);

  protected:
    static std::vector<T> baseCase(std::vector<T>);
    static std::vector<T> recursiveCase(std::vector<T>);

};
#endif //COMPLEXPRFS_H