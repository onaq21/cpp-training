#include <iostream>

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

int main() {
  cout << "=============================================\n";
  cout << "              Task context menu              \n";
  cout << "---------------------------------------------\n";
  cout << "Task: Check if the matrix is a magic square;\n";
  cout << "Who completed the task: Kostya Kudritsky;\n";
  cout << "Option: 9;\n\n";

  int size, value, row_sum, col_sum, magic_sum, diag1, diag2;
  bool is_magic;
  char answer;

  do {
    cout << "Enter the order of the square matrix:" << endl;
    while(!(cin >> size) || size <= 0) {
      cout << "Invalid input, please try again" << endl;
      cin.clear();
      cin.ignore(100000, '\n');
    }

    int* array = new int[size * size];
    magic_sum = 0;
    row_sum = 0;
    col_sum = 0;
    diag1 = 0;
    diag2 = 0;
    is_magic = true;

    for(int i = 0; i < size; ++i) {
      for(int j = 0; j < size; ++j) {
        cout << "Enter the value of the element at row " << i << ", column " << j << endl;
        while(!(cin >> value)) {
          cout << "Invalid input, please try again" << endl;
          cin.clear();
          cin.ignore(100000, '\n');
        }
        array[i * size + j] = value;
      }
    }

    for(int i = 0; i < size; ++i) {
      magic_sum += array[i];
    }

    for(int i = 0; i < size; ++i) {
      row_sum = 0, col_sum = 0;
      for(int j = 0; j < size; ++j) {
        row_sum += array[i * size + j];
        col_sum += array[j * size + i];
      }
      if (row_sum != magic_sum || col_sum != magic_sum) {
        is_magic = false;
        break;
      }

      diag1 += array[i * size + i];
      diag2 += array[i * size + (size - 1 - i)];
    }

    if(diag1 != magic_sum || diag2 != magic_sum) {
      is_magic = false;
    }

    cout << "\nYour matrix (total: " << size * size << " elements):" << endl;
    PrintMatrix(array, size);
    if (is_magic) {
      cout << "Your matrix is a magic square" << endl;
    }
    else {
      cout << "Your matrix isn't a magic square" << endl;
    }

    delete[] array;

    cout << "Exit the program? (y or n)" << endl;
    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Invalid input, please enter y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}