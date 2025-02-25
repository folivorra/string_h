#include "tests.h"

START_TEST(to_lower_check_1) {
  // Arrange
  const char str[256] = "ABCDT";
  // Act
  char *cpy = s21_to_lower(str);
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "abcdt");
  }
  free(cpy);
}
END_TEST

START_TEST(to_lower_check_2) {
  // Arrange
  const char str[256] = "ABC3DT44";
  // Act
  char *cpy = s21_to_lower(str);
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "abc3dt44");
  }
  free(cpy);
}
END_TEST

START_TEST(to_lower_check_3) {
  // Arrange
  const char str[256] = "ABCQQDT";
  // Act
  char *cpy = s21_to_lower(str);
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "abcqqdt");
  }
  free(cpy);
}
END_TEST

START_TEST(to_lower_check_4) {
  // Arrange
  const char *str = NULL;
  // Act
  char *cpy = s21_to_lower(str);
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "ABCDT");
  }
  free(cpy);
}
END_TEST

START_TEST(to_lower_check_5) {
  // Arrange
  const char str[256] = "&%124";
  // Act
  char *cpy = s21_to_lower(str);
  // Assert
  if (cpy == NULL) {
    ck_assert_ptr_null(cpy);
  } else {
    ck_assert_str_eq(cpy, "&%124");
  }
  free(cpy);
}
END_TEST

Suite *s21_to_lower_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_to_lower");

  tc = tcase_create("case_to_lowe");
  tcase_add_test(tc, to_lower_check_1);
  tcase_add_test(tc, to_lower_check_2);
  tcase_add_test(tc, to_lower_check_3);
  tcase_add_test(tc, to_lower_check_4);
  tcase_add_test(tc, to_lower_check_5);

  suite_add_tcase(s, tc);
  return s;
}