#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code = OK;

  if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0) {
    res_code = INCORRECT_MATRIX;

  } else if (A->rows != B->rows || A->columns != B->columns) {
    res_code = CALCULATION_ERROR;

  } else {
    s21_create_matrix(A->rows, B->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int y = 0; y < A->columns; y++) {
        result->matrix[i][y] = A->matrix[i][y] + B->matrix[i][y];
      }
    }
  }

  return res_code;
}