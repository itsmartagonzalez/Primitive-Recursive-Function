#include "Add.h"
#include "Multiply.h"
#include "Power.h"
#include <iostream>

int main() {
  std::vector<int> x = {2, 8};
  Add<int> add;
  Multiply<int> multiply;
  Power<int> pow;
  std::cout << "\n" << pow.solve(x)[0];
}
