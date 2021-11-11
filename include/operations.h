#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template <typename T>
using fun = std::function<std::vector<T>(std::vector<T>)>;

template <typename T>
fun<T> combination(fun<T> f, fun<T> g) {
  return [&](std::vector<T> args) {
    std::vector<T> v1 = f(args);
    std::vector<T> v2 = g(args);
    std::vector<T> result(v1.size() + v2.size());
    std::copy(v1.begin(), v1.end(), result.begin());
    std::copy(v2.begin(), v2.end(), result.begin() + v1.size());
    return result;
  };
}

template <typename T>
fun<T> composition(fun<T> f, fun<T> g) {
  return [&](std::vector<T> args) {
    return f(g(args));
  };
}
