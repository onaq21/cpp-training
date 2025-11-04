#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void InvalidInput() {
  cout << "Invalid input, please try again" << endl;
  cin.clear();
  cin.ignore(100000, '\n');
}

int Get(int* arr, int size, int x, int y, int z) {
  return arr[(x * size + y) * size + z];
}

int main() {
  cout << "=============================================\n";
  cout << "              Task context menu              \n";
  cout << "---------------------------------------------\n";
  cout << "Task: Determine the cube diagonal with the largest sum of elements;\n";
  cout << "Who completed the task: Kostya Kudritsky;\n";

  int size, value, sum1, sum2, sum3, sum4, max_sum, max_diag;
  int x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4;
  char answer;

  do {
    cout << "Enter the number of elements per side of the cube" << endl;
    while(!(cin >> size) || size <= 0) {
      InvalidInput();
    }

    int* array = new int[size * size * size];
    sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;

    for(int x = 0; x < size; ++x) {
      for(int y = 0; y < size; ++y) {
        for(int z = 0; z < size; ++z) {
          cout << "Enter the value of the element at x: " << x << ", y: " << y << ", z: " << z << endl;
          while(!(cin >> value) || value < 0) {
            InvalidInput();
          }
          array[(x * size + y) * size + z] = value;
        }
      }
    }

    for(int i = 0; i < size; ++i) {
      x1 = i, y1 = i, z1 = i;
      sum1 += Get(array, size, x1, y1, z1);

      x2 = i, y2 = i, z2 = size - 1 - i;
      sum2 += Get(array, size, x2, y2, z2);

      x3 = size - 1 - i, y3 = i, z3 = i;
      sum3 += Get(array, size, x3, y3, z3);

      x4 = size - 1 - i, y4 = i, z4 = size - 1 - i;
      sum4 += Get(array, size, x4, y4, z4);
    }

    max_sum = sum1, max_diag = 1;
    if (sum2 > max_sum) {
      max_sum = sum2;
      max_diag = 2;
    }
    if (sum3 > max_sum) {
      max_sum = sum3;
      max_diag = 3;
    }
    if (sum4 > max_sum) {
      max_sum = sum4;
      max_diag = 4;
    }

    cout << "Diagonal with the largest sum of elements is:" << endl;

    for(int i = 0; i < size; ++i) {
      switch (max_diag) {
        case 1:
          x1 = i, y1 = i, z1 = i;
          break;
        case 2:
          x1 = i, y1 = i, z1 = size - 1 - i;
          break;
        case 3:
          x1 = size -1 - i, y1 = i, z1 = i;
          break;
         case 4:
          x1 = size - 1 - i, y1 = i, z1 = size - 1 -i;
          break;
      }

      cout << "(" << x1 << " " << y1 << " " << z1 << ") = " << Get(array, size, x1, y1, z1) << ", ";
    }

    cout << "\nThe largest sum is " << max_sum << endl;

    delete[] array;

    cout << "Exit the program? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Invalid input, please enter y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}