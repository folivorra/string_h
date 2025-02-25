#include "s21_string.h"
// Копирует n символов из src в dest.

// Итерируемся по массивам и заменяем содержимое массива dest
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *str1 = dest;
  const char *str2 = src;
  for (s21_size_t i = 0; i < n; i++) {
    str1[i] = str2[i];
  }
  return str1;
}
