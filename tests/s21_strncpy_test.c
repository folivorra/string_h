#include "tests.h"

START_TEST(strncpy_check_1) {
  // Arrange
  char str[256] = "Hello\0";
  const char dst[256] = "\0";
  // Act
  char* res_orig = strncpy(str, dst, 3);
  char* res_own = s21_strncpy(str, dst, 3);
  // Assert
  ck_assert_str_eq(res_orig, res_own);
}
END_TEST

START_TEST(strncpy_check_2) {
  // Arrange
  char str[256] = "Hello world\n\0";
  const char dst[256] = "12345678\0";
  // Act
  char* res_orig = strncpy(str, dst, 5);
  char* res_own = s21_strncpy(str, dst, 5);
  // Assert
  ck_assert_str_eq(res_orig, res_own);
}
END_TEST

START_TEST(strncpy_check_3) {
  // Arrange
  char str[256] = "\0";
  const char dst[256] = "\0";
  // Act
  char* res_orig = strncpy(str, dst, 5);
  char* res_own = s21_strncpy(str, dst, 5);
  // Assert
  ck_assert_str_eq(res_orig, res_own);
}
END_TEST

START_TEST(strncpy_check_4) {
  // Arrange
  char str[256] = "Short\0";
  const char dst[256] = "\0";
  // Act
  char* res_orig = strncpy(str, dst, 10);
  char* res_own = s21_strncpy(str, dst, 10);
  // Assert
  ck_assert_str_eq(res_orig, res_own);
}
END_TEST

START_TEST(strncpy_check_5) {
  // Arrange
  char str[256] = "Hello\0";
  const char dst[256] = "\0";
  // Act
  char* res_orig = strncpy(str, dst, 1);
  char* res_own = s21_strncpy(str, dst, 1);
  // Assert
  ck_assert_str_eq(res_orig, res_own);
}
END_TEST

START_TEST(strncpy_check_6) {
  // Arrange
  char str[256] = "Test\0";
  const char dst[256] = "ABCDEFG\0";
  // Act
  char* res_orig = strncpy(str, dst, 100);
  char* res_own = s21_strncpy(str, dst, 100);
  // Assert
  ck_assert_str_eq(res_orig, res_own);
}
END_TEST

START_TEST(strncpy_check_7) {
  // Arrange
  char str[256] = "Embedded\0Null";
  const char dst[256] = "\0";
  // Act
  char* res_orig = strncpy(str, dst, 12);
  char* res_own = s21_strncpy(str, dst, 12);
  // Assert
  ck_assert_str_eq(res_orig, res_own);
}
END_TEST

Suite* s21_strncpy_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_strncpy");

  tc = tcase_create("case_strncpy");
  tcase_add_test(tc, strncpy_check_1);
  tcase_add_test(tc, strncpy_check_2);
  tcase_add_test(tc, strncpy_check_3);
  tcase_add_test(tc, strncpy_check_4);
  tcase_add_test(tc, strncpy_check_5);
  tcase_add_test(tc, strncpy_check_6);
  tcase_add_test(tc, strncpy_check_7);
  suite_add_tcase(s, tc);
  return s;
}