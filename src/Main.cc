#include "Add.h"
#include "Multiply.h"
#include <iostream>

int main() {
  std::vector<int> x = {5, 7};
  Add<int> add;
  Multiply<int> multiply;
  std::cout << "\n" << multiply.solve(x)[0];
}
