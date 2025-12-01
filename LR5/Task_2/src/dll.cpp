#include "../include/matrix.h"
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

double RecursiveProduct(int* arr, int size) {
  double result = 1;
  if (size == 1) return sin(arr[0]) - cos(arr[0]);
  if (size == 2) return (sin(arr[0]) - cos(arr[0])) * (sin(arr[1]) - cos(arr[1]));
  
    int first_third = size / 3;
    int remaining = size - first_third;
    double prod1, prod2;

    prod1 = RecursiveProduct(arr, first_third);
    prod2 = RecursiveProduct(arr + first_third, remaining);

    return prod1 * prod2;
}

void FillArray(int * arr, int size) {
  int value;
  for (int i = 0; i < size; ++i) {
    cout << "Enter the value of element " << i << ": ";
    while(!(cin >> value)) {
      InvalidInput();
    }
    arr[i] = value;
  }
}

extern "C" void __attribute__((visibility("default"))) SolveTask() {
  cout << "=============================================\n";
  cout << "              Task context menu              \n";
  cout << "---------------------------------------------\n";


  
  cout << "Task: Compute the product of (sin(Ci) - cos(Ci) for all elements of array C using recursion that divides the array into 1/3 and 2/3 until 1 or 2 elements remain.\n";
  cout << "Completed by: Kostya Kudritsky;\n";
  cout << "Option: 9\n";

  int n;
  char answer;

  do {
    cout << "Enter number of elements in the array(max " << kMaxSize << "):\n";
    while(!(cin >> n) || n < 1) {
      InvalidInput();
    }

    int* array = new int[n];

    FillArray(array, n);

    cout << "Your product is " << RecursiveProduct(array, n) << "\n";

    delete[] array;

    cout << "Exit the program? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Invalid input, please enter y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}