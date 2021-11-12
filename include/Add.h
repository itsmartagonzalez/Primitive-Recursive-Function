#ifndef ADD_H
#define ADD_H
#include <iostream>
#include "ComplexPRFs.h"
#include "BasicPRFs.h"
#include "operations.h"
#pragma once

template <typename T>
class Add : public ComplexPRFs<T> {

  public:
    Add() {}
    ~Add() {}
    static std::vector<T> solve(std::vector<T>);

  protected:
    static std::vector<T> baseCase(std::vector<T>);
    static std::vector<T> recursiveCase(std::vector<T>);

};
#endif //ADD_H

/*
  Base case → suma(x, 0) = P₁(x)
  Recursive case → suma(x, s(y)) = s ∘ P₃(x, y, suma(x, y))
*/
template <typename T>
std::vector<T> Add<T>::solve(std::vector<T> args) {
  if (args[1] == 0) {
    return baseCase(args);
  }
  return recursiveCase(args);
}

template <typename T>
std::vector<T> Add<T>::baseCase(std::vector<T> args) {
  return BasicPRFs::projection<0>(args);
}

template <typename T>
std::vector<T> Add<T>::recursiveCase(std::vector<T> args) {
  std::vector<T> aux = args;
  aux[1]--;
  std::vector<T> recursive = solve(aux);
  aux.resize(recursive.size()  + args.size());
  std::copy(recursive.begin(), recursive.end(), aux.begin() + args.size());
  return composition<T>(BasicPRFs::successor, BasicPRFs::projection<2>)(aux);
}

