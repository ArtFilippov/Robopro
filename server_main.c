#include "server.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    struct Server server = {.cyclic_i = 0, .matrices = 0};
    server.socket  = socket(AF_INET, SOCK_STREAM, 0);
    if (server.socket < 0) 
    {
        fprintf(stderr, "bed socket");
        exit(1);
    }

    struct sockaddr_in addr = {.sin_family = AF_INET, .sin_port = htons(3456), .sin_addr.s_addr = htonl(INADDR_ANY)};

    if (bind(server.socket, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "bed bind");
        exit(1);
    }

    if (listen(server.socket, 1) < 0) {
        fprintf(stderr, "bed listen");
        exit(1);
    }

    run(&server);

    close(server.socket);

    return 0;
}