#include "tests.h"

START_TEST(to_upper_check_1) {
  // Arrange
  const char str[256] = "abcdt";
  // Act
  char *cpy = s21_to_upper(str);
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "ABCDT");
  }
  free(cpy);
}
END_TEST

START_TEST(to_upper_check_2) {
  // Arrange
  const char str[256] = "abc3dt44";
  // Act
  char *cpy = s21_to_upper(str);
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "ABC3DT44");
  }
  free(cpy);
}
END_TEST

START_TEST(to_upper_check_3) {
  // Arrange
  const char str[256] = "abcQQdt";
  // Act
  char *cpy = s21_to_upper(str);
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "ABCQQDT");
  }
  free(cpy);
}
END_TEST

START_TEST(to_upper_check_4) {
  // Arrange
  const char *str = NULL;
  // Act
  char *cpy = s21_to_upper(str);
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "ABCDT");
  }
  free(cpy);
}
END_TEST

START_TEST(to_upper_check_5) {
  // Arrange
  const char str[256] = "&%124";
  // Act
  char *cpy = s21_to_upper(str);
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "&%124");
  }
  free(cpy);
}
END_TEST

Suite *s21_to_upper_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_to_upper");

  tc = tcase_create("case_to_upper");
  tcase_add_test(tc, to_upper_check_1);
  tcase_add_test(tc, to_upper_check_2);
  tcase_add_test(tc, to_upper_check_3);
  tcase_add_test(tc, to_upper_check_4);
  tcase_add_test(tc, to_upper_check_5);

  suite_add_tcase(s, tc);
  return s;
}