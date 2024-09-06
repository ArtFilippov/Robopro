#include "client.h"
#include "send_recv.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_matrix(double *matrix, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n * n; ++i) {
        matrix[i] = -MAX_INT_PART + rand() % MAX_INT_PART + (double) rand() / RAND_MAX;
    }
}

void show_matrix(double *matrix, int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%lf ", matrix[i * n + j]);
        }
        printf("\n");
    }
}

void run_by_key(int sock)
{
    while (getchar() == '\n') {
        double matrix[N * N];
        get_matrix(matrix, N);

        show_matrix(matrix, N);

        if (sendall(sock, matrix, MATRIX_SIZE, 0) <= 0)
        {
            fprintf(stderr, "bed send\n");
            exit(1);
        }

        char r_buf[MAX_RESPONSE];
        if (recvall(sock, r_buf, MAX_RESPONSE, 0) <= 0) {
            fprintf(stderr, "bed recv\n");
            exit(1);
        }

        printf("%s\n", r_buf);
    }
}