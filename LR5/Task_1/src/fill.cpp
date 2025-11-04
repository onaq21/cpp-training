#include "../include/matrix.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void FillMatrix(int* arr, int order) {
  int value;
  for (int i = 0; i < order; ++i) {
    for (int j = 0; j < order; ++j) {
      if (i + 1 <= 5) value = 2 * j * (i * j - 1);
      else value = 3 * (i * j - 1);
      arr[i * order + j] = value;
    }
  }
}