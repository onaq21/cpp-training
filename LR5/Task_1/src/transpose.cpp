#include "../include/matrix.h"

int* GetTranspose(int* arr, int order) {
  int *trans_arr = new int [order * order];
  for (int i = 0; i < order; ++i) {
    for (int j = 0; j < order; ++j) {
      trans_arr[j * order + i] = arr[i * order + j];
    }
  }
  return trans_arr;
}