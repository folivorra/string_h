#include "tests.h"

START_TEST(memcmp_check_1) {
  // Arrange
  const char str1[256] = "hello world\0";
  const char str2[256] = " hello";
  s21_size_t size = sizeof(str2);
  // Act
  int res_orig = memcmp(str1, str2, size);
  int res_own = s21_memcmp(str1, str2, size);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(memcmp_check_2) {
  // Arrange
  const char str1[256] = "1232414";
  const char str2[256] = " 32111";
  s21_size_t size = sizeof(str1);
  // Act
  int res_orig = memcmp(str1, str2, size);
  int res_own = s21_memcmp(str1, str2, size);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(memcmp_check_3) {
  // Arrange
  const char str1[256] = "11111";
  const char str2[256] = "3333";
  s21_size_t size = 0;
  // Act
  int res_orig = memcmp(str1, str2, size);
  int res_own = s21_memcmp(str1, str2, size);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(memcmp_check_4) {
  // Arrange
  const char str1[256] = "";
  const char str2[256] = "123123123123";
  s21_size_t size = sizeof(str2);
  // Act
  int res_orig = memcmp(str1, str2, size);
  int res_own = s21_memcmp(str1, str2, size);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(memcmp_check_5) {
  // Arrange
  const char str1[256] = "hello world\0";
  const char str2[256] = "hello worlz";
  s21_size_t size = sizeof(str1);
  // Act
  int res_orig = memcmp(str1, str2, size);
  int res_own = s21_memcmp(str1, str2, size);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(memcmp_check_6) {
  // Arrange
  const char str1[256] = "\0\0\0\\0";
  const char str2[256] = "\0\0";
  s21_size_t size = 5;
  // Act
  int res_orig = memcmp(str1, str2, size);
  int res_own = s21_memcmp(str1, str2, size);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

START_TEST(memcmp_check_7) {
  // Arranges
  const char str1[256] = "";
  const char str2[256] = "";
  s21_size_t size = 10;
  // Act
  int res_orig = memcmp(str1, str2, size);
  int res_own = s21_memcmp(str1, str2, size);
  // Assert
  ck_assert_int_eq(res_orig, res_own);
}
END_TEST

Suite* s21_memcmp_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_memcmp");

  tc = tcase_create("case_memcmp");
  tcase_add_test(tc, memcmp_check_1);
  tcase_add_test(tc, memcmp_check_2);
  tcase_add_test(tc, memcmp_check_3);
  tcase_add_test(tc, memcmp_check_4);
  tcase_add_test(tc, memcmp_check_5);
  tcase_add_test(tc, memcmp_check_6);
  tcase_add_test(tc, memcmp_check_7);

  suite_add_tcase(s, tc);
  return s;
}