#include <cstdio>

void ReadInput(char* first_number, char* second_number) {
  int ch, i, j, minus_first, minus_second, digit_first, digit_second, space_count;
  bool valid = false;
  printf("Enter two numbers separated by a space to sum: ");
  while(!valid) {
    valid = true;
    i = 0, j = 0, minus_first = 0, minus_second = 0, digit_first = 0, digit_second = 0, space_count = 0;
    while((ch = getchar()) != EOF && ch != '\n') {
      if ((ch >= '0' && ch <= '9') || (space_count == 0 && minus_first == 0 && i == 0 && ch == '-') || 
            (space_count == 1 && minus_second == 0 && j == 0 && ch == '-') || (ch == ' ' && space_count == 0)) {
        if (ch == ' ') {
          if (digit_first == 0) {
            printf("Invalid input, please try again\n");
            while((ch = getchar()) != '\n' && ch != EOF);
            valid = false;
            break;
          }
          space_count++;
        }
        else if (space_count < 1){
          if (ch == '-') minus_first++;
          else digit_first++;
          first_number[i++] = (char)ch;
        }
        else {
          if (ch == '-') minus_second++;
          else digit_second++;
          second_number[j++] = (char)ch;
        }
      }
      else {
        printf("Invalid input, please try again\n");
        while((ch = getchar()) != '\n' && ch != EOF);
        valid = false;
        break;
      }
    }
    if (valid && digit_second == 0) {
      printf("Invalid input, please try again\n");
      valid = false;
    }
  }
  first_number[i] = '\0', second_number[j] = '\0';
}

char* ToDirectCode(char* number) {
  int nlen = 0, size = 0;
  char* bits = new char[1000];
  for (int i = 0; number[i] != 0; ++i) nlen++;
  if (number[0] == '-') {
    bits[size++] = '1';
    for (int i = 0; i < nlen; ++i) number[i] = number[i + 1];
    nlen--;
  }
  else bits[size++] = '0';
  
  while (nlen > 0) {
    int new_len = 0, remainder = 0;

    for (int i = 0; i < nlen; ++i) {
      int value = remainder * 10 + number[i] - '0';
      int new_digit = value / 2;
      remainder = value % 2;
      number[new_len++] = new_digit + '0';
    }
    bits[size++] = remainder + '0';

    int k = 0;
    while (k < new_len && number[k] == '0') k++;
    for (int j = 0; j < new_len - k; ++j) number[j] = number[j + k];
    nlen = new_len - k;
  }
  
  char* result = new char[size + 1];
  result[0] = bits[0];
  for (int i = 1; i < size; ++i) result[i] = bits[size - i];
  result[size] = '\0';
  delete[] bits;
  return result;
}

char* ToAdditionalCode(char* number, int& size) {
  int carry = 1;
  size = 0;
  char* bits = ToDirectCode(number);
  for (int i = 0; bits[i] != '\0'; ++i) size++;
  if (bits[0] == '0') return bits;

  for (int i = size - 1; i > 0; --i) {
    bits[i] = bits[i] == '0'? '1' : '0';
    if (carry == 1) {
      if (bits[i] == '0') {
        bits[i] = '1';
        carry = 0;
      }
      else bits[i] = '0';
    }
  }
  return bits;
}

char* SignExtend(char* short_number, int long_size, int short_size) {
  int i = 0, j = 0;
  char* result = new char[long_size + 1];
  char fill_bit = short_number[0];
  while (i < long_size - short_size) result[i++] = fill_bit;
  while (i < long_size) result[i++] = short_number[j++];
  result[long_size] = '\0';
  return result;
}

char* SumAdditionalCode(char* first_n, char* second_n) {
  int first_size, second_size, sum_bit, carry = 0, size = 0;
  char* first_number = ToAdditionalCode(first_n, first_size);
  char* second_number = ToAdditionalCode(second_n, second_size);

  size = first_size > second_size ? first_size + 1 : second_size + 1;

  char* n1 = SignExtend(first_number, size, first_size);
  char* n2 = SignExtend(second_number, size, second_size);

  delete[] first_number;
  delete[] second_number;

  char* sum = new char[size + 1];
  sum[size] = '\0';
  for (int i = size - 1; i >= 0; --i) {
    sum_bit = n1[i] + n2[i] - 2 * '0' + carry;
    carry = sum_bit / 2;
    sum[i] = (sum_bit % 2) + '0';
  }

  delete[] n1;
  delete[] n2;

  return sum;
}

char* AdditionalToDirect(char* add_code) {
  int size = 0;
  while (add_code[size] != '\0') size++;
  char* result = new char[size + 1];
  result[size] = '\0';
  for (int i = 0; i < size; ++i) result[i] = add_code[i];
  if (result[0] == '0') return result;
  else {
    int carry = 1;
    for (int i = size - 1; i > 0; --i) {
      result[i] = result[i] == '0'? '1' : '0';
      if (carry == 1) {
        if (result[i] == '0') {
          result[i] = '1';
          carry = 0;
        }
        else result[i] = '0';
      }
    }
  }
  return result;
}

char* NormalizeDirectCode(char* direct_code) {
  int size = 0;
  for (int i = 0; direct_code[i] != '\0'; ++i) size++;
  if (size <= 2) return direct_code;

  int start = 1;

  while (start < size - 1 && direct_code[start] == '0') start++;
  if (start == 1) return direct_code;

  char* result = new char[size - start + 2];
  result[0] = direct_code[0];
  int i = 1;
  while (direct_code[start] != '\0') {
    result[i++] = direct_code[start];
    start++;
  }
  result[i] = '\0';

  delete[] direct_code;
  return result;
}


int main() {
  char* first_number = new char[1000];
  char* second_number = new char[1000];
  ReadInput(first_number, second_number);

  char* sum_add_code = SumAdditionalCode(first_number, second_number);
  printf("Sum in direct code: ");
  char* additional_sum = AdditionalToDirect(sum_add_code);
  char* result = NormalizeDirectCode(additional_sum);
  printf("%s\n", result);

  delete[] sum_add_code;
  delete[] result;
  delete[] first_number;
  delete[] second_number;
}