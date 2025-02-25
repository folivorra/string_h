#include "tests.h"

START_TEST(strncmp_check_1) {
  // Arrange
  const char str1[256] = "hello world\0";
  const char str2[256] = "hello wordld\0";
  s21_size_t size = 4;
  // Act
  int res_orig = strncmp(str1, str2, size);
  int res_own = s21_strncmp(str1, str2, size);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strncmp_check_2) {
  // Arrange
  const char str1[256] = "hello world\0";
  const char str2[256] = "hello world\0";
  s21_size_t size = 11;
  // Act
  int res_orig = strncmp(str1, str2, size);
  int res_own = s21_strncmp(str1, str2, size);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strncmp_check_3) {
  // Arrange
  const char str1[256] = "hello world\0";
  const char str2[256] = "";
  s21_size_t size = 6;
  // Act
  int res_orig = strncmp(str1, str2, size);
  int res_own = s21_strncmp(str1, str2, size);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strncmp_check_4) {
  // Arrange
  const char str1[256] = "";
  const char str2[256] = "hello wordld\0";
  s21_size_t size = 4;
  // Act
  int res_orig = strncmp(str1, str2, size);
  int res_own = s21_strncmp(str1, str2, size);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strncmp_check_5) {
  // Arrange
  const char str1[256] = "hello world\0";
  const char str2[256] = "1234567";
  s21_size_t size = 5;
  // Act
  int res_orig = strncmp(str1, str2, size);
  int res_own = s21_strncmp(str1, str2, size);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strncmp_check_6) {
  // Arrange
  const char str1[256] = "hello world\0";
  const char str2[256] = "hello world\0";
  s21_size_t size = 0;
  // Act
  int res_orig = strncmp(str1, str2, size);
  int res_own = s21_strncmp(str1, str2, size);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strncmp_check_7) {
  // Arrange
  const char str1[256] = "\0\0hello world\0";
  const char str2[256] = "\0";
  s21_size_t size = 6;
  // Act
  int res_orig = strncmp(str1, str2, size);
  int res_own = s21_strncmp(str1, str2, size);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

Suite *s21_strncmp_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_strncmp");

  tc = tcase_create("case_strncmp");
  tcase_add_test(tc, strncmp_check_1);
  tcase_add_test(tc, strncmp_check_2);
  tcase_add_test(tc, strncmp_check_3);
  tcase_add_test(tc, strncmp_check_4);
  tcase_add_test(tc, strncmp_check_5);
  tcase_add_test(tc, strncmp_check_6);
  tcase_add_test(tc, strncmp_check_7);
  suite_add_tcase(s, tc);
  return s;
}