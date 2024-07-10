#include "s21_matrix.h"

int checking_size(int rows, int columns) { return rows <= 0 || columns <= 0; }

int checking_null(matrix_t *A) { return A == NULL; }

int checking_equality(matrix_t *A, matrix_t *B) {
  return A->rows != B->rows || A->columns != B->columns;
}