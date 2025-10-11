#include "../cmath.h"

int main() {
  cout << "=============================================\n";
  cout << "           Контекстное меню задания          \n";
  cout << "---------------------------------------------\n";
  cout << "Суть задания: Вычислить разность функции sin(x) - cos(x) на заданном отрезке с шагом step\n";
  cout << "Задание выполнил: Кудрицкий Константин\n";

  double A, B, x, step;
  int part, i;
  char answer;
  
  A = 0;
  B = kPi / 2;
  part = 20;
  step = (B - A) / part;

  do {
    i = 0;
    for (; i <= part; ++i) {
      x = A + i * step;
      cout << "При x = " << x << " значение функции y = " << Sin(x) - Cos(x) << endl;
    }

    cout << "Желаете закончить программу? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Введите y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}