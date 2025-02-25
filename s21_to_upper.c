#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *cpy = s21_NULL;
  if (str != s21_NULL) {
    cpy = malloc(sizeof(char) * (s21_strlen(str) + 1));
    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        cpy[i] = str[i] - ' ';
      } else {
        cpy[i] = str[i];
      }
    }
    cpy[s21_strlen(str)] = '\0';
  }
  return cpy;
}