#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res_code = OK;

  if (A->rows <= 0 || A->columns <= 0) {
    res_code = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    res_code = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);

    if (A->rows == 1) {
      result->matrix[0][0] = 1.;
    } else {
      for (int i = 0; i < A->rows && A->rows > 1; i++) {
        for (int y = 0; y < A->columns && A->columns > 1; y++) {
          matrix_t minor;
          s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
          int minor_i = 0;
          for (int k = 0; k < A->rows; k++) {
            if (k != i) {
              int minor_j = 0;
              for (int l = 0; l < A->columns; l++) {
                if (l != y) {
                  minor.matrix[minor_i][minor_j] = A->matrix[k][l];
                  minor_j++;
                }
              }
              minor_i++;
            }
          }
          double det;
          s21_determinant(&minor, &det);
          result->matrix[i][y] = det * pow(-1, i + y);
          s21_remove_matrix(&minor);
        }
        if (res_code != OK) {
          break;
        }
      }
    }
  }

  return res_code;
}