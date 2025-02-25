#include "s21_string.h"
// Выполняет поиск первого вхождения символа 'c' (беззнаковый тип) в строке, на
// которую указывает аргумент 'str'.
char *s21_strchr(const char *str, int c) {
  char *res = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str) + 1; i++) {
    if (str[i] == c) {
      res = (char *)&str[i];
      break;
    }
  }
  return res;
}
