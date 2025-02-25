#include "tests.h"

START_TEST(strncat_check_1) {
  // Arrange
  const char src[256] = "Hello world\0";
  char dest1[256] = "";
  char dest2[256] = "";
  s21_size_t size = 5;
  // Act
  strncat(dest1, src, size);
  s21_strncat(dest2, src, size);
  // Assert
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_check_2) {
  // Arrange
  const char src[256] = "12355321";
  char dest1[256] = "asd";
  char dest2[256] = "asd";
  s21_size_t size = 5;
  // Act
  strncat(dest1, src, size);
  s21_strncat(dest2, src, size);
  // Assert
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_check_3) {
  // Arrange
  const char src[256] = "Hello worldssss";
  char dest1[256] = "asddddd";
  char dest2[256] = "asddddd";
  s21_size_t size = 5;
  // Act
  strncat(dest1, src, size);
  s21_strncat(dest2, src, size);
  // Assert
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_check_4) {
  // Arrange
  const char src[256] = "Hello world";
  char dest1[256] = "aaaaaa";
  char dest2[256] = "aaaaaa";
  s21_size_t size = 0;
  // Act
  strncat(dest1, src, size);
  s21_strncat(dest2, src, size);
  // Assert
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_check_5) {
  // Arrange
  const char src[256] = "Hello world";
  char dest1[256] = "";
  char dest2[256] = "";
  s21_size_t size = 11;
  // Act
  strncat(dest1, src, size);
  s21_strncat(dest2, src, size);
  // Assert
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_check_6) {
  // Arrange
  const char src[256] = "Hello";
  char dest1[256] = "aaaa";
  char dest2[256] = "aaaa";
  s21_size_t size = 10;
  // Act
  strncat(dest1, src, size);
  s21_strncat(dest2, src, size);
  // Assert
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_check_7) {
  // Arrange
  const char src[256] = "Hello world\0\0\0\0\0";
  char dest1[256] = "\0\0";
  char dest2[256] = "\0\0";
  s21_size_t size = 8;
  // Act
  strncat(dest1, src, size);
  s21_strncat(dest2, src, size);
  // Assert
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite *s21_strncat_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_strncat");

  tc = tcase_create("case_strncat");
  tcase_add_test(tc, strncat_check_1);
  tcase_add_test(tc, strncat_check_2);
  tcase_add_test(tc, strncat_check_3);
  tcase_add_test(tc, strncat_check_4);
  tcase_add_test(tc, strncat_check_5);
  tcase_add_test(tc, strncat_check_6);
  tcase_add_test(tc, strncat_check_7);
  suite_add_tcase(s, tc);
  return s;
}