#include "s21_string.h"

void cmp(char *itr_n, char *itr_h, int *flag) {
  while (*itr_n) {
    if (*itr_h++ != *itr_n++) {
      *flag = 1;
      break;
    }
  }
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = s21_NULL;

  if (*needle == '\0') {
    res = (char *)haystack;
  }

  while (*haystack) {
    if (*haystack == *needle) {
      char *itr_h = (char *)haystack;
      char *itr_n = (char *)needle;
      int flag = 0;
      cmp(itr_n, itr_h, &flag);
      if (!flag) {
        res = (char *)haystack;
        break;
      }
    }
    haystack++;
  }

  return res;
}

// иду по первой строке в поисках первого символа из искомой строки, если нашел
// совпадение то начинаю цикл по второй строке посимвольно сравнивая подстроки
// если не нахожу расхождений то прерываю весь цикл и возращаю указатель