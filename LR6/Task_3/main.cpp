#include <stdio.h>
#include <wchar.h>
#include <locale.h>

bool IsPalindrome(wchar_t* word, int word_len);

void ReadInput(wchar_t* str) {
  wint_t ch;
  int i;
  bool valid = false;
  printf("Enter words in Russian, separated by spaces:\n");
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
      if ((ch >= L'а' && ch <= L'я') || (ch >= L'А' && ch <= L'Я') || ch == L' ') str[i++] = (wchar_t)ch;
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

void CheckPalindroms(wchar_t* str) {
  wchar_t word[81];
  int word_len = 0;
  for (int i = 0; str[i] != '\0'; ++i) {
    if (str[i] != L' ') {
      wprintf(L"%lc", str[i]);
      word[word_len++] = str[i];
    }
    if ((str[i] == L' ' || str[i + 1] == '\0') && word_len > 0) {
      if (IsPalindrome(word, word_len)) printf(" is a palindrome\n");
      else printf(" isn't a palindrome\n");
      word_len = 0;
      continue;
    }
  }
}

bool IsPalindrome(wchar_t* word, int word_len) {
  int left, right;
  left = 0, right = word_len - 1;
  for (int i = 0; i < word_len / 2; ++i) {
    if (word[left++] != word[right--]) return false;
  }
  return true;
}

int main() {
  setlocale(LC_ALL, "");
  wchar_t* str = new wchar_t[81];
  ReadInput(str);
  CheckPalindroms(str);

  delete[] str;
}