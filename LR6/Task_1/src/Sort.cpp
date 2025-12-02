#include "../include/functions.h"
#include <stdio.h>

void PrintSortedNumbers(char* str) {
  bool start_number = false;
  int number, counter;
  number = 0, counter = 0;
  int* numbers = new int [40];
  for (int i = 0; str[i] != '\0'; ++i) {
    if (str[i] != ' ') {
        number = number * 10 + (str[i] - '0');
        start_number = true;
    }
    if ((str[i] == ' ' || str[i + 1] == '\0') && start_number) {
      numbers[counter++] = number;
      number = 0;
      start_number = false;
    }
  }

  int value, j;
  for (int i = 1; i < counter; ++i) {
    value = numbers[i]; j = i - 1;
    while (j >= 0 && numbers[j] > value) {
      numbers[j + 1] = numbers[j];
      --j;
    }  
    numbers[j + 1] = value;
  }

  printf("Your sorted numbers: ");
  for (int i = 0; i < counter; ++i) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  delete[] numbers;
}