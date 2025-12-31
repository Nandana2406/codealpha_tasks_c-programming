#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void add_matrices(int A[][MAX_COLS], int B[][MAX_COLS], int C[][MAX_COLS], int rows, int cols);
void multiply_matrices(int A[][MAX_COLS], int B[][MAX_COLS], int C[][MAX_COLS], int r1, int c1, int c2);
void transpose_matrix(int A[][MAX_COLS], int B[][MAX_COLS], int rows, int cols);
void print_matrix(int matrix[][MAX_COLS], int rows, int cols);

int main() {
    int A[MAX_ROWS][MAX_COLS] = {{1, 2}, {3, 4}};
    int B[MAX_ROWS][MAX_COLS] = {{5, 6}, {7, 8}};
    int C[MAX_ROWS][MAX_COLS];
    int rows_A = 2, cols_A = 2;
    int rows_B = 2, cols_B = 2;

    if (rows_A == rows_B && cols_A == cols_B) {
        printf("Matrix A:\n");
        print_matrix(A, rows_A, cols_A);
        printf("Matrix B:\n");
        print_matrix(B, rows_B, cols_B);
        add_matrices(A, B, C, rows_A, cols_A);
        printf("Result of Matrix Addition (A + B):\n");
        print_matrix(C, rows_A, cols_A);
    } else {
        printf("Addition not possible. Dimensions must be the same.\n");
    }

    printf("\n--------------------------\n\n");

    if (cols_A == rows_B) {
        printf("Matrix A:\n");
        print_matrix(A, rows_A, cols_A);
        printf("Matrix B:\n");
        print_matrix(B, rows_B, cols_B);
        multiply_matrices(A, B, C, rows_A, cols_A, cols_B);
        printf("Result of Matrix Multiplication (A * B):\n");
        print_matrix(C, rows_A, cols_B);
    } else {
        printf("Multiplication not possible. Number of columns in A must equal number of rows in B.\n");
    }

    printf("\n--------------------------\n\n");

    printf("Original Matrix A:\n");
    print_matrix(A, rows_A, cols_A);
    transpose_matrix(A, C, rows_A, cols_A);
    printf("Result of Matrix Transpose of A:\n");
    print_matrix(C, cols_A, rows_A);

    return 0;
}
void add_matrices(int A[][MAX_COLS], int B[][MAX_COLS], int C[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void multiply_matrices(int A[][MAX_COLS], int B[][MAX_COLS], int C[][MAX_COLS], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void transpose_matrix(int A[][MAX_COLS], int B[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            B[j][i] = A[i][j];
        }
    }
}

void print_matrix(int matrix[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

