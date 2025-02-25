#include "tests.h"

START_TEST(strlen_check_1) {
  // Arrange
  const char str[256] = "Hello world\0";
  // Act
  int res_orig = strlen(str);
  int res_own = s21_strlen(str);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strlen_check_2) {
  // Arrange
  const char str[256] = "Hello world\n\0";
  // Act
  int res_orig = strlen(str);
  int res_own = s21_strlen(str);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strlen_check_3) {
  // Arrange
  const char str[256] = "a\n\0";
  // Act
  int res_orig = strlen(str);
  int res_own = s21_strlen(str);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strlen_check_4) {
  // Arrange
  const char str[256] = " \n\0";
  // Act
  int res_orig = strlen(str);
  int res_own = s21_strlen(str);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strlen_check_5) {
  // Arrange
  const char str[256] = " \0";
  // Act
  int res_orig = strlen(str);
  int res_own = s21_strlen(str);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strlen_check_6) {
  // Arrange
  const char str[256] = "\n\0";
  // Act
  int res_orig = strlen(str);
  int res_own = s21_strlen(str);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strlen_check_7) {
  // Arrange
  const char str[256] = "\0";
  // Act
  int res_orig = strlen(str);
  int res_own = s21_strlen(str);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

Suite *s21_strlen_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_strlen");

  tc = tcase_create("case_strlen");
  tcase_add_test(tc, strlen_check_1);
  tcase_add_test(tc, strlen_check_2);
  tcase_add_test(tc, strlen_check_3);
  tcase_add_test(tc, strlen_check_4);
  tcase_add_test(tc, strlen_check_5);
  tcase_add_test(tc, strlen_check_6);
  tcase_add_test(tc, strlen_check_7);
  suite_add_tcase(s, tc);
  return s;
}