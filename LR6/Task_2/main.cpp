#include <stdio.h>
#include <wchar.h>
#include <locale.h>

wchar_t vowels[] = L"аеиоуыэюяАЕИОУЫЭЮЯ";

void ReadInput(wchar_t* str) {
  wint_t ch;
  int i;
  bool valid = false;
  printf("Enter your string (Russian letters only):\n");
  while(!valid) {
    valid = true;
    i = 0;
    while((ch = fgetwc(stdin)) != EOF && ch != '\n') {
      if (i >= 80) {
        printf("Too long! Maximum 80 symbols\n");
        while((ch = fgetwc(stdin)) != '\n' && ch != EOF);
        valid = false;
        break;
      }
      if ((ch >= L'а' && ch <= L'я') || (ch >= L'А' && ch <= L'Я') || ch == L' ' || ch == L',' || ch == L'.' || ch == L':') str[i++] = (wchar_t)ch;
      else {
        printf("Invalid string, please try again\n");
        while((ch = fgetwc(stdin)) != '\n' && ch != EOF);
        valid = false;
        break;
      }
    }
  }
  str[i] = '\0';
}

bool IsVowels(wchar_t ch) {
  for (int i = 0; vowels[i] != '\0'; ++i) {
    if (vowels[i] == ch) return true;
  }
  return false;
}

void CountVowelsAndConsonants(wchar_t* str) {
  int count_vowels = 0;
  int count_consonants = 0;
  wchar_t ch;
  for (int i = 0; str[i] != '\0'; ++i) {
    if (str[i] == L',' || str[i] == L'.' || str[i] == L':' || str[i] == L' ') continue;
    else if (IsVowels(str[i])) count_vowels++;
    else count_consonants++;
  }
  printf("Number of vowels: %d\nNumber of consonants: %d\n", count_vowels, count_consonants);
  if (count_vowels > count_consonants) printf("Vowels are more than consonants\n");
  else if (count_vowels < count_consonants) printf("Consonants are more than vowels\n");
  else printf("Equal number of vowels and consonants\n");
}

int main() {
  setlocale(LC_ALL, "");
  wchar_t* str = new wchar_t[81];
  ReadInput(str);
  CountVowelsAndConsonants(str);

  delete[] str;
}