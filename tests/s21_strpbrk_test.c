#include "tests.h"

START_TEST(strpbrk_check_1) {
  // Arrange
  char str1[256] = "hello world\0";
  char str2[256] = " \0";
  // Act
  char* res_orig = strpbrk(str1, str2);
  char* res_own = s21_strpbrk(str1, str2);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strpbrk_check_2) {
  // Arrange
  char str1[256] = "abcdefg\0";
  char str2[256] = "xyz\0";
  // Act
  char* res_orig = strpbrk(str1, str2);
  char* res_own = s21_strpbrk(str1, str2);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strpbrk_check_3) {
  // Arrange
  char str1[256] = "1234567890\0";
  char str2[256] = "567\0";
  // Act
  char* res_orig = strpbrk(str1, str2);
  char* res_own = s21_strpbrk(str1, str2);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strpbrk_check_4) {
  // Arrange
  char str1[256] = "start,end\0";
  char str2[256] = ",.\0";
  // Act
  char* res_orig = strpbrk(str1, str2);
  char* res_own = s21_strpbrk(str1, str2);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strpbrk_check_5) {
  // Arrange
  char str1[256] = "\0";
  char str2[256] = "abc\0";
  // Act
  char* res_orig = strpbrk(str1, str2);
  char* res_own = s21_strpbrk(str1, str2);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strpbrk_check_6) {
  // Arrange
  char str1[256] = "sample\0";
  char str2[256] = "\0";
  // Act
  char* res_orig = strpbrk(str1, str2);
  char* res_own = s21_strpbrk(str1, str2);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strpbrk_check_7) {
  // Arrange
  char str1[256] = "abcdef\0";
  char str2[256] = "f\0";
  // Act
  char* res_orig = strpbrk(str1, str2);
  char* res_own = s21_strpbrk(str1, str2);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

Suite* s21_strpbrk_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_strpbrk");

  tc = tcase_create("case_strpbrk");
  tcase_add_test(tc, strpbrk_check_1);
  tcase_add_test(tc, strpbrk_check_2);
  tcase_add_test(tc, strpbrk_check_3);
  tcase_add_test(tc, strpbrk_check_4);
  tcase_add_test(tc, strpbrk_check_5);
  tcase_add_test(tc, strpbrk_check_6);
  tcase_add_test(tc, strpbrk_check_7);
  suite_add_tcase(s, tc);
  return s;
}