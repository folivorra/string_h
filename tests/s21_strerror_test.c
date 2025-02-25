#include "tests.h"

START_TEST(strerror_check_1) {
  // Arrange
  int errnum = 10;
  // Act
  char* res_orig = strerror(errnum);
  char* res_own = s21_strerror(errnum);
  // Assert
  ck_assert_str_eq(res_orig, res_own);
}
END_TEST

START_TEST(strerror_check_2) {
  // Arrange
  int errnum = -1;
  // Act
  char* res_orig = strerror(errnum);
  char* res_own = s21_strerror(errnum);
  // Assert
  ck_assert_str_eq(res_orig, res_own);
}
END_TEST

START_TEST(strerror_check_3) {
  // Arrange
  int errnum = 100;
  // Act
  char* res_orig = strerror(errnum);
  char* res_own = s21_strerror(errnum);
  // Assert
  ck_assert_str_eq(res_orig, res_own);
}
END_TEST

START_TEST(strerror_check_4) {
  // Arrange
  int errnum = 130;
  // Act
  char* res_orig = strerror(errnum);
  char* res_own = s21_strerror(errnum);
  // Assert
  ck_assert_str_eq(res_orig, res_own);
}
END_TEST

START_TEST(strerror_check_5) {
  // Arrange
  int errnum = 133;
  // Act
  char* res_orig = strerror(errnum);
  char* res_own = s21_strerror(errnum);
  // Assert
  ck_assert_str_eq(res_orig, res_own);
}
END_TEST

START_TEST(strerror_check_6) {
  // Arrange
  int errnum = 134;
  // Act
  char* res_orig = strerror(errnum);
  char* res_own = s21_strerror(errnum);
  // Assert
  ck_assert_str_eq(res_orig, res_own);
}
END_TEST

START_TEST(strerror_check_7) {
  // Arrange
  int errnum = 200;
  // Act
  char* res_orig = strerror(errnum);
  char* res_own = s21_strerror(errnum);
  // Assert
  ck_assert_str_eq(res_orig, res_own);
}
END_TEST

Suite* s21_strerror_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_strerror");

  tc = tcase_create("case_strerror");
  tcase_add_test(tc, strerror_check_1);
  tcase_add_test(tc, strerror_check_2);
  tcase_add_test(tc, strerror_check_3);
  tcase_add_test(tc, strerror_check_4);
  tcase_add_test(tc, strerror_check_5);
  tcase_add_test(tc, strerror_check_6);
  tcase_add_test(tc, strerror_check_7);
  suite_add_tcase(s, tc);
  return s;
}