#include "../cmath.h"

int NumberOfDigits(int number) {
  int digits = 0;
  for (; number > 0; number /= 10) {
    digits++;
  }
  return digits;
}

bool IsArmstrongNumber(int number) {
  int NOfDigits, digit, sum;
  
  NOfDigits = NumberOfDigits(number);
  sum = 0;

  for (int n = number; n > 0; n /= 10) {
    digit = n % 10;
    sum += Pow(digit, NOfDigits);
    if (sum > number) {
      return false;
    }
  }

  return number == sum;
}

int main() {
  cout << "=============================================\n";
  cout << "           Контекстное меню задания          \n";
  cout << "---------------------------------------------\n";
  cout << "Суть задания: Поиск чисел Армстронга до указанного числа\n";
  cout << "Задание выполнил: Кудрицкий Константин\n";

  int border;
  char answer;

  do {
    cout << "Введите границу поиска чисел Армстронга(минимум трехзначное число):" << endl;
    while(!(cin >> border) || border < 100) {
        cout << "Введите корректную границу" << endl;
        cin.clear();
        cin.ignore(100000, '\n');
    }

    if (border < 153) {
        cout << "До вашего числа нет чисел Армстронга" << endl;
    }
    else {
      cout << "Числа Армстронга до вашей границы:" << endl;
      for (int i = 153; i < border; ++i) {
        if (IsArmstrongNumber(i)) {
          cout << i << endl;
        }
      }
    }
    
    cout << "Желаете закончить программу? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Введите y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}