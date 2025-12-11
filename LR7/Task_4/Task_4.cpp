#include <iostream>
using std::cout;
using std::cin;

void InvalidInput() {
  cout << "Invalid input, please try again\n";
  cin.clear();
  cin.ignore(10000, '\n');
}

bool IsDivisible(long long number, int divider) {
  if (number == 0) return true;
  if (divider == 0) return false;
  long long abs_number = number > 0 ? number : ~number + 1;
  int abs_divider = divider > 0 ? divider : ~divider + 1;

  while (abs_number >= abs_divider) {
    long long k = abs_divider;
    while ((k << 1) <= abs_number) k <<= 1;
    abs_number += ~k + 1;
  }
  return abs_number == 0;
}

int main() {
  long long number;
  int divider;
  cout << "Enter your number and divider: ";
  while (!(cin >> number >> divider)) {
    InvalidInput();
  }
  if (IsDivisible(number, divider)) cout << number << " is divisible by " << divider << "\n";
  else cout << number << " is not divisible by " << divider << "\n";
}