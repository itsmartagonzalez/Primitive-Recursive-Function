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
    virtual std::vector<T> solve(std::vector<T>) = 0;

  protected:
    virtual std::vector<T> baseCase(std::vector<T>) = 0;
    virtual std::vector<T> recursiveCase(std::vector<T>) = 0;

};
#endif //COMPLEXPRFS_H