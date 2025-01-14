#include <check.h>
#include <stdio.h>

#include "s21_matrix.h"

// Тесты для функции:
// int s21_create_matrix(int rows, int columns, matrix_t *result);
START_TEST(s21_create_matrix_test_1) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(2, 2, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_2) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(15, 15, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_3) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(30, 30, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_4) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(1, 1, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_5) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(10, 1, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_6) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(1, 10, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_7) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_create_matrix(-5, 5, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_8) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_create_matrix(0, 0, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_9) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_create_matrix(5, -1, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_10) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_create_matrix(-1, 5, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_11) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_create_matrix(-5, -5, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_12) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_create_matrix(-10, 10, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_13) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(5, 10, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_14) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(0, s21_create_matrix(10, 5, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_15) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_create_matrix(-1, 4, &matrix));
}
END_TEST

// Тесты для функции:
// void s21_remove_matrix(matrix_t *A);
START_TEST(s21_remove_matrix_test_1) {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(2, 2, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test_2) {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(20, 20, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test_3) {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(20, 0, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test_4) {
  matrix_t matrix = {NULL, 0, 0};
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test_5) {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(1, 1, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

// Тесты для функции -- int s21_eq_matrix(matrix_t *A, matrix_t *B);
START_TEST(s21_eq_matrix_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0000001;
  A.matrix[0][1] = 2.0000001;
  A.matrix[1][0] = 3.0000001;
  A.matrix[1][1] = 4.0000001;
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.12345671;
  A.matrix[0][1] = 2.12345672;
  A.matrix[1][0] = 3.12345673;
  A.matrix[1][1] = 4.12345674;
  B.matrix[0][0] = 1.12345675;
  B.matrix[0][1] = 2.12345676;
  B.matrix[1][0] = 3.12345677;
  B.matrix[1][1] = 4.12345679;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.12345671;
  A.matrix[0][1] = 2.12345672;
  A.matrix[0][2] = 3.12345673;
  A.matrix[1][0] = 4.12345674;
  A.matrix[1][1] = 4.12345674;
  A.matrix[1][2] = 4.12345674;
  B.matrix[0][0] = 1.12345675;
  B.matrix[0][1] = 2.12345676;
  B.matrix[1][0] = 3.12345677;
  B.matrix[1][1] = 4.12345679;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  A.matrix[0][0] = 3454.213;
  A.matrix[0][1] = 32413.324;
  A.matrix[0][2] = 234.25;
  A.matrix[0][3] = 3124.3215;
  A.matrix[0][4] = 12.1;
  A.matrix[1][0] = 123.23;
  A.matrix[1][1] = 3456.46;
  A.matrix[1][2] = 32467.1;
  A.matrix[1][3] = -1234.56;
  A.matrix[1][4] = 1234.43;
  A.matrix[2][0] = 3454.213;
  A.matrix[2][1] = 32413.324;
  A.matrix[2][2] = 234.25;
  A.matrix[2][3] = 3124.3215;
  A.matrix[2][4] = 12.1;
  A.matrix[3][0] = 123.23;
  A.matrix[3][1] = 3456.46;
  A.matrix[3][2] = 32467.1;
  A.matrix[3][3] = 1234.56;
  A.matrix[3][4] = 1234.43;
  A.matrix[4][0] = 3454.213;
  A.matrix[4][1] = -32413.324;
  A.matrix[4][2] = 234.25;
  A.matrix[4][3] = 3124.3215;
  A.matrix[4][4] = 12.1;
  B.matrix[0][0] = 3454.213;
  B.matrix[0][1] = 32413.324;
  B.matrix[0][2] = 234.25;
  B.matrix[0][3] = 3124.3215;
  B.matrix[0][4] = 12.1;
  B.matrix[1][0] = 123.23;
  B.matrix[1][1] = 3456.46;
  B.matrix[1][2] = 32467.1;
  B.matrix[1][3] = -1234.56;
  B.matrix[1][4] = 1234.43;
  B.matrix[2][0] = 3454.213;
  B.matrix[2][1] = 32413.324;
  B.matrix[2][2] = 234.25;
  B.matrix[2][3] = 3124.3215;
  B.matrix[2][4] = 12.1;
  B.matrix[3][0] = 123.23;
  B.matrix[3][1] = 3456.46;
  B.matrix[3][2] = 32467.1;
  B.matrix[3][3] = 1234.56;
  B.matrix[3][4] = 1234.43;
  B.matrix[4][0] = 3454.213;
  B.matrix[4][1] = -32413.324;
  B.matrix[4][2] = 234.25;
  B.matrix[4][3] = 3124.3215;
  B.matrix[4][4] = 12.1;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  A.matrix[0][0] = -3454.213;
  A.matrix[0][1] = -32413.324;
  A.matrix[0][2] = -234.25;
  A.matrix[0][3] = -3124.3215;
  A.matrix[0][4] = -12.1;
  A.matrix[1][0] = -123.23;
  A.matrix[1][1] = -3456.46;
  A.matrix[1][2] = -32467.1;
  A.matrix[1][3] = -1234.56;
  A.matrix[1][4] = 1234.43;
  A.matrix[2][0] = 3454.213;
  A.matrix[2][1] = 32413.324;
  A.matrix[2][2] = 234.25;
  A.matrix[2][3] = 3124.3215;
  A.matrix[2][4] = 12.1;
  A.matrix[3][0] = 123.23;
  A.matrix[3][1] = 3456.46;
  A.matrix[3][2] = -32467.1;
  A.matrix[3][3] = 1234.56;
  A.matrix[3][4] = 1234.43;
  A.matrix[4][0] = 3454.213;
  A.matrix[4][1] = -32413.324;
  A.matrix[4][2] = 234.25;
  A.matrix[4][3] = 3124.3215;
  A.matrix[4][4] = 12.1;
  B.matrix[0][0] = 3454.213;
  B.matrix[0][1] = 32413.324;
  B.matrix[0][2] = 234.25;
  B.matrix[0][3] = 3124.3215;
  B.matrix[0][4] = 12.1;
  B.matrix[1][0] = 123.23;
  B.matrix[1][1] = 3456.46;
  B.matrix[1][2] = 32467.1;
  B.matrix[1][3] = -1234.56;
  B.matrix[1][4] = 1234.43;
  B.matrix[2][0] = 3454.213;
  B.matrix[2][1] = 32413.324;
  B.matrix[2][2] = 234.25;
  B.matrix[2][3] = 3124.3215;
  B.matrix[2][4] = 12.1;
  B.matrix[3][0] = 123.23;
  B.matrix[3][1] = 3456.46;
  B.matrix[3][2] = 32467.1;
  B.matrix[3][3] = 1234.56;
  B.matrix[3][4] = 1234.43;
  B.matrix[4][0] = 3454.213;
  B.matrix[4][1] = -32413.324;
  B.matrix[4][2] = 234.25;
  B.matrix[4][3] = 3124.3215;
  B.matrix[4][4] = 12.1;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 234.12345679;
  B.matrix[0][0] = 234.1234567123;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 234.12345679;
  B.matrix[0][0] = 234.1134567123;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_8) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 234.12345679;
  B.matrix[0][0] = -234.1234567123;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_9) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(1, 5, &B);
  A.matrix[0][0] = 123.2121;
  A.matrix[0][1] = 123;
  A.matrix[0][2] = 1243235;
  A.matrix[0][3] = 43532;
  A.matrix[0][4] = 2435;
  B.matrix[0][0] = 123.2121;
  B.matrix[0][1] = 123;
  B.matrix[0][2] = 1243235;
  B.matrix[0][3] = 43532;
  B.matrix[0][4] = 2435;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_10) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(1, 5, &B);
  A.matrix[0][0] = 123.2121;
  A.matrix[0][1] = 123;
  A.matrix[0][2] = 1243235;
  A.matrix[0][3] = 43532;
  A.matrix[0][4] = 2435;
  B.matrix[0][0] = 123.2121;
  B.matrix[0][1] = 123;
  B.matrix[0][2] = 1243235;
  B.matrix[0][3] = 43532;
  B.matrix[0][4] = 2;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_11) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(1, 5, &B);
  A.matrix[0][0] = 123.2121;
  A.matrix[0][1] = 123;
  A.matrix[0][2] = 1243235;
  B.matrix[0][0] = 123.2121;
  B.matrix[0][1] = 123;
  B.matrix[0][2] = 1243235;
  B.matrix[0][3] = 43532;
  B.matrix[0][4] = 2;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_12) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = -123.2121;
  A.matrix[0][1] = -123;
  A.matrix[0][2] = -1243235;
  A.matrix[1][0] = -123.324;
  A.matrix[1][1] = -543.123;
  A.matrix[1][2] = -354.123;
  A.matrix[2][0] = -54.123;
  A.matrix[2][1] = -34.213;
  A.matrix[2][2] = -123.5;
  B.matrix[0][0] = -123.2121;
  B.matrix[0][1] = -123;
  B.matrix[0][2] = -1243235;
  B.matrix[1][0] = -123.324;
  B.matrix[1][1] = -543.123;
  B.matrix[1][2] = -354.123;
  B.matrix[2][0] = -54.123;
  B.matrix[2][1] = -34.213;
  B.matrix[2][2] = -123.5;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_13) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = -123.2121;
  A.matrix[0][1] = -123;
  A.matrix[0][2] = -1243235;
  A.matrix[1][0] = -123.324;
  A.matrix[1][1] = -543.123;
  A.matrix[1][2] = -354.123;
  A.matrix[2][0] = -54.123;
  A.matrix[2][1] = -34.213;
  A.matrix[2][2] = -123.5;
  B.matrix[0][0] = 123.2121;
  B.matrix[0][1] = 123;
  B.matrix[0][2] = 1243235;
  B.matrix[1][0] = 123.324;
  B.matrix[1][1] = 543.123;
  B.matrix[1][2] = 354.123;
  B.matrix[2][0] = 54.123;
  B.matrix[2][1] = 34.213;
  B.matrix[2][2] = 123.5;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_14) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  B.columns = -100;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_15) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  B.rows = 0;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// Тесты для функции:
