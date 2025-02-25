#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  str1 += s21_strcspn(str1, str2);
  if (!(*str1)) str1 = s21_NULL;
  return (char *)str1;
}

// тут просто переиспользование предыдущей функции, одно отличие что
// возвращается указатель на первое вхождение в строку, а не номер символа