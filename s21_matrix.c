#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int my_res = 0;
  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          my_res = 1;
          for (int j = 0; j < i; j++) {
            free(result->matrix[i]);
          }
          free(result->matrix);
        }
      }
    } else {
      my_res = 1;
    }
  } else {
    my_res = 1;
  }
  return my_res;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->rows = 0;
    A->columns = 0;
    A->matrix = NULL;
  }
}

int is_true_matrix(matrix_t *A) {
  int my_res = 1;
  if (A == NULL) {
    my_res = 0;
  } else if (A->matrix == NULL) {
    my_res = 0;
  } else if (A->rows <= 0 || A->columns <= 0) {
    my_res = 0;
  }
  return my_res;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int my_res = SUCCESS;
  if (is_true_matrix(A) && is_true_matrix(B)) {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) {
            my_res = FAILURE;
          }
        }
      }
    } else {
      my_res = FAILURE;
    }
  } else {
    my_res = FAILURE;
  }
  return my_res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int my_res = 0;
  if (is_true_matrix(A) && is_true_matrix(B)) {
    if (A->rows == B->rows && A->columns == B->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    } else {
      my_res = 2;
    }
  } else {
    my_res = 1;
  }
  return my_res;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int my_res = 0;
  if (is_true_matrix(A) && is_true_matrix(B)) {
    if (A->rows == B->rows && A->columns == B->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    } else {
      my_res = 2;
    }
  } else {
    my_res = 1;
  }
  return my_res;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int my_res = 0;
  if (is_true_matrix(A)) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  } else {
    my_res = 1;
  }
  return my_res;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int my_res = 0;
  if (is_true_matrix(A) && is_true_matrix(B)) {
    if (A->columns == B->rows) {
      s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = 0;
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      my_res = 2;
    }
  } else {
    my_res = 1;
  }
  return my_res;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int my_res = 0;
  if (is_true_matrix(A)) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  } else {
    my_res = 1;
  }
  return my_res;
}

int is_square_matrix(matrix_t *A) {
  int my_res = 1;
  if (is_true_matrix(A) != 1 || A->rows != A->columns) {
    my_res = 0;
  }
  return my_res;
}

int minor_matrix(matrix_t *A, int x, int y, matrix_t *minor) {
  int my_res = 0;
  if (A->rows > 1 && A->columns > 1 && x < A->rows && y < A->columns) {
    s21_create_matrix(A->rows - 1, A->columns - 1, minor);
    int minorI = 0;
    for (int i = 0; i < A->rows; i++) {
      if (i == x) {
        minorI = 1;
      } else {
        int minorJ = 0;
        for (int j = 0; j < A->columns; j++) {
          if (j == y) {
            minorJ = 1;
          } else {
            minor->matrix[i - minorI][j - minorJ] = A->matrix[i][j];
          }
        }
      }
    }
  } else {
    my_res = 2;
  }
  return my_res;
}

double calc_determinant(matrix_t *A) {
  double my_res = 0;
  if (A->rows == 1) {
    my_res = A->matrix[0][0];
  } else {
    for (int i = 0; i < A->rows; i++) {
      matrix_t minor = {NULL, 0, 0};
      minor_matrix(A, 0, i, &minor);
      my_res += A->matrix[0][i] * calc_determinant(&minor) * (i % 2 ? -1 : 1);
      s21_remove_matrix(&minor);
    }
  }
  return my_res;
}

int s21_determinant(matrix_t *A, double *result) {
  int my_res = 0;
  if (is_true_matrix(A)) {
    if (is_square_matrix(A)) {
      *result = calc_determinant(A);
    } else {
      my_res = 2;
    }
  } else {
    my_res = 1;
  }
  return my_res;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int my_res = 0;
  if (is_true_matrix(A) && result != NULL) {
    if (is_square_matrix(A)) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t minor = {NULL, 0, 0};
          minor_matrix(A, i, j, &minor);
          result->matrix[i][j] =
              calc_determinant(&minor) * ((i + j) % 2 == 0 ? 1 : -1);
          s21_remove_matrix(&minor);
        }
      }
    } else {
      my_res = 2;
    }
  } else {
    my_res = 1;
  }
  return my_res;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int my_res = 0;
  if (is_true_matrix(A) && result != NULL) {
    if (is_square_matrix(A)) {
      double determinant = 0;
      s21_determinant(A, &determinant);
      if (determinant != 0) {
        matrix_t matrix_calc = {NULL, 0, 0};
        matrix_t matrix_transpose = {NULL, 0, 0};
        s21_calc_complements(A, &matrix_calc);
        s21_transpose(&matrix_calc, &matrix_transpose);
        s21_mult_number(&matrix_transpose, 1 / determinant, result);
        s21_remove_matrix(&matrix_calc);
        s21_remove_matrix(&matrix_transpose);
      } else {
        my_res = 2;
      }
    } else {
      my_res = 2;
    }
  } else {
    my_res = 1;
  }
  return my_res;
}