// int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
START_TEST(s21_sum_matrix_test_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;
  matrix_t check;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  s21_create_matrix(2, 2, &check);
  matrix1.matrix[0][0] = 2.9;
  matrix1.matrix[0][1] = 1.2;
  matrix1.matrix[1][0] = -4.5;
  matrix1.matrix[1][1] = 7.1;

  matrix2.matrix[0][0] = 1.1;
  matrix2.matrix[0][1] = 2.3;
  matrix2.matrix[1][0] = 3.5;
  matrix2.matrix[1][1] = -2.1;

  check.matrix[0][0] = 4.0;
  check.matrix[0][1] = 3.5;
  check.matrix[1][0] = -1.0;
  check.matrix[1][1] = 5.0;
  int res = s21_sum_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_sum_matrix_test_2) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;
  matrix_t check;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  s21_create_matrix(2, 2, &check);
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 1;
  matrix1.matrix[1][0] = 1;
  matrix1.matrix[1][1] = 1;

  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = 1;
  matrix2.matrix[1][0] = 1;
  matrix2.matrix[1][1] = 1;

  check.matrix[0][0] = 2;
  check.matrix[0][1] = 2;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 2;
  int res = s21_sum_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_sum_matrix_test_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;
  matrix_t check;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  s21_create_matrix(2, 2, &check);
  matrix1.matrix[0][0] = -2;
  matrix1.matrix[0][1] = -2;
  matrix1.matrix[1][0] = -2;
  matrix1.matrix[1][1] = -2;

  matrix2.matrix[0][0] = 2;
  matrix2.matrix[0][1] = 2;
  matrix2.matrix[1][0] = 2;
  matrix2.matrix[1][1] = 2;

  check.matrix[0][0] = 0;
  check.matrix[0][1] = 0;
  check.matrix[1][0] = 0;
  check.matrix[1][1] = 0;
  int res = s21_sum_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_sum_matrix_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.columns = -100;
  ck_assert_int_eq(1, s21_sum_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(2, 3, &B);
  ck_assert_int_eq(2, s21_sum_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// Тесты для функции:
// int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
START_TEST(s21_sub_matrix_test_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;
  matrix_t check;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  s21_create_matrix(2, 2, &check);
  matrix1.matrix[0][0] = 4.1;
  matrix1.matrix[0][1] = 2.9;
  matrix1.matrix[1][0] = 3.3;
  matrix1.matrix[1][1] = 5.6;

  matrix2.matrix[0][0] = 2.1;
  matrix2.matrix[0][1] = 1.9;
  matrix2.matrix[1][0] = 3.3;
  matrix2.matrix[1][1] = 0.6;

  check.matrix[0][0] = 2.0;
  check.matrix[0][1] = 1.0;
  check.matrix[1][0] = 0;
  check.matrix[1][1] = 5.0;
  int res = s21_sub_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_sub_matrix_test_2) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;
  matrix_t check;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  s21_create_matrix(2, 2, &check);
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[1][0] = 2;
  matrix1.matrix[1][1] = 2;

  matrix2.matrix[0][0] = 2;
  matrix2.matrix[0][1] = 2;
  matrix2.matrix[1][0] = 2;
  matrix2.matrix[1][1] = 2;

  check.matrix[0][0] = 0;
  check.matrix[0][1] = 0;
  check.matrix[1][0] = 0;
  check.matrix[1][1] = 0;
  int res = s21_sub_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_sub_matrix_test_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;
  matrix_t check;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  s21_create_matrix(2, 2, &check);
  matrix1.matrix[0][0] = 10;
  matrix1.matrix[0][1] = 10;
  matrix1.matrix[1][0] = 10;
  matrix1.matrix[1][1] = 10;

  matrix2.matrix[0][0] = 5.123;
  matrix2.matrix[0][1] = 5.123;
  matrix2.matrix[1][0] = 5.123;
  matrix2.matrix[1][1] = 5.123;

  check.matrix[0][0] = 4.877;
  check.matrix[0][1] = 4.877;
  check.matrix[1][0] = 4.877;
  check.matrix[1][1] = 4.877;
  int res = s21_sub_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_sub_matrix_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(2, 3, &B);
  ck_assert_int_eq(2, s21_sub_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.columns = -100;
  ck_assert_int_eq(1, s21_sub_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// Тесты для функции:
// int s21_mult_number(matrix_t *A, double number, matrix_t *result);
START_TEST(s21_mult_number_test_1) {
  matrix_t A = {NULL, 0, 0};
  double number = 9.234;
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &check);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;

  check.matrix[0][0] = 9.234;
  check.matrix[0][1] = 9.234;
  check.matrix[1][0] = 9.234;
  check.matrix[1][1] = 9.234;

  int res = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_number_test_2) {
  matrix_t A = {NULL, 0, 0};
  double number = 5.3;
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &check);
  A.matrix[0][0] = 1.1;
  A.matrix[0][1] = -2.23;
  A.matrix[1][0] = 3.23;
  A.matrix[1][1] = 5.123;

  check.matrix[0][0] = 5.83;
  check.matrix[0][1] = -11.819;
  check.matrix[1][0] = 17.119;
  check.matrix[1][1] = 27.1519;

  int res = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_number_test_3) {
  matrix_t A = {NULL, 0, 0};
  double number = 123.1234;
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &check);
  A.matrix[0][0] = 12.345;

  check.matrix[0][0] = 1519.958373;

  int res = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_number_test_4) {
  matrix_t A = {NULL, 0, 0};
  double number = 123.1234;
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &check);
  A.columns = -100;
  ck_assert_int_eq(1, s21_mult_number(&A, number, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_number_test_5) {
  matrix_t A = {NULL, 0, 0};
  double number = -10;
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &check);
  A.matrix[0][0] = -12.3;
  A.matrix[0][1] = -2.23;
  A.matrix[1][0] = -1.3;
  A.matrix[1][1] = -12;

  check.matrix[0][0] = 123;
  check.matrix[0][1] = 22.3;
  check.matrix[1][0] = 13;
  check.matrix[1][1] = 120;

  int res = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(0, res);
  res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(1, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

// Тесты для функции:
// int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
START_TEST(s21_mult_matrix_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &check);

  A.matrix[0][0] = 3;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 5;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 4;

  check.matrix[0][0] = 11;
  check.matrix[0][1] = 25;
  check.matrix[1][0] = 16;
  check.matrix[1][1] = 38;

  ck_assert_int_eq(0, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(2, s21_mult_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_mult_matrix(&A, &B, &result));
}
END_TEST

START_TEST(s21_mult_matrix_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = -45.5;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 64.46;
  A.matrix[1][1] = 7.7;
  A.matrix[2][0] = 31.87;
  A.matrix[2][1] = -44.454;

  B.matrix[0][0] = 78.16;
  B.matrix[0][1] = -14.11;
  B.matrix[0][2] = 44.11;
  B.matrix[1][0] = 118.23;
  B.matrix[1][1] = 58.36;
  B.matrix[1][2] = 6.97;

  check.matrix[0][0] = -3556.28;
  check.matrix[0][1] = 642.005;
  check.matrix[0][2] = -2007.005;
  check.matrix[1][0] = 5948.5646;
  check.matrix[1][1] = -460.1586;
  check.matrix[1][2] = 2896.9996;
  check.matrix[2][0] = -2764.83722;
  check.matrix[2][1] = -3044.02114;
  check.matrix[2][2] = 1095.94132;

  ck_assert_int_eq(0, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 5.0;
  A.matrix[2][0] = 3.0;
  A.matrix[2][1] = 6.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = -1.0;
  B.matrix[0][2] = 1.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 3.0;
  B.matrix[1][2] = 4.0;

  check.matrix[0][0] = 9.0;
  check.matrix[0][1] = 11.0;
  check.matrix[0][2] = 17.0;
  check.matrix[1][0] = 12.0;
  check.matrix[1][1] = 13.0;
  check.matrix[1][2] = 22.0;
  check.matrix[2][0] = 15.0;
  check.matrix[2][1] = 15.0;
  check.matrix[2][2] = 27.0;

  ck_assert_int_eq(0, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &check);

  A.matrix[0][0] = 123.124;

  B.matrix[0][0] = 1.12;

  check.matrix[0][0] = 137.89888;

  ck_assert_int_eq(0, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &check);

  A.matrix[0][0] = 123;
  A.matrix[0][1] = 123;
  A.matrix[1][0] = 123;
  A.matrix[1][1] = 123;

  B.matrix[0][0] = 1.3;
  B.matrix[0][1] = 1.4;
  B.matrix[1][0] = 1.5;
  B.matrix[1][1] = -1.6;

  check.matrix[0][0] = 344.4;
  check.matrix[0][1] = -24.6;
  check.matrix[1][0] = 344.4;
  check.matrix[1][1] = -24.6;

  ck_assert_int_eq(0, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// Тесты для функции:
// int s21_transpose(matrix_t *A, matrix_t *result);
START_TEST(s21_transpose_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1.1;
  A.matrix[1][0] = -2.2;
  A.matrix[1][1] = 3.3;
  A.matrix[2][0] = 4.4;
  A.matrix[2][1] = -5.5;

  B.matrix[0][0] = 0;
  B.matrix[0][1] = -2.2;
  B.matrix[0][2] = 4.4;
  B.matrix[1][0] = 1.1;
  B.matrix[1][1] = 3.3;
  B.matrix[1][2] = -5.5;

  ck_assert_int_eq(0, s21_transpose(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1.1;
  A.matrix[1][0] = -2.2;
  A.matrix[1][1] = 3.3;
  A.matrix[2][0] = 4.4;
  A.matrix[2][1] = -5.5;

  B.matrix[0][0] = 0;
  B.matrix[0][1] = 1.1;
  B.matrix[0][2] = -2.2;
  B.matrix[1][0] = 3.3;
  B.matrix[1][1] = 4.4;
  B.matrix[1][2] = -5.5;

  ck_assert_int_eq(0, s21_transpose(&A, &result));
  ck_assert_int_eq(0, s21_eq_matrix(&result, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  A.columns = 0;
  ck_assert_int_eq(1, s21_transpose(&A, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(3, 1, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  B.matrix[0][0] = 1;
  B.matrix[1][0] = 2;
  B.matrix[2][0] = 3;

  ck_assert_int_eq(0, s21_transpose(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(3, 1, &B);

  A.matrix[0][0] = 123;
  A.matrix[0][1] = 12;
  A.matrix[0][2] = 5;

  B.matrix[0][0] = 123;
  B.matrix[1][0] = 12;
  B.matrix[2][0] = 5;

  ck_assert_int_eq(0, s21_transpose(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

// Тесты для функции:
// int s21_determinant(matrix_t *A, double *result);
START_TEST(s21_determinant_test_1) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  double my_res = 13;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 6;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 8;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = 0;
  ck_assert_int_eq(0, s21_determinant(&A, &result));
  ck_assert_int_eq(my_res, result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  double my_res = 9323182115255.62662111846136;
  s21_create_matrix(5, 5, &A);
  A.matrix[0][0] = -1.11;
  A.matrix[0][1] = 434.464;
  A.matrix[0][2] = -3611.4;
  A.matrix[0][3] = 99.3;
  A.matrix[0][4] = 8.7;
  A.matrix[1][0] = 2.89;
  A.matrix[1][1] = -63.23;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 87.11;
  A.matrix[1][4] = -12.8;
  A.matrix[2][0] = 994.6;
  A.matrix[2][1] = -134.15;
  A.matrix[2][2] = 58.461;
  A.matrix[2][3] = 115.466;
  A.matrix[2][4] = -161.21;
  A.matrix[3][0] = 251.1;
  A.matrix[3][1] = 356.14;
  A.matrix[3][2] = 365.44;
  A.matrix[3][3] = 34.411;
  A.matrix[3][4] = 124.416;
  A.matrix[4][0] = 15.2;
  A.matrix[4][1] = -31.8;
  A.matrix[4][2] = 8.1;
  A.matrix[4][3] = 611.61;
  A.matrix[4][4] = 0;
  ck_assert_int_eq(0, s21_determinant(&A, &result));
  ck_assert_int_eq(my_res, result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  s21_create_matrix(3, 5, &A);
  ck_assert_int_eq(2, s21_determinant(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_4) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  ck_assert_int_eq(1, s21_determinant(&A, &result));
}
END_TEST

START_TEST(s21_determinant_test_5) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  double my_res = -2;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(0, s21_determinant(&A, &result));
  ck_assert_int_eq(my_res, result);
  s21_remove_matrix(&A);
}
END_TEST

// Тесты для функции:
// int s21_calc_complements(matrix_t *A, matrix_t *result);
START_TEST(s21_calc_complements_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &R);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  R.matrix[0][0] = 4;
  R.matrix[0][1] = -3;
  R.matrix[1][0] = -2;
  R.matrix[1][1] = 1;

  ck_assert_int_eq(0, s21_calc_complements(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  R.matrix[0][0] = 0;
  R.matrix[0][1] = 10;
  R.matrix[0][2] = -20;
  R.matrix[1][0] = 4;
  R.matrix[1][1] = -14;
  R.matrix[1][2] = 8;
  R.matrix[2][0] = -8;
  R.matrix[2][1] = -2;
  R.matrix[2][2] = 4;

  ck_assert_int_eq(0, s21_calc_complements(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R);
  A.matrix[0][0] = 37.33;
  A.matrix[0][1] = -4;
  A.matrix[0][2] = -373.4;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3673.4;
  A.matrix[1][2] = -637.4;
  A.matrix[2][0] = 89.8;
  A.matrix[2][1] = -6737.5;
  A.matrix[2][2] = 0;

  R.matrix[0][0] = -4294482.5;
  R.matrix[0][1] = -57238.52;
  R.matrix[0][2] = -329871.32;
  R.matrix[1][0] = 2515782.5;
  R.matrix[1][1] = 33531.32;
  R.matrix[1][2] = 251151.675;
  R.matrix[2][0] = 1374197.16;
  R.matrix[2][1] = 23794.142;
  R.matrix[2][2] = 137128.022;

  ck_assert_int_eq(0, s21_calc_complements(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 5, &A);
  ck_assert_int_eq(2, s21_calc_complements(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_calc_complements(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_6) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_calc_complements(NULL, &result));
}
END_TEST

START_TEST(s21_calc_complements_test_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  R.matrix[0][0] = -3;
  R.matrix[0][1] = 6;
  R.matrix[0][2] = -3;
  R.matrix[1][0] = 6;
  R.matrix[1][1] = -12;
  R.matrix[1][2] = 6;
  R.matrix[2][0] = -3;
  R.matrix[2][1] = 6;
  R.matrix[2][2] = -3;

  ck_assert_int_eq(0, s21_calc_complements(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

// Тесты для функции:
// int s21_inverse_matrix(matrix_t *A, matrix_t *result);
START_TEST(s21_inverse_matrix_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  R.matrix[0][0] = 1;
  R.matrix[0][1] = -1;
  R.matrix[0][2] = 1;
  R.matrix[1][0] = -38;
  R.matrix[1][1] = 41;
  R.matrix[1][2] = -34;
  R.matrix[2][0] = 27;
  R.matrix[2][1] = -29;
  R.matrix[2][2] = 24;

  ck_assert_int_eq(0, s21_inverse_matrix(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R);
  A.matrix[0][0] = -34, 435;
  A.matrix[0][1] = 95, 45;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 6, 54;
  A.matrix[1][1] = 8, 6;
  A.matrix[1][2] = 9.45;
  A.matrix[2][0] = -78, 4;
  A.matrix[2][1] = 35, 4;
  A.matrix[2][2] = 342, 55;

  R.matrix[0][0] = -0.0069366937;
  R.matrix[0][1] = 0.0937005217;
  R.matrix[0][2] = -0.0025890934;
  R.matrix[1][0] = 0.0080437096;
  R.matrix[1][1] = 0.0335349236;
  R.matrix[1][2] = -0.0009266229;
  R.matrix[2][0] = -0.0024052396;
  R.matrix[2][1] = 0.0179383578;
  R.matrix[2][2] = 0.0024283115;

  ck_assert_int_eq(0, s21_inverse_matrix(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(2, s21_inverse_matrix(&A, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 5, &A);
  ck_assert_int_eq(2, s21_inverse_matrix(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_inverse_matrix(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_6) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_inverse_matrix(NULL, &result));
}
END_TEST

START_TEST(s21_inverse_matrix_test_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &R);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  R.matrix[0][0] = -2;
  R.matrix[0][1] = 1;
  R.matrix[1][0] = 1.5;
  R.matrix[1][1] = -0.5;

  ck_assert_int_eq(0, s21_inverse_matrix(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

// Набор тестов для функции:
// int s21_create_matrix(int rows, int columns, matrix_t *result);
Suite *s21_create_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("1) s21_create_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_create_matrix_test_1);
  tcase_add_test(test_core, s21_create_matrix_test_2);
  tcase_add_test(test_core, s21_create_matrix_test_3);
  tcase_add_test(test_core, s21_create_matrix_test_4);
  tcase_add_test(test_core, s21_create_matrix_test_5);
  tcase_add_test(test_core, s21_create_matrix_test_6);
  tcase_add_test(test_core, s21_create_matrix_test_7);
  tcase_add_test(test_core, s21_create_matrix_test_8);
  tcase_add_test(test_core, s21_create_matrix_test_9);
  tcase_add_test(test_core, s21_create_matrix_test_10);
  tcase_add_test(test_core, s21_create_matrix_test_11);
  tcase_add_test(test_core, s21_create_matrix_test_12);
  tcase_add_test(test_core, s21_create_matrix_test_13);
  tcase_add_test(test_core, s21_create_matrix_test_14);
  tcase_add_test(test_core, s21_create_matrix_test_15);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции:
// void s21_remove_matrix(matrix_t *A);
Suite *s21_remove_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("2) s21_remove_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_remove_matrix_test_1);
  tcase_add_test(test_core, s21_remove_matrix_test_2);
  tcase_add_test(test_core, s21_remove_matrix_test_3);
  tcase_add_test(test_core, s21_remove_matrix_test_4);
  tcase_add_test(test_core, s21_remove_matrix_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции:
// int s21_eq_matrix(matrix_t *A, matrix_t *B);
Suite *s21_eq_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("3) s21_eq_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_eq_matrix_test_1);
  tcase_add_test(test_core, s21_eq_matrix_test_2);
  tcase_add_test(test_core, s21_eq_matrix_test_3);
  tcase_add_test(test_core, s21_eq_matrix_test_4);
  tcase_add_test(test_core, s21_eq_matrix_test_5);
  tcase_add_test(test_core, s21_eq_matrix_test_6);
  tcase_add_test(test_core, s21_eq_matrix_test_7);
  tcase_add_test(test_core, s21_eq_matrix_test_8);
  tcase_add_test(test_core, s21_eq_matrix_test_9);
  tcase_add_test(test_core, s21_eq_matrix_test_10);
  tcase_add_test(test_core, s21_eq_matrix_test_11);
  tcase_add_test(test_core, s21_eq_matrix_test_12);
  tcase_add_test(test_core, s21_eq_matrix_test_13);
  tcase_add_test(test_core, s21_eq_matrix_test_14);
  tcase_add_test(test_core, s21_eq_matrix_test_15);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции:
// int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
Suite *s21_sum_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("4) s21_sum_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_sum_matrix_test_1);
  tcase_add_test(test_core, s21_sum_matrix_test_2);
  tcase_add_test(test_core, s21_sum_matrix_test_3);
  tcase_add_test(test_core, s21_sum_matrix_test_4);
  tcase_add_test(test_core, s21_sum_matrix_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции:
// int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
Suite *s21_sub_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("5) s21_sub_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_sub_matrix_test_1);
  tcase_add_test(test_core, s21_sub_matrix_test_2);
  tcase_add_test(test_core, s21_sub_matrix_test_3);
  tcase_add_test(test_core, s21_sub_matrix_test_4);
  tcase_add_test(test_core, s21_sub_matrix_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции:
// int s21_mult_number(matrix_t *A, double number, matrix_t *result);
Suite *s21_mult_number_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("6) s21_mult_number");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_mult_number_test_1);
  tcase_add_test(test_core, s21_mult_number_test_2);
  tcase_add_test(test_core, s21_mult_number_test_3);
  tcase_add_test(test_core, s21_mult_number_test_4);
  tcase_add_test(test_core, s21_mult_number_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции:
// int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
Suite *s21_mult_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("7) s21_mult_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_mult_matrix_test_1);
  tcase_add_test(test_core, s21_mult_matrix_test_2);
  tcase_add_test(test_core, s21_mult_matrix_test_3);
  tcase_add_test(test_core, s21_mult_matrix_test_4);
  tcase_add_test(test_core, s21_mult_matrix_test_5);
  tcase_add_test(test_core, s21_mult_matrix_test_6);
  tcase_add_test(test_core, s21_mult_matrix_test_7);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции:
// int s21_transpose(matrix_t *A, matrix_t *result);
Suite *s21_transpose_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("8) s21_transpose");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_transpose_test_1);
  tcase_add_test(test_core, s21_transpose_test_2);
  tcase_add_test(test_core, s21_transpose_test_3);
  tcase_add_test(test_core, s21_transpose_test_4);
  tcase_add_test(test_core, s21_transpose_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции:
// int s21_determinant(matrix_t *A, double *result);
Suite *s21_determinant_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("9) s21_determinant");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_determinant_test_1);
  tcase_add_test(test_core, s21_determinant_test_2);
  tcase_add_test(test_core, s21_determinant_test_3);
  tcase_add_test(test_core, s21_determinant_test_4);
  tcase_add_test(test_core, s21_determinant_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции:
// int s21_calc_complements(matrix_t *A, matrix_t *result);
Suite *s21_calc_complements_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("10) s21_calc_complements");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_calc_complements_test_1);
  tcase_add_test(test_core, s21_calc_complements_test_2);
  tcase_add_test(test_core, s21_calc_complements_test_3);
  tcase_add_test(test_core, s21_calc_complements_test_4);
  tcase_add_test(test_core, s21_calc_complements_test_5);
  tcase_add_test(test_core, s21_calc_complements_test_6);
  tcase_add_test(test_core, s21_calc_complements_test_7);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции:
// int s21_inverse_matrix(matrix_t *A, matrix_t *result);
Suite *s21_inverse_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("11) s21_inverse_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_inverse_matrix_test_1);
  tcase_add_test(test_core, s21_inverse_matrix_test_2);
  tcase_add_test(test_core, s21_inverse_matrix_test_3);
  tcase_add_test(test_core, s21_inverse_matrix_test_4);
  tcase_add_test(test_core, s21_inverse_matrix_test_5);
  tcase_add_test(test_core, s21_inverse_matrix_test_6);
  tcase_add_test(test_core, s21_inverse_matrix_test_7);
  suite_add_tcase(selection, test_core);
  return selection;
}

void case_tests(Suite *selection, int *fail) {
  SRunner *runner = srunner_create(selection);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int fail = 0;
  case_tests(s21_create_matrix_suite(), &fail);
  case_tests(s21_remove_matrix_suite(), &fail);
  case_tests(s21_eq_matrix_suite(), &fail);
  case_tests(s21_sum_matrix_suite(), &fail);
  case_tests(s21_sub_matrix_suite(), &fail);
  case_tests(s21_mult_number_suite(), &fail);
  case_tests(s21_mult_matrix_suite(), &fail);
  case_tests(s21_transpose_suite(), &fail);
  case_tests(s21_determinant_suite(), &fail);
  case_tests(s21_calc_complements_suite(), &fail);
  case_tests(s21_inverse_matrix_suite(), &fail);
  return 0;
}