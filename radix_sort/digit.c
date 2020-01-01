#include "digit.h"

int getDigit(int num, int n) {
  int digit = 0;
  for (int i = 0; i < n; i++) {
    digit = num % 10;
    num /= 10;
  }

  return digit;
}

int hasMinDigits(int num, int n) {
  if (num == 0) {
    return (n == 1);
  } else {
    return (n < floor(log10(abs(num))) + 2);
  }
}