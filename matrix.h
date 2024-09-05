struct Matrix
{
    double **m;
    int n;
};

struct Matrix to_matrix(double *matrix, int n);

double det(struct Matrix matrix);

struct Matrix submatrix(struct Matrix matrix, int *rows, int *columns, int n);
