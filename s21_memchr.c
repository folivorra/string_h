#include "s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  void *res = s21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (*((unsigned char *)str + i) == (unsigned char)c) {
      res = ((unsigned char *)str + i);
      break;
    }
  }
  return res;
}
