#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

const string all_digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void InvalidInput() {
  cout << "Invalid input, please try again\n";
  cin.clear();
  cin.ignore(10000, '\n');
}
bool CheckNumber(string& number, int base) {
  string digits = all_digits.substr(0, base);
  int count_digits = 0;
  for (int i = 0; i < number.size(); ++i) {
    number[i] = toupper(number[i]);
    char ch = number[i];
    if (ch == '-') {
      if (i != 0) return false;
      continue;
    }
    else if (digits.find(ch) == string::npos) return false;
    count_digits++;
  }
  if (count_digits == 0) return false;
  return true;
}
void NormalizeLength(string& a, string& b) {
  if (a.size() > b.size()) {
    b.insert(0, a.size() - b.size(), '0');
  }
  else if (b.size() > a.size()) {
    a.insert(0, b.size() - a.size(), '0');
  }
  a.insert(0, 1, '0');
  b.insert(0, 1, '0');
}

string SumString(string a, string b, int base) {
  string digits = all_digits.substr(0, base);
  string result;
  int fval, sval;
  bool a_negative = false, b_negative = false;
  if (a[0] == '-') {
    a.erase(0, 1);
    a_negative = true;
  }
  if (b[0] == '-') {
    b.erase(0, 1);
    b_negative = true;
  }
  NormalizeLength(a, b);
  if (a_negative == b_negative) {
    int sum, carry = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
      fval = digits.find(a[i]);
      sval = digits.find(b[i]);
      sum = fval + sval + carry;
      if (sum >= base) {
        carry = 1;
        sum -= base;
      }
      else carry = 0;
      result.insert(0, 1, digits[sum]);
    }
    if (result[0] == '0') result.erase(0, 1);
    if (a_negative && b_negative) result.insert(0, 1, '-');
    return result;
  }
  else {
    bool res_negative = false, a_greater = false;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) {
        a_greater = digits.find(a[i]) > digits.find(b[i]);
        if (a_greater) res_negative = a_negative;
        else {
          res_negative = b_negative;
          swap(a, b);
        }
        break;
      }
    }
    int subtract, carry = 0;
    for (int i = a.size() - 1; i >=0; --i) {
      fval = digits.find(a[i]) - carry;
      carry = 0;
      sval = digits.find(b[i]);
      if (fval - sval < 0) {
        fval += base;
        carry = 1;
      }
      subtract = fval - sval;
      result.insert(0, 1, digits[subtract]);
    }
    while (result.size() > 1 && result[0] == '0') result.erase(0, 1);
    if (res_negative) result.insert(0, 1, '-');
    return result;
  }
}
string SubtractStrings(string first_number, string second_number, int base) {
  if (second_number[0] == '-') second_number.erase(0, 1);
  else second_number.insert(0, 1, '-');
  return SumString(first_number, second_number, base);
}

int main() {
  int base;
  cout << "Enter the base of the system(2 - 36): ";
  while (!(cin >> base) || base < 2 || base > 36) {
    InvalidInput();
  }
  cin.ignore(10000, '\n');

  string first_number, second_number;

  cout << "Enter two numbers separated by a space: ";
  while (cin >> first_number >> second_number) {
    if (CheckNumber(first_number, base) && CheckNumber(second_number, base)) {
      cin.ignore(10000, '\n');
      break;
    }
    InvalidInput();
  }

  cout << "Add your numbers: " << SumString(first_number, second_number, base);
  cout << "\nSubtract your numbers: " << SubtractStrings(first_number, second_number, base) << std::endl;
}