#include "tests.h"

START_TEST(strchr_check_1) {
  // Arrange
  const char str[256] = "hello world\0";
  int c = 'l';
  // Act
  char* res_orig = strchr(str, c);
  char* res_own = s21_strchr(str, c);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_ptr_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strchr_check_2) {
  // Arrange
  const char str[256] = "hello world\0";
  int c = 'h';
  // Act
  char* res_orig = strchr(str, c);
  char* res_own = s21_strchr(str, c);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_ptr_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strchr_check_3) {
  // Arrange
  const char str[256] = "hello world \0";
  int c = '\0';
  // Act
  char* res_orig = strchr(str, c);
  char* res_own = s21_strchr(str, c);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_ptr_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strchr_check_4) {
  // Arrange
  const char str[256] = "";
  int c = 'l';
  // Act
  char* res_orig = strchr(str, c);
  char* res_own = s21_strchr(str, c);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_ptr_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strchr_check_5) {
  // Arrange
  const char str[256] = "hello world\0a12313333";
  int c = '3';
  // Act
  char* res_orig = strchr(str, c);
  char* res_own = s21_strchr(str, c);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_ptr_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strchr_check_6) {
  // Arrange
  const char str[256] = "hello world\0";
  int c = ' ';
  // Act
  char* res_orig = strchr(str, c);
  char* res_own = s21_strchr(str, c);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_ptr_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strchr_check_7) {
  // Arrange
  const char str[256] = "hello world\0\0\0\0";
  int c = '\0';
  // Act
  char* res_orig = strchr(str, c);
  char* res_own = s21_strchr(str, c);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_ptr_eq(res_orig, res_own);
  }
}
END_TEST

Suite* s21_strchr_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_strchr");

  tc = tcase_create("case_strchr");
  tcase_add_test(tc, strchr_check_1);
  tcase_add_test(tc, strchr_check_2);
  tcase_add_test(tc, strchr_check_3);
  tcase_add_test(tc, strchr_check_4);
  tcase_add_test(tc, strchr_check_5);
  tcase_add_test(tc, strchr_check_6);
  tcase_add_test(tc, strchr_check_7);
  suite_add_tcase(s, tc);
  return s;
}