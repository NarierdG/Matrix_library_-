#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code = OK;

  if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0) {
    res_code = INCORRECT_MATRIX;

  } else if (A->columns != B->rows) {
    res_code = CALCULATION_ERROR;

  } else {
    s21_create_matrix(A->rows, B->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int y = 0; y < B->columns; y++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][y] += A->matrix[i][k] * B->matrix[k][y];
        }
      }
    }
  }

  return res_code;
}