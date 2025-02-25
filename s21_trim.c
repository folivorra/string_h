#include "s21_string.h"

void* s21_trim(const char* src, const char* trim_chars) {
  char* res = s21_NULL;

  if (src != s21_NULL && trim_chars != s21_NULL) {
    s21_size_t len_src = s21_strlen(src);
    char* start = (char*)src;
    char* end = (char*)src + (int)len_src - 1;
    res = calloc(len_src + 1, 1);
    while (*start == ' ' || *start == '\n' || *start == '\t' ||
           *start == '\v' || *start == '\r' ||
           (!s21_strcspn(start, trim_chars) && *start != '\0')) {
      start++;
    }
    while (*end == ' ' || *end == '\n' || *end == '\t' || *end == '\v' ||
           *end == '\r' || !s21_strcspn(end, trim_chars)) {
      end--;
    }
    if (end - start + 1 > 0) s21_strncpy(res, start, end - start + 1);
  }

  return res;
}