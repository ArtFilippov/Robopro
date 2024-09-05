#include "matrix.h"

struct Matrix to_matrix(double *matrix, int n)
{
    struct Matrix new_matrix = {.n = n};
    for (int i = 0; i < n; ++i) {
        new_matrix.data[i] = matrix + i * n;
    }

    return new_matrix;
}

struct Matrix submatrix(struct Matrix matrix, int *rows, int n)
{
    struct Matrix new_matrix = {.n = n};
    for (int i = 0; i < n; ++i) {
        new_matrix.data[i] = matrix.data[rows[i]] + matrix.n - n;
    }
}