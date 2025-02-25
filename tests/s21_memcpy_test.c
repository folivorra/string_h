#include "tests.h"

START_TEST(memcpy_check_1) {
  // Arrange
  const char src[256] = "hello world\0";
  char dest1[256] = "";
  char dest2[256] = "";
  s21_size_t size = 5;
  // Act
  memcpy(dest1, src, size);
  s21_memcpy(dest2, src, size);
  // Assert
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(memcpy_check_2) {
  // Arrange
  const char src[256] = "hello world\0";
  char dest1[256] = "123";
  char dest2[256] = "123";
  s21_size_t size = 5;
  // Act
  memcpy(dest1, src, size);
  s21_memcpy(dest2, src, size);
  // Assert
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(memcpy_check_3) {
  // Arrange
  const char src[256] = "hello world1111\0";
  char dest1[256] = "\0\0";
  char dest2[256] = "\0\0";
  s21_size_t size = 0;
  // Act
  memcpy(dest1, src, size);
  s21_memcpy(dest2, src, size);
  // Assert
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(memcpy_check_4) {
  // Arrange
  const char src[256] = "hello world";
  char dest1[256] = "aaaa";
  char dest2[256] = "aaaa";
  s21_size_t size = 10;
  // Act
  memcpy(dest1, src, size);
  s21_memcpy(dest2, src, size);
  // Assert
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(memcpy_check_5) {
  // Arrange
  const char src[256] = "hello world\0";
  char dest1[256] = "11";
  char dest2[256] = "11";
  s21_size_t size = sizeof(src);
  // Act
  memcpy(dest1, src, size);
  s21_memcpy(dest2, src, size);
  // Assert
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(memcpy_check_6) {
  // Arrange
  const char src[256] = "";
  char dest1[256] = "";
  char dest2[256] = "";
  s21_size_t size = 0;
  // Act
  memcpy(dest1, src, size);
  s21_memcpy(dest2, src, size);
  // Assert
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(memcpy_check_7) {
  // Arrange
  const char src[256] = "hello world\0\0\0\0qqqq33";
  char dest1[256] = "\0\0\0\0\0\0\0";
  char dest2[256] = "\0\0\0\0\0\0\0";
  s21_size_t size = sizeof(dest1);
  // Act
  memcpy(dest1, src, size);
  s21_memcpy(dest2, src, size);
  // Assert
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite* s21_memcpy_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_memcpy");

  tc = tcase_create("case_memcpy");
  tcase_add_test(tc, memcpy_check_1);
  tcase_add_test(tc, memcpy_check_2);
  tcase_add_test(tc, memcpy_check_3);
  tcase_add_test(tc, memcpy_check_4);
  tcase_add_test(tc, memcpy_check_5);
  tcase_add_test(tc, memcpy_check_6);
  tcase_add_test(tc, memcpy_check_7);
  suite_add_tcase(s, tc);
  return s;
}