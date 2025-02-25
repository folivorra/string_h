#include "tests.h"

int run_tests(Suite *s);

int main() {
  Suite *all_cases[] = {
      s21_strlen_suite(),  s21_strcspn_suite(),  s21_strncpy_suite(),
      s21_strpbrk_suite(), s21_strrchr_suite(),  s21_strstr_suite(),
      s21_strtok_suite(),  s21_memchr_suite(),   s21_memcmp_suite(),
      s21_memcpy_suite(),  s21_memset_suite(),   s21_strncat_suite(),
      s21_strchr_suite(),  s21_strncmp_suite(),  s21_strerror_suite(),
      s21_sprintf_suite(), s21_to_upper_suite(), s21_to_lower_suite(),
      s21_insert_suite(),  s21_trim_suite()};

  for (int i = 0; i < 20; i++) {
    run_tests(all_cases[i]);
  }
  return 0;
}

int run_tests(Suite *s) {
  SRunner *runner;
  runner = srunner_create(s);
  int failed = 0;
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}