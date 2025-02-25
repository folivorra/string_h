#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int flag = 0;
  s21_size_t i = 0;
  while (n-- && (*str1 || *str2)) {
    if (str1[i] != str2[i]) {
      flag = str1[i] - str2[i];
    } else {
      i++;
    }
  }
  return flag;
}
