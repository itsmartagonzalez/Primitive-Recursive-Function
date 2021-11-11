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
    std::vector<T> solve(std::vector<T>);

  protected:
    std::vector<T> baseCase(std::vector<T>);
    std::vector<T> recursiveCase(std::vector<T>);

};
#endif //ADD_H

template <typename T>
std::vector<T> Add<T>::solve(std::vector<T> args) {
  if (args[1] == 0) {
    return baseCase(args);
  }
  return recursiveCase(args);
}

template <typename T>
std::vector<T> Add<T>::baseCase(std::vector<T> args) {
  args.push_back(0);
  return BasicPRFs<T>::projection(args);
}

template <typename T>
std::vector<T> Add<T>::recursiveCase(std::vector<T> args) {
  std::vector<T> aux = args;
  aux[1] = aux[1] - 1;
  std::vector<T> recursive = solve(aux);
  aux.resize(recursive.size()  + args.size());
  std::copy(recursive.begin(), recursive.end(), aux.begin() + args.size());
  aux.push_back(2);
  auto x = composition<T>(BasicPRFs<T>::successor, BasicPRFs<T>::projection)(aux);
  return x;
}

