#include <cstdio>

void ReadInput(char* number) {
  int ch, i;
  bool valid = false;
  printf("Enter your number: ");
  while(!valid) {
    valid = true;
    i = 0;
    while((ch = getchar()) != EOF && ch != '\n') {
      if ((ch >= '0' && ch <= '9') || (i == 0 && ch == '-')) number[i++] = (char)ch;
      else {
        printf("Invalid input, please try again\n");
        while((ch = getchar()) != '\n' && ch != EOF);
        valid = false;
        break;
      }
    }
  }
  number[i] = '\0';
}

void ToDirectCode(char* number) {
  int nlen = 0, size = 0;
  for (int i = 0; number[i] != '\0'; ++i) nlen++;
  printf("Your number in direct code: ");
  if (number[0] == '-') {
    printf("1");
    for (int i = 0; i < nlen; ++i) number[i] = number[i + 1];
    nlen--;
  }
  else printf("0");

  char bits[1000];
  
  while (nlen > 0) {
    int new_len = 0, remainder = 0;

    for (int i = 0; i < nlen; ++i) {
      int value = remainder * 10 + number[i] - '0';
      int new_digit = value / 2;
      remainder = value % 2;
      number[new_len++] = new_digit + '0';
    }

    bits[size++] = remainder;

    int k = 0;
    while (k < new_len && number[k] == '0') k++;
    for (int j = 0; j < new_len - k; ++j) number[j] = number[j + k];
    nlen = new_len - k;
  }

  for (int i = size - 1; i >= 0; --i) printf("%d", bits[i]);
  printf("\n");
}

int main() {
  char* number = new char[1000];
  ReadInput(number);

  ToDirectCode(number);
  delete[] number;
}