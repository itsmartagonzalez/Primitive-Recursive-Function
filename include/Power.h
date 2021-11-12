#ifndef POWER_H
#define POWER_H
#include "Multiply.h"
#pragma once

template <typename T>
class Power : public ComplexPRFs<T> {

  public:
    Power() {}
    ~Power() {}
    static std::vector<T> solve(std::vector<T>);

  protected:
    static std::vector<T> baseCase(std::vector<T>);
    static std::vector<T> recursiveCase(std::vector<T>);

};
#endif //POWER_H

template <typename T>
std::vector<T> Power<T>::solve(std::vector<T> args) {
  if (args[1] == 0) {
    return baseCase(args);
  }
  return recursiveCase(args);
}

template <typename T>
std::vector<T> Power<T>::baseCase(std::vector<T> args) {
  return composition<T>(BasicPRFs::successor, BasicPRFs::zero)(args);
}

template <typename T>
std::vector<T> Power<T>::recursiveCase(std::vector<T> args) {
  std::vector<T> aux = args;
  aux[1]--;
  std::vector<T> recursive = solve(aux);
  aux.resize(recursive.size()  + args.size());
  std::copy(recursive.begin(), recursive.end(), aux.begin() + args.size());
  return composition<T>(Multiply<T>::solve, combination<T>(BasicPRFs::projection<0>, BasicPRFs::projection<2>))(aux);
}

