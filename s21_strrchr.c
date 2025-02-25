#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  for (s21_size_t i = s21_strlen(str) + 1; i > 0; i--) {
    if (str[i - 1] == c) {
      res = (char *)&str[i - 1];
      break;
    }
  }
  return res;
}