#include "../cmath.h"

int main() {
  cout << "=============================================\n";
  cout << "           Контекстное меню задания          \n";
  cout << "---------------------------------------------\n";
  cout << "Суть задания: Вычислить сумму ряда\n";
  cout << "Задание выполнил: Кудрицкий Константин\n";

  int n, term;
  long sum;
  char answer;

  do {
    cout << "Введите количество членов ряда(n):" << endl;
    while(!(cin >> n) || n <=0) {
      cout << "Введите корректное количество членов ряда" << endl;
      cin.clear();
      cin.ignore(100000, '\n');
    }

    int list [n];

    for(int i = 0; i < n; ++i) {
      cout << "Введите значение коэффициента с номером " << i << endl;
      while(!(cin >> list[i])) {
        cout << "Введите корректное значение" << endl;
        cin.clear();
        cin.ignore(100000, '\n');
      }
    }

    sum = 0;
    term = 1;

    for(int i = 0; i < n; ++i) {
      sum += term * list[i];
      term *= -2;
    }

    cout << "Сумма ряда равна " << sum << endl;
    cout << "Желаете закончить программу? (y or n)" << endl;

    while (!(cin >> answer) || (answer != 'n' && answer != 'y')) {
      cout << "Введите y or n" << endl;
      cin.clear();
      cin.ignore(1000000, '\n');
    }
  } while (answer == 'n');
}