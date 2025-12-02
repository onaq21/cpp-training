#include "../include/functions.h"
#include <stdio.h>

void ReadInput(char* str) {
  char ch;
  int i;
  bool valid = false;
  printf("Enter your string (numbers and spaces only):\n");
  while(!valid) {
    valid = true;
    i = 0;
    while((ch = getchar()) != EOF && ch != '\n') {
      if(i >= 80) {
        printf("Too long! Maximum 80 symbols\n");
        while((ch = getchar()) != '\n' && ch != EOF);
        valid = false;
        break;
      }
      if ((ch >= '0' && ch <= '9') || ch == ' ') {
        str[i++] = ch;
      }
      else {
        printf("Invalid string, please try again\n");
        while((ch = getchar()) != '\n' && ch != EOF);
        valid = false;
        break;
      }
    }
    str[i] = '\0';
  }
}