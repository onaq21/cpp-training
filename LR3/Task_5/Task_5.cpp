#include "../cmath.h"

int main() {
  cout << "=============================================\n";
  cout << "           Контекстное меню задания          \n";
  cout << "---------------------------------------------\n";
  cout << "Суть задания: Нахождение приближенного корня уравнения\n";
  cout << "Задание выполнил: Кудрицкий Константин\n";
  cout << "Вариант: 9" << endl;

  int start, end, parts;
  double step, x, minX, minFunc, tempFunc;
  char answer;

  start = 0;
  end = 2;

  do {
    cout << "Введите количество частей интервала:" << endl;
    while(!(cin >> parts) || parts <=0) {
      cout << "Введите корректные значения" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }

    step = (double)(end - start) / parts;
    minFunc = Fabs(Log10(Cosh(start)) - Tanh(start) + 0.5);
    minX = start;

    for(int i = 0; i <= parts; ++i) {
      x = start + i * step;
      tempFunc = Log10(Cosh(x)) - Tanh(x) + 0.5;
      if (Fabs(tempFunc) < minFunc) {
        minFunc = Fabs(tempFunc);
        minX = x;
      }
    }

    cout << "Функция достигает минимального значения f(x) = " << minFunc << " при x = " << minX << endl;

    cout << "Желаете закончить программу? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Введите y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}