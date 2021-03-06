#include "Power.h"
#include <iostream>

int main(int argc, char *argv[]) {
  bool stop = false;
  Power<int> pow;
  int base, exponent;
  std::cout << "\n======Welcome to the Power simulator======\nβ This program allows you to solve a number π₯ to the power of π¦ (π₯ΚΈ)\n(Bare in mind that due to the recursive calls, the program might require more memory than what your PC has)\n";
  
  while (!stop) {
    std::vector<int> exponentiation;
    std::cout << "\nPlease, introduce your base number π₯\n β";
    std::cin >> base;
    exponentiation.push_back(base);

    std::cout << "Please, introduce your exponent number π¦\n β";
    std::cin >> exponent;
    exponentiation.push_back(exponent);

    std::cout << "\n" << base << "^" << exponent << " = " << pow.solve(exponentiation)[0];
    std::cout << "\n\n0. Solve another operation.\n1. Exit the program.\n β ";
    std::cin >> stop;
  }

  std::cout << "\nThank you for using this program. Have a nice day!\n";
}