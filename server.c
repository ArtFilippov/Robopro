#include "server.h"
#include "send_recv.h"
#include "matrix.h"

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>

int form_response(struct Server *server, char *buff, int max_len)
{
    double d = server->dets[(server->cyclic_i - 1) % NUMBER_OF_MATRICES];
    int n = -1;
    if (server->matrices >= NUMBER_OF_MATRICES)
    {
        double avg = 0;
        for (int i = 0; i < NUMBER_OF_MATRICES; ++i)
        {
            avg += server->dets[i];
        }
        avg /= NUMBER_OF_MATRICES;
        double del = server->dets[server->cyclic_i];
        n = snprintf(buff, max_len, "Det. = %.4lf\nAvg. det = %.4lf\nDel. det = %.4lf\n", d, avg, del);
    }
    else
    {
        n = snprintf(buff, max_len, "Det. = %.4lf\nAvg. det = N/A\nDel. det = N/A", d);
    }

    return n;
}

void run(struct Server *server)
{
    while (1)
    {
        int sock = accept(server->socket, NULL, NULL);
        if (sock < 0)
        {
            fprintf(stderr, "bed accept\n");
            exit(1);
        }

        switch (fork())
        {
        case -1:
            fprintf(stderr, "bed fork\n");
            exit(1);
        case 0:
            close(server->socket);
            server->socket = sock;
            client_handler(server);
            return;
        default:
            close(sock);
        }
    }
}

void client_handler(struct Server *server)
{
    while (1)
    {
        char r_buf[MATRIX_SIZE];
        int received = recvall(server->socket, r_buf, MATRIX_SIZE, 0);
        if (received < 0)
        {
            fprintf(stderr, "bed recv\n");
            exit(1);
        } else if (received == 0) {
            printf("disconnected\n");
            return;
        }

        struct Matrix m;
        m.data = (double **)malloc(sizeof(double **) * N);
        m.n = N;
        to_matrix(&m, (double *)r_buf);
        
        double d = det(m);
        free(m.data);

        server->dets[server->cyclic_i] = d;
        server->cyclic_i = (server->cyclic_i + 1) % NUMBER_OF_MATRICES;
        if (server->matrices < NUMBER_OF_MATRICES) {
            server->matrices += 1;
        }

        char s_buf[MAX_RESPONSE];
        int msg_size = form_response(server, s_buf, MAX_RESPONSE);
        if (sendall(server->socket, s_buf, MAX_RESPONSE, 0) < 0)
        {
            fprintf(stderr, "bed send\n");
            exit(1);
        }
    }
}