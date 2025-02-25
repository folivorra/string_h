#include "tests.h"

START_TEST(strtok_check_1) {
  // Arrange
  char str[256] = ",,,,\0";
  const char delim[256] = ",\0";
  // Act
  char* res_orig = strtok(str, delim);
  char* res_own = s21_strtok(str, delim);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strtok_check_2) {
  // Arrange
  char str1[256] = "a,b,c\0";
  char str2[256] = "a,b,c\0";
  const char delim[256] = ",\0";
  // Act
  char* res_orig = strtok(str1, delim);
  char* res_own = s21_strtok(str2, delim);

  res_orig = strtok(s21_NULL, delim);
  res_own = s21_strtok(s21_NULL, delim);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strtok_check_3) {
  // Arrange
  char str[256] = ",,,Hello,,world,,,\0";
  const char delim[256] = ",\0";
  // Act
  char* res_orig = strtok(str, delim);
  char* res_own = s21_strtok(str, delim);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strtok_check_4) {
  // Arrange
  char str[256] = "abc;;def;;ghi\0";
  const char delim[256] = ";;\0";
  // Act
  char* res_orig = strtok(str, delim);
  char* res_own = s21_strtok(str, delim);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strtok_check_5) {
  // Arrange
  char str[256] = "abc\0";
  const char delim[256] = ".\0";
  // Act
  char* res_orig = strtok(str, delim);
  char* res_own = s21_strtok(str, delim);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strtok_check_6) {
  // Arrange
  char str[256] = "\0";
  const char delim[256] = " \0";
  // Act
  char* res_orig = strtok(str, delim);
  char* res_own = s21_strtok(str, delim);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

START_TEST(strtok_check_7) {
  // Arrange
  char str[256] = "one:two:three\0";
  const char delim[256] = ";:\0";
  // Act
  char* res_orig = strtok(str, delim);
  char* res_own = s21_strtok(str, delim);
  // Assert
  if (res_orig == NULL && res_own == NULL) {
    ck_assert_ptr_null(res_orig);
    ck_assert_ptr_null(res_own);
  } else {
    ck_assert_str_eq(res_orig, res_own);
  }
}
END_TEST

Suite* s21_strtok_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_strtok");

  tc = tcase_create("case_strtok");
  tcase_add_test(tc, strtok_check_1);
  tcase_add_test(tc, strtok_check_2);
  tcase_add_test(tc, strtok_check_3);
  tcase_add_test(tc, strtok_check_4);
  tcase_add_test(tc, strtok_check_5);
  tcase_add_test(tc, strtok_check_6);
  tcase_add_test(tc, strtok_check_7);
  suite_add_tcase(s, tc);
  return s;
}