#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res_code = OK;

  if (A->rows <= 0 || A->columns <= 0) {
    res_code = INCORRECT_MATRIX;
  } else {
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int y = 0; y < A->columns; y++) {
        result->matrix[i][y] = A->matrix[i][y] * number;
      }
    }
  }

  return res_code;
}