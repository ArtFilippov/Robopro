cmake_minimum_required(VERSION 2.6.0)

project(Robopro LANGUAGES C)

set(CLIENT_SRC client_main.c client.c client.h)
set(SEND_RECV_SRC send_recv.c send_recv.h)
set(SERVER_SRC server_main.c server.c server.h)
set(MATRIX_SRC matrix.c matrix.h)

add_executable(client ${CLIENT_SRC} ${SEND_RECV_SRC})
add_executable(server ${SERVER_SRC} ${MATRIX_SRC} ${SEND_RECV_SRC})