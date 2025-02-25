#include "tests.h"

START_TEST(strrchr_check_1) {
  // Arrange
  const char str[256] = "hello world\0";
  int c = 'o';
  // Act
  char* res_orig = strrchr(str, c);
  char* res_own = s21_strrchr(str, c);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strrchr_check_2) {
  // Arrange
  const char str[256] = "abcdefg\0";
  int c = 'x';
  // Act
  char* res_orig = strrchr(str, c);
  char* res_own = s21_strrchr(str, c);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strrchr_check_3) {
  // Arrange
  const char str[256] = "1234567890\0";
  int c = '1';
  // Act
  char* res_orig = strrchr(str, c);
  char* res_own = s21_strrchr(str, c);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strrchr_check_4) {
  // Arrange
  const char str[256] = "hello\0";
  int c = '\0';
  // Act
  char* res_orig = strrchr(str, c);
  char* res_own = s21_strrchr(str, c);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strrchr_check_5) {
  // Arrange
  const char str[256] = "repeat repeat\0";
  int c = 'r';
  // Act
  char* res_orig = strrchr(str, c);
  char* res_own = s21_strrchr(str, c);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strrchr_check_6) {
  // Arrange
  const char str[256] = "\0";
  int c = 'a';
  // Act
  char* res_orig = strrchr(str, c);
  char* res_own = s21_strrchr(str, c);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strrchr_check_7) {
  // Arrange
  const char str[256] = "abcdef\0";
  int c = 'f';
  // Act
  char* res_orig = strrchr(str, c);
  char* res_own = s21_strrchr(str, c);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

Suite* s21_strrchr_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_strrchr");

  tc = tcase_create("case_strrchr");
  tcase_add_test(tc, strrchr_check_1);
  tcase_add_test(tc, strrchr_check_2);
  tcase_add_test(tc, strrchr_check_3);
  tcase_add_test(tc, strrchr_check_4);
  tcase_add_test(tc, strrchr_check_5);
  tcase_add_test(tc, strrchr_check_6);
  tcase_add_test(tc, strrchr_check_7);
  suite_add_tcase(s, tc);
  return s;
}