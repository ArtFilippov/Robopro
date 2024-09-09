#ifndef SERVER_H
#define SERVER_H

enum
{
    NUMBER_OF_MATRICES = 5,
    N = 6,
    MATRIX_SIZE = sizeof(double) * N * N,
    MAX_RESPONSE = 256
};

struct Server
{
    int socket;
    double dets[NUMBER_OF_MATRICES];
    short cyclic_i; // указывает на самую старую запись в dets
    short matrices;
};

void run(struct Server *server);
int form_response(struct Server *server, char *buff, int max_len);
void client_handler(struct Server *server);

#endif // SERVER_H