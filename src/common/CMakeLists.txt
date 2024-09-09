cmake_minimum_required(VERSION 3.5)

project(SendRecv)

set(SEND_RECV_SRC send_recv.c send_recv.h)

add_library(SendRecv STATIC ${SEND_RECV_SRC})