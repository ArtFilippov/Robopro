struct Matrix
{
    double **data;
    int n;
};

void to_matrix(struct Matrix *new_matrix, double *matrix);

double det(const struct Matrix matrix);

struct Matrix submatrix(const struct Matrix matrix, int *rows, int n);
