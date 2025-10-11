#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const double kPi = 3.141592653589793;

double Pow(double number, int exp) {
  double result = 1;

  if (exp == 0) return 1;
  if (number == 0) return 0;

  if (exp > 0) {
    for (int i = 1; i <= exp; ++i) {
      result *= number;
    }
  }  
  else {
    for (int i = 1; i <= -exp; ++i) {
      result *= 1 / number;
    }
  }

  return result;
}

double Factorial(int number) {
  double result = 1;
  for(int i = 2; i <= number; ++i) {
    result *= i;
  }
  return result;
}

double Fabs(double number) {
  return number < 0? -number : number;
}

double Ln(double number) {
  if (number <= 0) {
    cout << "Ошибка: логарифм от неположительного числа" << endl;
    return 0;
  }

  double halfLn, y;

  halfLn = 0;
  y = (number - 1) / (number + 1);

  for (int i = 0; i < 20; ++i) {
    halfLn += Pow(y, (2 * i) + 1) / (2 * i + 1);
  }

  return 2 * halfLn;
}

double Log10(double number) {
  if (number <= 0) {
    cout << "Ошибка: логарифм от неположительного числа" << endl;
    return 0;
  }

  double result, ln10;

  ln10 = 2.302585093;

  result = Ln(number) / ln10;
  return result;
}

double Exp(double exp) {
  double result, term;

  result = 1.0;
  term = 1.0;

  for (int i = 1; i < 20; ++i) {
    term *= exp / i;
    result += term;
  }

  return result;
}

double NormalizeAngle(double x) {
  int quantityOfPi;
  double normalizedX;

  quantityOfPi = x / (2 * kPi);
  normalizedX = x - 2 * kPi * quantityOfPi; 

  if (normalizedX <= -kPi || normalizedX > kPi) {
    if (normalizedX > kPi) {
      normalizedX -= 2 * kPi;
    }
    else {
      normalizedX += 2 * kPi;
    }
  }

  return normalizedX;
}

double Sin(double x) {
  double angle, newX, sign;

  newX = NormalizeAngle(x);
  angle = 0;
  sign = 1.0;

  for (int i = 0; i <= 15; ++i) {
    angle += sign * Pow(newX, (2 * i + 1)) / Factorial(2 * i + 1);
    sign *= -1;
  }

  return angle;
}

double Cos(double x) {
  double angle, newX, sign;

  newX = NormalizeAngle(x);
  angle = 0;
  sign = 1.0;

  for (int i = 0; i <= 15; ++i) {
    angle += sign * Pow(newX, 2 * i) / Factorial(2 * i);
    sign *= -1;
  }

  return angle;
}

double Cosh(double x) {
  return (Exp(x) + Exp(-x)) / 2.0;
}

double Tanh(double x) {
  double ex, emx;

  ex = Exp(x);
  emx = Exp(-x);

  return (ex - emx) / (ex + emx);
}
