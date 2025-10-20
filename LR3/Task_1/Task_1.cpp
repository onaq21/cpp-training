#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
  cout << "=============================================\n";
  cout << "           Контекстное меню задания          \n";
  cout << "---------------------------------------------\n";
  cout << "Суть задания: Вычислить сумму квадратов разности a_i и b_i для i = 1..30\n";
  cout << "Задание выполнил: Кудрицкий Константин\n";

  int a, b, i;
  long long sum;
  char answer;

  do {
    sum = 0;
    i = 1;

    while (i <= 30) {
      a = (i % 2 == 0) ? (i / 2) : i;
      b = (i % 2 == 0) ? (i * i * i) : (i * i);
      sum += (a - b) * (a - b);
      ++i;
    }

    cout << "Ответ: " << sum << endl;
    cout << "Желаете закончить программу? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Введите y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}