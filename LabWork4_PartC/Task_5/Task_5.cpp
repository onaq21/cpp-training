#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void InvalidInput() {
  cout << "Invalid input, please try again" << endl;
  cin.clear();
  cin.ignore(100000, '\n');
}

void PrintMatrix(char* arr, int rows, int columns) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      char c = arr[i * columns + j];
      if (c == '.') cout << "\033[1m" << c << "\033[0m ";
      else if (c == '*') cout << "\033[31m" << c << "\033[0m ";
      else cout << "\033[32m" << c << "\033[0m ";
    }
    cout << endl;
  }
}

int main() {
  cout << "=============================================\n";
  cout << "              Task context menu              \n";
  cout << "---------------------------------------------\n";
  cout << "Task: Complete the Minesweeper field by adding numbers;\n";
  cout << "Who completed the task: Kostya Kudritsky;\n";

  int rows, columns, count;
  char answer, value;

  do {
    cout << "Enter the number of rows and columns of the field:" << endl;
    while (!(cin >> rows >> columns) || rows <= 0 || columns <= 0 ) {
        InvalidInput();
    }

    char* array = new char[rows * columns];
    count = 0;

    cout << "Fill the field: '.' is empty space, '*' is a bomb." << endl; 

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        cout << "Square at row " << i << ", column " << j << endl;
        while(!(cin >> value) || (value != '.' && value != '*')) {
          InvalidInput();
        }
        array[i * columns + j] = value;
      }
    }

    cout << "Your field:" << endl;
    PrintMatrix(array, rows, columns);

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        if (array[i * columns + j] == '*') continue;

        for (int dy = -1; dy < 2; ++dy) {
          int y = i + dy;
          if (y < 0 || y >= rows) continue;
          for (int dx = -1; dx < 2; ++dx) {
            int x = j + dx;
            if (x < 0 || x >= columns) continue;
            if (array[y * columns + x] == '*') count++;
          }
        }

        array[i * columns + j] = count > 0? char('0' + count) : '.';
        count = 0;
      }
    }

    cout << "Your field with numbers:" << endl;
    PrintMatrix(array, rows, columns);

    delete[] array;

    cout << "Exit the program? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Invalid input, please enter y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}
