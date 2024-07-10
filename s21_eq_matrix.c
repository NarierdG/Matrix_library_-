#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0 ||
      checking_equality(A, B)) {
    return FAILURE;
  }

  int res_code = SUCCESS;

  for (int i = 0; i < A->rows; i++) {
    for (int y = 0; y < A->columns; y++) {
      if (fabs(A->matrix[i][y] - B->matrix[i][y]) >
          1e-7) {  // Проверяю на различие в шести знаках после запятой
        res_code = FAILURE;
        i = A->rows;
        y = A->columns;
      }
    }
  }

  return res_code;
}