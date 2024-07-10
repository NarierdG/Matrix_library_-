#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res_code = OK;

  if (A->rows <= 0 || A->columns <= 0 || result == NULL) {
    res_code = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    res_code = CALCULATION_ERROR;
  } else {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      *result = (A->matrix[0][0] * A->matrix[1][1]) -
                (A->matrix[0][1] * A->matrix[1][0]);
    } else {
      *result = 0;
      for (int j = 0; j < A->rows; j++) {
        matrix_t minor;
        if (s21_create_matrix(A->rows - 1, A->columns - 1, &minor) == OK) {
          for (int i = 1; i < A->rows; i++) {
            for (int k = 0; k < j; k++) {
              minor.matrix[i - 1][k] = A->matrix[i][k];
            }
            for (int k = j + 1; k < A->columns; k++) {
              minor.matrix[i - 1][k - 1] = A->matrix[i][k];
            }
          }
          double minor_det;
          s21_determinant(&minor, &minor_det);
          *result += A->matrix[0][j] * pow(-1, j) * minor_det;
          s21_remove_matrix(&minor);
        }
      }
    }
  }

  return res_code;
}