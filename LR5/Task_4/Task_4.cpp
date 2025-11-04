#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void InvalidInput() {
  cout << "Invalid input, please try again" << endl;
  cin.clear();
  cin.ignore(100000, '\n');
}

void PrintMatrix(double* arr, int rows, int columns) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      cout << arr[i * columns + j] << " ";
    }
    cout << "\n";
  }
}

void PrintZeroPositions(int* arr, int size) {
  for (int i = 0; i < size; i += 2) {
    cout << "x: " << arr[i] << ", y: " << arr[i + 1] << "\n";
  }
}

int FillMatrixAndCountZeroElements(double* arr, int rows, int columns) {
  double value;
  int count = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      cout << "Enter the value of element (at x: " << j << ", y: " << i << "):\n";
      while(!(cin >> value)) InvalidInput();
      arr[i * columns + j] = value;
      if (value == 0.0) ++count;
    }
  }
  return count;
}

int* CheckZeroElements(double *arr, int rows, int columns, int count) {
  int counter = 0;
  int* positions = new int[count * 2];
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      if (arr[i * columns + j] == 0.0) {
        positions[counter] = j;
        positions[counter + 1] = i;
        counter += 2;
      }
    }
  }
  return positions;
}

void ReverseInPlace(double* arr, int rows, int columns) {
  double temp;
  int total = rows * columns;
  for (int i = 0; i < total / 2; ++i) {
    temp = arr[i];
    arr[i] = arr[total - 1 - i];
    arr[total - 1 - i] = temp;
  }
}

const int kMaxSize = 10000;

int main() {
  cout << "=============================================\n";
  cout << "              Task context menu              \n";
  cout << "---------------------------------------------\n";
  cout << "Task: Check for zero elements in a matrix, find their positions and count, then reverse the matrix\n";
  cout << "Completed by: Kostya Kudritsky;\n";

  int rows, columns, count;
  char answer;

  do {
    cout << "Enter the number of rows and columns of the matrix(max: " << kMaxSize << ")\n";
    while(!(cin >> rows >> columns) || rows < 1 || rows > kMaxSize || columns < 1 || columns > kMaxSize) {
      InvalidInput();
    }

    double* matrix = new double[rows * columns];
    count = FillMatrixAndCountZeroElements(matrix, rows, columns);

    cout << "Your matrix:\n";
    PrintMatrix(matrix, rows, columns);

    if (count == 0) cout << "There are not zero elements in your matrix\n";
    else {
      int* zero_positions = CheckZeroElements(matrix, rows, columns, count);
      cout << "Number of zero elements in your matrix: " << count << "\n";
      cout << "Their positions:\n";
      PrintZeroPositions(zero_positions, count * 2);
      delete[] zero_positions;
    }

    cout << "Your reverse matrix:\n";
    ReverseInPlace(matrix, rows, columns);
    PrintMatrix(matrix, rows, columns);

    delete[] matrix;

    cout << "Exit the program? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Invalid input, please enter y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}