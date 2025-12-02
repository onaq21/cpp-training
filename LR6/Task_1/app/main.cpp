#include "../include/functions.h"

int main() {
  char* str = new char[81];
  ReadInput(str);
  PrintSortedNumbers(str);

  delete[] str;
}