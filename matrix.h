#ifndef MATRIX_H
#define MATRIX_H

struct Matrix
{
    double **data;
    int n;
};

void to_matrix(struct Matrix *new_matrix, double *matrix);

double det(const struct Matrix matrix);

void submatrix(struct Matrix *new_matrix, struct Matrix matrix, int *rows);

#endif //MATRIX_H