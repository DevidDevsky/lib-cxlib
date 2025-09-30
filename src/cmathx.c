// src/cmathx.c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "cmathx.h"

// Факториал через рекурсию
long long factorial(int n) {
    if (n < 0) return -1; // ошибка
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// Проверка простоты числа
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// ======== Работа с матрицами ========

// Создание матрицы
matrix_t* matrix_create(int rows, int cols) {
    matrix_t *m = malloc(sizeof(matrix_t));
    m->rows = rows;
    m->cols = cols;

    m->data = malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        m->data[i] = calloc(cols, sizeof(double));
    }

    return m;
}

// Освобождение памяти
void matrix_free(matrix_t *m) {
    if (!m) return;
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

// Сложение матриц
matrix_t* matrix_add(matrix_t *a, matrix_t *b) {
    if (a->rows != b->rows || a->cols != b->cols) return NULL;

    matrix_t *res = matrix_create(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            res->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return res;
}

// Вычитание матриц
matrix_t* matrix_sub(matrix_t *a, matrix_t *b) {
    if (!a || !b || a->rows != b->rows || a->cols != b->cols) return NULL;

    matrix_t *res = matrix_create(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            res->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return res;
}

// Умножение матрицы на число
matrix_t* matrix_mul_scalar(matrix_t *a, double k) {
    if (!a) return NULL;

    matrix_t *res = matrix_create(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            res->data[i][j] = a->data[i][j] * k;
        }
    }
    return res;
}

// Умножение матрицы на матрицу
matrix_t* matrix_mul(matrix_t *a, matrix_t *b) {
    if (!a || !b) return NULL;
    if (a->cols != b->rows) return NULL; // условие умножения

    matrix_t *res = matrix_create(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            double sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            res->data[i][j] = sum;
        }
    }
    return res;
}

// Транспонирование матрицы
matrix_t* matrix_transpose(matrix_t *a) {
    if (!a) return NULL;

    matrix_t *res = matrix_create(a->cols, a->rows);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            res->data[j][i] = a->data[i][j];
        }
    }
    return res;
}

// Вспомогательная функция для получения минора
static matrix_t* matrix_minor(matrix_t *m, int row, int col) {
    matrix_t *res = matrix_create(m->rows - 1, m->cols - 1);
    int r = 0, c = 0;
    for (int i = 0; i < m->rows; i++) {
        if (i == row) continue;
        c = 0;
        for (int j = 0; j < m->cols; j++) {
            if (j == col) continue;
            res->data[r][c] = m->data[i][j];
            c++;
        }
        r++;
    }
    return res;
}

double matrix_determinant(matrix_t *m) {
    if (!m || m->rows != m->cols) return 0; // только квадратные матрицы

    int n = m->rows;
    // Создаем временную копию матрицы
    matrix_t *temp = matrix_create(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp->data[i][j] = m->data[i][j];

    double det = 1;
    for (int i = 0; i < n; i++) {
        // Находим ненулевой элемент в текущем столбце
        int pivot = i;
        while (pivot < n && temp->data[pivot][i] == 0) pivot++;
        if (pivot == n) { det = 0; break; } // столбец полностью нулевой => det=0

        // Если нужно, меняем строки местами
        if (pivot != i) {
            for (int j = 0; j < n; j++) {
                double t = temp->data[i][j];
                temp->data[i][j] = temp->data[pivot][j];
                temp->data[pivot][j] = t;
            }
            det *= -1; // смена строк меняет знак детерминанта
        }

        det *= temp->data[i][i];

        // Обнуляем элементы под диагональю
        for (int j = i + 1; j < n; j++) {
            double factor = temp->data[j][i] / temp->data[i][i];
            for (int k = i; k < n; k++) {
                temp->data[j][k] -= factor * temp->data[i][k];
            }
        }
    }

    matrix_free(temp);
    return det;
}

int matrix_rank(matrix_t *m) {
    if (!m) return 0;

    matrix_t *temp = matrix_create(m->rows, m->cols);
    // копируем данные
    for (int i = 0; i < m->rows; i++)
        for (int j = 0; j < m->cols; j++)
            temp->data[i][j] = m->data[i][j];

    int rank = temp->cols;
    for (int row = 0; row < rank; row++) {
        if (temp->data[row][row] != 0) {
            for (int i = row + 1; i < temp->rows; i++) {
                double factor = temp->data[i][row] / temp->data[row][row];
                for (int j = 0; j < rank; j++)
                    temp->data[i][j] -= factor * temp->data[row][j];
            }
        } else {
            int reduce = 1;
            for (int i = row + 1; i < temp->rows; i++) {
                if (temp->data[i][row] != 0) {
                    for (int j = 0; j < temp->cols; j++) {
                        double t = temp->data[row][j];
                        temp->data[row][j] = temp->data[i][j];
                        temp->data[i][j] = t;
                    }
                    reduce = 0;
                    break;
                }
            }
            if (reduce) {
                rank--;
                for (int i = 0; i < temp->rows; i++)
                    temp->data[i][row] = temp->data[i][rank];
            }
            row--;
        }
    }

    matrix_free(temp);
    return rank;
}