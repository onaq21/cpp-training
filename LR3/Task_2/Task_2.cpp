#include "../cmath.h"

int main() {
  cout << "=============================================\n";
  cout << "           Контекстное меню задания          \n";
  cout << "---------------------------------------------\n";
  cout << "Суть задания: Вычислить сумму ряда d_n с заданной точностью\n";
  cout << "Задание выполнил: Кудрицкий Константин\n";

  const double kEps = 0.001;
  double sum, d;
  int n;
  char answer;

  do {
    sum = 0;
    n = 0;

    do {
      d = 1.0 / Pow(2, n) + 1.0 / Pow(3, n);
      sum += d;
      ++n;
    } while (d >= kEps);

    cout << "Ответ: " << sum << endl;
    cout << "Желаете закончить программу? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Введите y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}