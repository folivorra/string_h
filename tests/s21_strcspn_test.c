#include "tests.h"

START_TEST(strcspn_check_1) {
  // Arrange
  const char str1[256] = "hello world\0";
  const char str2[256] = " \0";
  // Act
  s21_size_t res_orig = strcspn(str1, str2);
  s21_size_t res_own = s21_strcspn(str1, str2);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strcspn_check_2) {
  // Arrange
  const char str1[256] = "abcdefg\0";
  const char str2[256] = "xzy\0";
  // Act
  s21_size_t res_orig = strcspn(str1, str2);
  s21_size_t res_own = s21_strcspn(str1, str2);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strcspn_check_3) {
  // Arrange
  const char str1[256] = "1234567890\0";
  const char str2[256] = "567\0";
  // Act
  s21_size_t res_orig = strcspn(str1, str2);
  s21_size_t res_own = s21_strcspn(str1, str2);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strcspn_check_4) {
  // Arrange
  const char str1[256] = "foo bar\0";
  const char str2[256] = "o\0";
  // Act
  s21_size_t res_orig = strcspn(str1, str2);
  s21_size_t res_own = s21_strcspn(str1, str2);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strcspn_check_5) {
  // Arrange
  const char str1[256] = "empty\0";
  const char str2[256] = "\0";
  // Act
  s21_size_t res_orig = strcspn(str1, str2);
  s21_size_t res_own = s21_strcspn(str1, str2);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strcspn_check_6) {
  // Arrange
  const char str1[256] = "\0";
  const char str2[256] = "ABC\0";
  // Act
  s21_size_t res_orig = strcspn(str1, str2);
  s21_size_t res_own = s21_strcspn(str1, str2);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(strcspn_check_7) {
  // Arrange
  const char str1[256] = "beginning,end\0";
  const char str2[256] = ",.\0";
  // Act
  s21_size_t res_orig = strcspn(str1, str2);
  s21_size_t res_own = s21_strcspn(str1, str2);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

Suite *s21_strcspn_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_strcspn");

  tc = tcase_create("case_strcspn");
  tcase_add_test(tc, strcspn_check_1);
  tcase_add_test(tc, strcspn_check_2);
  tcase_add_test(tc, strcspn_check_3);
  tcase_add_test(tc, strcspn_check_4);
  tcase_add_test(tc, strcspn_check_5);
  tcase_add_test(tc, strcspn_check_6);
  tcase_add_test(tc, strcspn_check_7);
  suite_add_tcase(s, tc);
  return s;
}