struct Matrix
{
    double **data;
    int n;
};

struct Matrix to_matrix(double *matrix, int n);

double det(const struct Matrix matrix);

struct Matrix submatrix(const struct Matrix matrix, int *rows, int n);
