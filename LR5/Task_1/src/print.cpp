#include "../include/matrix.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void PrintMatrix(int* arr, int order) {
  for (int i = 0; i < order; ++i) {
    for (int j = 0; j < order; ++j) {
      cout << arr[i * order + j] << " ";
    }
    cout << "\n";
  }
}