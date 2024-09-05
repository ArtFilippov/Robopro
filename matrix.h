struct Matrix
{
    double **data;
    int n;
};

struct Matrix to_matrix(double *matrix, int n);

double det(struct Matrix matrix);

struct Matrix submatrix(struct Matrix matrix, int *rows, int n);
