#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void InvalidInput() {
  cout << "Invalid input, please try again" << endl;
  cin.clear();
  cin.ignore(100000, '\n');
}

void PrintMatrix(int* arr, int rows, int columns) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      cout << arr[i * columns + j] << " ";
    }
    cout << "\n";
  }
}

void PrintArray(int* arr, int size) {
  for (int i = 0; i < size; ++i) {
    cout << arr[i] << ", ";
  }
  cout << "\n";
}

void FillMatrix(int* arr, int rows, int columns) {
  int value;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      cout << "Enter the value of element (at x: " << j << ", y: " << i << "):\n";
      while(!(cin >> value)) InvalidInput();
      arr[i * columns + j] = value;
    }
  }
}



int* GetOddElementsFromEvenColumns(int* arr, int rows, int columns, int& count) {
  for (int index = 0; index < rows * columns; ++index)
    if ((index % columns) % 2 == 0 && arr[index] % 2 != 0) ++count;

  int* result = new int[count];
  count = 0;

  for (int index = 0; index < rows * columns; ++index) {
    if ((index % columns) % 2 == 0 && arr[index] % 2 != 0) {
      result[count] = arr[index];
      ++count;
    }
  }
  return result;
}

double GetAverage(int* arr, int size) {
  if (size == 0) return 0.0;
  double sum = 0;
  for (int i = 0; i < size; ++i)
    sum += arr[i];
  return sum / size;
}

const int kMaxSize = 10000;

int main() {
  cout << "=============================================\n";
  cout << "              Task context menu              \n";
  cout << "---------------------------------------------\n";
  cout << "Task: Create an array with odd elements from even columns of the original matrix\n";
  cout << "Completed by: Kostya Kudritsky;\n";

  int rows, columns, size;
  double average;
  char answer;

  do {
    cout << "Enter the number of rows and columns of the matrix(max: " << kMaxSize << ")\n";
    while(!(cin >> rows >> columns) || rows < 1 || rows > kMaxSize || columns < 1 || columns > kMaxSize) InvalidInput();
    
    int* matrix = new int[rows * columns];
    FillMatrix(matrix, rows, columns);

    cout << "Your matrix:\n";
    PrintMatrix(matrix, rows, columns);

    size = 0;
    int* array = GetOddElementsFromEvenColumns(matrix, rows, columns, size);

    if (size ==0) cout << "There are not odd elements from even columns of your matrix\n";
    else {
      average = GetAverage(array, size);

      cout << "Odd elements from even columns of your matrix: ";
      PrintArray(array, size);  
      cout << "Their average value: " << average << "\n";
    }

    delete[] matrix;
    delete[] array;
    cout << "Exit the program? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Invalid input, please enter y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}