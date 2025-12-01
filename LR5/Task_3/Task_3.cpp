#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

void InvalidInput() {
  cout << "Invalid input, please try again" << endl;
  cin.clear();
  cin.ignore(100000, '\n');
}

int Min(int a, int b) {
  if (a > b) return b;
  return a;
}

int* FillArrayAndReturnEvenDiagonalArray(int * arr, int rows, int columns, int* size) {
  int value;
  int count = 0;

  int* temp = new int[Min(rows, columns)];
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      cout << "Enter the value of element (at x: " << j << ", y: " << i << "): ";
      while(!(cin >> value)) {
        InvalidInput();
      }
      arr[i * columns + j] = value;
      if (i == j && value % 2 == 0) {
        temp[count] = value;
        ++count;
      }
    }
  }

  int* array = new int[count];
  for (int i = 0; i < count; ++i) {
    array[i] = temp[i];
  }

  *size = count;
  delete[] temp;
  return array;
}

void PrintMatrix(int* arr, int rows, int columns) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      cout << arr[i * columns + j] << " ";
    }
    cout << "\n";
  }
}

const int kMaxSize = 10000;

int main() {
  cout << "=============================================\n";
  cout << "              Task context menu              \n";
  cout << "---------------------------------------------\n";
  cout << "Task: Create an array that contains the even elements from the main diagonal of the matrix\n";
  cout << "Completed by: Kostya Kudritsky;\n";

  int rows, columns, product, size;
  char answer;

  do {
    cout << "Enter the number of rows and columns(max " << kMaxSize << "):\n";
    while(!(cin >> rows >> columns) || rows <= 0 || rows > kMaxSize || columns <= 0 || columns > kMaxSize) {
      InvalidInput();
    }

    int* matrix = new int[rows * columns];
    product = 1;

    int* array = FillArrayAndReturnEvenDiagonalArray(matrix, rows, columns, &size);

    cout << "Your matrix:\n";
    PrintMatrix(matrix, rows, columns);

    if (size == 0) cout << "There are no even elements on the main diagonal of your matrix:(";
    else {
      cout << "The even elements from the main diagonal of your matrix: ";
      for (int i = 0; i < size; ++i) {
        int value = *(array + i);
        cout << value << ", ";
        product *= value;
      }
      cout << "\nTheir product: " << product;
    }

    delete[] matrix;
    delete[] array;

    cout << "\nExit the program? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Invalid input, please enter y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}