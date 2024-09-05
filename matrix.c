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

void submatrix(struct Matrix *new_matrix, struct Matrix matrix, int *rows)
{
    for (int i = 0; i < new_matrix->n; ++i)
    {
        new_matrix->data[i] = matrix.data[rows[i]] + (matrix.n - new_matrix->n);
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

        struct Matrix subm;
        subm.n = matrix.n - 1;
        subm.data = (double **) malloc(sizeof(double **) * subm.n);
        
        submatrix(&subm, matrix, rows);
        free(rows);

        double d = det(subm);

        result += coeff * matrix.data[i][0] * d;
        free(subm.data);

        coeff *= -1;
    }

    return result;
}



int main()
{
    double m[9] = {3, 5, 1,
                   1, 4, 2,
                   7, 1, 9};
    struct Matrix mat = {.n = 3};
    mat.data = malloc(sizeof(double*) * mat.n);

    to_matrix(&mat, m);
    printf("det = %lf", det(mat));

    return 0;
}