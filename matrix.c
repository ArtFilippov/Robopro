#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

void to_matrix(struct Matrix *new_matrix, double *matrix)
{
    for (int i = 0; i < new_matrix->n; ++i)
    {
        new_matrix->data[i] = matrix + i * new_matrix->n;
    }
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

void print(struct Matrix matrix)
{
    for (int i = 0; i < matrix.n; ++i) {
        for (int j = 0; j < matrix.n; ++j) {
            printf("%lf ", matrix.data[i][j]);
        }
        printf("\n");
    }
}

double det(const struct Matrix matrix)
{
    if (matrix.n == 1)
    {
        return matrix.data[0][0];
    }

    int coeff = 1;
    double result = 0;

    for (int i = 0; i < matrix.n; ++i)
    {
        int *rows = (int *)malloc(sizeof(int) * (matrix.n - 1));
        if (!rows)
        {
            fprintf(stderr, "bed alloc\n");
            exit(1);
        }

        for (int j = 0; j < matrix.n; ++j)
        {
            if (i > j)
            {
                rows[j] = j;
            }
            else if (i < j)
            {
                rows[j - 1] = j;
            }
        }

        struct Matrix subm = submatrix(matrix, rows, matrix.n - 1);
        free(rows);

        print(subm);

        result += coeff * matrix.data[0][i] * det(subm);
        coeff *= -1;
    }

    return result;
}



int main()
{
    double m[9] = {3, 5, 1,
                   1, 4, 2,
                   7, 1, 9};
    printf("i am here\n");
    struct Matrix mat = {.n = 3};
    mat.data = malloc(sizeof(double*) * mat.n);

    to_matrix(&mat, m);
    print(mat);
    printf("det = %lf", det(mat));

    return 0;
}