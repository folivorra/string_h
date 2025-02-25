#include "s21_string.h"

char* s21_strerror(int errnum) {
  char* errors[] = ERRORS;
  char* res = s21_NULL;
  static char unkErr[100] = "";

  if (errnum >= 0 && errnum <= NUM_OF_ERRORS - 1) {
    res = errors[errnum];
  } else {
    s21_sprintf(unkErr, "Unknown error %d", errnum);
  }
  if (res == s21_NULL) {
    res = unkErr;
  }
  return res;
}
