#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void PrintArray(int* arr, int size) {
  if (size == 0) {
    cout << "No elements" << endl;
  }
  else {
    for(int i = 0; i < size; ++i) {
      cout << arr[i] << ", ";
    }
    cout << endl;
  }
}

const int kMaxSize = 10000;

int main() {
  cout << "=============================================\n";
  cout << "              Task context menu              \n";
  cout << "---------------------------------------------\n";
  cout << "Task: Split the original array into two arrays: the first with negative values, the second with non-negative values;\n";
  cout << "Who completed the task: Kostya Kudritsky;\n";
  cout << "Option: 9;\n\n";

  int size, neg_count, nonneg_count, neg_index, nonneg_index;
  char answer;

  do {
    cout << "Enter the number of elements in the array(max " << kMaxSize << "):"<< endl;
    while(!(cin >> size) || size <= 0 || size > kMaxSize) {
      cout << "Invalid input, please try again" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }

    int array[size];
    neg_count = 0;
    nonneg_count = 0;
    neg_index = 0;
    nonneg_index = 0;

    for(int i = 0; i < size; ++i) {
      cout << "Enter element at index " << i << ":" << endl;
      while(!(cin >> array[i])) {
        cout << "Invalid input, please try again" << endl;
        cin.clear();
        cin.ignore(100000, '\n');
      }
      
      if (array[i] < 0) {
        ++neg_count;
      }
      else {
        ++nonneg_count;
      }
    }

    int neg_array[neg_count];
    int nonneg_array[nonneg_count];

    for(int i = 0; i < size; ++i) {
      if (array[i] < 0) {
        neg_array[neg_index] = array[i];
        ++neg_index;
      }
      else {
        nonneg_array[nonneg_index] = array[i];
        ++nonneg_index;
      }
    }

    cout << "\nOriginal array elements (total: " << size << "):" << endl;
    PrintArray(array, size);
    cout << "Negative array elements (total: " << neg_count << "):" << endl;
    PrintArray(neg_array, neg_count);
    cout << "Non-negative array elements (total: " << nonneg_count << "):" << endl;
    PrintArray(nonneg_array, nonneg_count);

    cout << "Exit the program? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Invalid input, please enter y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}