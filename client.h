#ifndef CLIENT_H
#define CLIENT_H

enum
{
    N = 6,
    MATRIX_SIZE = sizeof(double) * N * N,
    MAX_RESPONSE = 256,
    MAX_INT_PART = 10
};

void run(int sock);
void get_matrix(double *matrix, int n);

#endif //CLIENT_H
