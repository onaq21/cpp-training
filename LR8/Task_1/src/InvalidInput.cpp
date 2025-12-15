#include "../include/product.h"

void InvalidInput() {
  cout << "Invalid input, please try again: ";
  cin.clear();
  cin.ignore(10000, '\n');
}