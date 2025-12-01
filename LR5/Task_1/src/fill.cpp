#include "../include/matrix.h"

void FillMatrix(int* arr, int order) {
  int value;
  for (int i = 0; i < order; ++i) {
    for (int j = 0; j < order; ++j) {
      if (i + 1 <= 5) value = 2 * (j + 1) * ((i + 1) * (j + 1) - 1);
      else value = 3 * ((i + 1) * (j + 1) - 1);
      arr[i * order + j] = value;
    }
  }
}