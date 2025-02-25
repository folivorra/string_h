#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  char *res = s21_NULL;
  static char *cur;
  static int f;
  if (str != s21_NULL) {
    cur = str;
    f = 0;
  }
  res = cur;
  char *end = s21_strpbrk(cur, delim);
  while (end == cur) {
    res++;
    cur++;
    end = s21_strpbrk(cur, delim);
  }
  if (end != s21_NULL) {
    *end = 0;
    cur = end + 1;
  } else if (f || s21_strlen(cur) == 0) {
    res = s21_NULL;
  } else {
    f = 1;
  }
  return res;
}