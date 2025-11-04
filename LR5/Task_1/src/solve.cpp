#include "../include/matrix.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void SolveTask() {
  cout << "=============================================\n";
  cout << "              Task context menu              \n";
  cout << "---------------------------------------------\n";
  cout << "Task: Create a transposed matrix\n";
  cout << "Completed by: Kostya Kudritsky;\n";
  cout << "Option: 9\n";

  int order;
  char answer;

  do {
    cout << "Enter matrix size:\n";
    while(!(cin >> order) || order < 1) {
      InvalidInput();
    }

    int* matrix = new int[order * order];

    FillMatrix(matrix, order);

    int * transpose_matrix = GetTranspose(matrix, order);

    cout << "Original matrix:\n"; 
    PrintMatrix(matrix, order);

    cout << "Transpose matrix:\n";
    PrintMatrix(transpose_matrix, order);

    cout << "Sum of elements in even rows and odd columns: " << SumEvenRowsOddCols(matrix, order) << "\n";
    cout << "Sum of elements in odd rows and even columns: " << SumOddRowsEvenCols(transpose_matrix, order) << "\n";

    delete[] matrix;
    delete[] transpose_matrix;

    cout << "Exit the program? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Invalid input, please enter y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}