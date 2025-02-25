#include "tests.h"

START_TEST(sprintf_check_1) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";
  char *test_str = "hello";

  // Act
  sprintf(str_orig, "String: %10s", test_str);
  s21_sprintf(str_own, "String: %10s", test_str);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_2) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";
  char test_char = 'A';

  // Act
  sprintf(str_orig, "Char: %5c", test_char);
  s21_sprintf(str_own, "Char: %5c", test_char);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_3) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";
  int test_num = 12345;

  // Act
  sprintf(str_orig, "Number: %+10ld", (long)test_num);
  s21_sprintf(str_own, "Number: %+10ld", (long)test_num);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_4) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";
  int test_num = 0;
  unsigned int test_un = 0;

  // Act
  sprintf(str_orig, "Number: %12.hd %4.lu", (short)test_num,
          (unsigned long)test_un);
  s21_sprintf(str_own, "Number: %12.hd %4.lu", (short)test_num,
              (unsigned long)test_un);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_5) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";
  unsigned short test_num = 54321;

  // Act
  sprintf(str_orig, "Unsigned: %10hu", test_num);
  s21_sprintf(str_own, "Unsigned: %10hu", test_num);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_6) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";
  double test_num = 123.456789;

  // Act
  sprintf(str_orig, "Float: %.6f", test_num);
  s21_sprintf(str_own, "Float: %.6f", test_num);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_7) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "Literal %% sign");
  s21_sprintf(str_own, "Literal %% sign");

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_8) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";
  char *test_str = "test";
  int test_num = -42;
  unsigned int test_unsigned = 4242;
  double test_double = 42.42;

  // Act
  sprintf(str_orig, "Combined: %-10s %+5d %.2f %u %%", test_str, test_num,
          test_double, test_unsigned);
  s21_sprintf(str_own, "Combined: %-10s %+5d %.2f %u %%", test_str, test_num,
              test_double, test_unsigned);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_9) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";
  char *test_str = "hello";

  // Act
  sprintf(str_orig, "String: %.3s", test_str);
  s21_sprintf(str_own, "String: %.3s", test_str);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_10) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  int res1 = sprintf(str_orig, "%s", "asf");
  int res2 = s21_sprintf(str_own, "%s", "asf");

  // Assert
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_check_11) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  int res1 = sprintf(str_orig, "%.5d", -120);
  int res2 = s21_sprintf(str_own, "%.5d", -120);

  // Assert
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_check_12) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  int res1 = sprintf(str_orig, "%.20f", 123.1234);
  int res2 = s21_sprintf(str_own, "%.20f", 123.1234);

  // Assert
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_check_13) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%10.5d", -120);
  s21_sprintf(str_own, "%10.5d", -120);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_14) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "% d", 120);
  s21_sprintf(str_own, "% d", 120);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_15) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%10f", 33.1234);
  s21_sprintf(str_own, "%10f", 33.1234);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_16) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%-10.0f", 133.1234);
  s21_sprintf(str_own, "%-10.0f", 133.1234);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_17) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%.10f", 133.1234);
  s21_sprintf(str_own, "%.10f", 133.1234);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_18) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%#*.*x", 5, 3, 123);
  s21_sprintf(str_own, "%#*.*x", 5, 3, 123);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_19) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";
  int x = 123;

  // Act
  sprintf(str_orig, "%p", &x);
  s21_sprintf(str_own, "%p", &x);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_20) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%#o", 234);
  s21_sprintf(str_own, "%#o", 234);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_21) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%Lf", 234.123L);
  s21_sprintf(str_own, "%Lf", 234.123L);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_22) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%Le", 0.12L);
  s21_sprintf(str_own, "%Le", 0.12L);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_23) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%e", -3.12);
  s21_sprintf(str_own, "%e", -3.12);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_24) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%.5Lg", 12.543L);
  s21_sprintf(str_own, "%.5Lg", 12.543L);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_25) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%g", 23.0);
  s21_sprintf(str_own, "%g", 23.0);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_26) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%.12e", 0.0);
  s21_sprintf(str_own, "%.12e", 0.0);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_27) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%#x %#X", 123, 321);
  s21_sprintf(str_own, "%#x %#X", 123, 321);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_28) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%*.*d", 10, 3, -123);
  s21_sprintf(str_own, "%*.*d", 10, 3, -123);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_29) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%e", 123456789123.1);
  s21_sprintf(str_own, "%e", 123456789123.1);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_30) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%.6g", -1123123.1);
  s21_sprintf(str_own, "%.6g", -1123123.1);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_31) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%#*.*o", 10, 20, 11231);
  s21_sprintf(str_own, "%#*.*o", 10, 20, 11231);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_32) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%#*.*o", 10, 0, 11231);
  s21_sprintf(str_own, "%#*.*o", 10, 0, 11231);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_33) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%-20.g", 11231.2341);
  s21_sprintf(str_own, "%-20.g", 11231.2341);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_34) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%.20d", 11231);
  s21_sprintf(str_own, "%.20d", 11231);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_35) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%020d", 11231);
  s21_sprintf(str_own, "%020d", 11231);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_36) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%g", 11231.000);
  s21_sprintf(str_own, "%g", 11231.000);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_37) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%0*X", 30, 112315598);
  s21_sprintf(str_own, "%0*X", 30, 112315598);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_38) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%#0*X", 30, 112315598);
  s21_sprintf(str_own, "%#0*X", 30, 112315598);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_39) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%#0*x Helllo %+19.10d --- %10.5s", 30, 112315598, 2598,
          "Not hello");
  s21_sprintf(str_own, "%#0*x Helllo %+19.10d --- %10.5s", 30, 112315598, 2598,
              "Not hello");

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_40) {
  // Arrange
  char str_orig[1024] = "";
  char str_own[1024] = "";

  // Act
  sprintf(str_orig, "%#0*o", 30, 112315598);
  s21_sprintf(str_own, "%#0*o", 30, 112315598);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

START_TEST(sprintf_check_41) {
  // Arrange
  char str_orig[1024];
  char str_own[1024];
  int d = -42;
  unsigned int u = 3000000000;
  float f = 3.14159f;
  double df = 2.718281828459;
  char c = 'A';
  char *s = "Hello, World!";
  char *p = &c;
  int n_sprintf = 0;
  int n_s21 = 0;
  char percent = '%';

  const char *format =
      "%%: %% | %%c: %c | %%s: %s | %%d: %d | %%u: %u | %%f: %.2f | %%e: %.3e "
      "| %%E: %.3E | %%g: %.4g | %%G: %.4G | %%x: %#x | %%X: %#X | %%o: %#o | "
      "%%p %p |";

  // Act
  s21_sprintf(str_own, format, c, s, d, u, f, df, df, f, f, d, d, d, p);
  sprintf(str_orig, format, c, s, d, u, f, df, df, f, f, d, d, d, p);

  // Assert
  ck_assert_str_eq(str_orig, str_own);
}
END_TEST

Suite *s21_sprintf_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sprintf");

  tc = tcase_create("case_sprintf");
  tcase_add_test(tc, sprintf_check_1);
  tcase_add_test(tc, sprintf_check_2);
  tcase_add_test(tc, sprintf_check_3);
  tcase_add_test(tc, sprintf_check_4);
  tcase_add_test(tc, sprintf_check_5);
  tcase_add_test(tc, sprintf_check_6);
  tcase_add_test(tc, sprintf_check_7);
  tcase_add_test(tc, sprintf_check_8);
  tcase_add_test(tc, sprintf_check_9);
  tcase_add_test(tc, sprintf_check_10);
  tcase_add_test(tc, sprintf_check_11);
  tcase_add_test(tc, sprintf_check_12);
  tcase_add_test(tc, sprintf_check_13);
  tcase_add_test(tc, sprintf_check_14);
  tcase_add_test(tc, sprintf_check_15);
  tcase_add_test(tc, sprintf_check_16);
  tcase_add_test(tc, sprintf_check_17);
  tcase_add_test(tc, sprintf_check_18);
  tcase_add_test(tc, sprintf_check_19);
  tcase_add_test(tc, sprintf_check_20);
  tcase_add_test(tc, sprintf_check_21);
  tcase_add_test(tc, sprintf_check_22);
  tcase_add_test(tc, sprintf_check_23);
  tcase_add_test(tc, sprintf_check_24);
  tcase_add_test(tc, sprintf_check_25);
  tcase_add_test(tc, sprintf_check_26);
  tcase_add_test(tc, sprintf_check_27);
  tcase_add_test(tc, sprintf_check_28);
  tcase_add_test(tc, sprintf_check_29);
  tcase_add_test(tc, sprintf_check_30);
  tcase_add_test(tc, sprintf_check_31);
  tcase_add_test(tc, sprintf_check_32);
  tcase_add_test(tc, sprintf_check_33);
  tcase_add_test(tc, sprintf_check_34);
  tcase_add_test(tc, sprintf_check_35);
  tcase_add_test(tc, sprintf_check_36);
  tcase_add_test(tc, sprintf_check_37);
  tcase_add_test(tc, sprintf_check_38);
  tcase_add_test(tc, sprintf_check_39);
  tcase_add_test(tc, sprintf_check_40);
  tcase_add_test(tc, sprintf_check_41);

  suite_add_tcase(s, tc);

  return s;
}