#include "s21_string.h"

char *s21_strncpy(char *dst, const char *src, size_t len) {
  char *res = dst;
  size_t i = 0;
  for (; i < len && src[i] != '\0'; i++) {
    dst[i] = src[i];
  }
  for (; i < len; i++) {
    dst[i] = '\0';
  }
  return res;
}

// копируем ровно len символов из dest в src, существует UB при котором даже
// если места в буфере не хватает то он начинает перезаписывать
// неинициализированную память так как это есть и в ориг функции не стал фиксить
// эту проблему