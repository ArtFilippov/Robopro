#ifndef CLIENT_H
#define CLIENT_H

#include <unistd.h>

enum
{
    N = 6,
    MATRIX_SIZE = sizeof(double) * N * N,
    MAX_RESPONSE = 256,
    MAX_INT_PART = 100
};

void run_by_timer(int sock, unsigned time);
void run_by_key(int sock);
void get_matrix(double *matrix, int n);

#endif //CLIENT_H
