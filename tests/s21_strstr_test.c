#include "tests.h"

START_TEST(strstr_check_1) {
  // Arrange
  char haystack[256] = "hello world\0";
  const char needle[256] = "world\0";
  // Act
  char* res_orig = strstr(haystack, needle);
  char* res_own = s21_strstr(haystack, needle);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strstr_check_2) {
  // Arrange
  char haystack[256] = "abcdef\0";
  const char needle[256] = "xyz\0";
  // Act
  char* res_orig = strstr(haystack, needle);
  char* res_own = s21_strstr(haystack, needle);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strstr_check_3) {
  // Arrange
  char haystack[256] = "1234567890\0";
  const char needle[256] = "124\0";
  // Act
  char* res_orig = strstr(haystack, needle);
  char* res_own = s21_strstr(haystack, needle);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strstr_check_4) {
  // Arrange
  char haystack[256] = "abcdef\0";
  const char needle[256] = "\0";
  // Act
  char* res_orig = strstr(haystack, needle);
  char* res_own = s21_strstr(haystack, needle);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strstr_check_5) {
  // Arrange
  char haystack[256] = "\0";
  const char needle[256] = "xyz\0";
  // Act
  char* res_orig = strstr(haystack, needle);
  char* res_own = s21_strstr(haystack, needle);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strstr_check_6) {
  // Arrange
  char haystack[256] = "repeated repeated\0";
  const char needle[256] = "repeated\0";
  // Act
  char* res_orig = strstr(haystack, needle);
  char* res_own = s21_strstr(haystack, needle);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strstr_check_7) {
  // Arrange
  char haystack[256] = "needle in a haystack\0";
  const char needle[256] = "stack\0";
  // Act
  char* res_orig = strstr(haystack, needle);
  char* res_own = s21_strstr(haystack, needle);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

Suite* s21_strstr_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_strstr");

  tc = tcase_create("case_strstr");
  tcase_add_test(tc, strstr_check_1);
  tcase_add_test(tc, strstr_check_2);
  tcase_add_test(tc, strstr_check_3);
  tcase_add_test(tc, strstr_check_4);
  tcase_add_test(tc, strstr_check_5);
  tcase_add_test(tc, strstr_check_6);
  tcase_add_test(tc, strstr_check_7);
  suite_add_tcase(s, tc);
  return s;
}