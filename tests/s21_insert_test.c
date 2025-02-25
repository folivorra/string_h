#include "tests.h"

START_TEST(insert_check_1) {
  const char str[256] = "abc";
  const char src[256] = "asd";
  s21_size_t start_index = 1;
  // Act
  char* new_str = s21_insert(src, str, start_index);
  // Assert
  if (new_str == NULL) {
    ck_assert_ptr_null(new_str);
  } else {
    ck_assert_str_eq(new_str, "aabcsd");
  }
  free(new_str);
}
END_TEST

START_TEST(insert_check_2) {
  const char str[256] = "abcasda";
  const char src[256] = "asd";
  s21_size_t start_index = 3;
  // Act
  char* new_str = s21_insert(src, str, start_index);
  // Assert
  if (new_str == NULL) {
    ck_assert_ptr_null(new_str);
  } else {
    ck_assert_str_eq(new_str, "asdabcasda");
  }
  free(new_str);
}
END_TEST

START_TEST(insert_check_3) {
  const char str[256] = "abc";
  const char src[256] = "asd";
  s21_size_t start_index = 0;
  // Act
  char* new_str = s21_insert(src, str, start_index);
  // Assert
  if (new_str == NULL) {
    ck_assert_ptr_null(new_str);
  } else {
    ck_assert_str_eq(new_str, "abcasd");
  }
  free(new_str);
}
END_TEST

START_TEST(insert_check_4) {
  const char str[256] = "abc";
  const char src[256] = "asd";
  s21_size_t start_index = 5;
  // Act
  char* new_str = s21_insert(str, src, start_index);
  // Assert
  if (new_str == NULL) {
    ck_assert_ptr_null(new_str);
  } else {
    ck_assert_str_eq(new_str, "abcasd");
  }
  free(new_str);
}
END_TEST

START_TEST(insert_check_5) {
  const char str[256] = "abc";
  const char src[256] = "";
  s21_size_t start_index = 0;
  // Act
  char* new_str = s21_insert(src, str, start_index);
  // Assert
  if (new_str == NULL) {
    ck_assert_ptr_null(new_str);
  } else {
    ck_assert_str_eq(new_str, "abc");
  }
  free(new_str);
}
END_TEST

Suite* s21_insert_suite(void) {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_insert");

  tc = tcase_create("case_insert");
  tcase_add_test(tc, insert_check_1);
  tcase_add_test(tc, insert_check_2);
  tcase_add_test(tc, insert_check_3);
  tcase_add_test(tc, insert_check_4);
  tcase_add_test(tc, insert_check_5);
  suite_add_tcase(s, tc);
  return s;
}