#include "client.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    int sock;
    if (sock = socket(AF_INET, SOCK_STREAM, 0) < 0) 
    {
        fprintf(stderr, "bed socket");
        exit(1);
    }

    struct sockaddr_in addr = {.sin_family = AF_INET, .sin_port = 0, .sin_addr.s_addr = htonl(INADDR_LOOPBACK)};

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "bed connect");
        exit(1);
    }

    run_by_key(sock);

    close(sock);

    return 0;
}