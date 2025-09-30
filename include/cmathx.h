#ifndef CMATHX_H
#define CMATHX_H

#include <stdbool.h>

// === Базовые функции ===
long long factorial(int n);     // Факториал
bool is_prime(int n);           // Проверка на простое число

// === Матрицы ===
typedef struct {
    int rows;
    int cols;
    double **data;
} matrix_t;

// Создание и освобождение
matrix_t* matrix_create(int rows, int cols);
void matrix_free(matrix_t *m);

// Операции с матрицами
matrix_t* matrix_add(matrix_t *a, matrix_t *b);
matrix_t* matrix_sub(matrix_t *a, matrix_t *b);
matrix_t* matrix_mul_scalar(matrix_t *a, double k);
matrix_t* matrix_mul(matrix_t *a, matrix_t *b);
matrix_t* matrix_transpose(matrix_t *a);

// (план на будущее)
double matrix_determinant(matrix_t *a); // Определитель
int matrix_rank(matrix_t *a);           // Ранг

#endif // CMATHX_H