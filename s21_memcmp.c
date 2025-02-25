#include "s21_string.h"

// Сравнивает первые n байтов str1 и str2.
/* Если обнаруживается первое различие, программа завершает работу и выводит
разницу в виде ASCII-кода.*/
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  unsigned const char *s1 = str1;
  unsigned const char *s2 = str2;
  for (s21_size_t i = 0; i < n; i++) {
    int dif = s1[i] - s2[i];
    if (dif != 0) {
      res = dif;
      break;
    }
  }
  return res;
}
