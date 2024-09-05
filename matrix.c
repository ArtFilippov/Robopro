#include "matrix.h"

#include <stdio.h>

struct Matrix to_matrix(double *matrix, int n)
{
    struct Matrix new_matrix = {.n = n};
    for (int i = 0; i < n; ++i)
    {
        new_matrix.data[i] = matrix + i * n;
    }

    return new_matrix;
}

struct Matrix submatrix(const struct Matrix matrix, int *rows, int n)
{
    struct Matrix new_matrix = {.n = n};
    for (int i = 0; i < n; ++i)
    {
        new_matrix.data[i] = matrix.data[rows[i]] + matrix.n - n;
    }

    return new_matrix;
}

double det(const struct Matrix matrix)
{
    if (matrix.n == 1) {
        return matrix.data[0][0];
    }

    int coeff = 1;
    double result = 0;

    for (int i = 0; i < matrix.n; ++i) {
        int *rows = (int *) malloc(sizeof(int) * (matrix.n - 1));
        if (!rows) {
            fprintf(stderr, "bed alloc\n");
            exit(1);
        }

        for (int j = 0; j < matrix.n; ++j) {
            if (i > j) {
                rows[j] = j;
            } else if (i < j) {
                rows[j - 1] = j;
            }
        }

        struct Matrix subm = submatrix(matrix, rows, matrix.n - 1);
        free(rows);

        result += coeff * matrix.data[0][i] * det(subm);
        coeff *= -1;
    }
}