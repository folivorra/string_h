#include <stdlib.h>

#include "s21_string.h"

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  s21_size_t len_src = s21_strlen(src);
  s21_size_t len_str = s21_strlen(str);

  if (start_index > len_src) start_index = len_src;

  s21_size_t new_len = len_src + len_str;

  char* new_str = calloc(new_len + 1, 1);

  s21_strncpy(new_str, src, start_index);
  s21_strncpy(new_str + start_index, str, len_str);
  s21_strncpy(new_str + start_index + len_str, src + start_index,
              len_src - start_index);
  new_str[new_len] = '\0';
  return new_str;
}
