#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

//fun = function that receives and returns a vector<T>
template <typename T>
using fun = std::function<std::vector<T>(std::vector<T>)>;

/*
  It recieves two functions as declared above and executes them both
  with the arguments received in the lambda function (args).
  Then a vector with both of the results is returned
*/
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

/*
  The function g is executed with the args given in the
  lambda function. The result is passed to the f function.
*/
template <typename T>
fun<T> composition(fun<T> f, fun<T> g) {
  return [&](std::vector<T> args) {
    return f(g(args));
  };
}
