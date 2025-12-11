#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::vector;
using std::string;

string ToBase3(int number) {
  string result;
  while (number > 0) {
    result.insert(0, 1, '0' + number % 3);
    number /= 3;
  }
  result.insert(0, 5 - result.size(), '0');
  return result;
}

int main() {
  unsigned short poison_barrel, result = 0;
  cout << "Enter the number of the barrel you want to poison(1 - 240): ";
  while (!(cin >> poison_barrel) || poison_barrel < 1 || poison_barrel > 240) {
    cout << "Invalid input, please try again\n";
    cin.clear();
    cin.ignore(10000, '\n');
  }

  vector<int> day_slave[2][5];
  int death[5] {};

  for (int barrel = 1; barrel <= 240; barrel++) {
    string code = ToBase3(barrel);

    for (int slave = 0; slave < 5; slave++) {
      if (code[slave] == '1') day_slave[0][slave].push_back(barrel);
      else if (code [slave] == '2') day_slave[1][slave].push_back(barrel);
    }
  }

  for (int day = 0; day < 2; day++) {
    for (int slave = 0; slave < 5; slave++) {
      if (death[slave] != 0) continue;
      
      for (int barrel : day_slave[day][slave]) {
        if (barrel == poison_barrel) death[slave] = day + 1;
      }
    }
  }

  int power = 1;
  for (int i = 4; i >= 0; i--) {
    result += death[i] * power;
    power *= 3;
  }

  cout << "You poisoned the barrel is №" << result << '\n';
}