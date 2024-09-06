#include "client.h"
#include "send_recv.h"

#include <stdio.h>
#include <stdlib.h>

void get_matrix(double *matrix, int n)
{
    for (int i = 0; i < n * n; ++i)
    {
        int sign = -1 + 2 * (rand() % 2);
        matrix[i] = sign * ((double)rand() / RAND_MAX) * MAX_INT_PART;
    }
}

void show_matrix(double *matrix, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%8.4lf ", matrix[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void run(int sock)
{
    printf("Press Enter to continue: ");
    while (getchar() == '\n')
    {
        double matrix[N * N];
        get_matrix(matrix, N);

        printf("send matrix:\n");
        show_matrix(matrix, N);

        if (sendall(sock, (char *)matrix, MATRIX_SIZE, 0) <= 0)
        {
            fprintf(stderr, "bed send\n");
            exit(1);
        }
    }
}