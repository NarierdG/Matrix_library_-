#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (checking_null(result) || checking_size(rows, columns)) {
    return INCORRECT_MATRIX;
  }

  int res_code = OK;

  result->matrix = (double **)calloc(
      rows, sizeof(double *));  // Выделяем память под указатели на строки

  for (int pointer = 0; pointer < rows; pointer++) {
    result->matrix[pointer] =
        (double *)calloc(columns, sizeof(double));  // Создаем строки
  }

  result->columns = columns;
  result->rows = rows;

  return res_code;
}