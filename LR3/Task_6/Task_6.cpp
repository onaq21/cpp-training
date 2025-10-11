#include "../cmath.h"

int main() {
  cout << "=============================================\n";
  cout << "           Контекстное меню задания          \n";
  cout << "---------------------------------------------\n";
  cout << "Суть задания: Определить минимальное значение трех функций: sinx, cosx, ln|x|\n";
  cout << "Задание выполнил: Кудрицкий Константин\n";

  double x, a, b, c, min;
  char answer;

  do {
    cout << "Введите значение x:" << endl;
    while(!(cin >> x) || x <= 0) {
      cout << "Введите корректное значение x(x > 0)" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }

    a = Sin(x);
    b = Cos(x);
    c = Ln(x);

    if (a <= b && a <= c) {
      min = a;
    }
    else if (b <= a && b <= c) {
      min = b;
    }
    else {
      min = c;
    }

    cout << "Минимальное значение из трех функций при x = " << x << " равно " << min << endl;

    cout << "Желаете закончить программу? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Введите y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}