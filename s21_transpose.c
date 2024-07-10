#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res_code = OK;

  if (A->rows <= 0 || A->columns <= 0) {
    res_code = INCORRECT_MATRIX;

  } else {
    s21_create_matrix(A->columns, A->rows, result);

    for (int i = 0; i < A->rows; i++) {
      for (int y = 0; y < A->columns; y++) {
        result->matrix[y][i] = A->matrix[i][y];
      }
    }
  }

  return res_code;
}