#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void PrintMatrix(int* arr, int rows, int columns) {
  for(int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      cout << arr[i * columns + j] << " ";
    }
    cout << endl;
  }
}

const int kMaxSize = 10000;

int main() {
  cout << "=============================================\n";
  cout << "              Task context menu              \n";
  cout << "---------------------------------------------\n";
  cout << "Task: Find the maximum element above the secondary diagonal of the matrix;\n";
  cout << "Who completed the task: Kostya Kudritsky;\n";
  cout << "Option: 9;\n\n";

  int rows, columns, value, max_element;
  bool found;
  char answer;

  do {
    cout << "Enter the number of rows and columns(max " << kMaxSize << "):"<< endl;
    while(!(cin >> rows >> columns) || (rows <= 0 || rows > kMaxSize) || (columns <= 0 || columns > kMaxSize)) {
      cout << "Invalid input, please try again" << endl;
      cin.clear();
      cin.ignore(100000, '\n');
    }

    int array[rows][columns];

    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < columns; ++j) {
        cout << "Enter the value of the element at row " << i << ", column " << j << endl;
        while(!(cin >> value)) {
          cout << "Invalid input, please try again" << endl;
          cin.clear();
          cin.ignore(100000, '\n');
        }
        array[i][j] = value;
      }
    }

    found = false;

    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < columns; ++j) {
        if (i + j < columns - 1) {
          if (!found) {
            max_element = array[i][j];
            found = true;
          }
          if(array[i][j] > max_element) {
            max_element = array[i][j];
          }
        }
      }
    }

    cout << "\nYour matrix (total: " << rows * columns << " elements):" << endl;
    PrintMatrix(&array[0][0], rows, columns);
    if (found) {
      cout << "The maximum element above the secondary diagonal of the matrix is " << max_element << endl;
    }
    else {
      cout << "There is no element above the secondary diagonal in the matrix." << endl;
    }

    cout << "Exit the program? (y or n)" << endl;
    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Invalid input, please enter y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}