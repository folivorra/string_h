#include "tests.h"

START_TEST(memset_check_1) {
  // Arrange
  char str1[256] = "hello world\0";
  char str2[256] = "hello world\0";
  int c = 'q';
  s21_size_t size = 5;
  // Act
  memset(str1, c, size);
  s21_memset(str2, c, size);
  // Assert
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memset_check_2) {
  // Arrange
  char str1[256] = "hello world";
  char str2[256] = "hello world";
  int c = '0';
  s21_size_t size = 11;
  // Act
  memset(str1, c, size);
  s21_memset(str2, c, size);
  // Assert
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memset_check_3) {
  // Arrange
  char str1[256] = "";
  char str2[256] = "";
  int c = 'q';
  s21_size_t size = 5;
  // Act
  memset(str1, c, size);
  s21_memset(str2, c, size);
  // Assert
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memset_check_4) {
  // Arrange
  char str1[256] = "hello world\0";
  char str2[256] = "hello world\0";
  int c = 'q';
  s21_size_t size = 20;
  // Act
  memset(str1, c, size);
  s21_memset(str2, c, size);
  // Assert
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memset_check_5) {
  // Arrange
  char str1[256] = "hello world\0";
  char str2[256] = "hello world\0";
  int c = '4';
  s21_size_t size = 0;
  // Act
  memset(str1, c, size);
  s21_memset(str2, c, size);
  // Assert
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memset_check_6) {
  // Arrange
  char str1[256] = "hello world\0\0\0\0";
  char str2[256] = "hello world\0\0\0\0";
  int c = '\0';
  s21_size_t size = 10;
  // Act
  memset(str1, c, size);
  s21_memset(str2, c, size);
  // Assert
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memset_check_7) {
  // Arrange
  char str1[256] = "hello world\0";
  char str2[256] = "hello world\0";
  int c = 'q';
  s21_size_t size = 1;
  // Act
  memset(str1, c, size);
  s21_memset(str2, c, size);
  // Assert
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite* s21_memset_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_memset");

  tc = tcase_create("case_memset");
  tcase_add_test(tc, memset_check_1);
  tcase_add_test(tc, memset_check_2);
  tcase_add_test(tc, memset_check_3);
  tcase_add_test(tc, memset_check_4);
  tcase_add_test(tc, memset_check_5);
  tcase_add_test(tc, memset_check_6);
  tcase_add_test(tc, memset_check_7);
  suite_add_tcase(s, tc);
  return s;
}