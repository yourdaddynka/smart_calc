#include "../s21_smartcalc.h"

#include <check.h>

START_TEST(test_calc_1) {
  double x = 0.00;
  char *str = "5+1";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq(result, 6.00000);
}
END_TEST

START_TEST(test_calc_2) {
  double x = 0.00;
  char *str = "sqrt(16)+sin(1)";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq_tol(result, 4.841470, 1e-06);
}

END_TEST

START_TEST(test_calc_3) {
  double x = 0.00;
  char *str = "2^(2^(2^2))";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq(result, 65536);
}
END_TEST

START_TEST(test_calc_4) {
  double x = 0.00;
  char *str = "log(25)-acos(0.45)";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq_tol(result, 0.293909, 1e-06);
}
END_TEST

START_TEST(test_calc_5) {
  double x = 0.00;
  char *str = "(4*sin(2.9)+3*cos(0.47))/4";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq_tol(result, 0.907926, 1e-06);
}
END_TEST

START_TEST(test_calc_6) {
  double x = 0.00;
  char *str = "log(50)/acos(0.35)*atan(1.1)*sqrt(64)";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq_tol(result, 9.3318876, 1e-06);
}
END_TEST

START_TEST(test_calc_7) {
  double x = 0.00;
  char *str =
      "(sin(1.4)cos(0.85)/tan(0.68))/(asin(0.38)/"
      "2*acos(0.45)^3-atan(0.54)*sqrt(49))+ln(5)*log(100)";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq_tol(result, 2.98272, 1e-05);
}
END_TEST

START_TEST(test_calc_8) {
  double x = 0.00;
  char *str =
      "acos(0.25)^ln(2)-atan(1.5)*sqrt(16)*log(10)*sin(2.5)/(cos(1.1)/"
      "tan(1.9)*asin(0.4))";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq_tol(result, 38.104222613215, 1e-06);
}
END_TEST

START_TEST(test_calc_9) {
  double x = 0.00;
  char *str =
      "((sin(1.7)*acos(0.3)-atan(0.35)*tan(1.5))^2)/sqrt(9)*(ln(7)+log(1000)/"
      "acos(0.6))";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq_tol(result, 21.0601731, 1e-06);
}
END_TEST

START_TEST(test_calc_10) {
  double x = 0.00;
  char *str =
      "atan(0.75)*log(10)+sqrt(64)*sin(2)-cos(0.576)/acos(0.78)/"
      "5-2*ln(3)*asin(0.29)*tan(1.05)";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq_tol(result, 6.5427849584, 1e-06);
}
END_TEST

START_TEST(test_calc_11) {
  double x = 0.00;
  char *str =
      "(cos(2.1)^2*sin(1.2)*atan(0.85)+acos(0.4))/"
      "log(250)*sqrt(169)+ln(5)*asin(0.55)*tan(0.5)";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq_tol(result, 7.70412863, 1e-06);
}

END_TEST

START_TEST(test_calc_12) {
  double x = 0.00;
  char *str =
      "(sin(0.93)+acos(0.71)/atan(1.37)*tan(1.8))/"
      "(sqrt(25)*ln(10)*acos(0.3)-asin(0.6)*cos(1.1))";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq_tol(result, -0.193212471, 1e-06);
}
END_TEST

START_TEST(test_calc_13) {
  double x = 0.00;
  char *str = "sin(cos(tan(ln(log(1234)+1)*2)/3)-4)";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq_tol(result, -0.134926396, 1e-06);
}
END_TEST

START_TEST(test_calc_14) {
  double x = 0.00;
  char *str =
      "(sin(0.93)+acos(0.71)/atan(1.37)*tan(1.8))/"
      "(sqrt(25)*ln(10)*acos(0.3)-asin(0.6)*cos(1.1))-sin(cos(tan(ln(log((cos("
      "2.1)^2*sin(1.2)*atan(0.85)+acos(0.4))/"
      "log(250)*sqrt(169)+ln(5)*asin(0.55)*tan(0.5))+1)*2)/3)-4)";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq_tol(result, -0.565264615, 1e-06);
}
END_TEST

START_TEST(test_calc_15) {
  double x = 0.00;
  char *str = "(5+";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq_tol(result, 0, 1e-06);
}

END_TEST

START_TEST(test_calc_16) {
  double x = 0.00;
  char *str = "6*";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_double_eq_tol(result, 0, 1e-06);
}

END_TEST

START_TEST(test_calc_17) {
  double x = 0.00;
  char *str = "1/0";
  double result = 0;
  s21_smartcalc(str, x, &result);
  ck_assert_int_eq(isnan(result), 0);
}

END_TEST

int main() {
  Suite *suite = suite_create("s21_smartcalc: ");
  TCase *tcase_core = tcase_create("s21_smartcalc: ");
  SRunner *suite_runner = srunner_create(suite);
  int result;
  suite_add_tcase(suite, tcase_core);

  tcase_add_test(tcase_core, test_calc_1);
  tcase_add_test(tcase_core, test_calc_2);
  tcase_add_test(tcase_core, test_calc_3);
  tcase_add_test(tcase_core, test_calc_4);
  tcase_add_test(tcase_core, test_calc_5);
  tcase_add_test(tcase_core, test_calc_6);
  tcase_add_test(tcase_core, test_calc_7);
  tcase_add_test(tcase_core, test_calc_8);
  tcase_add_test(tcase_core, test_calc_9);
  tcase_add_test(tcase_core, test_calc_10);
  tcase_add_test(tcase_core, test_calc_11);
  tcase_add_test(tcase_core, test_calc_12);
  tcase_add_test(tcase_core, test_calc_13);
  tcase_add_test(tcase_core, test_calc_14);
  tcase_add_test(tcase_core, test_calc_15);
  tcase_add_test(tcase_core, test_calc_16);
  tcase_add_test(tcase_core, test_calc_17);

  srunner_run_all(suite_runner, CK_VERBOSE);
  result = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return result == 0 ? 0 : 1;
}