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
std::vector<T> suma(std::vector<T> a) {
  std::vector<T> vec;
  vec.push_back(a[0] + 4);
  return vec;
}

template <typename T>
std::vector<T> mul(std::vector<T> a) {
  std::vector<T> vec;
  vec.push_back(a[0] * a[1]);
  return vec;
}

template <typename T>
fun<T> composition(fun<T> f, fun<T> g) {
  return [&](std::vector<T> p) {
    return f(g(p));
  };
}





int main() {
  std::vector<int> y = {3, 2};
  auto x = composition<int>(suma<int>, mul<int>)(y);
  std::cout << "\n" << x[0];
  auto m = combination<int>(suma<int>, mul<int>)(y);
  std::cout << "\n(";
  for (auto w : m) {
    std::cout << ", " << w;
  }
  std::cout << ")";
}
