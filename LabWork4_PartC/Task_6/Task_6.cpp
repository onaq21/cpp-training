#include <iostream>
#include <cstdint>

using std::cout;
using std::cin;
using std::endl;

void PrintMatrix(int* arr, int size) {
  for(int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      cout << arr[i * size + j] << " ";
    }
    cout << endl;
  }
}

void InvalidInput() {
  cout << "Invalid input, please try again" << endl;
  cin.clear();
  cin.ignore(100000, '\n');
}

int main() {
  cout << "=============================================\n";
  cout << "              Task context menu              \n";
  cout << "---------------------------------------------\n";
  cout << "Task: Build a magic square of the entered order;\n";
  cout << "Who completed the task: Kostya Kudritsky;\n";

  uint32_t order, row, column, row_new, column_new;
  char answer;

  do {
    cout << "Enter the order of the magic square(order < 10 000):" << endl;
    while (!(cin >> order) || order < 3 || order > 10000) {
      InvalidInput();
    }

    int* array = new int[order * order] {};
    row = 0;
    column = order / 2;

    if(order % 2 != 0) {
      array[column] = 1;

      for(uint32_t number = 2; number <= order * order; ++number) {
        row_new = (row - 1 + order) % order;
        column_new = (column + 1) % order;
        if (array[row_new * order + column_new] == 0) {
          row = row_new;
          column = column_new;
        }
        else row = (row + 1) % order;

        array[row * order + column] = number;
      }
    }
    else if (order % 4 == 0) {
      for (int y = 0; y < order; ++y) {
        for (int x = 0; x < order; ++x) {
          uint32_t number = y * order + x + 1;
          if (y % 4 == x % 4 || (y + x) % 4 == 3) {
            array[y * order + x] = order * order + 1 - number;
          }
          else {
            array[y * order + x] = number;
          }
        }
      }
    }
    else {
      int p = order / 2;
      int p2 = p * p;
      int* S = new int[p2] {};
      int row = 0, column = p / 2;
      S[p / 2] = 1;
      for(uint32_t number = 2; number <= p2; ++number) {
      row_new = (row - 1 + p) % p;
      column_new = (column + 1) % p;
      if (S[row_new * p + column_new] == 0) {
        row = row_new;
        column = column_new;
      }
      else row = (row + 1) % p;

      S[row * p + column] = number;
      }

      for (int i = 0; i < p * p; ++i) {
        int x = i % p, y = i / p;
        int el = S[y * p + x];
        array[y * order + x] = el;
        array[y * order + x + p] = el + 2 * p2;
        array[(y + p) * order + x] = el + 3 * p2;
        array[(y + p) * order + x + p] = el + p2;
      }

      delete[] S;

      for (int i = 0; i < p; ++i) {
        int k = order / 4;
        
        for (int j = 0; j < k; ++j) {
          int temp = array[i * order + j];
          array[i * order + j] = array[(i + p) * order + j];
          array[(i + p) * order + j] = temp;
        }

        for (int j = order - k; j < order - 1; ++j) {
          int temp = array[i * order + j];
          array[i * order + j] = array[(i + p) * order + j];
          array[(i + p) * order + j] = temp;
        }
      }

      int temp = array[p / 2 * order + p / 2];
      array[p / 2 * order + p / 2] = array[(3 * p / 2) * order + p / 2];
      array[(3 * p / 2) * order + p / 2] = temp;

      temp = array[p / 2 * order];
      array[p / 2 * order] = array[(3 * p / 2) * order];
      array[(3 * p / 2) * order] = temp;
    }

    cout << "Your magic square:" << endl;
    PrintMatrix(array, order);

    delete[] array;

    cout << "Exit the program? (y or n)" << endl;
    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Invalid input, please enter y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}