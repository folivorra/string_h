#include "tests.h"

START_TEST(trim_check_1) {
  // Arrange
  const char str[256] = "   \n\tHello, World!\n   ";
  // Act
  char *cpy = s21_trim(str, "");
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "Hello, World!");
  }
  free(cpy);
}
END_TEST

START_TEST(trim_check_2) {
  // Arrange
  const char str[256] = "xxABCyy";
  // Act
  char *cpy = s21_trim(str, "xy");
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "ABC");
  }
  free(cpy);
}
END_TEST

START_TEST(trim_check_3) {
  // Arrange
  const char str[256] = "NoTrimmingHere";
  // Act
  char *cpy = s21_trim(str, "");
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "NoTrimmingHere");
  }
  free(cpy);
}
END_TEST

START_TEST(trim_check_4) {
  // Arrange
  const char *str = NULL;
  // Act
  char *cpy = s21_trim(str, "");
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "");
  }
  free(cpy);
}
END_TEST

START_TEST(trim_check_5) {
  // Arrange
  const char str[256] = " \v\r\n\t ";
  // Act
  char *cpy = s21_trim(str, "");
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "");
  }
  free(cpy);
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_trim");

  tc = tcase_create("case_trim");
  tcase_add_test(tc, trim_check_1);
  tcase_add_test(tc, trim_check_2);
  tcase_add_test(tc, trim_check_3);
  tcase_add_test(tc, trim_check_4);
  tcase_add_test(tc, trim_check_5);

  suite_add_tcase(s, tc);
  return s;
}