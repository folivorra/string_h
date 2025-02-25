#include "tests.h"

START_TEST(memchr_check_1) {
  // Arrange
  char str[256] = "hello world";
  char* res_orig;
  char* res_own;
  int c = 'l';
  s21_size_t size = sizeof(str);
  // Act
  res_orig = memchr(str, c, size);
  res_own = s21_memchr(str, c, size);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_ptr_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(memchr_check_2) {
  // Arrange
  char str[256] = "hello world123123aaas";
  char* res_orig;
  char* res_own;
  int c = 's';
  s21_size_t size = 15;
  // Act
  res_orig = memchr(str, c, size);
  res_own = s21_memchr(str, c, size);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_ptr_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(memchr_check_3) {
  // Arrange
  char str[256] = "hello world";
  char* res_orig;
  char* res_own;
  int c = '1';
  s21_size_t size = sizeof(str);
  // Act
  res_orig = memchr(str, c, size);
  res_own = s21_memchr(str, c, size);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_ptr_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(memchr_check_4) {
  // Arrange
  char str[256] = "he5llo world";
  char* res_orig;
  char* res_own;
  int c = '5';
  s21_size_t size = 2;
  // Act
  res_orig = memchr(str, c, size);
  res_own = s21_memchr(str, c, size);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_ptr_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(memchr_check_5) {
  // Arrange
  char str[256] = "hello world";
  char* res_orig;
  char* res_own;
  int c = 'e';
  s21_size_t size = 3;
  // Act
  res_orig = memchr(str, c, size);
  res_own = s21_memchr(str, c, size);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_ptr_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(memchr_check_6) {
  // Arrange
  char str[256] = "";
  char* res_orig;
  char* res_own;
  int c = 'l';
  s21_size_t size = sizeof(str);
  // Act
  res_orig = memchr(str, c, size);
  res_own = s21_memchr(str, c, size);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_ptr_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(memchr_check_7) {
  // Arrange
  char str[256] = "hello world\0\0\0";
  char* res_orig;
  char* res_own;
  int c = 'd';
  s21_size_t size = sizeof(str);
  // Act
  res_orig = memchr(str, c, size);
  res_own = s21_memchr(str, c, size);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_ptr_eq(res_orig, res_own);
  }
}
END_TEST

Suite* s21_memchr_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_memchr");

  tc = tcase_create("case_memchr");
  tcase_add_test(tc, memchr_check_1);
  tcase_add_test(tc, memchr_check_2);
  tcase_add_test(tc, memchr_check_3);
  tcase_add_test(tc, memchr_check_4);
  tcase_add_test(tc, memchr_check_5);
  tcase_add_test(tc, memchr_check_6);
  tcase_add_test(tc, memchr_check_7);
  suite_add_tcase(s, tc);
  return s;
}