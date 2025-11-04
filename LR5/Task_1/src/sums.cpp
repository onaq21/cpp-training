#include "../include/matrix.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int SumEvenRowsOddCols(int* arr, int order) {
  int sum = 0;
  for (int i = 0; i < order; ++i) {
    if ((i + 1) % 2 != 0) continue;
    for (int j = 0; j < order; ++j) {
      if ((j + 1) % 2 == 0) continue;
      sum += arr[i * order + j];
    }
  }
  return sum;
}

int SumOddRowsEvenCols(int* arr, int order) {
  int sum = 0;
  for (int i = 0; i < order; ++i) {
    if ((i + 1) % 2 == 0) continue;
    for (int j = 0; j < order; ++j) {
      if ((j + 1) % 2 != 0) continue;
      sum += arr[i * order + j];
    }
  }
  return sum;
}