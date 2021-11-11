#include "Add.h"
#include <iostream>

int main() {
  std::vector<int> x = {5, 7};
  Add<int> add;
  std::cout << "\n" << add.solve(x)[0];
}
