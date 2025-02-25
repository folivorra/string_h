#include "s21_string.h"
// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов.
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *p = dest + s21_strlen(dest);  // оказываемся в конце строки dest
  s21_size_t i = 0;
  while (i < n && src[i] != '\0') {
    *p = src[i];
    p++;
    i++;
  }
  *p = '\0';
  return dest;
}
