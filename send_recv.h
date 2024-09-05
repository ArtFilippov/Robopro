#ifndef SEND_RECV_H
#define SEND_RECV_H

int sendall(int s, char *buf, int len, int flags);
int recvall(int s, char *buf, int len, int flags);

#endif //SEND_RECV_H