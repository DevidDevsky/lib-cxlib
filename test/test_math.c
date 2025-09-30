#include <stdio.h>
#include "cmathx.h"

int main(void) {
    printf("=== CXLib: Matrix Tests ===\n\n");

    // --- Шаг 1: Создание матриц A и B ---
    printf("Step 1: Creating matrices A and B\n");
    matrix_t *A = matrix_create(3, 3);
    matrix_t *B = matrix_create(3, 3);

    // Заполняем матрицу A
    A->data[0][0] = 1; A->data[0][1] = 2; A->data[0][2] = 3;
    A->data[1][0] = 0; A->data[1][1] = 1; A->data[1][2] = 4;
    A->data[2][0] = 5; A->data[2][1] = 6; A->data[2][2] = 0;

    // Заполняем матрицу B
    B->data[0][0] = 7; B->data[0][1] = 8; B->data[0][2] = 9;
    B->data[1][0] = 1; B->data[1][1] = 0; B->data[1][2] = 2;
    B->data[2][0] = 3; B->data[2][1] = 4; B->data[2][2] = 5;

    printf("Matrix A:\n");
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->cols; j++)
            printf("%5.1f ", A->data[i][j]);
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < B->rows; i++) {
        for (int j = 0; j < B->cols; j++)
            printf("%5.1f ", B->data[i][j]);
        printf("\n");
    }

    // --- Шаг 2: Сложение ---
    printf("\nStep 2: A + B\n");
    matrix_t *C = matrix_add(A, B);
    for (int i = 0; i < C->rows; i++) {
        for (int j = 0; j < C->cols; j++)
            printf("%5.1f ", C->data[i][j]);
        printf("\n");
    }

    // --- Шаг 3: Вычитание ---
    printf("\nStep 3: A - B\n");
    matrix_t *D = matrix_sub(A, B);
    for (int i = 0; i < D->rows; i++) {
        for (int j = 0; j < D->cols; j++)
            printf("%5.1f ", D->data[i][j]);
        printf("\n");
    }

    // --- Шаг 4: Умножение на число ---
    printf("\nStep 4: A * 2\n");
    matrix_t *E = matrix_mul_scalar(A, 2.0);
    for (int i = 0; i < E->rows; i++) {
        for (int j = 0; j < E->cols; j++)
            printf("%5.1f ", E->data[i][j]);
        printf("\n");
    }

    // --- Шаг 5: Умножение матриц ---
    printf("\nStep 5: A * B\n");
    matrix_t *F = matrix_mul(A, B);
    for (int i = 0; i < F->rows; i++) {
        for (int j = 0; j < F->cols; j++)
            printf("%5.1f ", F->data[i][j]);
        printf("\n");
    }

    // --- Шаг 6: Транспонирование ---
    printf("\nStep 6: Transpose(A)\n");
    matrix_t *G = matrix_transpose(A);
    for (int i = 0; i < G->rows; i++) {
        for (int j = 0; j < G->cols; j++)
            printf("%5.1f ", G->data[i][j]);
        printf("\n");
    }

    // --- Шаг 7: Определитель ---
    printf("\nStep 7: Determinant\n");
    double detA = matrix_determinant(A);
    double detB = matrix_determinant(B);
    printf("Determinant(A) = %.2f\n", detA);
    printf("Determinant(B) = %.2f\n", detB);

    // --- Шаг 8: Ранг ---
    printf("\nStep 8: Rank\n");
    int rankA = matrix_rank(A);
    int rankB = matrix_rank(B);
    printf("Rank(A) = %d\n", rankA);
    printf("Rank(B) = %d\n", rankB);

    // --- Шаг 9: Тест итеративного детерминанта на 5x5 ---
    printf("\nStep 9: Determinant of larger 5x5 matrix\n");
    matrix_t *H = matrix_create(5, 5);
    int val = 1;
    for (int i = 0; i < H->rows; i++)
        for (int j = 0; j < H->cols; j++)
            H->data[i][j] = val++; // заполняем числами от 1 до 25

    printf("Matrix H:\n");
    for (int i = 0; i < H->rows; i++) {
        for (int j = 0; j < H->cols; j++)
            printf("%5.1f ", H->data[i][j]);
        printf("\n");
    }

    double detH = matrix_determinant(H);
    printf("Determinant(H) = %.2f\n", detH);

    // --- Очистка памяти ---
    matrix_free(A);
    matrix_free(B);
    matrix_free(C);
    matrix_free(D);
    matrix_free(E);
    matrix_free(F);
    matrix_free(G);
    matrix_free(H);

    printf("\n✅ All matrix tests completed.\n");
    return 0;
}